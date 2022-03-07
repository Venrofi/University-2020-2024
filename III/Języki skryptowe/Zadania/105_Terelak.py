liczba = ""
liczby = []

while(liczba != "exit"):
    try:
        liczba = input("Podaj liczbę, wpisz 'exit' by zakończyć: ")
        liczby.append(int(liczba))
    except:
        if(liczba != "exit"):
            print("Nie podano liczby całkowitej!")

print("\nŚrednia liczb:", sum(liczby) / len(liczby))
print("Najmniejsza liczba:", min(liczby))
print("Największa liczba:", max(liczby))