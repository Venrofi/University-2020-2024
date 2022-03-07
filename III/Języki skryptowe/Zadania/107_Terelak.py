def szyfrCezara(przesuniecie: int, tekst: str):
    zakodowany_tekst = ""
    for znak in tekst:
        zakodowany_tekst += chr(ord(znak)+przesuniecie)
    print("Przesunięcie: {}\nTekst: {}\nTekst po zakodowaniu: {}\n".format(przesuniecie, tekst, zakodowany_tekst))
    return zakodowany_tekst

tekst = "Parostatkiem w piękny rejs!"
tekst = szyfrCezara(3, tekst)
tekst = szyfrCezara(-3, tekst)