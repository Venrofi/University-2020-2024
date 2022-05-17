using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MiniTC_Terelak.ViewModels
{
    class Panel : BaseViewModel
    {
        private string path;
        private string driveSelected;
        private string listSelected;
        private ObservableCollection<string> contentCollection;

        public Panel()
        {
            DriveArray = Directory.GetLogicalDrives();
            DriveSelected = DriveArray[0];

            Path = DriveSelected;
            ContentCollection = LoadContentCollection(DriveSelected);
        }

        #region Get/Set
        public string Path
        {
            get
            {
                return path;
            }
            set
            {
                path = value; OnPropertyChanged(nameof(Path));
            }
        }

        public string DriveSelected
        {
            get
            {
                return driveSelected;
            }
            set
            {
                driveSelected = value; OnPropertyChanged(nameof(DriveSelected));
            }
        }

        public string ListSelected
        {
            get
            {
                return listSelected;
            }
            set
            {
                listSelected = value; OnPropertyChanged(nameof(ListSelected));
            }
        }

        public string[] DriveArray { get; set; }
        public ObservableCollection<string> ContentCollection
        {
            get => contentCollection;
            set
            {
                contentCollection = value; OnPropertyChanged(nameof(ContentCollection));
            }
        }
        #endregion

        public ObservableCollection<string> LoadContentCollection(string path)
        {
            try
            {
                ObservableCollection<string> listOfElements = new ObservableCollection<string>();
                string[] directories = Directory.GetDirectories(path);
                string[] files = Directory.GetFiles(path);
                string relativePath = string.Empty;
                if (!DriveArray.Contains(path))
                {
                    listOfElements.Add("..");
                }
                for (int i = 0; i < directories.Length; i++)
                {
                    if (directories[i].Contains(path))
                    {
                        relativePath = directories[i].Replace(path, "");
                        if (relativePath.ElementAt(0).Equals(Convert.ToChar("\\")))
                        {
                            relativePath = relativePath.Substring(1);
                        }
                    }
                    listOfElements.Add("<D>" + relativePath);
                }
                for (int i = 0; i < files.Length; i++)
                {
                    if (files[i].Contains(path))
                    {
                        relativePath = files[i].Replace(path, "");
                        if (relativePath.ElementAt(0).Equals(Convert.ToChar("\\")))
                        {
                            relativePath = relativePath.Substring(1);
                        }
                    }
                    listOfElements.Add(relativePath);
                }
                return listOfElements;
            }
            catch (UnauthorizedAccessException)
            {
                SetDefaultPath(new object());
                return ContentCollection;
            }
        }

        public void SetDefaultPath(object sender)
        {
            Path = DriveSelected;
            ContentCollection = LoadContentCollection(DriveSelected);
        }
        public void RefreshPath(string path)
        {
            this.path = path;
            ContentCollection = LoadContentCollection(path);
        }

        public void UpdatePathAndContent(object sender)
        {
            FileAttributes temp = File.GetAttributes(path);
            DirectoryInfo parent = Directory.GetParent(path);
            string fillPath = string.Empty;
            if (fillPath == string.Empty)
            {
                fillPath += path;
                if (File.Exists(fillPath))  // sprawdzanie czy plik jest zaznaczony -> zeby uniknac nadpisania sciezki 
                {
                    fillPath = parent.FullName;
                }
            }

            if (listSelected != null)
            {
                if (listSelected == "..")
                {
                    if (temp.HasFlag(FileAttributes.Directory))
                    {
                        path = parent.FullName;
                        ContentCollection = LoadContentCollection(path);
                    }
                    else
                    {
                        parent = Directory.GetParent(parent.FullName);
                        path = parent.FullName;
                        ContentCollection = LoadContentCollection(path);
                    }
                    listSelected = null;
                }
                else if (listSelected[0] == '<')
                {
                    string slash = "\\";
                    if (fillPath != (path[0] + ":\\"))
                    {
                        listSelected = listSelected.Substring(3);
                        fillPath += slash + listSelected;
                    }
                    else
                    {
                        listSelected = listSelected.Substring(3);
                        fillPath += listSelected;
                    }
                    path = fillPath;
                    ContentCollection = LoadContentCollection(fillPath);
                }
                else
                {
                    if (fillPath != (path[0] + ":\\"))
                    {
                        fillPath += "\\" + listSelected;
                    }
                    else
                    {
                        fillPath += listSelected;
                    }
                    path = fillPath;
                }
            }
        }
    }
}
