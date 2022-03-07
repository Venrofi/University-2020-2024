import time

class randomGenerator:
    def __init__(self, seed=11):
        self.seed = seed

    def random(self):
        self.seed = (8835710 + self.seed * int(time.time())) & 0x7ffff
        return self.seed

generator = randomGenerator(14)

print("Losowa liczba:", generator.random())