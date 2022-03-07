import math

def Floyd_Warshall(polaczenia, ile_wierzcholkow, trasa_start, trasa_koniec):
	d = [] # Macierz z najkrótszymi drogami między wierzchołkami
	p = [] # Macierz umożliwiająca odtworzenie najkrótszej trasy

	# Zmienne do znalenienia trasy dla określonych punktów
	poczatek_trasy = trasa_start
	element_trasy = trasa_koniec
	koniec_trasy = element_trasy
	trasa = [koniec_trasy]
	koszt_trasy = 0

	# Wypełnienie macierzy 
	for i in range(0, ile_wierzcholkow+1): # Pierwszy wiersz oraz kolumna są pomocnicze - liczymy wierzchołki od 1
		d += [[math.inf]*(ile_wierzcholkow+1)]
		p += [[0]*(ile_wierzcholkow+1)]
		d[i][i] = 0 
		p[i][i] = 0 
	for polaczenie in polaczenia: # Uzupełnianie macierzy połączeniami
		d[polaczenie[0]][polaczenie[1]] = polaczenie[2]
		p[polaczenie[0]][polaczenie[1]] = polaczenie[0]

	print("Pierwsze wiersze i kolumny użyte w celach pomocniczych - liczymy wierzchołki od 1 \nMacierz d: ")
	for i in d:
		print('\t'.join(map(str, i)))

	print("\nMacierz p: ")
	for i in p:
		print('\t'.join(map(str, i)))

	# Algorytm
	# Ignorujemy pierwszy wiersz i kolumnę bo jest użyta w celach pomocniczych - liczymy wierzchołki od 1
	for u in range(1, ile_wierzcholkow+1): 
		for v in range(1, ile_wierzcholkow+1):
			if u != v:
				for w in range(1, ile_wierzcholkow+1):
					if w != u and w != v and d[v][u] + d[u][w] < d[v][w]:
						d[v][w] = d[v][u] + d[u][w]
						p[v][w] = p[u][w]
	
	# Odnajdywanie optymalnej trasy
	while True:
		#print("\nTrasa Od:", poczatek_trasy, " Do:", element_trasy, "\np[Od, Do]: " + str(p[poczatek_trasy][element_trasy]))
		if p[poczatek_trasy][element_trasy] == poczatek_trasy:
			trasa += [p[poczatek_trasy][element_trasy]]
			break
		trasa += [p[poczatek_trasy][element_trasy]]
		element_trasy = p[poczatek_trasy][element_trasy]
		#print("Trasa:", trasa)

	trasa.reverse()
	print("\nTrasa: ", trasa)

	for i in range(0, len(trasa)):
		koszt_trasy += trasa[i]
	print("Koszt połączenia:", koszt_trasy)

# [wierzchołek początkowy; wierzchołek końcowy; koszt połączenia]
polaczenia = [[1,2,1],[1,3,5],[2,3,2],[4,1,7],[4,5,1],[5,6,1],[6,1,2],[6,4,4],[7,1,6],[7,6,3]]
ile_wierzcholkow = 7
punkt_startowy = 7
punkt_koncowy = 3

Floyd_Warshall(polaczenia, ile_wierzcholkow, punkt_startowy, punkt_koncowy)