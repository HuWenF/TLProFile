using System.Runtime.InteropServices;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;



namespace 天龙二叉树人物遍历
{
    public partial class Form1 : Form
    {
        //载入初始化DLL的调用函数
        [DllImport("DLL",EntryPoint = "initDll",CallingConvention=CallingConvention.Cdecl)]
        public static extern int initDll(int ProcID);
       
        //全局参数
        string GameName = "Game";

        public Form1()
        {

            InitializeComponent();
            //DLL初始化
             //获取进程ID
            Process[] LocalName = Process.GetProcessesByName(GameName);
            if (LocalName.Length != 1)
            {
                MessageBox.Show("无此进程名或者出现重复进程名");
                return;
            }
            
            initDll(LocalName[0].Id);
        }

        private void button1_Click(object sender, EventArgs e)
        {
          
           
            //搜索二叉树
            DLL.ReserchTree();

        }

        private void FCbutton_Click(object sender, EventArgs e)
        {
            
            

            //获取内容
            //进制转换
            Int32 FAddressInt = Convert.ToInt32(BasetextBox.Text, 16);
            String FCodestr = FCtextBox.Text;
            char[] Code = FCodestr.ToCharArray();

            //特征码搜索
            DLL.FeatureCode(FAddressInt, Code);




        }

      
    }
}
