lista = []

element = input("Podaj element listy: ")
lista.append(element)
while(element != "exit"):
    element = input("Podaj kolejny element listy (wpisz 'exit' by zakończyć): ")
    lista.append(element)

for item in lista:
    print(item)
