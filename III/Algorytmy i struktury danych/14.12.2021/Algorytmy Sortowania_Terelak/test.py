import timeit, random

def sortowanieWstawianie(T):
    for k in range(1, len(T)):
        tmp = T[k] # obecnie sprawdzany element
        i = k - 1
        while i >= 0 and tmp < T[i]: # Zamieniaj elementy większe od obecnie sprawdzanego miejscami
            T[i+1] = T[i] 
            i -= 1
        T[i+1] = tmp # Ustaw wartość mniejszego elementu na wartość obecnie sprawdzanego
    
    return T

lista = [77, 44, 10, 33, 88, 14]
print("Lista przed sortowaniem:", lista)
print("Lista po sortowaniu:", sortowanieWstawianie(lista))

rozmiar_maly = 1000
rozmiar_duzy = 100000
lista_testowa_1 = [random.randint(0, 100000) for i in range(rozmiar_maly)]
lista_testowa_2 = [random.randint(0, 100000) for i in range(rozmiar_duzy)]

print("Sortowanie 1000 elementów 1000 razy InsertionSort: ",timeit.timeit('sortowanieWstawianie(lista_testowa_1)', 'from __main__ import sortowanieWstawianie, lista_testowa_1', number=1000)) # Wynik: 0.28s, 0.27s, 0.25s

print("Sortowanie 100000 elementów InsertionSort: ",timeit.timeit('sortowanieWstawianie(lista_testowa_2)', 'from __main__ import sortowanieWstawianie, lista_testowa_2', number=1)) # Wynik: 636s = 10.6 min