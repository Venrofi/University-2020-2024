def silnia(n):
    if abs(n) == 1:
        return n
    return n * silnia(abs(n) - 1)

try:
    liczba = int(input("Podaj liczbę: "))
    print("Silnia liczby", liczba, "wynosi:", silnia(liczba))

except ValueError:
    print("Nie podano liczby!")