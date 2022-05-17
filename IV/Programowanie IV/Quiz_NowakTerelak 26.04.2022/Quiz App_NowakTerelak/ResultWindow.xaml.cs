using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;

namespace Quiz_App_NowakTerelak
{
    /// <summary>
    /// Interaction logic for ResultWindow.xaml
    /// </summary>
    public partial class ResultWindow : Window
    {
        public ResultWindow()
        {
            InitializeComponent();
            checkResult();

            int maks_liczba_pkt = GLOBAL.LIST_of_questions.Count() - 1;
            Wynik.Content = "Twój wynik to: " + GLOBAL.pointCount.ToString() + " / " + maks_liczba_pkt.ToString();
            Czas.Content = "Czas: " + GLOBAL.time;
        }
        private int checkResult()   //funkcja liczaca punkty z quizu
        {
            for (int i = 0; i < GLOBAL.LIST_of_answer.Count(); i++)
            {
                string[] elements = GLOBAL.LIST_of_questions[i].Split(';');

                if (Int32.Parse(elements[5]) == GLOBAL.LIST_of_answer[i])
                {
                    GLOBAL.pointCount++;
                }
            }
            return GLOBAL.pointCount;
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            for (int i = 0; i < GLOBAL.LIST_of_questions.Count() - 1; i++)
            {
                questionList.Items.Add(GLOBAL.LIST_of_questions[i]);
            }
        }
        private void listbox_Changed_Index(object sender, RoutedEventArgs e)
        {
            if (questionList.SelectedItem != null)
            {
                string choosenItem = questionList.SelectedItem.ToString();
                string[] singleItems = choosenItem.Split(';');
                questionInput.Text = singleItems[0].Trim();
                answerA_Input.Text = singleItems[1].Trim();
                answerB_Input.Text = singleItems[2].Trim();
                answerC_Input.Text = singleItems[3].Trim();
                answerD_Input.Text = singleItems[4].Trim();
                
                // RESETY
                answerA_Input.Background = Brushes.White;
                answerB_Input.Background = Brushes.White;
                answerC_Input.Background = Brushes.White;
                answerD_Input.Background = Brushes.White;

                answerA_Input.Foreground = Brushes.Black;
                answerB_Input.Foreground = Brushes.Black;
                answerC_Input.Foreground = Brushes.Black;
                answerD_Input.Foreground = Brushes.Black;

                answerA_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Normal);
                answerB_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Normal);
                answerC_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Normal);
                answerD_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Normal);

                if (questionList.SelectedIndex < GLOBAL.LIST_of_answer.Count() && Convert.ToInt32(singleItems[5]) != GLOBAL.LIST_of_answer[questionList.SelectedIndex]) // Jeśli odp użytkownika była błędna
                {
                    switch (GLOBAL.LIST_of_answer[questionList.SelectedIndex]) {
                        case 0:
                            answerA_Input.Background = Brushes.Red;
                            answerA_Input.Foreground = Brushes.White;
                            answerA_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            break;
                        case 1:
                            answerB_Input.Background = Brushes.Red;
                            answerB_Input.Foreground = Brushes.White;
                            answerB_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            break;
                        case 2:
                            answerC_Input.Background = Brushes.Red;
                            answerC_Input.Foreground = Brushes.White;
                            answerC_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            break;
                        case 3:
                            answerD_Input.Background = Brushes.Red;
                            answerD_Input.Foreground = Brushes.White;
                            answerD_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            break;
                        default:
                            MessageBox.Show("Nie udało się ustalić odpowiedzi!");
                            break;
                    }
                }

                if(questionList.SelectedIndex < GLOBAL.LIST_of_answer.Count())
                {
                    switch (Convert.ToInt32(singleItems[5])) // ustawienie poprawnej odpowiedzi
                    {
                        case 0:
                            Answer0.IsChecked = true;
                            if (Convert.ToInt32(singleItems[5]) == GLOBAL.LIST_of_answer[questionList.SelectedIndex]) // Jeśli odp użytkownika jest poprawna ustaw kolor zielony
                            {
                                answerA_Input.Background = Brushes.Green;
                                answerA_Input.Foreground = Brushes.White;
                                answerA_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            }
                            break;
                        case 1:
                            Answer1.IsChecked = true;
                            if (Convert.ToInt32(singleItems[5]) == GLOBAL.LIST_of_answer[questionList.SelectedIndex])
                            {
                                answerB_Input.Background = Brushes.Green;
                                answerB_Input.Foreground = Brushes.White;
                                answerB_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            }
                            break;
                        case 2:
                            Answer2.IsChecked = true;
                            if (Convert.ToInt32(singleItems[5]) == GLOBAL.LIST_of_answer[questionList.SelectedIndex])
                            {
                                answerC_Input.Background = Brushes.Green;
                                answerC_Input.Foreground = Brushes.White;
                                answerC_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            }
                            break;
                        case 3:
                            Answer3.IsChecked = true;
                            if (Convert.ToInt32(singleItems[5]) == GLOBAL.LIST_of_answer[questionList.SelectedIndex])
                            {
                                answerD_Input.Background = Brushes.Green;
                                answerD_Input.Foreground = Brushes.White;
                                answerD_Input.SetValue(TextBlock.FontWeightProperty, FontWeights.Bold);
                            }
                            break;
                        default:
                            MessageBox.Show("Nie udało się ustalić poprawnej odpowiedzi!");
                            break;
                    }
                }
                else
                {
                    switch (Convert.ToInt32(singleItems[5])) // ustawienie poprawnej odpowiedzi
                    {
                        case 0:
                            Answer0.IsChecked = true;
                            break;
                        case 1:
                            Answer1.IsChecked = true;
                            break;
                        case 2:
                            Answer2.IsChecked = true;
                            break;
                        case 3:
                            Answer3.IsChecked = true;
                            break;

                        default:
                            MessageBox.Show("Nie udało się ustalić poprawnej odpowiedzi!");
                            break;
                    }
                }
            }
        }
    }
}
