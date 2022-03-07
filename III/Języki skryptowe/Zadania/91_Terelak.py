try:
    with open("91.txt", "r") as plik:
        liczba = int(plik.readline())

    print("Liczba", liczba, "w postaci szestnastkowej:", hex(liczba), "oraz ósemkowej:", oct(liczba))

    with open("wyjsciezadanie91.txt", "w") as plik:
        plik.write("Liczba " + str(liczba) + " w postaci szestnastkowej: " + str(hex(liczba)))
        plik.write("\nLiczba " + str(liczba) + " w postaci ósemkowej: " +  str(oct(liczba)))
        print("Pomyślnie zapisano liczby do pliku wynikowego!")
except IOError:
    print("W pliku nie znaleziono liczby!")