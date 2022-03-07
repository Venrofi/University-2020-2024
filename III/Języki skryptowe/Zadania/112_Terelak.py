import datetime, time, os

def zegar():
    while True:
        czas = datetime.datetime.now()
        obecna_godzina = czas.strftime("%H:%M:%S")
        print(obecna_godzina)
        time.sleep(1)
        os.system("cls")

zegar()