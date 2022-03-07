ile_samoglosek = 0
tekst = input("Podaj tekst: ")

for litera in tekst:
    if(litera in "aeyioąęuóAEYIOĄĘUÓ"):
        ile_samoglosek += 1

print("Liczba samogłosek w tekście:", ile_samoglosek)