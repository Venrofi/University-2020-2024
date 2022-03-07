i = 0

for gender in ["Mężczyzna", "Kobieta"]:
    for color in ["biały", "czarny", "zielony", "czerwony", "niebieski"]:
        for size in ["XL", "L", "M", "S"]:
            try:
                outputFile = open("100_metka_" + str(i) + "_" + gender[:1] + "_" + size + ".txt", "w")
                outputFile.write(gender + ", " + color + ", " + size)
                i+=1
            except IOError:
                print("Blad otwierania pliku")
                exit()
            finally:
                outputFile.close()
print("Pomyślnie wygenerowano metki i zapisano je do plików..")