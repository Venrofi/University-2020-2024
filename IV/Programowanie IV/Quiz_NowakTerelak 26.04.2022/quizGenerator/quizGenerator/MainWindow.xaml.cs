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
using System.Xml;

namespace quizGenerator
{
    public partial class MainWindow : Window
    {
        Question initialObject = new Question();
        public MainWindow()
        {
            InitializeComponent();
        }
        private void clearInput()
        {
            questionInput.Text = default;
            answerA_Input.Text = default;
            answerB_Input.Text = default;
            answerC_Input.Text = default;
            answerD_Input.Text = default;
            Answer0.IsChecked = false;
            Answer1.IsChecked = false;
            Answer2.IsChecked = false;
            Answer3.IsChecked = false;
        }
        private bool checkIfNotEmpty()
        {
            return questionInput.Text != "" & answerA_Input.Text != "" & answerB_Input.Text != "" & answerC_Input.Text != "" & answerD_Input.Text != "" & checkChosenTrueAnswer() != -1;
        }
        private int checkChosenTrueAnswer()
        {
            if (Answer0.IsChecked == true)
                return 0;
            else if (Answer1.IsChecked == true)
                return 1;
            else if (Answer2.IsChecked == true)
                return 2;
            else if (Answer3.IsChecked == true)
                return 3;
            else
                return -1;
        }
        private void Add_Click(object sender, RoutedEventArgs e)
        {
            if(checkIfNotEmpty())
            {
                initialObject.questionString = questionInput.Text;
                initialObject.answer_A = answerA_Input.Text;
                initialObject.answer_B = answerB_Input.Text;
                initialObject.answer_C = answerC_Input.Text;
                initialObject.answer_D = answerD_Input.Text;
                initialObject.true_Answer = checkChosenTrueAnswer();
                questionList.Items.Add(initialObject.ToString());
                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupełnij dane!");
            }
        }
        private void Modify_Click(object sender, RoutedEventArgs e)
        {
            if(checkIfNotEmpty())
            {
                initialObject.questionString = questionInput.Text;
                initialObject.answer_A = answerA_Input.Text;
                initialObject.answer_B = answerB_Input.Text;
                initialObject.answer_C = answerC_Input.Text;
                initialObject.answer_D = answerD_Input.Text;
                initialObject.true_Answer = checkChosenTrueAnswer();
                int oldIndex = questionList.SelectedIndex;
                questionList.Items.RemoveAt(questionList.SelectedIndex);
                questionList.Items.Insert(oldIndex, initialObject.ToString());
                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupełnij dane!");
            }
        }
        private void Delete_Click(object sender, RoutedEventArgs e)
        {
            if(checkIfNotEmpty())
            {
                initialObject.questionString = questionInput.Text;
                initialObject.answer_A = answerA_Input.Text;
                initialObject.answer_B = answerB_Input.Text;
                initialObject.answer_C = answerC_Input.Text;
                initialObject.answer_D = answerD_Input.Text;
                initialObject.true_Answer = checkChosenTrueAnswer();
                questionList.Items.RemoveAt(questionList.SelectedIndex);
                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupełnij dane!");
            }
        }
        private void SaveData_Click(object sender, RoutedEventArgs e)
        {
            if(questionList.Items.Count > 0)
            {
                try
                {
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    string filePath = string.Empty;
                    saveFileDialog.DefaultExt = ".xml";
                    saveFileDialog.Filter = "Dokumenty tekstowe XML | *.xml";
                    bool? result = saveFileDialog.ShowDialog();
                    if (result.Equals(true))
                    {
                        filePath = saveFileDialog.FileName;
                    }
                    writeXMLData(filePath);
                }
                catch(Exception)
                {
                    MessageBox.Show("SaveData_Click()");
                }
            }
            
        }
        private bool writeXMLData(string XMLPath)
        {
            try
            {
                string exceptionString = string.Empty;
                FileNotFoundException _exception = new FileNotFoundException(exceptionString);
                XmlTextWriter textWriter = new XmlTextWriter(XMLPath, Encoding.UTF8);
                if (_exception.Message != exceptionString)
                {
                    MessageBox.Show("Nie znaleziono pliku!");
                    return false;
                }
                for (int i = 0; i < questionList.Items.Count; i++)
                {
                    textWriter.WriteValue(CesarCipher.Caesar_coding(questionList.Items[i].ToString() + "\n", initialObject.key));
                }
                textWriter.Close();
            }
            catch (Exception)
            {
                return false;
            }

            return true;
        }
        private void Load_Click(object sender, RoutedEventArgs e)
        {
            if (questionList.Items.Count > 0)
            {
                string msg = "Czy chcesz zapisać obecny quiz?";
                MessageBoxResult dataLoadAlert =
                      MessageBox.Show(
                        msg,
                        "Ostrzeżenie",
                        MessageBoxButton.YesNo,
                        MessageBoxImage.Warning);
                if (dataLoadAlert == MessageBoxResult.Yes)
                {
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    string filePath = string.Empty;
                    saveFileDialog.DefaultExt = ".xml";
                    saveFileDialog.Filter = "Dokumenty tekstowe XML | *.xml";
                    bool? result = saveFileDialog.ShowDialog();
                    if (result.Equals(true))
                    {
                        filePath = saveFileDialog.FileName;
                    }
                    if (writeXMLData(filePath).Equals(false))
                    {
                        MessageBox.Show("Błąd zapisu pliku!");
                    }
                    questionList.Items.Clear();

                    /////
                    OpenFileDialog openFileDialog = new OpenFileDialog();
                    openFileDialog.DefaultExt = ".xml";
                    openFileDialog.Filter = "Dokumenty tekstowe XML | *.xml";

                    result = openFileDialog.ShowDialog();
                    if (result.Equals(true))
                    {
                        filePath = openFileDialog.FileName;
                    }
                    readXMLData(filePath);
                }
                else
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
                    questionList.Items.Clear();
                    readXMLData(filePath);
                }

            }
            else
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
                questionList.Items.Clear();
                readXMLData(filePath);
            }
        }
        private void readXMLData(string XMLPath)
        {
            try
            {
                List<string> loadQuestions = new List<string>(File.ReadAllText(XMLPath).Split("\n"));
                for (int i = 0; i < loadQuestions.Count() - 1; i++)
                {
                    loadQuestions[i] = CesarCipher.Caesar_decoding(loadQuestions[i], initialObject.key);
                    string[] elements = loadQuestions[i].Split(";");
                    initialObject.questionString = elements[0].Trim();
                    initialObject.answer_A = elements[1].Trim();
                    initialObject.answer_B = elements[2].Trim();
                    initialObject.answer_C = elements[3].Trim();
                    initialObject.answer_D = elements[4].Trim();
                    if (elements[5].All(char.IsDigit))
                    {
                        continue;
                    }
                    initialObject.true_Answer = Convert.ToInt32(elements[5].Trim());
                    questionList.Items.Add(initialObject.ToString());
                }
            }
            catch(Exception)
            {
                MessageBox.Show("readXMLData()");
            }
            
        }
        private void listbox_Changed_Index(object sender, RoutedEventArgs e)
        {
            clearInput();
            if(questionList.SelectedItem != null)
            {
                string choosenItem = questionList.SelectedItem.ToString();
                string[] singleItems = choosenItem.Split(";");
                questionInput.Text = singleItems[0].Trim();
                answerA_Input.Text = singleItems[1].Trim();
                answerB_Input.Text = singleItems[2].Trim();
                answerC_Input.Text = singleItems[3].Trim();
                answerD_Input.Text = singleItems[4].Trim();
                if (Convert.ToInt32(singleItems[5]) == 0)
                    Answer0.IsChecked = true;
                else if (Convert.ToInt32(singleItems[5]) == 1)
                    Answer1.IsChecked = true;
                else if (Convert.ToInt32(singleItems[5]) == 2)
                    Answer2.IsChecked = true;
                else if (Convert.ToInt32(singleItems[5]) == 3)
                    Answer3.IsChecked = true;
            }
        }
        private void closingWindowEvent(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if(questionList.Items.Count > 0)
            {
                string msg = "Czy chcesz zapisać dane przed zamknięciem?";
                MessageBoxResult decision =
                      MessageBox.Show(
                        msg,
                        "Ostrzeżenie",
                        MessageBoxButton.YesNo,
                        MessageBoxImage.Warning);
                if (decision == MessageBoxResult.Yes)
                {
                    e.Cancel = false;
                    SaveFileDialog saveFileDialog = new SaveFileDialog();
                    string filePath = string.Empty;
                    saveFileDialog.DefaultExt = ".xml";
                    saveFileDialog.Filter = "Dokumenty tekstowe XML | *.xml";
                    bool? result = saveFileDialog.ShowDialog();
                    if (result.Equals(true))
                    {
                        filePath = saveFileDialog.FileName;
                    }
                    if (writeXMLData(filePath).Equals(false))
                    {
                        MessageBox.Show("Błąd zapisu pliku!");
                    }
                }
            }
        }
    }
}
