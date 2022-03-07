import time

def pierwszy_poniedzialek(rok, tydzien):
    return time.asctime(time.strptime("{} {} 1".format(rok, tydzien), "%Y %W %w"))

try:
    rok = int(input("Podaj rok: "))
    tydzien = int(input("Podaj tydzień: "))
    print("Pierwszy poniedziałek w tygodniu {0} roku {1} to:".format(tydzien, rok), pierwszy_poniedzialek(rok, tydzien))

except ValueError:
    print("Podano złe dane!")