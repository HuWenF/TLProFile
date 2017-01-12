using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
namespace 天龙二叉树人物遍历
{
    class DLL
    {
       
        //调用的DLL函数
        [DllImport("DLL", EntryPoint = "FeatureCode", CallingConvention = CallingConvention.Cdecl)]
        public static extern int FeatureCode(System.Int32 BaseAddress, int SectionSize, System.Byte[] FCode, int FCodeSize);

        [DllImport("DLL", EntryPoint = "ReserchTree", CallingConvention = CallingConvention.Cdecl)]
        public static extern int ReserchTree();

        [DllImport("DLL", EntryPoint = "GetProSectionSizeFromPE", CallingConvention = CallingConvention.Cdecl)]
        public static extern int GetProSectionSizeFromPE(System.Int32 BaseAddress, char[] TarGetName,System.Int32 SectionBase,System.Int32 SectionSize);
        [DllImport("DLL", EntryPoint = "initDll", CallingConvention = CallingConvention.Cdecl)]
        public static extern int initDll(int ProcID);

    }
}
