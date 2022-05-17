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

namespace Formularz_Dodawania_Kierowcy
{
    public partial class MainWindow : Window
    {
        readonly Driver initDriver = new Driver();
        public MainWindow()
        {
            TextBoxWithErrorProvider.BrushForAll = Brushes.Green;
            InitializeComponent();
            readXMLData();
        }
        private bool writeXMLData()
        {
            try
            {
                string exceptionString = string.Empty;
                System.IO.FileNotFoundException _exception = new FileNotFoundException(exceptionString);
                string XMLPath = Directory.GetCurrentDirectory() + @"\data.xml";
                XmlTextWriter textWriter = new XmlTextWriter(XMLPath, Encoding.UTF8);
                if (_exception.Message != exceptionString)
                {
                    MessageBox.Show("Nie znaleziono pliku!");
                    return false;
                }
                for (int i = 0; i < DriversList.Items.Count; i++)
                {
                    textWriter.WriteValue(DriversList.Items[i].ToString() + "\n");
                }
                textWriter.Close();
            }
            catch (Exception e)
            {
                MessageBox.Show("Blad z zapisem XML!" + e);
                return false;
            }

            return true;
        }
        private void readXMLData()
        {
            try
            {
                string XMLPath = Directory.GetCurrentDirectory() + @"\data.xml";
                List<string> loadPlayers = new List<string>(File.ReadAllText(XMLPath).Split('\n'));
                for (int i = 0; i < loadPlayers.Count() - 1; i++)
                {
                    DriversList.Items.Add(loadPlayers[i]);
                }
            }
            catch (Exception e)
            {
                MessageBox.Show("Blad odczytu pliku XML!" + e);
            }
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            string msg = "Czy na pewno chcesz zamknac aplikacje?";
            MessageBoxResult result =
                  MessageBox.Show(
                    msg,
                    "Wyjscie",
                    MessageBoxButton.YesNo,
                    MessageBoxImage.Warning);
            if (result == MessageBoxResult.No)
            {
                // If user doesn't want to close, cancel closure
                e.Cancel = true;
            }
            else
            {
                if (writeXMLData().Equals(false))
                {
                    MessageBox.Show("Blad zapisu!");
                }
            }
        }
        private void listBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (DriversList.SelectedItem != null)
            {
                string choosenIndex = DriversList.SelectedItem.ToString();
                string[] singleItems = choosenIndex.Split(',');
                firstNameInput.Text = singleItems[0].Trim();
                lastNameInput.Text = singleItems[1].Trim();

                singleItems[2] = singleItems[2].Remove(singleItems[2].Length - 3);
                ageInput.SelectedIndex = Convert.ToInt32(singleItems[2]) - 18;

                singleItems[3] = singleItems[3].Remove(singleItems[3].Length - 2);
                weightSlider.Value = Convert.ToInt32(singleItems[3]);
            }
        }

        private bool checkIfClear()
        {
            return firstNameInput.Text != "" && lastNameInput.Text != "" && ageInput.Text != "";
        }
        private void clearInput()
        {
            firstNameInput.Text = default;
            lastNameInput.Text = default;
            ageInput.Text = default;
            weightSlider.Value = default;
        }
        private void Button_Add(object sender, RoutedEventArgs e)
        {
            if (checkIfClear())
            {
                initDriver.firstName = firstNameInput.Text;
                initDriver.lastName = lastNameInput.Text;
                initDriver.age = Convert.ToInt32(ageInput.Text);
                initDriver.weight = Convert.ToInt32(weightSlider.Value);

                DriversList.Items.Add(initDriver.ToString());

                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupełnij dane!");
            }
        }
        private void Button_Modify(object sender, RoutedEventArgs e)
        {
            if (checkIfClear())
            {
                initDriver.firstName = firstNameInput.Text;
                initDriver.lastName = lastNameInput.Text;
                initDriver.age = Convert.ToInt32(ageInput.Text);
                initDriver.weight = Convert.ToInt32(weightSlider.Value);

                int oldIndex = DriversList.SelectedIndex;
                DriversList.Items.RemoveAt(DriversList.SelectedIndex);
                DriversList.Items.Insert(oldIndex, initDriver.ToString());
                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupelnij formularz!");
            }
        }
        private void Button_Delete(object sender, RoutedEventArgs e)
        {
            if (checkIfClear())
            {
                initDriver.firstName = firstNameInput.Text;
                initDriver.lastName = lastNameInput.Text;
                initDriver.age = Convert.ToInt32(ageInput.Text);
                initDriver.weight = Convert.ToInt32(weightSlider.Value);
                DriversList.Items.RemoveAt(DriversList.SelectedIndex);
                clearInput();
            }
            else
            {
                MessageBox.Show("Uzupelnij formularz!");
            }
        }
    }
}
