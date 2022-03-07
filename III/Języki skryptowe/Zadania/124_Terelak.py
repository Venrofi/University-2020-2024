def intNaRzym(liczba):
    rzym = []
    while liczba >= 1000:
        rzym.append("M")
        liczba -= 1000
    while liczba >= 500:
        rzym.append("D")
        liczba -= 500
    while liczba >= 100:
        rzym.append("C")
        liczba -= 100
    while liczba >= 50:
        rzym.append("L")
        liczba -= 50
    while liczba >= 10:
        rzym.append("X")
        liczba -= 10
    while liczba >= 5:
        rzym.append("V")
        liczba -= 5
    while liczba >= 1:
        rzym.append("I")
        liczba -= 1

    wynik = "".join(rzym)
    return wynik

try:
    liczba = int(input("Podaj liczbę całkowitą: "))
    if(liczba > 0 and liczba < 4000):
        print("Liczba {} w systemie rzymskim:".format(liczba), intNaRzym(liczba))
    else:
        print("Podanej liczby nie można zamienić na postać rzymską!")
except ValueError:
    print("To nie jest liczba!")