liczba = input("Podaj liczbę: ")

try:
    if(int(liczba) > 0):
        print("Więcej niż zero!")
    elif(int(liczba) < 0):
        print("Mniej niż zero!")
except:
    print("Nie podano liczby!")