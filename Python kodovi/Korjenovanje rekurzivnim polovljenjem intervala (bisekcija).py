def rekurzivno_korjenovanje(a, b, n, e):
    c = (a + b) / 2  # Sredina intervala.

    if abs(c * c - n) < e:  # Siguran nacin za ispitivanje "c * c == n".
        return c  # Vraca broj koji predstavlja korijen datog broja.
    elif c * c > n:  # Ako je "c * c" vece od broja kojeg treba korjenovati, onda treba smanjiti supremum intervala.
        b = c  # Kraj intervala je prethodni broj c, dok je pocetak intervala nepromjenjen.
    elif c * c < n:  # Ako je "c * c" manje od broja kojeg treba korjenovati, onda treba povecati infimum intervala.
        a = c  # Pocetak intervala je prethodni broj c, dok je kraj intervala nepromjenjen.

    return rekurzivno_korjenovanje(a, b, n, e)  # Rekurzivni poziv funkcije.


def sqrt(n):
    if n < 0:  # Slucaj kada je broj ispod korijena negativan.
        raise Exception("Korijen negativnog broja nije definisan!")
    elif n == 0:  # Korijen nule je nula.
        return 0
    elif n == 1:  # Korijen nule je nula.
        return 1
    else:  # Korijen broja moja biti drugi broj iz intevrala (1,n).
        a = 1  # Pocetak intervala.
        b = n  # Kraj intervala.
        epsilon = 1.0E-10  # Okruzenje koje zaustavlja polovljenje intervala.
        return rekurzivno_korjenovanje(a, b, n, epsilon)  # Rekurzivno polovljenje intervala, sto je zapravo sami
        # proces korjenovanja.


print("Unesite broj koji zelite korjenovati:")
broj = float(input())
print("Kvadratni korijen unesenog broja:", sqrt(broj))

print("\nPritisnite 'enter' za izlaz:")
izlaz = input()
