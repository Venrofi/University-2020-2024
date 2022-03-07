from collections import Counter

try:
    with open("95.txt", "r") as plik:
        tekst = plik.read()
    print(tekst + "\n")
    tekst = tekst.upper()
    
    with open("wynik96.txt", "w") as plik:
        plik.write(tekst)
        print("Pomyślnie zapisano tekst do pliku wynikowego!")

except IOError:
    print("W pliku nie znaleziono liczby!")