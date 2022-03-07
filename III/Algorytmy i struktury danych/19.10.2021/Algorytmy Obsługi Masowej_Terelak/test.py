class PriorityQueue:
    tab=[]
    tab_length=0
    tab_max=10
    def add_to_q(self ,obj):
        if self.tab_length<self.tab_max:
            self.tab += [obj]
            self.tab_length += 1
            if self.tab_length >1:
                for i in range(self.tab_length):
                    if self.tab[self.tab_length-1]>self.tab[i]:
                        self.tab[self.tab_length-1],self.tab[i]=self.tab[i],self.tab[self.tab_length-1]
        else:
            print("tablica jest pełna!")
        return
    def remove_from_q(self):
        try:
            wynik=self.tab[0]
            self.tab=self.tab[1:]
            return wynik
        except Exception as e:
            print("Tablica jest pusta!")
    def find_element(self,element):
        try:
            return self.tab[element]
        except Exception as e:
            return e
test=PriorityQueue()
test.add_to_q(2)
test.add_to_q(8)
test.add_to_q(5)
test.add_to_q(132)
test.add_to_q(6)
test.add_to_q(43)
test.add_to_q(122131)
test.add_to_q(1)
test.add_to_q(21)
test.add_to_q(23)
print(test.tab)
print(test.find_element(9))
print(test.remove_from_q())
print(test.remove_from_q())
print(test.tab)