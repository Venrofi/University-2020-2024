try:
    liczba_a = int(input("Podaj część rzeczywistą liczby: "))
    liczba_b = int(input("Podaj część urojoną liczby: "))

    print("\nModuł liczby {0}+{1}j:".format(liczba_a, liczba_b), abs(complex(liczba_a,liczba_b)))

except ValueError:
    print("Nie podano liczby!")