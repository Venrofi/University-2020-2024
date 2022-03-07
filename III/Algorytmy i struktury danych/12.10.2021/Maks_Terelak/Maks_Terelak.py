import sys 

max = sys.float_info.min  #najmniejsza dostępna liczba
temp = ""

plik = open("1_1.txt", "r")
liczby = plik.read()
liczby = liczby.strip() # usuń /n w tekście
liczby = liczby.replace(" ", "") # usuń spacje

print("Wczytane liczby ze zbioru: ", liczby)
for liczba in liczby:
    if liczba != ";": # wczytuj znaki liczby do momentu aż pojawi się średnik
        temp += liczba
    else:
        if float(temp) > max:
            max = float(temp)
        temp = ""

print("Największa liczba ze zbioru to:", max)