import timeit, random

def merge(lewa, prawa):
	wynik = []
	while len(lewa) > 0 and len(prawa) > 0:
		if lewa[0] <= prawa[0]:
			wynik += [lewa.pop(0)]
		else:
			wynik += [prawa.pop(0)]
	while len(lewa) > 0:
		wynik += [lewa.pop(0)]
	while len(prawa) > 0:
		wynik += [prawa.pop(0)]
	return wynik

def mergeSort(T):
	if len(T) > 1:
		lewa = mergeSort(T[:int(len(T)/2)])
		prawa = mergeSort(T[int(len(T)/2):])
		return merge(lewa, prawa)
	else:
		return T

lista = [77, 44, 10, 33, 88, 14]
print("Lista przed sortowaniem:", lista)
print("Lista po sortowaniu:", mergeSort(lista))

rozmiar_maly = 1000
rozmiar_duzy = 100000
lista_testowa_1 = [random.randint(0, 100000) for i in range(rozmiar_maly)]
lista_testowa_2 = [random.randint(0, 100000) for i in range(rozmiar_duzy)]

print("Sortowanie 1000 elementów 1000 razy MergeSort: ",timeit.timeit('mergeSort(lista_testowa_1)', 'from __main__ import mergeSort, merge, lista_testowa_1', number=1000)) # Wynik: 5.19s, 5.28

print("Sortowanie 100000 elementów MergeSort: ",timeit.timeit('mergeSort(lista_testowa_2)', 'from __main__ import mergeSort, merge, lista_testowa_2', number=1)) # 100 razy - wynik: 214.67s = 3.5min  Wynik: 2.16s