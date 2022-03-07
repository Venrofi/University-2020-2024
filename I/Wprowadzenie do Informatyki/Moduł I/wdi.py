from selenium import webdriver

game = 'Y'
while game == 'Y' or game == 'y':
    print("KALKULATOR TEMPERATUR I WALUT")
    print("1. KALKULATOR TEMPERATUR")
    print("2. KALKULATOR WALUT")
    ans0 = int(input("Podaj wybor: "))
    if ans0 == 1:
        print("KALKULATOR TEMPERATUR")
        print("1. Celsjusze na Fahrenheity")
        print("2. Fahrenheity na Celsjusze")
        ans = int(input("Podaj wybor: "))
        if ans == 1:
            temp_in = float(input("Podaj temperature w Celsjuszach: "))
            temp_out = (9 / 5) * temp_in + 32
            print("Temperatura w Fahrenheitach wynosi: ", temp_out)
        elif ans == 2:
            temp_in = float(input("Podaj temperature w Fahrenheitach: "))
            temp_out = (temp_in - 32) * (5 / 9)
            print("Temperatura w Celsjuszach wynosi: ", temp_out)
        else:
            print("Blad!")
    elif ans0 == 2:
            print("KALKULATOR WALUT")
            driver = webdriver.Chrome()
            driver.get("https://www.xe.com/currencyconverter/convert/?Amount=1&From=EUR&To=PLN")
            driver.minimize_window()
            ex_rate = driver.find_element_by_css_selector('span.converterresult-toAmount').text
            ex_rate = float(ex_rate)
            print("AKTUALNY KURS 1EUR TO: ", ex_rate, "zł")
            cash = float(input("Ile Euro do wymiany? "))
            cash *= ex_rate
            print("Ilosc PLN po wymianie: ", cash, "zł")
            driver.close()
    else:
        print("Blad!")
    game = input("Powrot na start -> Y/y ")