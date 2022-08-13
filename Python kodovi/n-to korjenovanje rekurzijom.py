from math import sqrt
from fractions import Fraction


def n_to_korjenovanje(n, m):
    if n < 0:
        print("Korjenovanje kompleksnog broja nije definisano.")
        exit(-1)
    elif n == 0:
        return 0
    elif n == 1:
        return 1
    elif m == n:
        return sqrt(m)
    else:
        return sqrt(m + n_to_korjenovanje(n, m + 1))


print("Unesite broj:")
n = int(input())
m = 1
r = n
print("Rezultat je:", n_to_korjenovanje(n, m))


def Sqrt(n):
    if n < 0:
        raise Exception("Korijen negativnog broja nije definisan!")
    if n == 0:
        return 0
    if n == 1:
        return 1

    rezultat_korjenovanja = 0
    inicijalna_pretpostavka = Fraction(1)
    konstanta = Fraction(1 / 2)
    epsilon = 1.0E-10

    for i in range(13):
        if abs(inicijalna_pretpostavka) < epsilon:
            break
        rezultat_korjenovanja = konstanta * (inicijalna_pretpostavka + (n / inicijalna_pretpostavka))
        inicijalna_pretpostavka = rezultat_korjenovanja
    return rezultat_korjenovanja.numerator / rezultat_korjenovanja.denominator


def n_to_korjenovanje2(r, m):
    if r < 0:
        print("Korjenovanje kompleksnog broja nije definisano.")
        exit(-1)
    elif r == 0:
        return 0
    elif r == 1:
        return 1
    elif m == r:
        return Sqrt(Fraction(m))
    else:
        return Sqrt(Fraction(m + n_to_korjenovanje2(r, m + 1)))

m = 1
print("Rezultat je:", n_to_korjenovanje2(r, m))
print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
