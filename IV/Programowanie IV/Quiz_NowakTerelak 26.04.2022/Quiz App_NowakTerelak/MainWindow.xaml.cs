using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;
using System.Xml;

namespace Quiz_App_NowakTerelak
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Question initialObject = new Question();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Load_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            string filePath = string.Empty;
            openFileDialog.DefaultExt = ".xml";
            openFileDialog.Filter = "Dokumenty tekstowe XML | *.xml";

            bool? result = openFileDialog.ShowDialog();
            if (result.Equals(true))
            {
                filePath = openFileDialog.FileName;
            }
            readXMLData(filePath);  // wczytanie zawartosci pliku do Listy jako pola prywatnego _questionList
            if(GLOBAL.LIST_of_questions.Count() == 0)
            {
                MessageBox.Show("Wczytano niewłaściwy plik!");
            }
            else
            {
                startClickButton.IsEnabled = true;
                initialObject.currentIndex = 0;
            }
        }

        private List<String> readXMLData(string XMLPath)
        {
            try
            {
                List<string> loadQuestions = new List<string>(File.ReadAllText(XMLPath).Split('\n'));
                for(int i = 0; i < loadQuestions.Count() - 1; i++)
                {
                    loadQuestions[i] = CesarCipher.Caesar_decoding(loadQuestions[i], GLOBAL.key);
                }
                GLOBAL.LIST_of_questions = loadQuestions;
                return GLOBAL.LIST_of_questions;
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
                return null;
            }

        }

        private async void Init_Click(object sender, RoutedEventArgs e)
        {
            startClickButton.IsEnabled = false;
            endClickButton.IsEnabled = true;
            loadDataButton.IsEnabled = false;

            //TIMER
            DispatcherTimer dt = new DispatcherTimer();
            dt.Interval = TimeSpan.FromSeconds(1);
            dt.Tick += Dt_Tick;
            dt.Start();

            QuestionLabel.Visibility = Visibility.Visible;
            QuestionInput.Visibility = Visibility.Visible;
            Answer0.Visibility = Visibility.Visible;
            Answer1.Visibility = Visibility.Visible;
            Answer2.Visibility = Visibility.Visible;
            Answer3.Visibility = Visibility.Visible;

            initialObject.isQuestionAnswered = false;
            initialObject.currentIndex = 0;

            List<int> qAns = new List<int>(GLOBAL.LIST_of_questions.Count);
            GLOBAL.LIST_of_answer = qAns;

            for(int i = 0; i < GLOBAL.LIST_of_questions.Count - 1; i++)
            {
                initialObject.isQuestionAnswered = false;
                string[] elements = GLOBAL.LIST_of_questions[i].Split(';');
                
                QuestionInput.Text = elements[0];
                Answer0.Content = elements[1];
                Answer1.Content = elements[2];
                Answer2.Content = elements[3];
                Answer3.Content = elements[4];
                
                while(initialObject.isQuestionAnswered == false)
                {
                    if (initialObject.isQuestionAnswered == true)
                    {
                        break;
                    }
                    else
                    {
                        await Task.Delay(1);
                    }
                }
                initialObject.currentIndex++;
            }

            QuestionLabel.Visibility = Visibility.Hidden;   // MOZNA USTAWIC CONTENT JAKO NP: WCISNIJ ZAKONCZ ABY POZNAC WYNIK LUB COS w/e
            QuestionInput.Visibility = Visibility.Hidden;
            Answer0.Visibility = Visibility.Hidden;
            Answer1.Visibility = Visibility.Hidden;
            Answer2.Visibility = Visibility.Hidden;
            Answer3.Visibility = Visibility.Hidden;
        }
        private int increment = 0;
        private int minute = 0;
        private void Dt_Tick(object sender, EventArgs e)
        {
            increment++;
            if (increment == 60)
            {
                minute += 1;
                increment = 0;
            }
            if (minute == 0)
            {
                if (increment < 10)
                {
                    GLOBAL.time ="00:0" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
                else
                {
                    GLOBAL.time ="00:" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
            }
            else if (minute <10)
            {
                if (increment < 10)
                {
                    GLOBAL.time = "0"+minute.ToString() + ":0" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
                else
                {
                    GLOBAL.time = "0"+minute.ToString() + ":" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
            }
            else
            {
                if (increment < 10)
                { 
                    GLOBAL.time = minute.ToString() + ":0" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
                else
                {
                    GLOBAL.time = minute.ToString() + ":" + increment.ToString();
                    timerValue.Text = GLOBAL.time;
                }
            }
        }
        private void Finish_Click(object sender, RoutedEventArgs e)
        {
            loadDataButton.IsEnabled = true;
            startClickButton.IsEnabled = false;
            endClickButton.IsEnabled = false;
            ResultWindow finishWindow = new ResultWindow();
            finishWindow.Show();
            Close();
        }
        private void AnswerA_Click(object sender, RoutedEventArgs e)
        {
            GLOBAL.LIST_of_answer.Insert(initialObject.currentIndex, 0);
            initialObject.isQuestionAnswered = true;
        }

        private void AnswerB_Click(object sender, RoutedEventArgs e)
        {
            GLOBAL.LIST_of_answer.Insert(initialObject.currentIndex, 1);
            initialObject.isQuestionAnswered = true;
        }

        private void AnswerC_Click(object sender, RoutedEventArgs e)
        {
            GLOBAL.LIST_of_answer.Insert(initialObject.currentIndex, 2);
            initialObject.isQuestionAnswered = true;
        }

        private void AnswerD_Click(object sender, RoutedEventArgs e)
        {
            GLOBAL.LIST_of_answer.Insert(initialObject.currentIndex, 3);
            initialObject.isQuestionAnswered = true;
        }
    }
}
