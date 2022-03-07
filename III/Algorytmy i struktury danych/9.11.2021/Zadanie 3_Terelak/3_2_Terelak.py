import sys;

class Dijkstra:
    def __init__(self, graf, start, koniec):
        self.graf = graf
        self.start = start
        self.koniec = koniec
        self.poprzednicy = [0] * len(self.graf)
        self.dystans = [sys.maxsize] * len(self.graf)
        self.dystans[start] = 0
        self.sprawdzone = [False] * len(self.graf)

    def najmniejszyDystans(self):
        obecny_min = sys.maxsize
        indeks_min = 0
        for i in range(len(self.graf)):
            # Znajdź najmniejszy dystans wsród jeszcze nie rozpatrywanych wierzchołków
            if(self.sprawdzone[i] == False and self.dystans[i] < obecny_min): 
                obecny_min = self.dystans[i]
                indeks_min = i
        return indeks_min 

    def wypiszDroge(self):
        obecny_poprzednik = self.poprzednicy[self.koniec]
        trasa = [self.koniec, obecny_poprzednik]
        #print("\nObecny poprzednik:", obecny_poprzednik, "Trasa:", trasa)
        while(obecny_poprzednik != self.start):
            obecny_poprzednik = self.poprzednicy[obecny_poprzednik]
            trasa.append(obecny_poprzednik)
            #print("Dodaj", obecny_poprzednik, "do trasy")
        #print("Trasa przed odwróceniem i dodaniem 1:", trasa)
        trasa.reverse()
        trasa = [x+1 for x in trasa] # Dla wyświetlania wierzchołków od 1
        print("Trasa: "+str(trasa)+"\nKoszt: "+str(self.dystans[self.koniec]))

    def ileOdwiedzonych(self):
        licznik = 0
        for i in self.sprawdzone:
            if i:   # Jeśli dany wierzchołek był sprawdzany dodaj 1
                licznik += 1
        return licznik

    def algorytm(self):
        poczatek = self.start
        ile_odwiedzonych = 0
        #print("Początek:", poczatek, " ile_odwiedzonych: ", ile_odwiedzonych)
        while(ile_odwiedzonych < len(self.graf)): # Sprawdź każdy wierzchołek
            #print("Ustawiam sprawdzone[",poczatek,"] na TRUE")
            self.sprawdzone[poczatek] = True
            for cel in range(0, len(self.graf)):
                if(self.sprawdzone[cel] is False and self.graf[poczatek][cel]): # Czy istnieje nowa droga do innego wierzchołka?
                    #print("Istnieje nowa droga do celu: ", cel+1," o koszcie: ", self.graf[poczatek][cel])
                    if(self.dystans[poczatek] + self.graf[poczatek][cel] < self.dystans[cel]): # Czy istnieje krótszy dystans?
                        self.dystans[cel] = self.graf[poczatek][cel] + self.dystans[poczatek]
                        #print("Istnieje krótszy dystans: ",poczatek+1," ->", cel+1, " wynosi: ", self.dystans[cel])
                        self.poprzednicy[cel] = poczatek # Dodaj obecnie sprawdzany wierzchołek do trasy
                        #print("Poprzednicy: ", self.poprzednicy)
            poczatek = self.najmniejszyDystans() # Znajdź namniejszy dystans
            ile_odwiedzonych = self.ileOdwiedzonych() # Zwiększ ilość rozpatrzonych wierzchołków
            #print("\nNowy początek:", poczatek, " ile_odwiedzonych: ", ile_odwiedzonych)
        self.wypiszDroge()

print("Algorytm Dijkstry")
dijkstra = Dijkstra([[0, 3, 0, 3, 5],
                    [3, 0, 5, 1, 0],
                    [0, 5, 0, 2, 0],
                    [3, 1, 2, 0, 1],
                    [5, 0, 0, 1, 0]], 0, 4)
dijkstra.algorytm()

