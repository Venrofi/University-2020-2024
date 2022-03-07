def pobierzLiczbe():
    liczba = input("Podaj liczbę: ")
    try:
        liczba = int(liczba)
        print("Podano liczbę całkowitą:", liczba, ":)")
    except ValueError:
        try:
            liczba = float(liczba)
            print("Podano liczbę rzeczywistą:", liczba, ":)")
        except ValueError:
            print("Nie podano liczby!")

pobierzLiczbe()