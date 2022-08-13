from fractions import Fraction


def Sqrt(n):
    if n < 0:
        raise Exception("Korijen negativnog broja nije definisan!")
    if n == 0:
        return 0
    if n == 1:
        return 1

    pocetna_matrica = [[0, 1], [n - 1, 2]]
    rezultujuca_matrica = pocetna_matrica.copy()
    for i in range(100):
        prvi_element = pocetna_matrica[0][1] * rezultujuca_matrica[1][0]
        drugi_element = pocetna_matrica[0][1] * rezultujuca_matrica[1][1]
        treci_element = (pocetna_matrica[1][0] * rezultujuca_matrica[0][0]) + (pocetna_matrica[1][1] *
                                                                               rezultujuca_matrica[1][0])
        cetvrti_element = (pocetna_matrica[1][0] * rezultujuca_matrica[0][1]) + (pocetna_matrica[1][1] *
                                                                                 rezultujuca_matrica[1][1])

        rezultujuca_matrica = [[prvi_element, drugi_element], [treci_element, cetvrti_element]]

    un = rezultujuca_matrica[0][1]
    un1 = rezultujuca_matrica[1][1]
    rezultat_korjenovanja = Fraction((Fraction(un1) / Fraction(un)) - 1)
    return rezultat_korjenovanja.numerator / rezultat_korjenovanja.denominator


print("Unesite broj koji zelite korjenovati:")
broj = float(input())
print("Kvadratni korijen unesenog broja:", Sqrt(broj))

print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
