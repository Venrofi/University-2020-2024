import timeit, random

def bubbleSort(T):
    for k in range(len(T), 1, -1):
        for i in range(0, k-1):
            if(T[i] > T[i+1]):
                T[i], T[i+1] = T[i+1], T[i]
    return T

lista = [77, 44, 10, 33, 88, 14]
print("Lista przed sortowaniem:", lista)
lista = bubbleSort(lista)
print("Lista po sortowaniu:", lista)

rozmiar_maly = 1000
rozmiar_duzy = 100000
lista_testowa_1 = [random.randint(0, 100000) for i in range(rozmiar_maly)]
lista_testowa_2 = [random.randint(0, 100000) for i in range(rozmiar_duzy)]

print("Sortowanie 1000 elementów 1000 razy BubbleSort: ",timeit.timeit('bubbleSort(lista_testowa_1)', 'from __main__ import bubbleSort, lista_testowa_1', number=1000)) # Wynik: 46.99s, 82.68s, 43.54s, 47.90s

#print("Sortowanie 100000 elementów BubbleSort: ",timeit.timeit('bubbleSort(lista_testowa_2)', 'from __main__ import bubbleSort, lista_testowa_2', number=1)) # Wynik: 1104.74s = 18.4min