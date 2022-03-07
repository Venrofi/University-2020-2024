from collections import Counter

try:
    with open("95.txt", "r") as plik:
        tekst = plik.read()
    print(tekst + "\n")
    tekst = tekst.lower().split()
    liczba_poszczegolnych_znakow = Counter(tekst)
    liczba_poszczegolnych_znakow = liczba_poszczegolnych_znakow.items()
    for litery in liczba_poszczegolnych_znakow:
        print(litery[0] + " : " + str(litery[1]))

except IOError:
    print("W pliku nie znaleziono liczby!")