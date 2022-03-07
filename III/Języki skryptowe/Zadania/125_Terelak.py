def rzymNaInt(liczba_rzym):
    liczba_rzym = liczba_rzym.upper()
    wynik = 0

    for znak in liczba_rzym:
        if(znak == "M"):
            wynik += 1000
        if(znak == "D"):
            wynik += 500
        if(znak == "C"):
            wynik += 100
        if(znak == "L"):
            wynik += 50
        if(znak == "X"):
            wynik += 10
        if(znak == "V"):
            wynik += 5
        if(znak == "I"):
            wynik += 1    
    return wynik

dozwolone = "MDCLXVImdclxvi"
liczba = input("Podaj liczbę w postaci rzymskiej: ")

if(all(znak in dozwolone for znak in liczba)):
    print("Liczba {} w systemie dziesiętnym:".format(liczba), rzymNaInt(liczba))
else:
    print("Podanej liczby nie można zamienić na postać dziesiętną!")