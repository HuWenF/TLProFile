// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef DLL_EXPORTS
#define DLL_API extern "C" __declspec(dllexport)
#else
#define DLL_API extern "C" __declspec(dllimport)
#endif





DLL_API int ReserchTree();
DLL_API int FeatureCode(IN DWORD BaseAddress, IN int SectionSize, IN char *FCode, IN int FCodeSize);
DLL_API int initDll(int ProcID);
DLL_API int GetProSectionSizeFromPE(DWORD BaseAddress, char TarGetName[], OUT int *OutSectionBase, OUT int *OutSectionSize);
