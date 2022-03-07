import math

try:
    liczby = []
    with open("82.txt", "r") as plik:
        for wiersz in plik:
            try:
                liczby.append(int(wiersz))
            except ValueError:
                print(wiersz,"- to nie jest liczba!")

    ile_liczb = len(liczby)
    if ile_liczb == 0:
        exit()
    
    print("Odczytane liczby:", liczby)

    suma = 0
    srednia = 0
    mediana = 0

    for item in liczby:
        suma += item
        srednia += item

    srednia /= ile_liczb

    liczby.sort(key=int)

    if(ile_liczb % 2 == 0):
        mediana = (liczby[math.floor(ile_liczb/2) - 1] + liczby[math.floor(ile_liczb/2)]) / 2
    else:
        mediana = liczby[math.floor(ile_liczb/2)]

    print("Suma:", suma)
    print("Średnia: ", srednia)
    print("Mediana: ", mediana)

except IOError:
    print("Plik nie istnieje!")