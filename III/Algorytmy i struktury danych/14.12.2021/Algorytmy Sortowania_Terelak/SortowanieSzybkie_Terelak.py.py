import timeit, random, sys

def quickSort(T):
	def dziel(T, lewa, prawa):
		j = lewa - 1
		pivot = T[prawa]
		for i in range(lewa, prawa): 
			if T[i] < pivot:
				j += 1
				T[i], T[j] = T[j], T[i] # Zamiana miejscami 
		
		T[prawa], T[j+1] = T[j+1], T[prawa] # Zamiana miejscami
		
		return j+1

	def sortuj(T, lewa, prawa):
		if lewa < prawa:
			podzial = dziel(T, lewa, prawa)
			sortuj(T, lewa, podzial-1)
			sortuj(T, podzial+1, prawa)
	
	sortuj(T, 0, len(T)-1)
	return T

lista = [77, 44, 10, 33, 88, 14]
print("Lista przed sortowaniem:", lista)
print("Lista po sortowaniu:", quickSort(lista))

rozmiar_maly = 1000
rozmiar_duzy = 100000
lista_testowa_1 = [random.randint(0, 100000) for i in range(rozmiar_maly)]
lista_testowa_2 = [random.randint(0, 100000) for i in range(rozmiar_duzy)]

sys.setrecursionlimit(2000)
#print("Sortowanie 1000 elementów 1000 razy QuickSort: ",timeit.timeit('quickSort(lista_testowa_1)', 'from __main__ import quickSort, lista_testowa_1', number=1000)) # Wynik: 93.33s, 88.34s, 91.20s

print("Sortowanie 100000 elementów QuickSort: ",timeit.timeit('quickSort(lista_testowa_2)', 'from __main__ import quickSort, lista_testowa_2', number=1)) # Wynik: 0.32s, 0.34s, 0.54s