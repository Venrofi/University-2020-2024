class KolejkaPriorytet:

    def __init__(self, size_):
        self.size = size_
        self.items = []
        self.ilosc_elementow = 0

    def czy_pusta(self):
       return self.ilosc_elementow == 0

    def dodaj(self, item, priorytet: int = 0): # priorytet musi być int'em oraz jeśli użytkownik nie poda swojego, domyślnym będzie 0
       if self.ilosc_elementow < self.size:
            self.items += [(priorytet, item)]
            self.ilosc_elementow += 1
            print(self.items)
       else:
            print("Kolejka jest pełna!")
            return

    def usun(self):
        if self.ilosc_elementow > 0:
            top_priority = 0
            for item in self.items: # Szukanie najwyższego priorytetu
                if(item[0] > top_priority):
                    top_priority = item[0]

            i = 0
            del_item = []
            for item in self.items:
                if(top_priority == item[0]): # Znajdowanie indeksu kolejki o najwyższym priorytecie
                    print("Trzeba usunąć:", item)
                    del_item = item          # Element do usunięcia
                    self.ilosc_elementow -= 1
                    break
                i +=1
            
            i = 0
            temp = []
            for item in self.items:          # Wyklucz element do usunięcia z kolejki
                if(item != del_item):
                    temp += [item]
            
            print("Przed:", self.items)
            print("Po:", temp)
            self.items = temp
            
            return del_item
        else:
            print("Kolejka jest pusta!")
            return

    def znajdz(self, indeks: int):
        if (indeks >= self.size or indeks < 0):
            # raise IndexError('Zły indeks')
            print("Zły indeks!")
            return
        else:
            return self.items[indeks][1]

kolejka = KolejkaPriorytet(5)

print("Rozmiar kolejki: ", kolejka.size)
print("Czy pusta? ", kolejka.czy_pusta())

print("\nDodaj element 'R'")
kolejka.dodaj("R")
print("Dodaj element 'a'")
kolejka.dodaj("a", 1)
print("Dodaj element 'd'")
kolejka.dodaj("d", 3)
print("Dodaj element 'e'")
kolejka.dodaj("e", 5)
print("Dodaj element 'k'")
kolejka.dodaj("k")

print("\nCzy pusta? ", kolejka.czy_pusta())

print("\nDodaj element 'X' gdy kolejka jest pełna")
kolejka.dodaj("X")

print("\nZnajdź element o indeksie '1': ", kolejka.znajdz(1))


print("Znajdź element o nieprawidłowym indeksie '6'")
kolejka.znajdz(6)


print("\nUsuń element")
kolejka.usun()
print("\nUsuń element")
kolejka.usun()
print("\nUsuń element")
kolejka.usun()
print("\nUsuń element")
kolejka.usun()
print("\nUsuń element")
kolejka.usun()

print("\nPróba usunięcia gdy kolejka jest pusta: ")
kolejka.usun()
