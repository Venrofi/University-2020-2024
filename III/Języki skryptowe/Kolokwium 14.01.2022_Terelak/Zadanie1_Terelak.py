# Napisz klasę Macierz, w której przeciążysz operator dodawania, odejmowania i mnożenia. Napisz metodę obliczającą wyznacznik macierzy

from random import randint

class Macierz:
    def __init__(self, m):
        self.m = m
        if not m:
            print("Nieprawidłowe wymiary.")
            raise ValueError
        else:
            self.rows = len(self.m)
            self.columns = len(self.m[0])
    
    def __str__(self):
        return f"{self.m}"

    def __add__(self, other):
        try:
            if self.rows == len(other.m) and self.columns == len(other.m[0]):
                return [[self.m[i][j] + other.m[i][j] for j in range(self.columns)] for i in range(self.rows)]
            else:
                print("Nieprawidłowe wymiary.")
                return -1
        except ValueError:
            print("Nieprawidłowa wartość.")
            return -1

    def __sub__(self, other):
        try:
            if self.rows == len(other.m) and self.columns == len(other.m[0]):
                return [[self.m[i][j] - other.m[i][j] for j in range(self.columns)] for i in range(self.rows)]
            else:
                print("Nieprawidłowe wymiary.")
                return -1
        except ValueError:
            print("Nieprawidłowa wartość.")
            return -1
    def __mul__(self, other):
        try:
            if self.rows == len(other.m) and self.columns == len(other.m[0]):
                return [[self.m[i][j] * other.m[i][j] for j in range(self.columns)] for i in range(self.rows)]
            else:
                print("Nieprawidłowe wymiary.")
                return -1
        except ValueError:
            print("Nieprawidłowa wartość.")
            return -1

    def det(self):
        try:
            if self.rows == self.columns:
                if self.rows == 2:
                    det = self.__det_2x2(self.m)
                    return det
                elif self.rows == 3:
                    det = self.__det_3x3(self.m)
                    return det
                else:
                    print("Nieobsługiwane wymiary.")
                    return -1
            else:
                print("Nieprawidłowe wymiary.")
                return -1
        except ValueError:
            print("Coś się popsuło..")
            return -1

    @staticmethod
    def __det_2x2(m):
        return m[0][0] * m[1][1] - m[0][1] * m[1][0]

    @staticmethod
    def __det_3x3(m):
        return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2]



m2x2 = Macierz([[2, 1], [5, 3]])
m2x2_2 = Macierz([[2, 2], [2, 2]])
print("m2x2: ", m2x2)
print("m2x2_2: ", m2x2_2)
print("Wyznacznik 'm2x2': ", m2x2.det())

dodawanie = m2x2 + m2x2_2
print("Dodanie do 'm2x2' macierzy 'm2x2_2':", dodawanie)
odejmowanie = m2x2 - m2x2_2
print("Odejmowanie od 'm2x2' macierzy 'm2x2_2':", odejmowanie)
mnozenie = m2x2 * m2x2_2
print("Mnożenie 'm2x2' i macierzy 'm2x2_2':", mnozenie)

m3x3 = Macierz([[2, 5, 7], [6, 3, 4], [5, -2, -3]])
m3x3_2 = Macierz([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
print("\nm3x3: ", m3x3)
print("m3x3_2: ", m3x3_2)
print("Wyznacznik 'm3x3': ", m3x3.det())

dodawanie = m3x3 + m3x3_2
print("Dodanie do 'm3x3' macierzy 'm3x3_2':", dodawanie)
odejmowanie = m3x3 - m3x3_2
print("Odejmowanie od 'm3x3' macierzy 'm3x3_2':", odejmowanie)
mnozenie = m3x3 * m3x3_2
print("Mnożenie 'm3x3' i macierzy 'm3x3_2':", mnozenie)