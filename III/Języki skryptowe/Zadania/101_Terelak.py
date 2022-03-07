try:
    liczba = int(input("Podaj liczbę: "))
    wynik = 1
    for i in range(1, abs(liczba)+1):
        wynik *= i
    if(liczba < 0):
        print("Silnia liczby", liczba, "wynosi:", -wynik)
    else:
        print("Silnia liczby", liczba, "wynosi:", wynik)

except ValueError:
    print("Nie podano liczby!")
