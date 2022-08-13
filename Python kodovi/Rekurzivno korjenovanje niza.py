from math import sqrt
from fractions import Fraction


def korjenovanje_elemenata_niza(a, n, indeks):
    if n == 0:
        print("Lista nema elemenata.")
        exit(-1)
    elif n == 1:
        return sqrt(a[0])
    elif indeks == n - 1:
        return sqrt(a[i])
    else:
        return sqrt(a[indeks] + korjenovanje_elemenata_niza(a, n, indeks + 1))


print("Unesite elemente liste:")
lista = input().split()
for i in range(len(lista)):
    lista[i] = float(lista[i])
index = 0
print("Rezultat je:", korjenovanje_elemenata_niza(lista, len(lista), index))


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

    for j in range(13):
        if abs(inicijalna_pretpostavka) < epsilon:
            break
        rezultat_korjenovanja = konstanta * (inicijalna_pretpostavka + (n / inicijalna_pretpostavka))
        inicijalna_pretpostavka = rezultat_korjenovanja
    return rezultat_korjenovanja.numerator / rezultat_korjenovanja.denominator


def korjenovanje_elemenata_niza2(a, n, indeks):
    if n == 0:
        print("Lista nema elemenata.")
        exit(-1)
    elif n == 1:
        return Sqrt(Fraction(a[0]))
    elif indeks == n - 1:
        return Sqrt(Fraction(a[i]))
    else:
        return Sqrt(Fraction(a[indeks] + korjenovanje_elemenata_niza2(a, n, indeks + 1)))


index = 0
print("Rezultat je:", korjenovanje_elemenata_niza2(lista, len(lista), index))

print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
