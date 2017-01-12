namespace 天龙二叉树人物遍历
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.BasetextBox = new System.Windows.Forms.TextBox();
            this.Baselabel = new System.Windows.Forms.Label();
            this.FCbutton = new System.Windows.Forms.Button();
            this.FClabel = new System.Windows.Forms.Label();
            this.FCtextBox = new System.Windows.Forms.TextBox();
            this.SectionNamelabel = new System.Windows.Forms.Label();
            this.SectionNametextBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.RawlabelList = new System.Windows.Forms.Label();
            this.ResultlistView = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.复制ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ProNamelabel = new System.Windows.Forms.Label();
            this.ProNametextBox = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(56, 333);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "遍历";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Visible = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // BasetextBox
            // 
            this.BasetextBox.Location = new System.Drawing.Point(137, 90);
            this.BasetextBox.Name = "BasetextBox";
            this.BasetextBox.Size = new System.Drawing.Size(100, 21);
            this.BasetextBox.TabIndex = 1;
            this.BasetextBox.Text = "400000";
            // 
            // Baselabel
            // 
            this.Baselabel.AutoSize = true;
            this.Baselabel.Location = new System.Drawing.Point(6, 93);
            this.Baselabel.Name = "Baselabel";
            this.Baselabel.Size = new System.Drawing.Size(125, 12);
            this.Baselabel.TabIndex = 2;
            this.Baselabel.Text = "请输入基址(十六进制)";
            // 
            // FCbutton
            // 
            this.FCbutton.Location = new System.Drawing.Point(56, 287);
            this.FCbutton.Name = "FCbutton";
            this.FCbutton.Size = new System.Drawing.Size(75, 23);
            this.FCbutton.TabIndex = 3;
            this.FCbutton.Text = "开始搜索";
            this.FCbutton.UseVisualStyleBackColor = true;
            this.FCbutton.Click += new System.EventHandler(this.FCbutton_Click);
            // 
            // FClabel
            // 
            this.FClabel.AutoSize = true;
            this.FClabel.Location = new System.Drawing.Point(54, 146);
            this.FClabel.Name = "FClabel";
            this.FClabel.Size = new System.Drawing.Size(77, 12);
            this.FClabel.TabIndex = 4;
            this.FClabel.Text = "请输入特征码";
            // 
            // FCtextBox
            // 
            this.FCtextBox.Location = new System.Drawing.Point(137, 143);
            this.FCtextBox.Name = "FCtextBox";
            this.FCtextBox.Size = new System.Drawing.Size(237, 21);
            this.FCtextBox.TabIndex = 5;
            // 
            // SectionNamelabel
            // 
            this.SectionNamelabel.AutoSize = true;
            this.SectionNamelabel.Location = new System.Drawing.Point(78, 121);
            this.SectionNamelabel.Name = "SectionNamelabel";
            this.SectionNamelabel.Size = new System.Drawing.Size(53, 12);
            this.SectionNamelabel.TabIndex = 7;
            this.SectionNamelabel.Text = "区段名称";
            // 
            // SectionNametextBox
            // 
            this.SectionNametextBox.Location = new System.Drawing.Point(137, 118);
            this.SectionNametextBox.Name = "SectionNametextBox";
            this.SectionNametextBox.Size = new System.Drawing.Size(100, 21);
            this.SectionNametextBox.TabIndex = 6;
            this.SectionNametextBox.Text = ".text";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(78, 214);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 9;
            this.label1.Text = "搜索结果";
            // 
            // RawlabelList
            // 
            this.RawlabelList.AutoSize = true;
            this.RawlabelList.Location = new System.Drawing.Point(69, 241);
            this.RawlabelList.Name = "RawlabelList";
            this.RawlabelList.Size = new System.Drawing.Size(0, 12);
            this.RawlabelList.TabIndex = 11;
            // 
            // ResultlistView
            // 
            this.ResultlistView.Alignment = System.Windows.Forms.ListViewAlignment.Left;
            this.ResultlistView.BackgroundImageTiled = true;
            this.ResultlistView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2});
            this.ResultlistView.ContextMenuStrip = this.contextMenuStrip1;
            this.ResultlistView.Cursor = System.Windows.Forms.Cursors.Default;
            this.ResultlistView.FullRowSelect = true;
            this.ResultlistView.GridLines = true;
            this.ResultlistView.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.ResultlistView.Location = new System.Drawing.Point(146, 170);
            this.ResultlistView.Name = "ResultlistView";
            this.ResultlistView.Size = new System.Drawing.Size(175, 186);
            this.ResultlistView.TabIndex = 12;
            this.ResultlistView.UseCompatibleStateImageBehavior = false;
            this.ResultlistView.View = System.Windows.Forms.View.Details;
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "行数";
            this.columnHeader1.Width = 50;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "数值";
            this.columnHeader2.Width = 120;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.复制ToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(101, 26);
            this.contextMenuStrip1.Text = "复制";
            // 
            // 复制ToolStripMenuItem
            // 
            this.复制ToolStripMenuItem.Name = "复制ToolStripMenuItem";
            this.复制ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.复制ToolStripMenuItem.Text = "复制";
            this.复制ToolStripMenuItem.Click += new System.EventHandler(this.复制ToolStripMenuItem_Click);
            // 
            // ProNamelabel
            // 
            this.ProNamelabel.AutoSize = true;
            this.ProNamelabel.Location = new System.Drawing.Point(78, 66);
            this.ProNamelabel.Name = "ProNamelabel";
            this.ProNamelabel.Size = new System.Drawing.Size(41, 12);
            this.ProNamelabel.TabIndex = 14;
            this.ProNamelabel.Text = "进程名";
            // 
            // ProNametextBox
            // 
            this.ProNametextBox.Location = new System.Drawing.Point(137, 63);
            this.ProNametextBox.Name = "ProNametextBox";
            this.ProNametextBox.Size = new System.Drawing.Size(100, 21);
            this.ProNametextBox.TabIndex = 13;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(586, 439);
            this.Controls.Add(this.ProNamelabel);
            this.Controls.Add(this.ProNametextBox);
            this.Controls.Add(this.ResultlistView);
            this.Controls.Add(this.RawlabelList);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.SectionNamelabel);
            this.Controls.Add(this.SectionNametextBox);
            this.Controls.Add(this.FCtextBox);
            this.Controls.Add(this.FClabel);
            this.Controls.Add(this.FCbutton);
            this.Controls.Add(this.Baselabel);
            this.Controls.Add(this.BasetextBox);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox BasetextBox;
        private System.Windows.Forms.Label Baselabel;
        private System.Windows.Forms.Button FCbutton;
        private System.Windows.Forms.Label FClabel;
        private System.Windows.Forms.TextBox FCtextBox;
        private System.Windows.Forms.Label SectionNamelabel;
        private System.Windows.Forms.TextBox SectionNametextBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label RawlabelList;
        private System.Windows.Forms.ListView ResultlistView;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 复制ToolStripMenuItem;
        private System.Windows.Forms.Label ProNamelabel;
        private System.Windows.Forms.TextBox ProNametextBox;
    }
}

