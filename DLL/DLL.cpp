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

//����Ŀ���ڴ棨��λҳ��
DLL_API void FeatureCode(DWORD BaseAddress, char *FCode,int SectionSize)
{
	char *TempAddress = (char*)malloc(SectionSize);
	


	
	//��ȡ�ڴ��Լ���ʼ��
	memset(TempAddress, 0, SectionSize);
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, SectionSize, NULL);

	//��ȡĿ���ڴ�PE�ļ�text�εĴ�С
	//��ʼ���������ڴ�ռ�
	




	//ֱ����C����ʵ��
	for (int i = 0, j = 0; i < SectionSize; i++)
	{

		for (j = 0; j < sizeof(FCode); j++,i++)
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

	//�ͷ���Դ
	free(TempAddress);

		

}




//��ȡ�ļ������δ�С
DLL_API int GetProSectionSizeFromPE(DWORD BaseAddress, char TarGetName[],OUT int *OutSectionBase,OUT int *OutSectionSize)
{
	if (BaseAddress == NULL || TarGetName == NULL)
	{
		MessageBox(NULL, L"���������������", NULL, 0);
		return -1;
	}

	char TempAddress[ReadSize]; // ��ȡ��Ŀ���ַ
	IMAGE_DOS_HEADER *DosHeader;  //Dosͷ
	IMAGE_NT_HEADERS *NTHeader;	//Ntͷ
	IMAGE_OPTIONAL_HEADER *OPHeader;//Option ͷ
	IMAGE_SECTION_HEADER *SecHeader;//section ͷ
	int result = 0;
	int sectionCount = 0;
	DWORD SecTmp;
	int Tmp;
	int SectionSize = 0;
	
	//��ȡ�ڴ��Լ���ʼ��
	memset(TempAddress, 0, sizeof(TempAddress));
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, ReadSize, NULL);

	//��ȡĿ���ڴ�PE�ļ�text�εĴ�С

	DosHeader = (IMAGE_DOS_HEADER *)TempAddress;
	NTHeader = (IMAGE_NT_HEADERS *)(DosHeader->e_lfanew + TempAddress);
	//�ж��Ƿ���PE�ļ�
	if (DosHeader->e_magic != 0x5a4d || NTHeader->Signature != 0x4550)
	{
		MessageBox(NULL, L"��PE�ļ� Error", NULL, 0);
		return -1;
	}
	//��ȡ�������
	sectionCount = NTHeader->FileHeader.NumberOfSections;
	//��ȡ�����׵�ַ
	int SetionAddr = (int)(IMAGE_SECTION_HEADER *)&(NTHeader->OptionalHeader);
	SetionAddr = SetionAddr + NTHeader->FileHeader.SizeOfOptionalHeader;

	SecHeader = (IMAGE_SECTION_HEADER *)SetionAddr;

	OutputDebugStringA((LPCSTR)SecHeader->Name);
	//�ж��ǲ���.text����
	while (sectionCount)
	{
		//�ж��ǲ���Ŀ������
		result = strcmp((char *)SecHeader->Name, TarGetName);
		if (!result)
		{
			//��ȡ���δ�С
			SectionSize = SecHeader->SizeOfRawData;
			break;
		}
		//	int A = (int)&(SecHeader->Characteristics);
		//	int B = SecHeader->VirtualAddress;
		//	int C = (A - SecTmp + 0x4) + SecTmp;
		sectionCount--;
		//��ֵ��ʱ����
		SecTmp = (DWORD)SecHeader;
		Tmp = (DWORD)&(SecHeader->Characteristics);

		//���������С�õ���һ�������ַ
		SecHeader = (IMAGE_SECTION_HEADER *)(Tmp - SecTmp + 0x4 + SecTmp);

	}
	if (SectionSize == 0)
	{
		MessageBox(NULL, L"û�ҵ�Ŀ���������� Error", NULL, 0);
		return -1;
	}

	*OutSectionBase = NTHeader->OptionalHeader.ImageBase + SecHeader->VirtualAddress;
	*OutSectionSize = SectionSize;

	return 0;

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


