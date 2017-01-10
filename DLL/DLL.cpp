// DLL.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DLL.h"
#include <string>

using namespace std;

DWORD BaseAddress = 0xB04AC8;
HANDLE G_Handle = NULL;
const int ReadSize = 4096;

void ReadRightTree(DWORD Address);


DLL_API int initDll(int ProcID)
{

	G_Handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, ProcID);
	if (G_Handle == NULL)
	{
		MessageBox(NULL, L"OpenProcess Error", NULL, 0);
		return -1;
	}

	return 1;



}


// ���ǵ���������һ��ʾ����
DLL_API int ReserchTree()
{
	
	DWORD ReadAddress = NULL;
	BYTE ADD = NULL;
	int ReadResult = 0;
	
	//��ʼ��ȡ��������ַ

	
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4c + 0x4), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4), &ReadAddress, 4, NULL);
	//��ʼ�ж�
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x15), &ADD, 1, NULL);
	if (ADD == NULL)
	{
		return -1;
	}

	ReadRightTree(ReadAddress);


	return 0;

}


DLL_API void FeatureCode(DWORD BaseAddress, char *FCode)
{
	
	char TempAddress[ReadSize];
	string STempAddr;
	string SFCode(FCode);
	int matchInt = 0;
	//��ȡ�ڴ�
	memset(TempAddress, 0, sizeof(TempAddress));
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, ReadSize, NULL);
	//ֱ����C����ʵ��

	for (int i = 0,j = 0; i < sizeof(TempAddress); i++)
	{

		for (j = 0; j < sizeof(FCode); i++)
		{
			if (FCode[j] == (char)"?")
			{
				continue;
			}
			//���ƥ����ɾ��˳�ѭ��
			if (FCode[j] != TempAddress[i])
			{
				break;
			}
		}

		if (j == sizeof(FCode))
		{
			break;
		}

	}
		

}




void ReadRightTree(DWORD Address)
{
	if (Address == NULL)
	{
		return;
	}
	CHAR chInput[512];
	DWORD ReadAddress = NULL;
	ReadProcessMemory(G_Handle, (LPCVOID)(Address + 0x8), &ReadAddress, 4, NULL);

	//[[[[eax+0x10]+0x1D0]+0x4]+0x2788]
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x10), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x1d0), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x2788), &ReadAddress, 4, NULL);
	
	wsprintf((LPWSTR)chInput, L"HEX:%X DEC:%d \n", ReadAddress, ReadAddress);
	OutputDebugString((LPWSTR)chInput);
	
	ReadRightTree(ReadAddress);
	return;
	
}


