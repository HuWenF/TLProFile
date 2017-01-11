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

//搜索目标内存（单位页）
DLL_API void FeatureCode(DWORD BaseAddress, char *FCode,int SectionSize)
{
	char *TempAddress = (char*)malloc(SectionSize);
	


	
	//读取内存以及初始化
	memset(TempAddress, 0, SectionSize);
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, SectionSize, NULL);

	//获取目标内存PE文件text段的大小
	//开始遍历整个内存空间
	




	//直接用C语言实现
	for (int i = 0, j = 0; i < SectionSize; i++)
	{

		for (j = 0; j < sizeof(FCode); j++,i++)
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

	//释放资源
	free(TempAddress);

		

}




//获取文件的区段大小
DLL_API int GetProSectionSizeFromPE(DWORD BaseAddress, char TarGetName[],OUT int *OutSectionBase,OUT int *OutSectionSize)
{
	if (BaseAddress == NULL || TarGetName == NULL)
	{
		MessageBox(NULL, L"输入区块参数错误", NULL, 0);
		return -1;
	}

	char TempAddress[ReadSize]; // 读取的目标地址
	IMAGE_DOS_HEADER *DosHeader;  //Dos头
	IMAGE_NT_HEADERS *NTHeader;	//Nt头
	IMAGE_OPTIONAL_HEADER *OPHeader;//Option 头
	IMAGE_SECTION_HEADER *SecHeader;//section 头
	int result = 0;
	int sectionCount = 0;
	DWORD SecTmp;
	int Tmp;
	int SectionSize = 0;
	
	//读取内存以及初始化
	memset(TempAddress, 0, sizeof(TempAddress));
	ReadProcessMemory(G_Handle, (LPCVOID)BaseAddress, TempAddress, ReadSize, NULL);

	//获取目标内存PE文件text段的大小

	DosHeader = (IMAGE_DOS_HEADER *)TempAddress;
	NTHeader = (IMAGE_NT_HEADERS *)(DosHeader->e_lfanew + TempAddress);
	//判断是否是PE文件
	if (DosHeader->e_magic != 0x5a4d || NTHeader->Signature != 0x4550)
	{
		MessageBox(NULL, L"非PE文件 Error", NULL, 0);
		return -1;
	}
	//获取区块个数
	sectionCount = NTHeader->FileHeader.NumberOfSections;
	//获取区块首地址
	int SetionAddr = (int)(IMAGE_SECTION_HEADER *)&(NTHeader->OptionalHeader);
	SetionAddr = SetionAddr + NTHeader->FileHeader.SizeOfOptionalHeader;

	SecHeader = (IMAGE_SECTION_HEADER *)SetionAddr;

	OutputDebugStringA((LPCSTR)SecHeader->Name);
	//判断是不是.text区段
	while (sectionCount)
	{
		//判断是不是目标区段
		result = strcmp((char *)SecHeader->Name, TarGetName);
		if (!result)
		{
			//获取区段大小
			SectionSize = SecHeader->SizeOfRawData;
			break;
		}
		//	int A = (int)&(SecHeader->Characteristics);
		//	int B = SecHeader->VirtualAddress;
		//	int C = (A - SecTmp + 0x4) + SecTmp;
		sectionCount--;
		//赋值临时变量
		SecTmp = (DWORD)SecHeader;
		Tmp = (DWORD)&(SecHeader->Characteristics);

		//计算区块大小得到下一个区块地址
		SecHeader = (IMAGE_SECTION_HEADER *)(Tmp - SecTmp + 0x4 + SecTmp);

	}
	if (SectionSize == 0)
	{
		MessageBox(NULL, L"没找到目标区段名称 Error", NULL, 0);
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


