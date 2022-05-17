using System;
using System.Collections.Generic;
using System.Text;

namespace quizGenerator
{

    class Question
    {
        private string _questionString;
        private string _answer_A;
        private string _answer_B;
        private string _answer_C;
        private string _answer_D;
        private int _true_Answer;
        private int _key = 10;

        public Question()
        {
            _questionString = "";
            _answer_A = "";
            _answer_B = "";
            _answer_C = "";
            _answer_D = "";
            _true_Answer = -1;
        }

        public override string ToString()
        {
            return $"{_questionString}; {_answer_A}; {_answer_B}; {_answer_C}; {_answer_D}; {_true_Answer}";
        }

        public int key
        {
            get { return _key; }
            set { _key = value; }
        }

        public string questionString
        {
            get { return _questionString; }
            set { _questionString = value; }
        }
        public string answer_A
        {
            get { return _answer_A; }
            set { _answer_A = value; }
        }
        public string answer_B
        {
            get { return _answer_B; }
            set { _answer_B = value; }
        }
        public string answer_C
        {
            get { return _answer_C; }
            set { _answer_C = value; }
        }
        public string answer_D
        {
            get { return _answer_D; }
            set { _answer_D = value; }
        }
        public int true_Answer
        {
            get { return _true_Answer; }
            set { _true_Answer = value; }
        }
    }
}
