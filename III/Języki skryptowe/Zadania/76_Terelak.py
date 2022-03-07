lista = [33, "44", False, 3.14]
lista_2 = [10, "77", True, 2.71]

print(lista)

element = 10

if(element in lista or element in lista_2):
    print("Element", element, "znajduje się w liście!")
else:
    print("Element", element, "nie należy do listy :(")
