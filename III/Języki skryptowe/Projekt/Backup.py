from datetime import datetime
import os, glob

czas = datetime.now()
nazwa_pliku = "raport_" + czas.strftime("%d-%m-%Y_%H;%M;%S") + ".html"
data_godzina = czas.strftime("%d/%m/%Y %H:%M:%S")

folder_dane = "IN"
folder_wynik = "OUT"
folder_backup = "BACKUP"

wyniki = ["-"] * 10

html_start = f'''
<html>
    <head>
        <title>Raport {data_godzina}</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Oswald:wght@200;400;600&display=swap" rel="stylesheet">
        <link rel="stylesheet" href="style.css">
    </head>
    <body>
        <h1>Algorytmion 2011 - "Monety" Radosław Terelak 4G</h1>
        <h1>Raport {data_godzina}</h1>
        <table>
            <tr>
                <th>Nr pliku</th>
                <th>Dane wejściowe</th>
                <th>Wynik</th>
            </tr>
'''

html_end = f'''
        </table>
    </body>
</html>
'''

html = html_start

os.chdir(".\\" + folder_wynik)
for plik in glob.glob("wynik_?.txt"):
    with open(plik, 'r', encoding="utf-8", errors='ignore') as f:
        wyniki[int(plik[6:7])] = f.readline()

os.chdir("..\\" + folder_dane)
for plik in glob.glob("dane_?.txt"):
    nr_pliku = plik[5:6]
    wynik = wyniki[int(nr_pliku)]
    with open(plik, 'r', encoding="utf-8", errors='ignore') as f:
        ile_workow = f.readline().strip()
        liczba_wyciagnietych_monet = f.readline().strip()
        waga_monet = f.readline().strip()
        linia_4 = f.readline().strip()

    kontent = f'''
            <tr>
                <td>{nr_pliku}</td>
                <td>
                    {ile_workow}<br>
                    {liczba_wyciagnietych_monet}<br>
                    {waga_monet}<br>
                    {linia_4} 
                </td>
                <td>{wynik}</td>
            </tr>
    '''
    html += kontent

html += html_end
os.chdir("..\\" + folder_backup)
with open(nazwa_pliku, 'w', encoding="utf-8") as plik:
    try:
        plik.write(html)
        print("{} został pomyślnie utworzony :)".format(nazwa_pliku))
    except:
        print("Nie udało się utworzyć raportu :(")