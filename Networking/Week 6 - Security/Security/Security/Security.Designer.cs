namespace Security
{
    partial class Security
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lbl_pass = new System.Windows.Forms.Label();
            this.tb_pass = new System.Windows.Forms.TextBox();
            this.btn_selectinput = new System.Windows.Forms.Button();
            this.lbl_input = new System.Windows.Forms.Label();
            this.lbl_inputname = new System.Windows.Forms.Label();
            this.lbl_output = new System.Windows.Forms.Label();
            this.btn_encrypt = new System.Windows.Forms.Button();
            this.lbl_outputname = new System.Windows.Forms.Label();
            this.btn_selectoutput = new System.Windows.Forms.Button();
            this.btn_decrypt = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lbl_pass
            // 
            this.lbl_pass.AutoSize = true;
            this.lbl_pass.Location = new System.Drawing.Point(22, 121);
            this.lbl_pass.Name = "lbl_pass";
            this.lbl_pass.Size = new System.Drawing.Size(77, 17);
            this.lbl_pass.TabIndex = 1;
            this.lbl_pass.Text = "Password: ";
            // 
            // tb_pass
            // 
            this.tb_pass.Location = new System.Drawing.Point(127, 118);
            this.tb_pass.Name = "tb_pass";
            this.tb_pass.Size = new System.Drawing.Size(150, 22);
            this.tb_pass.TabIndex = 0;
            // 
            // btn_selectinput
            // 
            this.btn_selectinput.Location = new System.Drawing.Point(287, 65);
            this.btn_selectinput.Name = "btn_selectinput";
            this.btn_selectinput.Size = new System.Drawing.Size(83, 23);
            this.btn_selectinput.TabIndex = 2;
            this.btn_selectinput.Text = "Select File";
            this.btn_selectinput.UseVisualStyleBackColor = true;
            this.btn_selectinput.Click += new System.EventHandler(this.btn_selectinput_Click);
            // 
            // lbl_input
            // 
            this.lbl_input.AutoSize = true;
            this.lbl_input.Location = new System.Drawing.Point(22, 65);
            this.lbl_input.Name = "lbl_input";
            this.lbl_input.Size = new System.Drawing.Size(69, 17);
            this.lbl_input.TabIndex = 3;
            this.lbl_input.Text = "Input File:";
            // 
            // lbl_inputname
            // 
            this.lbl_inputname.Location = new System.Drawing.Point(124, 65);
            this.lbl_inputname.Name = "lbl_inputname";
            this.lbl_inputname.Size = new System.Drawing.Size(153, 23);
            this.lbl_inputname.TabIndex = 4;
            this.lbl_inputname.Text = "None";
            // 
            // lbl_output
            // 
            this.lbl_output.AutoSize = true;
            this.lbl_output.Location = new System.Drawing.Point(22, 181);
            this.lbl_output.Name = "lbl_output";
            this.lbl_output.Size = new System.Drawing.Size(81, 17);
            this.lbl_output.TabIndex = 5;
            this.lbl_output.Text = "Output File:";
            // 
            // btn_encrypt
            // 
            this.btn_encrypt.Location = new System.Drawing.Point(25, 274);
            this.btn_encrypt.Name = "btn_encrypt";
            this.btn_encrypt.Size = new System.Drawing.Size(119, 112);
            this.btn_encrypt.TabIndex = 7;
            this.btn_encrypt.Text = "ENCRYPT";
            this.btn_encrypt.UseVisualStyleBackColor = true;
            this.btn_encrypt.Click += new System.EventHandler(this.btn_encrypt_Click);
            // 
            // lbl_outputname
            // 
            this.lbl_outputname.Location = new System.Drawing.Point(124, 181);
            this.lbl_outputname.Name = "lbl_outputname";
            this.lbl_outputname.Size = new System.Drawing.Size(153, 17);
            this.lbl_outputname.TabIndex = 9;
            this.lbl_outputname.Text = "None";
            // 
            // btn_selectoutput
            // 
            this.btn_selectoutput.Location = new System.Drawing.Point(287, 181);
            this.btn_selectoutput.Name = "btn_selectoutput";
            this.btn_selectoutput.Size = new System.Drawing.Size(83, 23);
            this.btn_selectoutput.TabIndex = 8;
            this.btn_selectoutput.Text = "Select File";
            this.btn_selectoutput.UseVisualStyleBackColor = true;
            this.btn_selectoutput.Click += new System.EventHandler(this.btn_selectoutput_Click);
            // 
            // btn_decrypt
            // 
            this.btn_decrypt.Location = new System.Drawing.Point(234, 274);
            this.btn_decrypt.Name = "btn_decrypt";
            this.btn_decrypt.Size = new System.Drawing.Size(119, 112);
            this.btn_decrypt.TabIndex = 10;
            this.btn_decrypt.Text = "DECRYPT";
            this.btn_decrypt.UseVisualStyleBackColor = true;
            this.btn_decrypt.Click += new System.EventHandler(this.btn_decrypt_Click);
            // 
            // Security
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(393, 472);
            this.Controls.Add(this.btn_decrypt);
            this.Controls.Add(this.lbl_outputname);
            this.Controls.Add(this.btn_selectoutput);
            this.Controls.Add(this.btn_encrypt);
            this.Controls.Add(this.tb_pass);
            this.Controls.Add(this.lbl_output);
            this.Controls.Add(this.lbl_pass);
            this.Controls.Add(this.lbl_inputname);
            this.Controls.Add(this.btn_selectinput);
            this.Controls.Add(this.lbl_input);
            this.Name = "Security";
            this.Text = "Security";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label lbl_pass;
        private System.Windows.Forms.TextBox tb_pass;
        private System.Windows.Forms.Label lbl_inputname;
        private System.Windows.Forms.Label lbl_input;
        private System.Windows.Forms.Button btn_selectinput;
        private System.Windows.Forms.Button btn_encrypt;
        private System.Windows.Forms.Label lbl_output;
        private System.Windows.Forms.Label lbl_outputname;
        private System.Windows.Forms.Button btn_selectoutput;
        private System.Windows.Forms.Button btn_decrypt;
    }
}

