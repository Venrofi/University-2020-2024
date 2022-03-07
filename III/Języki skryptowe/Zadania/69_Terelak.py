import random

def PiMonte(dokladnosc):
    punkty_okregu = 0
    punkty_kwadratu = 0

    for i in range(dokladnosc):
        x = random.random()
        y = random.random()

        if x**2 + y**2 < 1:
            punkty_okregu += 1
    return 4 * punkty_okregu / dokladnosc

print("Przybliżona wartość PI na podstawie metody Monte Carlo: ", PiMonte(100))

