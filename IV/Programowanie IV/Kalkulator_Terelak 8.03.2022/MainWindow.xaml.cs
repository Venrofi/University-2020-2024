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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Kalkulator_Terelak_8._03._2022
{
    public partial class MainWindow : Window
    {
        private double number1 = 0;
        private double number2 = 0;
        private double UPPER_BOUNDRY = Math.Pow(10, 14);
        private bool divide_zero = false;
        string operation = "";
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Number_Click(object sender, RoutedEventArgs e)
        {
            Button przycisk = sender as Button;
            string cyfra = przycisk.Content.ToString();

            if (cyfra == "0" || cyfra == "1" || cyfra == "2" || cyfra == "3" || cyfra == "4" || cyfra == "5" || cyfra == "6" || cyfra == "7" || cyfra == "8" || cyfra == "9")
            {
                if (this.display.Text == "" || this.display.Text == "0")
                {
                    this.display.Text = cyfra;
                }
                else
                {
                    if(divide_zero == false)
                    {
                        this.display.Text += cyfra;
                    }
                }
            }
        }

        private void Minus_Click(object sender, RoutedEventArgs e)
        {
            if(this.display.Text == "")
            {
                this.display.Text = "-";
            }
            else
            {
                if(divide_zero == false)
                {
                    number1 = double.Parse(this.display.Text);
                    operation = "-";
                    this.display.Text = "";
                }
            }
        }

        private void Plus_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "" && divide_zero == false)
            {
                number1 = double.Parse(this.display.Text);
                operation = "+";
                this.display.Text = "";
            }
                
        }

        private void Divide_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "" && divide_zero == false)
            {
                number1 = double.Parse(this.display.Text);
                operation = "/";
                this.display.Text = "";
            }       
        }

        private void Multiply_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "" && divide_zero == false) 
            {
                number1 = double.Parse(this.display.Text);
                operation = "*";
                this.display.Text = "";
            }
        }

        private void Wynik_Click(object sender, RoutedEventArgs e)
        {
            double wynik = 0;

            if(operation != "" && this.display.Text != "" && divide_zero == false)
            {
                number2 = double.Parse(this.display.Text);

                switch (operation)
                {
                    case "+":
                        wynik = number1 + number2;
                        this.display.Text = wynik.ToString();
                        number1 = wynik;
                        number2 = 0;
                        operation = "";
                        break;
                    case "-":
                        wynik = number1 - number2;
                        this.display.Text = wynik.ToString();
                        number1 = wynik;
                        number2 = 0;
                        operation = "";
                        break;
                    case "/":
                        if(decimal.Parse(this.display.Text) != 0)
                        {
                            wynik = number1 / number2;
                            this.display.Text = wynik.ToString();
                        }
                        else
                        {
                            this.display.Text = "Nie dziel przez 0!";
                            divide_zero = true;
                        }
                        number1 = wynik;
                        number2 = 0;
                        operation = "";
                        break;
                    case "*":
                        wynik = number1 * number2;
                        this.display.Text = wynik.ToString();
                        number1 = wynik;
                        number2 = 0;
                        operation = "";
                        break;
                }
            }
        }

        private void Clear_Click(object sender, RoutedEventArgs e)
        {
            number1 = 0;
            number2 = 0;
            operation = "";
            this.display.Text = "";
            divide_zero = false;
        }
        private void Backspace_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "")
            {
                this.display.Text = this.display.Text.Substring(0, this.display.Text.Length - 1);
            }
            else
            {
                divide_zero = false;
            }
        }

        private void Inverse_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text.StartsWith("-")) // If Negative
            {
                this.display.Text = this.display.Text.Substring(1);
            }
            else if (!string.IsNullOrEmpty(this.display.Text) && divide_zero == false && decimal.Parse(this.display.Text) != 0) // If positive and not a zero
            {
                this.display.Text = "-" + this.display.Text;
            }
        }

        private void Power_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "" && divide_zero == false)
            {
                double power = double.Parse(this.display.Text);
                power *= power;
                this.display.Text = power.ToString();
            }
        }

        private void Fraction_Click(object sender, RoutedEventArgs e)
        {
            if (this.display.Text != "" && divide_zero == false)
            {
                if(double.Parse(this.display.Text) > UPPER_BOUNDRY)
                {
                    this.display.Text = "Wynik poza zakresem!";
                }
                else if(decimal.Parse(this.display.Text) != 0)
                {
                    double fraction = 1 / double.Parse(this.display.Text);
                    this.display.Text = fraction.ToString();
                }
                else
                {
                    this.display.Text = "Nie dziel przez 0!";
                    divide_zero = true;
                }
            }
        }

        private void Comma_Click(object sender, RoutedEventArgs e)
        {
            if (!this.display.Text.Contains(",") && divide_zero == false)
            {
                this.display.Text += ",";
            }
        }
    }
}