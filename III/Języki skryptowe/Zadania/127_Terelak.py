class OdwrocWyrazy:
    def __init__(self, tekst):
        self.tekst = tekst
    def odwroc(self):
        wyrazy = self.tekst.split(" ")
        wyrazy = wyrazy[::-1]
        wynik = " ".join(wyrazy)
        return wynik

tekst = "Parostatkiem w piękny rejs."
odwracanie = OdwrocWyrazy(tekst)
print("Tekst przed odwróceniem: " + tekst)
print("Tekst po odwróceniu:", odwracanie.odwroc())