import sys

G = [[0, 3, 0, 3, 5], [3, 0, 5, 1, 0], [0, 5, 0, 2, 0], [3, 1, 2, 0, 1], [5, 0, 0, 1, 0]] # Graf z wagami
N = len(G) # Ilość wierzchołków

wybrany_wierzcholek = [0] * len(G)
wybrany_wierzcholek[0] = True
sprawdzone_wierzcholki = 0
koszt_calkowity = 0

print("Krawędź : Koszt")
while (sprawdzone_wierzcholki < N - 1):
    #print("\nSprawdzam wierzchołek: ", sprawdzone_wierzcholki+1)
    koszt = sys.maxsize
    v = 0
    u = 0 # Resetujemy wierzchołki początkowe oraz koszt połączenia
    for i in range(N):
        if wybrany_wierzcholek[i]:
            #print("Wybrany wierzchołek: ",i+1," ", wybrany_wierzcholek[i])
            for j in range(N):
                if ((not wybrany_wierzcholek[j]) and G[i][j]):  # Jeśli nie wybrany i istnieje taka krawędź
                    #print("Istnieje połączenie z wierzchołkiem: ", j+1,", o koszcie: ", G[i][j])
                    if koszt > G[i][j]: # Szukamy najtańszego połączenia
                        koszt = G[i][j]
                        v = i
                        u = j
                        #print("Najtańsze połączenie: (", v+1,",", u+1, ") : ", koszt)
    print(" " +str(v+1) + " - " + str(u+1) + "  :   " + str(G[v][u]))
    #print("Ustawiam wierchołek u(", u+1, ") na TRUE: ")
    wybrany_wierzcholek[u] = True
    koszt_calkowity += koszt
    sprawdzone_wierzcholki += 1

print("\nKoszt całkowity: ", koszt_calkowity)