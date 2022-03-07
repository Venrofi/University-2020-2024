import math

liczby = []
liczba = input("Podaj liczbę: ")
ile_liczb = 0
try:
    liczby.append(int(liczba))
    ile_liczb += 1
except ValueError:
    print("To nie jest liczba!")
    liczba = ""

while(liczba != "exit" and liczba != "EXIT"):
    try:
        liczba = input("Podaj kolejną liczbę (wpisz 'exit' by zakończyć): ")
        if(liczba != "exit" and liczba != "EXIT"):
            liczby.append(int(liczba))
            ile_liczb += 1
    except ValueError:
        print("To nie jest liczba!")

suma = 0
srednia = 0
mediana = 0

if liczby:
    for item in liczby:
        suma += item
        srednia += item

    srednia /= ile_liczb

    liczby.sort()

    if(ile_liczb % 2 == 0):
        mediana = (liczby[math.floor(ile_liczb/2) - 1] + liczby[math.floor(ile_liczb/2)]) / 2
    else:
        mediana = liczby[math.floor(ile_liczb/2)]

    print("Suma:", suma)
    print("Średnia: ", srednia)
    print("Mediana: ", mediana)