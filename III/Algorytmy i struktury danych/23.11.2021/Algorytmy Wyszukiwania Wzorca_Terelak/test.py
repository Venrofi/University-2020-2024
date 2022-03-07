tekst = "Locale locale = new Locale('PL','pl');"
wzorzec = "Locale"

def kodowanie(string):
	wynik = 0
	i = 0
	while i < len(string):
		#print("ord(string[i]):", ord(string[i]))
		# Każdy kod ASCII kolejnego znaku wzorca/ciągu pomnóż przez 5 do określonej potęgi i dodaj do wyniku
		wynik += ord(string[i])*(5**(len(string)-i))
		print("Wynik:", wynik)
		i += 1
	return wynik%48901 # Wynik podziel modulo przez dużą liczbę pierwszą

przesuniecie = 0
zakodowany_wzorzec = kodowanie(wzorzec) # Kodujemy wzorzec
print("Zakodowany wzorzec:", zakodowany_wzorzec)
while przesuniecie < len(tekst):
	k = tekst[przesuniecie:przesuniecie+len(wzorzec)] # Sprawdź każdy ciąg znaków o długości wzorca i przesuwaj o 1
	print("k:", k)
	# Jeśli suma kontrolna kodowania wzorca jest taka sama jak sprawdzanego ciągu to znaleźliśmy wzorzec w tekście
	if kodowanie(k) == zakodowany_wzorzec: 
		print("Znaleziono wzorzec na pozycji:",przesuniecie+1)
	przesuniecie += 1
