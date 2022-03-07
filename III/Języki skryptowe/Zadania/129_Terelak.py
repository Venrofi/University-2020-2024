def modulLiczby(liczba = int):
    if(liczba >= 0):
        return liczba
    if(liczba < 0):
        return -liczba

print("Moduł liczby 5:", modulLiczby(5))
print("Moduł liczby -5:", modulLiczby(-5))
print("Moduł liczby 0:", modulLiczby(0))