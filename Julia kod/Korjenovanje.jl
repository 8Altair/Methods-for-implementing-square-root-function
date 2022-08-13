export PATH;"$PATH:/path/to/<Julia directory>/bin"
#=
Korjenovanje: 1.5.3
- Julia version: 
- Author: Korisnik
- Date: 2021-01-20
=#

x0= 1   # Inicijalna pretpostavka.
f(x) = x^2 - 2  # Funkcija ciji korijen pokusavamo naci.
fprime(x) = 2x  # Derivacija funkcije.
tolerance= 1e-7 # Preciznost na 7 cifri.
epsilon= 1e-14  # Okruzenje.
maxIterations= 20  # Broj iteracija koji je sasvim dovoljan za precizno korjenovanje.
solutionFound = false   # Vrijednost koja nam govori da li je rjesenje konvergiralo.

for i = 1:maxIterations
  y = f(x0)
  yprime = fprime(x0)

  if abs(yprime) < epsilon  # Ako je nazivnik previse mali, odnosno priblizan nuli, onda zaustavljamo petlju.
    break
  end

  global x1 = x0 - y/yprime # Racunanje po Newton-ovoj formuli.

  if abs(x1 - x0) <= tolerance  # Stop when the result is within the desired tolerance
    global solutionFound = true
    break
  end

  global x0 = x1
end

if solutionFound
  println("Solution: ", x1) # Konacno rjesenje.
else
  println("Did not converge")   # Newton-ova metoda nije konvergirala.
end
