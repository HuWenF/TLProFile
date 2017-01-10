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
            this.button1 = new System.Windows.Forms.Button();
            this.BasetextBox = new System.Windows.Forms.TextBox();
            this.Baselabel = new System.Windows.Forms.Label();
            this.FCbutton = new System.Windows.Forms.Button();
            this.FClabel = new System.Windows.Forms.Label();
            this.FCtextBox = new System.Windows.Forms.TextBox();
            this.SectionNamelabel = new System.Windows.Forms.Label();
            this.SectionNametextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(481, 205);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "遍历";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // BasetextBox
            // 
            this.BasetextBox.Location = new System.Drawing.Point(162, 118);
            this.BasetextBox.Name = "BasetextBox";
            this.BasetextBox.Size = new System.Drawing.Size(100, 21);
            this.BasetextBox.TabIndex = 1;
            this.BasetextBox.Text = "400000";
            // 
            // Baselabel
            // 
            this.Baselabel.AutoSize = true;
            this.Baselabel.Location = new System.Drawing.Point(31, 121);
            this.Baselabel.Name = "Baselabel";
            this.Baselabel.Size = new System.Drawing.Size(125, 12);
            this.Baselabel.TabIndex = 2;
            this.Baselabel.Text = "请输入基址(十六进制)";
            // 
            // FCbutton
            // 
            this.FCbutton.Location = new System.Drawing.Point(21, 182);
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
            this.FClabel.Location = new System.Drawing.Point(79, 147);
            this.FClabel.Name = "FClabel";
            this.FClabel.Size = new System.Drawing.Size(77, 12);
            this.FClabel.TabIndex = 4;
            this.FClabel.Text = "请输入特征码";
            // 
            // FCtextBox
            // 
            this.FCtextBox.Location = new System.Drawing.Point(162, 144);
            this.FCtextBox.Name = "FCtextBox";
            this.FCtextBox.Size = new System.Drawing.Size(237, 21);
            this.FCtextBox.TabIndex = 5;
            this.FCtextBox.Text = "8B44240C487826538B5C2414558B6C2410";
            // 
            // SectionNamelabel
            // 
            this.SectionNamelabel.AutoSize = true;
            this.SectionNamelabel.Location = new System.Drawing.Point(31, 91);
            this.SectionNamelabel.Name = "SectionNamelabel";
            this.SectionNamelabel.Size = new System.Drawing.Size(53, 12);
            this.SectionNamelabel.TabIndex = 7;
            this.SectionNamelabel.Text = "区段名称";
            // 
            // SectionNametextBox
            // 
            this.SectionNametextBox.Location = new System.Drawing.Point(162, 88);
            this.SectionNametextBox.Name = "SectionNametextBox";
            this.SectionNametextBox.Size = new System.Drawing.Size(100, 21);
            this.SectionNametextBox.TabIndex = 6;
            this.SectionNametextBox.Text = ".text";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(663, 374);
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
    }
}

