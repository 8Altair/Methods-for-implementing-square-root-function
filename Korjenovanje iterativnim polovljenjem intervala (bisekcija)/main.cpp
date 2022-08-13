#include <iostream>
using namespace std;

long double Sqrt(const double &n)
{
    if (n < 0) throw "Korijen kompleksnog broja nije definisan.";
    else if (n == 0) return 0;
    else if (n == 1) return 1;
    else
    {
        long double c;
        long double a(1);
        long double b(n);
        const long double epsilon(1e-20);
        unsigned short int broj_iteracija(100);

        do
        {
            c = (a + b) / 2;
            if (abs(c * c - n) < epsilon or broj_iteracija == 0) break;
            if ((c * c) > n)
            {
                b = c;
            }
            else if ((c * c) < n)
            {
                a = c;
            }
            broj_iteracija--;
        } while((c * c ) != n);
        return c;
    }
}

int main()
{
    double broj;
    cin >> broj;

    try
    {
        cout << Sqrt(broj);
    }
    catch (const char greska[])
    {
        cout << greska;
    }

    return 0;
}