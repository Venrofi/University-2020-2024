class Potega:
    def __init__(self, podstawa = int, wykladnik = int):
        self.podstawa = podstawa
        self.wykladnik = wykladnik
    def oblicz(self):
        if self.podstawa == 0 or self.podstawa == 1 or self.wykladnik == 1:
            return self.podstawa
        wynik = 1
        for _ in range(self.wykladnik):
            wynik *= self.podstawa
        return wynik

potega = Potega(2, 6)
print("Potęga 2^6:", potega.oblicz())