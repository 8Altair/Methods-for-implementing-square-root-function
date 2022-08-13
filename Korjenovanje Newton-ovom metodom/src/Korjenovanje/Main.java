package Korjenovanje;

import java.util.Scanner;

public class Main
{
    static double Sqrt(double n) throws Exception
    {
        if (n < 0)
        {
            throw new Exception("Korijen negativnog broja nije definisan!");
        }
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }

        double rezultat_korjenovanja = 0;
        double inicijalna_pretpostavka = 1;
        double konstanta = 1./2;
        double epsilon = 1.0E-10;

        for (int i = 0; i < 50; i++)
        {
            if (Math.abs(inicijalna_pretpostavka) < epsilon)
            {
                break;
            }
            rezultat_korjenovanja = konstanta * (inicijalna_pretpostavka + (n / inicijalna_pretpostavka));
            inicijalna_pretpostavka = rezultat_korjenovanja;
        }
        return rezultat_korjenovanja;
    }

    public static void main(String[] args) throws Exception
    {

        Scanner input = new Scanner(System.in);

        System.out.print("Unesite broj koji zelite korjenovati: ");
        double broj = input.nextDouble();

        long vrijeme1 = System.nanoTime();
        double korijen = Sqrt(broj);
        long vrijeme2 = System.nanoTime();

        System.out.println("Kvadratni korijen unesenog broja: " + korijen);

        double vrijeme = vrijeme2 - vrijeme1;
        System.out.println("Vrijeme izvrsavanja funkcije: " + (vrijeme / 1000000) + " milisekundi");
    }
}
