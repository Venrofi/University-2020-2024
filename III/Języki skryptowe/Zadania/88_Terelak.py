import random

try:
    ile_kolumn = 0
    ile_wierszy = 0
    while(ile_kolumn <= 0):
        ile_kolumn = int(input("Podaj liczbę kolumn macierzy: "))
    while(ile_wierszy <= 0):
        ile_wierszy = int(input("Podaj liczbę wierszy macierzy: "))

    macierz = [[0 for x in range(ile_kolumn)] for y in range(ile_wierszy)]
    wyswietl_macierz = ""

    for x in range(ile_wierszy):
        for y in range(ile_kolumn):
            macierz[x][y] = random.randint(10,99)
            wyswietl_macierz += str(macierz[x][y]) + " "
        
        wyswietl_macierz = wyswietl_macierz[:-1] + "\n"

    print(wyswietl_macierz)

except ValueError:
    print("Podano nieprawidłowe dane!")