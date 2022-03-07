def AlgorytmNaiwny(tekst, szukaneSlowo):
    print("Poszukiwania słowa: '" + szukaneSlowo + "' w podanym tekście..")
    for i in range(len(tekst) - len(szukaneSlowo) + 1):
        if tekst[i] == szukaneSlowo[0]:
            for j in range(1, len(szukaneSlowo)):
                if not tekst[i + j] == szukaneSlowo[j]:
                    break;
                if j==len(szukaneSlowo) - 1:
                    print("Znaleziono na pozycji: {0}".format(str(i+1)))


AlgorytmNaiwny("Koszula w porcie, towar jedzie w transporcie.", "porcie")