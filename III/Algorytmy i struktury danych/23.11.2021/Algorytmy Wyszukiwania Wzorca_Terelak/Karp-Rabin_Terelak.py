def kodowanie(string):
	wynik = 0
	i = 0
	while i < len(string):
		# Każdy kod ASCII kolejnego znaku wzorca/ciągu pomnóż przez 5 (choć należałoby użyć tutaj wielkości alfabetu) do określonej potęgi i dodaj do wyniku
		wynik += ord(string[i])*(5**(len(string)-i))
		i += 1
	return wynik%48901 # Wynik podziel modulo przez dużą liczbę pierwszą

def karpRabin(tekst, wzorzec):
	przesuniecie = 0
	zakodowany_wzorzec = kodowanie(wzorzec) # Kodujemy wzorzec

	while przesuniecie < len(tekst):
		k = tekst[przesuniecie:przesuniecie + len(wzorzec)] # Sprawdź każdy ciąg znaków o długości wzorca i przesuwaj o 1
		# Jeśli suma kontrolna kodowania wzorca jest taka sama jak sprawdzanego ciągu to znaleźliśmy wzorzec w tekście
		if kodowanie(k) == zakodowany_wzorzec: 
			print("Znaleziono wzorzec '"+ wzorzec + "' na pozycji:", przesuniecie + 1)
		przesuniecie += 1

karpRabin("Locale locale = new Locale('PL','pl');","Locale")

