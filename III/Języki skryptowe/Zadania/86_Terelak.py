def main():
    wynik = ""
    liczba = list(input("Podaj liczbę: "))
    print(liczba)
    for cyfra in liczba:
        try:
            cyfra = int(cyfra)
            wynik = polacz_cyfry(wynik, liczby[cyfra])
        except ValueError:
            print("Jeden z wprowadzonych elementów nie jest liczbą!")

    print(wynik)

def polacz_cyfry(a, b = False):
    if not b:
        return a
    if a == "":
        return b
    a_ = a.split("\n")
    b_ = b.split("\n")
    wynik_polaczenia = ""
    for element_a, element_b in zip(a_, b_):
        wynik_polaczenia += element_a + "  " + element_b + "\n"
    return wynik_polaczenia

liczby = {
    0: """
 ### 
## ##
#   #
#   #
#   #
## ##
 ### 
""",
    1: """
  ###
 ####
## ##
   ##
   ##
   ##
   ##
""",
    2: """
 ### 
## ##
## ##
  ## 
 ##  
##   
#####
""",
    3: """
#### 
   ##
   ##
#####
   ##
   ##
#### 
""",
    4: """
   ##
  ###
 ## #
##  #
#####
   ##
   ##
""",
    5: """
#####
##   
##   
#### 
   ##
   ##
#### 
""",
    6: """
    #
   # 
  #  
 ### 
#   #
#   #
 ### 
""",
    7: """
#####
#####
   ##
  ## 
  ## 
 ##  
##   
""",
    8: """
 ### 
#   #
#   #
 ### 
#   #
#   #
 ### 
""",
    9:"""
 ### 
#   #
#   #
 ####
   ##
  ## 
##   
""",}

main()
