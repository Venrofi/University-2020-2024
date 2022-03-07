def dzielenie(i1, i2):
    i1 = complex(*i1)
    i2 = complex(*i2)
    return i1 / i2

print("Dzielenie liczb: 1+8j i 2+3j")
print("Wynik:", dzielenie((1, 8), (2, 3)))