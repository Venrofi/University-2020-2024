class Lista:

    def __init__(self, size_):
        self.size = size_
        self.items = [None] * self.size
        self.ilosc_elementow = 0
        print(self.items)

    def czy_pusta(self):
       return self.ilosc_elementow == 0

    def dodaj(self, item, indeks: int):
       if indeks >= self.size or indeks < 0:
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
       elif self.ilosc_elementow < self.size:
            self.items[indeks] = item
            self.ilosc_elementow += 1
            print(self.items)
       else:
            print("Lista jest pełna!")
            return

    def usun(self, indeks: int):
        if indeks >= self.size or indeks < 0:
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
        elif self.ilosc_elementow > 0 and self.items[indeks] != None:
            temp = self.items[indeks]
            self.items[indeks] = None # Usuń pierwszy element z kolejki
            self.ilosc_elementow -= 1
            print(self.items)
            return temp
        else:
            if self.ilosc_elementow <= 0:
                print("Lista jest pusta!")
            else:
                print("Lista w podanym indeksie jest pusta!")
            return

    def znajdz(self, indeks: int):
        if (indeks >= self.size or indeks < 0):
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
        else:
            return self.items[indeks]

lista = Lista(5)

print("Rozmiar listy: ", lista.size)
print("Czy pusta? ", lista.czy_pusta())

print("\nDodaj element 'd' na 3 pozycję")
lista.dodaj("d", 2)
print("\nDodaj element 'a' na 2 pozycję")
lista.dodaj("a", 1)
print("\nDodaj element 'R' na 1 pozycję")
lista.dodaj("R", 0)
print("\nDodaj element 'e' na 4 pozycję")
lista.dodaj("e", 3)
print("\nDodaj element 'k' na 5 pozycję")
lista.dodaj("k", 4)

print("\nCzy pusta? ", lista.czy_pusta())

print("\nDodaj element 'X' pod indeks spoza zakresu")
lista.dodaj("X", 5)

print("\nZnajdź element o indeksie '1': ", lista.znajdz(1))


print("Znajdź element o nieprawidłowym indeksie '6'")
lista.znajdz(6)


print("\nUsuń 'R' z listy: ")
lista.usun(0)
print("Usuń 'a' z listy: ")
lista.usun(1)
print("Usuń 'd' z listy: ")
lista.usun(2)
print("Usuń 'e' z listy: ")
lista.usun(3)
print("\nUsuń element na pozycji 4, gdy jest pusty")
lista.usun(3)

print("\nUsuń 'k' z listy: ")
lista.usun(4)

print("\nPróba usunięcia elementu na pozycji 1 gdy lista jest pusta: ")
lista.usun(0)
