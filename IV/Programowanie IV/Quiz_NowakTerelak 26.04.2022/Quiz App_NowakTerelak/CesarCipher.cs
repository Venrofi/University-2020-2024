using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quiz_App_NowakTerelak
{
    public static class CesarCipher
    {
        static private char coding(char ch, int key)
        {
            if (!char.IsLetter(ch))
            {

                return ch;
            }

            char d = char.IsUpper(ch) ? 'A' : 'a';
            return (char)((((ch + key) - d) % 26) + d);
        }
        public static string Caesar_coding(string text, int key)
        {
            byte[] bytes = Encoding.Default.GetBytes(text);
            text = Encoding.UTF8.GetString(bytes);

            bytes = Encoding.Default.GetBytes("");
            string output = Encoding.UTF8.GetString(bytes);

            foreach (char ch in text)
                output += coding(ch, key);

            return output;
        }

        public static string Caesar_decoding(string text, int key)
        {
            return Caesar_coding(text, 26 - key);
        }
    }
}
