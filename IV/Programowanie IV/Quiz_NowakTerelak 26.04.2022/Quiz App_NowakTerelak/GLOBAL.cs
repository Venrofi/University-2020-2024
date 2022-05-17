using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quiz_App_NowakTerelak
{
    public static class GLOBAL
    {
        public static int key = 10; //szyfrowanie
        public static List<String> LIST_of_questions = new List<String>(); //pytania globalny range
        public static List<int> LIST_of_answer = new List<int>(); //odpowiedzi globalny range
        public static int pointCount = 0;
        public static String time { get; set; } //zmienna przechowujaca czas
    }
}
