import math

def pole_wielokata(ile_bokow, dlugosc_boku):  # liczba boków, długość
    return (ile_bokow * ((dlugosc_boku / (2 * math.sin(math.pi / ile_bokow))) ** 2) * math.sin(2 * math.pi / ile_bokow)) / 2

try:
    ile_bokow = 0
    dlugosc_boku = 0
    while(ile_bokow < 3):
        ile_bokow = int(input("Podaj ilość boków: "))
    while(dlugosc_boku <= 0):
        dlugosc_boku = int(input("Podaj długość boku: "))
    
    print("Pole wielokąta foremnego o {0} bokach długości {1} wynosi:".format(ile_bokow, dlugosc_boku), pole_wielokata(ile_bokow, dlugosc_boku))

except ValueError:
    print("Podano złe dane!")