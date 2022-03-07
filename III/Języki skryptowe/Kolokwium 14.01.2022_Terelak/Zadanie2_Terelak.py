with open('analizadanych.txt', encoding="utf-8", mode="w") as plik:
    plik.write("Osoba | żył lat | ur. i zm. w tym samym mieście | ur. i zm. w tym samym kraju\n")
    plik.write("-----------------------------------------------------------------------------\n")

try:
    with open('baza.txt', encoding="utf-8") as plik:
        for wiersz in plik:
            wiersz = wiersz.split(";")
            imie = wiersz[0]
            uro = wiersz[1]
            death = wiersz[4]
            wiek = int(death[len(death)-4:])-int(uro[len(uro)-4:])
            wiek = str(wiek) + " lat"
            wiersz[6] = wiersz[6].replace("\n", "")

            if wiersz[2].upper() == wiersz[5].upper():
                toSamoMiasto = "Tak"
            else:
                toSamoMiasto = "Nie"

            if wiersz[3].upper() == wiersz[6].upper():
                tenSamKraj = "Tak"
            else:
                tenSamKraj = "Nie"

            with open('analizadanych.txt', encoding="utf-8", mode="a") as plik_wynikowy:
                wynik = f'{imie.ljust(16)}|{str(wiek).center(15)}|{toSamoMiasto.center(15)}|{tenSamKraj.center(15)}\n'
                plik_wynikowy.write(wynik)
        print("Pomyślnie zapisano wynik do pliku :)")
except:
    print("Coś się popsuło..")
