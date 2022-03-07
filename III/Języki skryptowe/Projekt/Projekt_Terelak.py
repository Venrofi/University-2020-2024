# Języki Skryptowe - Projekt zaliczeniowy Radosław Terelak 4G
# Algorytmion - 2011 - Zadanie 1 "Monety"

import os, glob

folder_dane = "IN"
folder_wynik = "OUT"

def wczytajDane(nazwa_pliku): # Wczytaj dane z pliku wejściowego i sprawdź ich poprawność
    with open(nazwa_pliku, "r") as plik:
        try:
            numer_pliku = nazwa_pliku[5:6]
            ile_workow = int(plik.readline())
            monety = plik.readline().split(";")
            waga = int(plik.readline())

            if(len(monety) != ile_workow):
                raise ValueError
            sprawdzDane(ile_workow, monety, waga, numer_pliku)
        except ValueError:
            print("Podano złe dane!\n")

def sprawdzDane(ile_workow, monety, waga, numer_pliku): # Przeanalizuj dane, znajdź fałszywy worek
    suma_wag = 0
    znaleziono = False
    try:
        for i in range(ile_workow):
            if int(monety[i]) <= 0:
                raise ValueError
            suma_wag += int(monety[i]) * 3
    
        if(suma_wag == waga):
            print("Nie ma worka z fałszywymi monetami!")
            return zapiszWynik("Nie ma worka z fałszywymi monetami!", numer_pliku)

        for i in range(ile_workow):
            waga_falsz = int(monety[i]) * 2
            waga_pozostale = 0
            nr_worka = i + 1

            for j in range(ile_workow):
                if(j != i):
                    waga_pozostale += int(monety[j]) * 3

            if(waga_falsz + waga_pozostale == waga):
                znaleziono = True
                print("Fałszywym jest worek o numerze {}!".format(nr_worka))
                return zapiszWynik("Fałszywym jest worek o numerze: " + str(nr_worka), numer_pliku)

        if znaleziono == False:
            print("Dokonaj wyciągnięcia monet jeszcze raz!\n")
    except ValueError:
        print("Podano nieprawidłowe dane!\n")

def zapiszWynik(komunikat, numer_pliku): # Zapis wyników do odpowiednich plików w folderze wynikowym
    plik_wynikowy = "\wynik_" + numer_pliku + ".txt"
    with open("..\\" + folder_wynik + plik_wynikowy, "w") as plik:
        try:
            plik.write(komunikat)
            print("Pomyślnie zapisano wynik do pliku! :)\n")
        except:
            print("Nie udało się zapisać wyniku do pliku :(\n")

def START(): # Tworzenie folderu wynikowego oraz szukanie plików z danymi
    if os.path.exists(folder_dane):
        if not os.path.exists(folder_wynik):
            os.mkdir(folder_wynik)

        os.chdir(".\\" + folder_dane)
        for plik in glob.glob("dane_?.txt"):
            print(plik)
            wczytajDane(plik)
    else:
        print("Folder z danymi nie istnieje!")

START()