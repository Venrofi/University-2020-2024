class Stos:

    def __init__(self, size_):
        self.size = size_
        self.items = [None] * size_
        self.ilosc_elementow = 0

    def czy_pusty(self):
        return self.ilosc_elementow == 0
 
    def dodaj(self, item):
        if self.ilosc_elementow < self.size:
            self.items[self.ilosc_elementow] = item
            self.ilosc_elementow += 1
        else:
            print("Stos jest pełny!")
            return
 
    def usun(self):
        if self.ilosc_elementow > 0:
            temp = self.items[self.ilosc_elementow - 1]
            self.items[self.ilosc_elementow - 1] = None
            self.ilosc_elementow -= 1
            return temp
        else:
            print("Stos jest pusty!")
            return
 
    def ostatni_element(self):
        if self.ilosc_elementow > 0:
            return self.items[self.ilosc_elementow-1]
        else:
            return
 
    def rozmiar(self):
        return self.size

    def znajdz(self, indeks: int):
        if indeks >= self.ilosc_elementow or indeks < 0:
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
        else:
            return self.items[indeks]


stosik = Stos(10);

print("Rozmiar: ", stosik.rozmiar())
print("Czy pusty? ", stosik.czy_pusty())

#Próba usunięcia elementu gdy stos jest pusty
print("\nUsuń gdy stos jest pusty: ")
stosik.usun()


print("\nDodaj element '2'")
stosik.dodaj(2)
print("Dodaj element '1'")
stosik.dodaj(1)
print("Dodaj element '3'")
stosik.dodaj(3)
print("Dodaj element '7'")
stosik.dodaj(7)

print("\nRozmiar: ", stosik.rozmiar())
print("Czy pusty? ", stosik.czy_pusty())

print("\nIle elementów? ", stosik.ilosc_elementow)
print("Ostatni element: ", stosik.ostatni_element())

print("\nUsuń ", stosik.usun())

print("\nOstatni element: ", stosik.ostatni_element())
print("Ile elementów? ", stosik.ilosc_elementow)

print("\nDodaj element '99'")
stosik.dodaj(99)
print("Dodaj element '44'")
stosik.dodaj(44)
print("Dodaj element '77'")
stosik.dodaj(77)
print("Dodaj element '14'")
stosik.dodaj(14)
print("Dodaj element '4'")
stosik.dodaj(4)
print("Dodaj element '10'")
stosik.dodaj(10)
print("Dodaj element 'Radek'")
stosik.dodaj("Radek")

print("\nOstatni element: ", stosik.ostatni_element())

print("Ile elementów? ", stosik.ilosc_elementow)
# W tym momencie stos jest pełny

print("\nDodaj element '100' gdy stos jest pełny: ")
stosik.dodaj(100)

#Znajdowanie elementów

print("\nZnajdź wartość dla indeksu -1: ")
stosik.znajdz(-1)

print("Znajdź wartość dla indeksu 0: ", stosik.znajdz(0))

print("Znajdź wartość dla indeksu 10: ")
stosik.znajdz(10)

print("Znajdź wartość dla indeksu 69: ")
stosik.znajdz(69)

print("Znajdź wartość dla indeksu 9: ", stosik.znajdz(9))