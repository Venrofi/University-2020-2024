lista_liter = []

alfabet = input("Podaj alfabet: ")
lista_liter += alfabet
print("Alfabet:", alfabet)

for litera in lista_liter:
    if(litera in "aeyioąęuóAEYIOĄĘUÓ"):
        print(litera)

