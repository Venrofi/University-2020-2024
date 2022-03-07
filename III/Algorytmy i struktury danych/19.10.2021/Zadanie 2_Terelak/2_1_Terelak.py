class Kolejka:

    def __init__(self, size_):
        self.size = size_
        self.items = []
        self.ilosc_elementow = 0

    def czy_pusta(self):
       return self.ilosc_elementow == 0

    def dodaj(self, item):
       if self.ilosc_elementow < self.size:
            self.items += item
            self.ilosc_elementow += 1
            print(self.items)
       else:
            print("Kolejka jest pełna!")
            return

    def usun(self):
        if self.ilosc_elementow > 0:
            temp = self.items[0]
            self.items = self.items[1:] # Usuń pierwszy element z kolejki
            self.ilosc_elementow -= 1
            print(self.items)
            return temp
        else:
            print("Kolejka jest pusta!")
            return

    def znajdz(self, indeks: int):
        if (indeks >= self.size or indeks < 0):
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
        else:
            return self.items[indeks]

kolejka = Kolejka(5)

print("Rozmiar kolejki:", kolejka.size)
print("Czy pusta?", kolejka.czy_pusta())

print("\nDodaj element 'R'")
kolejka.dodaj("R")
print("Dodaj element 'a'")
kolejka.dodaj("a")
print("Dodaj element 'd'")
kolejka.dodaj("d")
print("Dodaj element 'e'")
kolejka.dodaj("e")
print("Dodaj element 'k'")
kolejka.dodaj("k")

print("\nCzy pusta?", kolejka.czy_pusta())

print("\nDodaj element 'X' gdy kolejka jest pełna")
kolejka.dodaj("X")

print("\nZnajdź element o indeksie '1':", kolejka.znajdz(1))

print("Znajdź element o nieprawidłowym indeksie '6'")
kolejka.znajdz(6)

print("\nUsuń 'R' z kolejki: ")
kolejka.usun()
print("Usuń 'a' z kolejki: ")
kolejka.usun()
print("Usuń 'd' z kolejki: ")
kolejka.usun()
print("Usuń 'e' z kolejki: ")
kolejka.usun()
print("Usuń 'k' z kolejki: ")
kolejka.usun()

print("\nPróba usunięcia gdy kolejka jest pusta: ")
kolejka.usun()
