ILE_ZNAKOW = 256

def indeksOstatniegoZnaku(wzorzec):
	tablica_znakow = [-1]*ILE_ZNAKOW

	# Wypełnij tablicę ostatnimi wystąpieniami danego znaku
	for i in range(len(wzorzec)):
		tablica_znakow[ord(wzorzec[i])] = i;

	# return initialized list
	return tablica_znakow

def boyerMoore(tekst, wzorzec):
	M = len(wzorzec)
	N = len(tekst)

	tablica_znakow = indeksOstatniegoZnaku(wzorzec)
	tablica_pomocnicza = ""
	for i in range(65,123):
		tablica_pomocnicza += str(chr(i))+" : "+str(tablica_znakow[i])+", "
		if(i%2 == 0):
			tablica_pomocnicza += "\n"
	print(tablica_pomocnicza)
	
	przesuniecie = 0
	while(przesuniecie <= N - M):
		j = M - 1 # długość wzorca - 1

		# Zmniejszaj j jeśli znaki wzorca zgadzają się z tekstem
		while j >= 0 and wzorzec[j] == tekst[przesuniecie + j]:
			j -= 1
		# Jeśli cały wzorzec zostanie znaleziony, j będzie wynosiło -1 

		if j<0:
			print("Wzorzec '" + wzorzec +"' występuje na pozycji:", przesuniecie)
			#print("Przesuń o: M - tablica_znakow[ord(tekst[przesuniecie + M])]")
			#print("M: ", M, "przesuniecie:", przesuniecie, "tekst[przesuniecie + M]:", tekst[przesuniecie + M], "ord(tekst[przesuniecie + M]):", ord(tekst[przesuniecie + M]))
			#print("tablica_znakow[ord(tekst[przesuniecie + M])]:", tablica_znakow[ord(tekst[przesuniecie + M])])

			# Przesunieńcie = długość wzorca - wartość znaku pod indeksem: przesunięcie + długość wzorca (jeśli występuje to coś > 0, jeśli nie to -1)
			przesuniecie += (M - tablica_znakow[ord(tekst[przesuniecie + M])] if przesuniecie + M < N else 1)
			
			#print("Przesuniecie:", przesuniecie, "\n")
		else:
			#print("ord(tekst[przesuniecie+j]):", ord(tekst[przesuniecie+j]))
			#print("tablica_znakow[ord(tekst[przesuniecie+j])]", tablica_znakow[ord(tekst[przesuniecie+j])])
			#print("max()", max(1, j-tablica_znakow[ord(tekst[przesuniecie+j])]))

			# Jeśli nie znaleziono wzorca, przesunieńcie ustaw na: znajdź znak który się niezgadza i odczytaj jego wartość z tablicy i dodaj do niego wartość j. Jeśli ta suma jest negatywna to dodaj 1
			przesuniecie += max(1, j-tablica_znakow[ord(tekst[przesuniecie+j])])


boyerMoore("Nie miałem studniówki, bywały dwudniówki", "dniówki")

