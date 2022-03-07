class Stos:
    def __init__(self):
        self.items = []
 
    def is_empty(self):
        return self.items == []
 
    def push(self, item):
        self.items.append(item)
 
    def pop(self):
        return self.items.pop()
 
    def top(self):
        return self.items[len(self.items) - 1]
 
    def size(self):
        return len(self.items)

def ONP(formula):
    operatory = {'^': 4,
                 '*': 3, '/': 3,
                 '+': 2, '-': 2, 
                 '(': 1, ')': 1 }

    stos_operatorow = Stos() 
    wynik = [] 
 
    for znak in formula:
        if znak == " ": # ignoruj ewentualne spacje
            continue
        elif znak.isalnum(): # jeśli to liczba dodaj do wyniku
            wynik.append(znak)
        elif znak == "(":
            stos_operatorow.push(znak)
        elif znak == ")":
            while stos_operatorow.top() != "(":
                wynik.append(stos_operatorow.pop()) # dodaj pozostałe operatory z nawiasu do wyniku
            stos_operatorow.pop() # zrzuć "(" ze stosu
        else:
            while not stos_operatorow.is_empty() and operatory[stos_operatorow.top()] >= operatory[znak]:
                wynik.append(stos_operatorow.pop()) # dodaj operatory o większym priorytecie do wyniku
            stos_operatorow.push(znak) # dodaj operator do stosu
 
    while not stos_operatorow.is_empty(): # dodaj do wyniku pozostałe operatory ze stosu
        wynik.append(stos_operatorow.pop())
 
    return "".join(wynik)
 
def OdwrocONP(formula):
    stos = Stos()
    for znak in formula:
        if znak in "+-*/^":
            ostatnia_liczba = stos.pop()
            stos.push("(" + stos.pop() + znak + ostatnia_liczba + ")") # Połącz ostatnie dwie liczby na stosie wraz z operatorem
        else:
            stos.push(znak)
    return stos.top()
 
# 4*(5-6/3+1)^2
# 4563/-1+2^*

plik = open("1_2.txt", "r")
formula = plik.read()
formula = formula.strip() # usuń /n w tekście
formula = formula.replace(" ", "") # usuń spacje

print("Wczytane wyrażenie: ", formula)
if formula[-1] in "+-*/^": # weź ostatni znak, jeśli obecny operator to oznacza notację ONP
	print("Postać klasyczna: ", OdwrocONP(formula))
else:
	print("Odwrócona Notacja Polska: ", ONP(formula))
