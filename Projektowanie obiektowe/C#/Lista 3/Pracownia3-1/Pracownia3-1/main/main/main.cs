using System;
using Pracownia3_1;

namespace main
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Slownik: ");
            slownik<int, string> slowniczek = new slownik<int, string>();

            Console.WriteLine("\nDodaje slowo: 1.Pierwszy");
            slowniczek.dodaj(1, "Pierwszy");
            Console.WriteLine("Dodaje slowo: 3.Krzeslo");
            slowniczek.dodaj(3, "Krzeslo");
            Console.WriteLine("Dodaje slowo: 5.Kon");
            slowniczek.dodaj(5, "Kon");
            Console.WriteLine("Dodaje slowo: 4.Baba");
            slowniczek.dodaj(4, "Baba");
            Console.WriteLine("Dodaje slowo: 7.Lizak");
            slowniczek.dodaj(7, "Lizak");

            Console.WriteLine("\nZnajdz element o kluczu 3.");
            Console.WriteLine(slowniczek.znajdz(3));
            Console.WriteLine("\nUsun element o kluczu 3.");
            slowniczek.usun(3);
            Console.WriteLine("\nZnajdz element o kluczu 3.");
            Console.WriteLine(slowniczek.znajdz(3));
            Console.WriteLine("\nUsun element o kluczu 2.");
            slowniczek.usun(2);
            Console.ReadLine();
        }
    }
}
