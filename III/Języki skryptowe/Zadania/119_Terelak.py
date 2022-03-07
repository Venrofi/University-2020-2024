import cmath

try:
    liczba = float(input("in: "))
    print("out: " + str(cmath.phase(complex(liczba))))

except:
    print("Nie podano liczby!")