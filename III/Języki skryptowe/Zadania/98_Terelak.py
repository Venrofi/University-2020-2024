import cmath

try:
    with open("98.txt", "r") as plik:
        linie = plik.readlines()
    
    a = int(linie[0])
    b = int(linie[1])
    c = int(linie[2])
    delta = (b**2) - (4*a*c)

    x1 = (-b - cmath.sqrt(delta)) / (2*a)
    x2 = (-b + cmath.sqrt(delta)) / (2*a)

    print("{0}x^2 + {1}x + {2}".format(a, b, c))
    print("x1 = {0} \nx2 = {1}".format(x1, x2))

except IOError:
    print("W pliku nie znaleziono liczb!")