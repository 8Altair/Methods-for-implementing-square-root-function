from fractions import Fraction


def racunanje_veriznog_razlomka(a, r, ite):
    ite += 1
    if ite == 50:
        return 2 * a
    if r == 0:
        return a
    return a + (r / (a + racunanje_veriznog_razlomka(a, r, ite)))


def Sqrt(n):

    if n < 0:
        raise Exception("Korijen negativnog broja nije definisan!")
    if n == 0:
        return 0
    if n == 1:
        return 1
    a = 0
    for i in range(int(n // 2), 0, -1):
        if i ** 2 <= n:
            a = i
            break

    r = n - a ** 2
    iteracija = 0
    rezultat_u_razlomku = racunanje_veriznog_razlomka(Fraction(a), Fraction(r), iteracija)
    return rezultat_u_razlomku.numerator / rezultat_u_razlomku.denominator


print("Unesite broj koji zelite korjenovati:")
broj = float(input())
print("Kvadratni korijen unesenog broja:", Sqrt(broj))

print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
