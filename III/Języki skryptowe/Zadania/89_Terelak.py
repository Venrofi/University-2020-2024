tekst = input("Podaj tekst do sprawdzenia: ")

tekst_reverse = tekst[::-1]
tekst_1 = tekst.replace(' ', '').lower()
tekst_2 = tekst_reverse.replace(' ', '').lower()

if(tekst_1 == tekst_2):
    print(tekst, "to Palindrom!")
else:
    print(tekst, "nie jest Palindromem :(")