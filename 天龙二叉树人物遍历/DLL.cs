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
        [DllImport("DLL")]
        public static extern void FeatureCode(System.Int32 BaseAddress, char[] FCode);
        [DllImport("DLL")]
        public static extern int ReserchTree();


    }
}
