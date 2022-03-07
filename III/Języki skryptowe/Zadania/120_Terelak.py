from fractions import Fraction

try:
    liczba = float(input("in: "))
    print("out:", Fraction(liczba).limit_denominator())

except:
    print("Nie podano liczby!")