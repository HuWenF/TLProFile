// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DLL_EXPORTS
#define DLL_API extern "C" __declspec(dllexport)
#else
#define DLL_API extern "C" __declspec(dllimport)
#endif





DLL_API int ReserchTree();
DLL_API void FeatureCode(DWORD BaseAddress, char *FCode, int SectionSize);
DLL_API int initDll(int ProcID);
DLL_API int GetProSectionSizeFromPE(DWORD BaseAddress, char TarGetName[], OUT int *OutSectionBase, OUT int *OutSectionSize);
