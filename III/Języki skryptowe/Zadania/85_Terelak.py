import random

try:
    od = int(input("Podaj początek przedziału: "))
    do = int(input("Podaj koniec przedziału: "))
    liczba = random.randint(od, do)

    try:
        elementy = []
        with open("85.txt", "r") as plik:
            for wiersz in plik:
                try:
                    elementy.append(int(wiersz))
                except:
                    print("Istnieje element w pliku, który nie jest liczbą!")
        element = elementy[random.randint(0, len(elementy))]
        print("Wylosowano:", liczba,"oraz", element)

        try:
            with open("wynikzadanie85.txt", "w") as plik:
                plik.write(str(liczba))
                plik.write(str(element))
            print("Pomyślnie zapisano wynik do pliku :)")
        except IOError:
            print("Nie udało się zapisać do pliku :(")    
    
    except IOError:
        print("Plik nie istnieje!")
        print("Wylosowano:", liczba)
        try:
            with open("wynikzadanie85.txt", "w") as plik:
                plik.write(str(liczba))
            print("Pomyślnie zapisano wynik do pliku :)")
        except IOError:
            print("Nie udało się zapisać do pliku :(") 

except ValueError:
    print("Podano nieprawidłowe dane!")