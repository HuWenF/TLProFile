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
            

            char[] SectionName = SectionNametextBox.Text.ToArray();
            int size = FCodestr.Length / 2;
            int result = 0;
            int Count = 0;
            List<Byte> Code = new List<Byte>();

            for (int i = 0; i < size; i++)
            {
                //Debug.WriteLine(FCodestr.Substring(i*8, 8));
                //Debug.WriteLine(FCodestr.Replace("?", "CC"));
                //首先把?字符串转化为CC字符串
                FCodestr = FCodestr.Replace("?", "C");
                //开始转换 ascii码转换为字节 比如"8E"的ascii转成8E的单字节字节
                Debug.WriteLine(Convert.ToByte(FCodestr.Substring(i * 2, 2), 16));

                //转换后加入到Code 的List数组中去
                Code.Add(Convert.ToByte(FCodestr.Substring(i * 2, 2), 16));
            }
            //特征码格式转换
            System.Byte[] FCoderchr = Code.ToArray();
            //获取区段大小

            
            

            unsafe
            {
                int SectionBase = (int)&SectionBase;
                int SectionSize = (int)&SectionSize;
                result = DLL.GetProSectionSizeFromPE(FAddressInt, SectionName, SectionBase, SectionSize);
                if (result == -1)
                {
                    return;
                }
                //首先清空textBox
               // ListTextBox.Clear();
                ResultlistView.Items.Clear();
                //特征码搜索
                while (true)
                {
                    result = DLL.FeatureCode(SectionBase, SectionSize, FCoderchr, size);
                    if (result == -1)
                    {
                        break;
                    }
                    
                 //   ListTextBox.AppendText(result.ToString("X") + "\r\n");
                   
                    
                    ListViewItem item = new ListViewItem();
                    Count++;
                    item.SubItems[0].Text = Count.ToString();
                    item.SubItems.Add(result.ToString("X"));
                    ResultlistView.Items.Add(item);
                  
                    SectionBase = result + 1;
                }
               
                return;

            }

        }

        private void 复制ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(ResultlistView.SelectedItems[0].SubItems[1].Text);

        }

      
    }
}
