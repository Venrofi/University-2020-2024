try:
    od = int(input("Podaj początek zakresu: "))
    do = int(input("Podaj koniec zakresu: "))

    print("Lata przestępne w okresie {0} - {1}".format(od, do))
    wynik = ""
    for rok in range(od, do + 1):
        if(rok % 4 == 0 and rok % 100 != 0):
            wynik += str(rok) + ", "
        elif(rok % 400 == 0):
            wynik += str(rok) + ", "
    print(wynik)

except ValueError:
    print("Nie podano liczby!")