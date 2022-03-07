import timeit, random

def heapSort(T):
	def heapify(T, m, i):
		maks = i
		lewy = (2*i)+1
		prawy = lewy+1
		if lewy < m and T[maks] < T[lewy]:
			maks = lewy
		if prawy < m and T[maks] < T[prawy]:
			maks = prawy
		if maks != i:
			T[maks], T[i] = T[i], T[maks] # Zamiana
			heapify(T, m, maks)

	for i in range(len(T), -1, -1):
		heapify(T, len(T), i)
	for i in range(len(T)-1, 0, -1):
		T[0], T[i] = T[i], T[0] # Zamiana
		heapify(T, i, 0)

	return T

lista = [77, 44, 10, 33, 88, 14]
print("Lista przed sortowaniem:", lista)
print("Lista po sortowaniu:", heapSort(lista))

rozmiar_maly = 1000
rozmiar_duzy = 100000
lista_testowa_1 = [random.randint(0, 100000) for i in range(rozmiar_maly)]
lista_testowa_2 = [random.randint(0, 100000) for i in range(rozmiar_duzy)]

print("Sortowanie 1000 elementów 1000 razy HeapSort: ",timeit.timeit('heapSort(lista_testowa_1)', 'from __main__ import heapSort, lista_testowa_1', number=1000)) # Wynik: 4.96s, 4.84s, 5.21s

print("Sortowanie 100000 elementów HeapSort: ",timeit.timeit('heapSort(lista_testowa_2)', 'from __main__ import heapSort, lista_testowa_2', number=100)) # 100 razy - wynik: 85.18s = 1.41 min   Wynik: 0.83s, 0.96s