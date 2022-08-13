from time import time
from fractions import Fraction


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


print("Unesite broj koji zelite korjenovati:")
broj = float(input())
pocetak_izvrsavanja = time()
print("Kvadratni korijen unesenog broja:", Sqrt(Fraction(broj)))
print("Vrijeme izvrsavanja:", (time() - pocetak_izvrsavanja) * 1000, "milisekundi")

print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
