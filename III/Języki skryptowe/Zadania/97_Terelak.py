try:
    podstawa = int(input("Podaj liczbę: "))

    print("Licznik     Suma")
    print("**0**       **0**")
    print("-----       -----")
    for i in range(1, 11):
        print(str(i).center(5, "*") + "   |   " + str(i*podstawa).center(5, "*"))

except ValueError:
    print("Nie podano liczby!")