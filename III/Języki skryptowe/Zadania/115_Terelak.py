def dodaj(i1, i2):
    i1 = complex(*i1)
    i2 = complex(*i2)
    return i1 + i2

print("Dodawanie liczb: 5+3j i -2-2j")
print("Wynik:", dodaj((5, 3), (-2, -2)))