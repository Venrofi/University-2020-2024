import random

def losowyElement(lista):
    element = random.randint(0, len(lista))
    return lista[element]

lista = [44, 77, 33, 11, 3, 4, 1, 7, 99, 5, 18, 88]
print("Lista:", lista)
print("Losowy element listy:", losowyElement(lista))