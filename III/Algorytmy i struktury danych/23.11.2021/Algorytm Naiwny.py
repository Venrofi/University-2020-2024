def ileWystapien(tekst, wzorzec):
	licznik = 0
	for i in range(0, len(tekst)):
		j = 0;
		while (j < len(wzorzec) and tekst[i + j] == wzorzec[j]):
			j += 1
		if (j > 0 and j == len(wzorzec)):
			licznik += 1
	return licznik

def ileWystapienTEST(tekst, wzorzec):
	print('W tekście \'' + tekst + '\' ', end='')
	print('wzorzec \'' + wzorzec + '\' występuje ', end='')
	print(str(ileWystapien(tekst, wzorzec)) + ' razy')

tekst = 'ab abb aab aaabb'
ileWystapienTEST(tekst, 'a')
ileWystapienTEST(tekst, 'ab')
ileWystapienTEST(tekst, ' b')