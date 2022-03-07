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

def START(nazwa_pliku, kryterium):
	try:
		dane_a = []
		dane_b = []
		with open(nazwa_pliku + ".txt", encoding="utf-8") as plik:
			for wiersz in plik:
				input = plik.readline().split(";")
				input[1] = input[1].replace('\n', '')
				dane_a += input[0]
				dane_b += input[1]

		print("Analizuje wczytane dane..")

		if(kryterium == 1):
			print("Dane punktacji za Zadanie 1 przed sortowaniem:", dane_a)
			print("Dane punktacji za Zadanie 1 po sortowaniu:", quickSort(dane_a))

			with open(nazwa_pliku + "_wynik.txt", encoding="utf-8", mode="w") as plik:
				plik.write("Dane punktacji za Zadanie 1 po sortowaniu: \n")
				for liczba in dane_a:
					plik.write(liczba + "\n")
			print("Pomyślnie zapisano wynik do pliku..")

		elif(kryterium == 2):
			print("Dane punktacji za Zadanie 2 przed sortowaniem:", dane_b)
			print("Dane punktacji za Zadanie 2 po sortowaniu:", quickSort(dane_b))

			with open(nazwa_pliku + "_wynik.txt", encoding="utf-8", mode="w") as plik:
				plik.write("Dane punktacji za Zadanie 2 po sortowaniu: \n")
				for liczba in dane_b:
					plik.write(liczba + "\n")
			print("Pomyślnie zapisano wynik do pliku..")

	except:
		print("Coś się popsuło..")

START("dane", 2)