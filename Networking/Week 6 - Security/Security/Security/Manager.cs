using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Security
{
    public class Manager
    {
        public string Password { get; private set; }
        public string InputFilePath { get; private set; }
        public string OutputFilePath { get; private set; }

        public Manager(string password, string inputFilePath, string outputFilePath)
        {
            if (string.IsNullOrWhiteSpace(password) || string.IsNullOrWhiteSpace(inputFilePath) ||
                string.IsNullOrWhiteSpace(outputFilePath))
            {
                throw new ArgumentNullException("Strings zijn null");
            }
            Password = password;
            InputFilePath = inputFilePath;
            OutputFilePath = outputFilePath;
        }


        public bool Encrypt()
        {
            //return false kan eventueel nog, maar nog niet belangrijk.
            string input = File.ReadAllText(InputFilePath);
            string[] encryptedResult = new string[input.Length];

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < input.Length; i++)
                sb.Append((char)(input[i] ^ Password[(i % Password.Length)]));
            string result = sb.ToString();

            File.WriteAllText(OutputFilePath, result);
            return true;
        }
        // dubbele code, maar voor later kan het veranderen
        public bool Decrypt()
        {
            string input = File.ReadAllText(InputFilePath);
            string[] encryptedResult = new string[input.Length];

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < input.Length; i++)
                sb.Append((char)(input[i] ^ Password[(i % Password.Length)]));
            string result = sb.ToString();

            File.WriteAllText(OutputFilePath, result);
            return true;
        }

    }
}
