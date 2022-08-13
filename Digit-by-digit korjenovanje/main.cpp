#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int brojac_cifri(unsigned int n)
{
    int brojac(0);
    while (n != 0)
    {
        brojac++;
        n /= 10;
    }
    return brojac;
}

unsigned int izokrenuti_parovi(unsigned int n, bool strana)
{
    unsigned int izokrenuto(0);

    if (brojac_cifri(n) % 2 == 0)   // Slucaj sa parnim brojem cifri.
    {
        while (n != 0)
        {
                const short int zadnja_cifra = n % 100;   // Ne rotira cijeli broj nego parove s lijeva na desno.
                izokrenuto = (izokrenuto * 100) + zadnja_cifra;
                n /= 100;
        }
    }
    else    // Slucaj sa neparnim brojem cifri.
    {
        short int pomocni_brojac(0);
        if (strana == 1)
        {
            while (n != 0)
            {
                if (pomocni_brojac < brojac_cifri(n))
                {
                    const short int zadnja_cifra = n % 100;   // Ne rotira cijeli broj nego parove s lijeva na desno.
                    izokrenuto = (izokrenuto * 100) + zadnja_cifra;
                    n /= 100;
                }
                else
                {
                    const short int zadnja_cifra = n % 10;   // Ne rotira cijeli broj nego parove s lijeva na desno.
                    izokrenuto = (izokrenuto * 10) + zadnja_cifra;
                    n /= 10;
                }
                pomocni_brojac++;
            }
        }
        else
        {
            short int zadnja_cifra;
            zadnja_cifra = n % 10;      // Prvi put se uzima samo jedna cifra jer je neparan broj cifri.
            izokrenuto += zadnja_cifra;     // Nije potreban standardni uslov jer je prvi put "izokrenuto" nula.
            n /= 10;
            while (n != 0)
            {
                if (pomocni_brojac < brojac_cifri(n))
                zadnja_cifra = n % 100;
                izokrenuto = (izokrenuto * 100) + zadnja_cifra;

                n /= 100;
                pomocni_brojac++;
            }
        }
    }
    return izokrenuto;
}

short int pronalazak_cifre_rezultata(unsigned int c, unsigned int p)
{
    short int x;
    for (int i(0); i <= 9; i++)  // Petlja ide od 0 do polovine c, plus 1.
    {
        if (i * (20*p + i) <= c)     // Provjera uslov. x mora odgovarati zadanoj nejednacini.
        {
            x = i;  // Nepoznata x poprima vrijednost od "i" te se petlja nastavlja.
            continue;   // Ako odgovara x, onda se petlja nastavlja.
        }
        else    // Ako x neodgovara, onda se vraća posljednji x.
        {
            return x;
        }
    }
}

string broj_u_string(double broj)
{
    stringstream ss;
    ss << broj;
    string U_string = ss.str();     // Pretvaranje broja u string.
    return U_string;
}

int decimala_u_integer(const double n)    /* Prva ideja je bila preko epsilon okruzenja da se provjerava
                                                            da li je razlika double i int bila zadovoljavajuca, medjutim uglavnom se dešavala beskonacna petlja.
                                                            Interesantno je da isti takav kod radi ispod u funkciji korjenovanja.*/
{
    double decimalni_dio = n - int(n);  // Postavljanje cijelog dijela broja na 0.
    string decimala_kao_integer = broj_u_string(decimalni_dio);

    decimala_kao_integer.erase(0, 2);   // Uklanjanje nule i zareza.
    int integer = stoi(decimala_kao_integer);  // Vracanje stringa u integer.
    return integer;
}

double integer_kao_decimala(string decimalni)     // Racunanje ostatka, odnsono korijena iz decimalnog dijela...
{
    int duzina_stringa = decimalni.length();    // Duzina stringa potrebna za izvrsavanje petlje.
    string Decimalni_sa_nulom("0.");    // Pocetni string sa kojim sa biramo elemente proslidjenog stringa.

    for (int i(0); i < duzina_stringa; i++)
    {
        Decimalni_sa_nulom += decimalni[i];
    }

    double Decimalni;
    Decimalni = stod(Decimalni_sa_nulom);   // Konvertovanje iz stringa u double.

    return Decimalni;
}

void Racunanje_varijabli(long int &trenutna_vrijednost, short int &x, long int &pronadjeni_dio_korijena,
                         long int &jednacina_umanitelja, int &ostatak)
{
    x = pronalazak_cifre_rezultata(trenutna_vrijednost, pronadjeni_dio_korijena);   // Racunanje cifre rezultata.
    jednacina_umanitelja = x * (20*pronadjeni_dio_korijena + x);    // Racunanje dijela kojim se oduzima.
    pronadjeni_dio_korijena = (pronadjeni_dio_korijena * 10) + x;   // Racunanje pomocnog dijela korijena. Ne radi sintaksa "pronadjeni_dio_korijena *= 10 + x".
    ostatak = trenutna_vrijednost - jednacina_umanitelja;   // Racunanje ostatka koji govori da li se algoritam izvrsava dalje.

}

double Sqrt(const double *n)
{
    if (*n < 0) // Ako je uneseni broj negativan.
    {
        throw "Korijen negativnog broja nije definisan u skupu realnih brojeva.";
    }
    else if (*n == 0)   // Korijen iz 0 je 0.
    {
        return 0;
    }
    else if (*n == 1)   // Korijen iz 1 je 1.
    {
        return 1;
    }
    else
    {
        double rezultat_korjenovanja(0);   // Konacni rezultat korjenovanja.

        long int pronadjeni_dio_korijena(0);  // Pomocni broj koji ima svrhu samo u procesu racunanja.
        int ostatak(0); // Ostatak pri oduzimanju.
        long int trenutna_vrijednost(0); // Par sacinjen od cifri plus ostatak.
        long int jednacina_umanitelja; // Sluzi za dobijanje novog ostatka.
        short int x;  // Cifra rezultata korjenovanja.

        const long double epsilon(0.000000000000000000000000000000000001);
        if ((*n - int(*n)) < epsilon and (int(*n) - *n < epsilon))   // Provjera da li se radi samo o prirodnom broju.
        {
            int broj_cifri = brojac_cifri(*n);  // Broj cifri potreban za formiranje parova.
            int broj_u_obrnutom_redoslijedu;

            if (*n > 1 and *n < 10)
            {
                broj_u_obrnutom_redoslijedu = *n;   // U slucaju da je broj jednocifren, nije ga potrebno obrtati.
            }
            else
            {
                broj_u_obrnutom_redoslijedu = izokrenuti_parovi(*n, 1);  // U slucaju da je broj visecifren onda se broj obrce.
            }

            if (broj_cifri % 2 == 0)    // Slucaj u kojem je broj cifri paran.
            {
                for (int i(0); i < broj_cifri / 2; i++) // Jer je paran broj cifri, bice duplo manje parova.
                {
                    trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu % 100);
                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);

                    rezultat_korjenovanja = (rezultat_korjenovanja * 10) + x;   // Ne radi sintaksa "rezultat_korjenovanja *= 10 + x".
                    broj_u_obrnutom_redoslijedu /= 100;
                }

                if (ostatak != 0)
                {
                    string decimalni;      // Decimalni dio zapisan kao integer.
                    short int broj_nepoznatih(0);   // Broj trenutnih decimala.

                    do
                    {
                        trenutna_vrijednost = ostatak * 100;
                        Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);
                        broj_nepoznatih++;

                        string X = broj_u_string(x);
                        decimalni += X;
                        short int x = stoi(X);

                        if (broj_nepoznatih == 6)  // Ako je broj cifri jednak 6 onda se petlja završava jer kasnije cifre malo odstupaju. Isti uslov ne radi u while petlji. Medjutim nekad i sam propgram zavrsi na 5. decimali.
                        {
                            break;
                        }
                    }
                    while (ostatak != 0);   // Ako je broj cifri jednak 10 onda se petlja zavrsava. Isti uslov ne radi u while petlji.


                    rezultat_korjenovanja += integer_kao_decimala(decimalni);  // Iako je granica stavljena na 6. decimalu, uvijek će zaokruzivati na 5 iz nekog razloga.
                }
            }
            else    // Slucaj u kojem je broj cifri neparan.
            {
                for (int i(0); i < (broj_cifri / 2) + 1; i++) // Jer je neparan broj cifri, postoji jedna dodatna iteracija.
                {
                    if (i == 0)
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu % 10);
                    }
                    else
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu % 100);
                    }

                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);

                    rezultat_korjenovanja = (rezultat_korjenovanja * 10) + x;   // Ne radi sintaksa "rezultat_korjenovanja *= 10 + x".

                    if (i == 0)
                    {
                        broj_u_obrnutom_redoslijedu /= 10;
                    }
                    else
                    {
                        broj_u_obrnutom_redoslijedu /= 100;
                    }
                }

                if (ostatak != 0)
                {
                    string decimalni;      // Decimalni dio zapisan kao integer.
                    short int broj_nepoznatih(0);   // Broj trenutnih decimala.

                    do
                    {
                        trenutna_vrijednost = ostatak * 100;
                        Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);
                        broj_nepoznatih++;

                        string X = broj_u_string(x);
                        decimalni += X;
                        short int x = stoi(X);

                        if (broj_nepoznatih == 6)  // Ako je broj cifri jednak 6 onda se petlja zavrsava jer kasnije cifre malo odstupaju i kompajler smatra da je "prevelik" broj. Isti uslov ne radi u while petlji.
                        {
                            break;
                        }
                    }
                    while (ostatak != 0);   // U slucaju da je ostatak nula, petlja se zavrsava.

                    rezultat_korjenovanja += integer_kao_decimala(decimalni);  // Iako je granica stavljena na 6. decimalu, uvijek će zaokruzivati na 5 iz nekog razloga.
                }
            }
        }

        else
        {
            unsigned int cio_dio = int(*n);

            double korijen_cijelog(0);
            int broj_cifri_1 = brojac_cifri(cio_dio);  // Broj cifri potreban za formiranje parova cijelog dijela.
            int broj_u_obrnutom_redoslijedu_1 = izokrenuti_parovi(cio_dio, 1);

            if (broj_cifri_1 % 2 == 0)    // Slucaj u kojem je broj cifri cijelog dijela paran.
            {
                for (int i(0); i < broj_cifri_1 / 2; i++) // Jer je paran broj cifri, biće duplo manje parova.
                {
                    trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_1 % 100);
                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);

                    korijen_cijelog = (korijen_cijelog * 10) + x;
                    broj_u_obrnutom_redoslijedu_1 /= 100;
                }
            }
            else    // Slucaj u kojem je broj cifri cijelog dijela neparan.
            {
                for (int i(0); i < (broj_cifri_1 / 2) + 1; i++) // Jer je neparan broj cifri cijelog dijela, postoji jedna dodatna iteracija.
                {
                    if (i == 0)
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_1 % 10);
                    }
                    else
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_1 % 100);
                    }

                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);

                    korijen_cijelog = (korijen_cijelog * 10) + x;

                    if (i == 0)
                    {
                        broj_u_obrnutom_redoslijedu_1 /= 10;
                    }
                    else
                    {
                        broj_u_obrnutom_redoslijedu_1 /= 100;
                    }
                }
            }

            unsigned int decimalni_kao_cijeli = decimala_u_integer(*n); // Posmatranje decimalnog dijela broj akao integer.
            string korijen_decimalnog;

            int broj_cifri_2 = brojac_cifri(decimalni_kao_cijeli);  // Broj cifri potreban za formiranje parova decimalnog dijela.

            if (broj_cifri_2 % 2 == 0)    // Slučaj u kojem je broj cifri decimalnog dijela paran.
            {
                int broj_u_obrnutom_redoslijedu_2 = izokrenuti_parovi(decimalni_kao_cijeli, 1);
                short int broj_nepoznatih(0);
                int i(0);
                while (ostatak != 0)
                {
                    trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_2 % 100);
                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);
                    broj_nepoznatih++;

                    string X = broj_u_string(x);
                    korijen_decimalnog += X;
                    short int x = stoi(X);

                    broj_u_obrnutom_redoslijedu_2 /= 100;

                    if (broj_nepoznatih == 6)
                    {
                        break;
                    }

                    i++;
                }
            }

            else    // Slučaj u kojem je broj cifri decimalnog dijela neparan.
            {
                int broj_u_obrnutom_redoslijedu_2 = izokrenuti_parovi(decimalni_kao_cijeli, 0);
                short int broj_nepoznatih(0);
                int i(0);
                while (ostatak != 0 or broj_u_obrnutom_redoslijedu_2 != 0)
                {
                    if (i == 0)
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_2 % 10);
                    }
                    else
                    {
                        trenutna_vrijednost = (ostatak * 100) + (broj_u_obrnutom_redoslijedu_2 % 100);
                    }

                    Racunanje_varijabli(trenutna_vrijednost, x, pronadjeni_dio_korijena, jednacina_umanitelja, ostatak);
                    broj_nepoznatih++;

                    string X = broj_u_string(x);
                    korijen_decimalnog += X;
                    short int x = stoi(X);

                    if (i == 0)
                    {
                        broj_u_obrnutom_redoslijedu_2 /= 10;
                    }
                    else
                    {
                        broj_u_obrnutom_redoslijedu_2 /= 100;
                    }

                    if (broj_nepoznatih == 6)
                    {
                        break;
                    }

                    i++;
                }
            }

            rezultat_korjenovanja = korijen_cijelog + integer_kao_decimala(korijen_decimalnog); // Sabira se rezultat od cijelog dijela i decimalnog dijela.
        }

        return rezultat_korjenovanja;
    }
}

int main()
{
    cout << "Unesite broj: ";
    double broj;
    cin >> broj;

    try
    {
        cout << Sqrt(&broj);
    }
    catch (const char poruka[])
    {
        cout << poruka;
    }

    return 0;
}