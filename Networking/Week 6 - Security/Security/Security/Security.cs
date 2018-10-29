using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Security
{
    public partial class Security : Form
    {

        public string InputPath;
        public string OutputPath;
        public Manager manager;
        public Security()
        {
            InputPath = "";
            OutputPath = "";
            InitializeComponent();
        }

        private void btn_selectinput_Click(object sender, EventArgs e)
        {
            InputPath = selectFile();
            lbl_inputname.Text = System.IO.Path.GetFileName(InputPath); // Properties > Auto scale uit i.v.m. layers button.
        }

        private void btn_selectoutput_Click(object sender, EventArgs e)
        {
            OutputPath = selectFile();
            lbl_outputname.Text = System.IO.Path.GetFileName(OutputPath);
        }


        private void btn_encrypt_Click(object sender, EventArgs e)
        {
            makeManager();
            if (manager.Encrypt())
            {
                MessageBox.Show("Encryption succesvol");
            }
            else
            {
                MessageBox.Show("Encryption niet succesvol");
            }
        }


        private void btn_decrypt_Click(object sender, EventArgs e)
        {
            makeManager();
            if (manager.Decrypt())
            {
                MessageBox.Show("Decryption succesvol");
            }
            else
            {
                MessageBox.Show("Decryption niet succesvol");
            }
        }

        private void makeManager()
        {
            try
            {
                manager = new Manager(Convert.ToString(tb_pass.Text), InputPath, OutputPath);
            }
            catch (ArgumentNullException)
            {
                MessageBox.Show("Argument null exception");
            }
            
        }

        private string selectFile()
        {
            string fileName = "";
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter =
               "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            dialog.InitialDirectory = "C:\\";
            dialog.Title = "Select a text file";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                fileName = dialog.FileName;
            }
            return fileName;
        }
    }
}
