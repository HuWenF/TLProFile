// DLL.cpp : 定义 DLL 应用程序的导出函数。
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


// 这是导出函数的一个示例。
DLL_API int ReserchTree()
{
	
	DWORD ReadAddress = NULL;
	BYTE ADD = NULL;
	int ReadResult = 0;
	
	//开始读取二叉树基址

	
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4c + 0x4), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4), &ReadAddress, 4, NULL);
	ReadProcessMemory(G_Handle, (LPCVOID)(ReadAddress + 0x4), &ReadAddress, 4, NULL);
	//开始判断
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
	//读取内存
	memset(TempAddress, 0, sizeof(TempAddress));
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, ReadSize, NULL);
	//直接用C语言实现

	for (int i = 0,j = 0; i < sizeof(TempAddress); i++)
	{

		for (j = 0; j < sizeof(FCode); i++)
		{
			if (FCode[j] == (char)"?")
			{
				continue;
			}
			//如果匹配完成就退出循环
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


