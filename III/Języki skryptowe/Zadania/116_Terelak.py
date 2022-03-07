def mnozenie(i1, i2):
    i1 = complex(*i1)
    i2 = complex(*i2)
    return i1 * i2

print("Mnożenie liczb: 5+2j i 3-7j")
print("Wynik:", mnozenie((5, 2), (3, -7)))