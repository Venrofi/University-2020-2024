   M S B A M L   `   `   `  ����I  EMiniTC_Terelak, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null;"clr-namespace:MiniTC_Terelak.ViewsMiniTC_Terelak.Views  5      "    MiniTC_Terelak.Views.PanelTC   5      R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      4local"clr-namespace:MiniTC_Terelak.Views     5      .��5	      �   � RowDefinitions  5
   
   �� 5      $��* �6   �� 5      $��* �6   �� 5      $��8* �6   .+�5   
   �� $��0��6    �� Orientation$ 
Horizontal=�6"   $��Right=�6;   $
��13 0q�6W   .+�5      �� $��Path:��6   $��Center=�6%   $��Right=�6@   $
��20 0q�6\   �� 5      -   5         ��Name$ textBox��5      $��25��6A   $	��250��6M    �� 
IsReadOnly . {�.  ��5      ��  �� Path$
 Text� �� Mode$ TwoWay=� �� UpdateSourceTrigger$ PropertyChanged=� �� RelativeSource ��  �� Mode$ FindAncestor=�	 �� AncestorType"	 >�5      �� 5   
   $��1��6   $ 
Horizontal=�6"   $��Right=�6;   $
��13 0q�6W   .+�5!      �� $��Drive:��6   $��Center=�6&   $��Right=�6A   $
��20 0q�6]   �� 5"      -   5        
 ��Name$
 comboBox��5"      $��25��6C   $	��100��6O   ��5$      �� $ CbItemsSource�$ TwoWay=�$ PropertyChanged=� �� $ FindAncestor=�"	 >� �� SelectedItem 5+      �� $ CbSelectedItem�$ TwoWay=�$ PropertyChanged=� �� $ FindAncestor=�"	 >�52      �� 55   
   -   5         ��Name$ listBox��55      $��2��6#   $��12(�60   $��	10,5,10,5q�6X   ��57      �� $ LsItemsSource�$ TwoWay=�$ PropertyChanged=� �� $ FindAncestor=�"	 >� 5>      �� $ LsSelectedItem�$ TwoWay=�$ PropertyChanged=� �� $ FindAncestor=�"	 >�5E      5F      