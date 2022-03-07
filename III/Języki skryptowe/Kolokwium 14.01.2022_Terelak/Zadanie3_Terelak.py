# Generator Park-Miller
# x[i] = (a * x[i - 1]) % m

def ParkMiller(i):
    x = [1] * i
    a = 5
    m = 23  
    print("Wygenerowane liczby (ilość: {}):".format(i))
    for _ in range(1, i):
        x[_] = (a * x[_ - 1]) % m
        print(x[_])

ParkMiller(10)