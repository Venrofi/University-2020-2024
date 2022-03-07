def pobierzLiczbe():
    try:
        liczba = int(input("Podaj liczbę całkowitą: "))
        print("Podano:", liczba, ":)")

    except ValueError:
        print("Nie podano liczby całkowitej!")

pobierzLiczbe()