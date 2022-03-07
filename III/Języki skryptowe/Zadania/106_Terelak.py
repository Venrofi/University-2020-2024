import random, timeit, sys

def bubbleSort(T):
    for k in range(len(T), 1, -1):
        for i in range(0, k-1):
            if(T[i] > T[i+1]):
                T[i], T[i+1] = T[i+1], T[i]
    return T

def sortowanieWstawianie(T):
    for k in range(1, len(T)):
        tmp = T[k] # obecnie sprawdzany element
        i = k - 1
        while i >= 0 and tmp < T[i]: # Zamieniaj elementy większe od obecnie sprawdzanego miejscami
            T[i+1] = T[i] 
            i -= 1
        T[i+1] = tmp # Ustaw wartość mniejszego elementu na wartość obecnie sprawdzanego
    
    return T

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

with open("106_raport.txt", "w") as plik:
	try:
		print("Zaczynam testować algorytmy..")
		sys.setrecursionlimit(2000) 

		plik.write("RAPORT ALGORYTMÓW SORTOWANIA")
		plik.write("\n    NAZWA    --".ljust(20) + "LICZBA SORTOWANYCH PLIKÓW  --".ljust(30) + " ŚREDNI CZAS".ljust(25) + "\n")

		print("1. Sortowanie bąbelkowe")
		lista_testowa = [random.randint(0, 100000) for i in range(1000)]
		czas_1 = timeit.timeit('bubbleSort(lista_testowa)', 'from __main__ import bubbleSort, lista_testowa', number=100)
		plik.write("\n1. bąbelkowe ".ljust(20) + "--       1000x100       --".ljust(30) + str(czas_1))
		
		print("2. Sortowanie przez wstawianie")
		lista_testowa = [random.randint(0, 100000) for i in range(1000)]
		czas_2 = timeit.timeit('sortowanieWstawianie(lista_testowa)', 'from __main__ import sortowanieWstawianie, lista_testowa', number=100)
		plik.write("\n2. wstawianie ".ljust(20) + "--       1000x100       --".ljust(30) + str(czas_2))
		
		print("3. Sortowanie szybkie")
		lista_testowa = [random.randint(0, 100000) for i in range(1000)]
		czas_3 = timeit.timeit('quickSort(lista_testowa)', 'from __main__ import quickSort, lista_testowa', number=100)
		plik.write("\n3. szybkie ".ljust(20) + "--       1000x100       --".ljust(30) + str(czas_3))

		print("Pomyślnie zapisano dane do pliku :)")
	except Exception as e:
		print(e)
		print("Nie udało się zapisać danych do pliku :(")