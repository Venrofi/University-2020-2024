using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Threading;

namespace Quiz_App_NowakTerelak
{
    class Question
    {
        private string _questionString;
        private string _answer_A;
        private string _answer_B;
        private string _answer_C;
        private string _answer_D;
        private int _true_Answer;

        private List<String> _questionList;
        private int _currentIndex;
        private bool _isQuestionAnswered;
        private List<int> _answerList;

        private String _timer;
        private int _timeIncrement = 0;
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
        public String timer
        {
            get { return _timer; }
            set { _timer = value; }
        }
        public int timeIncrement
        {
            get { return _timeIncrement; }
            set { _timeIncrement = value; }
        }
        public List<int> answerList
        {
            get { return _answerList; }
            set { _answerList = value; }
        }
        public bool isQuestionAnswered
        {
            get { return _isQuestionAnswered; }
            set { _isQuestionAnswered = value; }
        }
        public int currentIndex
        {
            get { return _currentIndex; }
            set { _currentIndex = value; }
        }
        public List<String> questionList
        {
            get { return _questionList; }
            set { _questionList = value; }
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
