from math import sin, cos, sqrt, factorial, pi
import random

def a(alfa, beta):
    a = 2 * sin(0.5 * (alfa + beta)) * cos(0.5 * (alfa - beta))
    b = 2 * sin(0.5 * (alfa - beta)) * cos(0.5 * (alfa + beta))
    print("92.\na)")
    print("Dla alfa =", alfa, "oraz beta =", beta)
    print("a =", a, "b =", b)

def b(x, n):
    n1 = [
        (factorial(n) / factorial(n - i)) * x ** (i) / factorial(i)
        for i in range(n + 1)
    ]
    print("\nb)")
    print("Suma ( 1 +" ,x ,")^",n , "wynosi:", sum(n1))

def c(a, b, c):
    delta = b**2 - 4*a*c
    if delta >= 0:
        x1 = (-b + sqrt(delta)) / 2*a
        x2 = (-b - sqrt(delta)) / 2*a
    else:
        x1 = (-b + complex(0, sqrt(-delta))) / (2*a)
        x2 = (-b - complex(0, sqrt(-delta))) / (2*a)
    print("\nc)")
    print("x1 =", x1, "\nx2 =", x2)

def d(x):
    ex = [(x ** i) / factorial(i) for i in range(1000)]
    # python nie obsługuje nieskończoności
    print("\nd)")
    print("e^x =", sum(ex))

def an(n):
    if n == 1:
        return 1
    return an(n - 1) * 3

def bn(n):
    if n == 1:
        return 2
    return bn(n - 1) ** 2

def e(x, n, k, L):
    print("\ne)")
    return 1 + sum(
        [
            an(i) * cos(i * pi * x / L) + bn(i) * sin(i * pi * x * n / L)
            for i in range(1, n)
        ]
    )

a(10, 5)
b(5, 3)
c(1, -4, 3)
d(6)
print(e(10, 10, 10, 10))

