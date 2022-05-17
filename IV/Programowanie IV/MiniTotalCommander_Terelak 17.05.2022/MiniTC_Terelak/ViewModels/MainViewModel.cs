using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using MiniTC_Terelak.Commands;

namespace MiniTC_Terelak.ViewModels
{
    using R = Properties.Resources;
    class MainViewModel : BaseViewModel
    {
        public Panel LeftPanel { get; set; }
        public Panel RightPanel { get; set; }

        public MainViewModel()
        {
            LeftPanel = new Panel();
            RightPanel = new Panel();
        }

        public void Copy(object sender)
        {
            string destination = RightPanel.Path;
            string updateData = destination;

            string[] leftPath = LeftPanel.Path.Split('\\');

            destination += '\\';
            destination += leftPath[leftPath.Length - 1];

            try
            {
                if (File.Exists(RightPanel.Path))
                {
                    RightPanel.RefreshPath(Directory.GetParent(updateData).ToString());
                    return;
                }

                if (!File.Exists(destination) && File.Exists(LeftPanel.Path))
                {
                    File.Copy(LeftPanel.Path, destination);
                    RightPanel.UpdatePathAndContent(new object());
                    RightPanel.RefreshPath(updateData);
                    MessageBox.Show($"{R.Copied} {RightPanel.Path}");
                }
                else
                {
                    MessageBox.Show(R.NotExist);
                }
            }
            catch (UnauthorizedAccessException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        #region Commands
        private ICommand _rightSelectionChanged = null;
        public ICommand RightSelectionChanged
        {
            get
            {
                if (_rightSelectionChanged == null)
                {
                    _rightSelectionChanged = new RelayCommand(RightPanel.UpdatePathAndContent, arg => true);
                }

                return _rightSelectionChanged;
            }
        }

        private ICommand _rightDriverChanged = null;
        public ICommand RightDriverChanged
        {
            get
            {
                if (_rightDriverChanged == null)
                {
                    _rightDriverChanged = new RelayCommand(RightPanel.SetDefaultPath, arg => true);
                }
                return _rightDriverChanged;
            }
        }


        private ICommand leftDriverChanged = null;
        public ICommand LeftDriverChanged
        {
            get
            {
                if (leftDriverChanged == null)
                {
                    leftDriverChanged = new RelayCommand(LeftPanel.SetDefaultPath, arg => true);
                }
                return leftDriverChanged;
            }
        }

        private ICommand leftSelectionChanged = null;
        public ICommand LeftSelectionChanged
        {
            get
            {
                if (leftSelectionChanged == null)
                {
                    leftSelectionChanged = new RelayCommand(LeftPanel.UpdatePathAndContent, arg => true);
                }
                return leftSelectionChanged;
            }
        }

        private ICommand copyClick = null;
        public ICommand CopyClick
        {
            get
            {
                if (copyClick == null)
                {
                    copyClick = new RelayCommand(Copy, 
                        arg => File.Exists(LeftPanel.Path) && Directory.Exists(RightPanel.Path));
                }
                return copyClick;
            }
        }

        #endregion
    }
}
