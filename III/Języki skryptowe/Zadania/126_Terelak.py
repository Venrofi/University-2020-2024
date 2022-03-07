import math

class Kolo:
    def __init__(self, r):
        self.r = float(r)
    def pole(self):
        return self.r * self.r * math.pi
    def obwod(self):
        return 2 * self.r * math.pi

kolo = Kolo(5)

print("Pole koła o promieniu {0}:".format(5), kolo.pole())
print("Obwód koła o promieniu {0}:".format(5), kolo.obwod())