import sys


class A:
    def __init__(self, graf, h, start):
        self.graf = graf
        self.dlugosc_grafu = len(self.graf)
        self.h = h # Oszacowany koszt z danego punktu do celu końcowego
        self.f = [0] * self.dlugosc_grafu # Całkowity koszt połączenia od punktu początkowego do końcowego
        self.g = [sys.maxsize] * self.dlugosc_grafu # Koszt połączenia z punktu początkowego do obecnie rozpatrywanego
        self.poprzednicy = [0] * self.dlugosc_grafu 
        self.start = start
        self.sprawdzone = [False] * self.dlugosc_grafu

    def najmniejszyDystans(self):
        obecny_min = sys.maxsize
        indeks_min = 0
        for i in range(0, len(self.graf)):
            # Jeśli wierzchołek nie był jeszcze rozpatrywany i jest koszt połaczenia jest tańszy
            if self.g[i] < obecny_min and self.sprawdzone[i] == False:
                obecny_min = self.g[i]
                indeks_min = i
        return indeks_min
    
    def wypiszDane(self):
        print("h = " + str(self.h))
        print("g = " + str(self.g))
        print("f = " + str(self.f))

        obecny_poprzednik = self.poprzednicy[self.dlugosc_grafu - 1]
        trasa = [self.dlugosc_grafu - 1, obecny_poprzednik]
        koszt_trasy = 0
        while obecny_poprzednik != self.start:
            obecny_poprzednik = self.poprzednicy[obecny_poprzednik]
            trasa.append(obecny_poprzednik)
        trasa.reverse()
        
        # Oryginał trasy i poprzedników zwiększamy o 1 dla numeracji od 1 a nie od 0
        for i in range(1, len(self.poprzednicy)):
            self.poprzednicy[i] += 1
        for i in range(0, len(trasa)):
            trasa[i] += 1
            koszt_trasy += trasa[i]

        print("pred = " + str(self.poprzednicy))
        print("Trasa: " + str(trasa))
        print("Koszt połączenia:", koszt_trasy)

    def algorytmA(self):
        self.g[self.start] = 0
        self.f[self.start] = self.h[self.start] + self.g[self.start]
        for i in range(0, len(self.graf)):
            v = self.najmniejszyDystans() # Znajdź jeszcze nierozpatrywany wierzchołek o najtańszym połączeniu całkowitym
            self.sprawdzone[v] = True
            #print("Najtańszy wierzchołek v: ", v)
            for u in range(0, len(self.graf)):
                # Jeśli istnieje połączenie między rozpatrywanymi wierzchołkami, dany wierzchołek nie był jeszcze sprawdzany oraz połaczenie jest tańsze
                if self.graf[v][u] > 0 and self.sprawdzone[u] == False and self.g[u] > self.g[v] + self.graf[v][u]:
                    self.g[u] = self.g[v] + self.graf[v][u]
                    self.poprzednicy[u] = v
                    self.f[u] = self.g[u] + self.h[u]
                    #print("Znalezione tańsze połaczenie dla pary v,u: (", v, ",", u, ")", "pred = " + str(self.poprzednicy))
        self.wypiszDane()

# h - oszacowany koszt, A - macierz i punkt początkowy
h = [4, 8, 3, 4, 5, 2, 1, 0]
a = A([[0, 5, 0, 1, 0, 0, 0, 0],
       [0, 0, 2, 0, 1, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 3],
       [0, 0, 0, 0, 1, 2, 0, 0],
       [0, 0, 4, 0, 0, 0, 0, 0],
       [4, 0, 0, 0, 0, 0, 2, 0],
       [0, 0, 0, 0, 1, 0, 0, 1],
       [0, 0, 0, 0, 2, 0, 0, 0]],
      h, 0)

a.algorytmA()
