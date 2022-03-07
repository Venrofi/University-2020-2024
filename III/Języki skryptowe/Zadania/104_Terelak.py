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

with open("104.txt", "r") as plik:
	lista = plik.read()
	lista = lista.split(",")
	liczby = []
	for element in lista:
		try:
			liczby.append(int(element))
		except ValueError:
			print("W pliku znaleziono element który nie jest liczbą!")
	print("Wczytane dane:", liczby)

with open("104wyniki.txt", "w") as plik:
	a, b, c = liczby, liczby, liczby
	try:
		plik.write("Pierwotne dane: " + str(liczby))
		plik.write("\na) Sortowanie bąbelkowe: " + str(bubbleSort(a)))
		plik.write("\nb) Sortowanie przez wstawianie: " + str(sortowanieWstawianie(b)))
		plik.write("\nc) Sortowanie szybkie: " + str(quickSort(c)))
		print("Pomyślnie zapisano dane do pliku :)")
	except:
		print("Nie udało się zapisać danych do pliku :(")