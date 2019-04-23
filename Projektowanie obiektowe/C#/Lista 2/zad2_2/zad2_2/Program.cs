using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zad2_2
{
    class ListaLeniwa
    {
        List<int> tablica = new List<int>();


        virtual public int element(int i)
        {
            
            Random rand = new Random();
            while (tablica.Count <= i && i < 2147483647)
            {
                tablica.Add(rand.Next());
            }
            return tablica[i];

        }

        virtual public int size()
        {
            return tablica.Count;
        }


        

        }

    class Pierwsze : ListaLeniwa
    {
        List<int> pierw = new List<int>();
        int MaxValue = Int32.MaxValue;

        override public int element(int i)
        {
            if (pierw.Count == 0)
            {
                pierw.Add(2);
            }
            int liczba = pierw[pierw.Count - 1] + 1;
            while (pierw.Count <= i)
            {
                bool czypier = true;
                for (int k = 2; k <= Math.Sqrt(liczba); k++)
                {
                    if (liczba % k == 0)
                    {
                        czypier = false;
                        break;
                    }
                }

                if (czypier)
                {
                    pierw.Add(liczba);
                }
                else
                {
                    if (liczba < MaxValue - 1)
                        liczba++;
                    else
                        throw new Exception("BLAD : Liczba z poza zakresu...");
                }
            }

            return pierw[i];

        }

        override public int size()
        {
            return pierw.Count;
        }
    }

    class Program
    {
        public static void Main(string[] args)
        {
            ListaLeniwa lista = new ListaLeniwa();
            Console.WriteLine("LISTA KOLEJNYCH LICZB PIERWSZYCH:");
            for (int i = 8; i < 30; i++)
            {
                Console.WriteLine(" element " + i + " : " + lista.element(i) + "  rozmiar tablicy: " + lista.size());
            }

            Console.WriteLine(" element 10 : " + lista.element(10) + "  rozmiar tablicy: " + lista.size());
            
            Pierwsze pierw = new  Pierwsze();
            Console.WriteLine("LISTA LICZB PIERWSZYCH:");
            for (int i = 0; i < 100; i++)
            {
                Console.WriteLine(" element " + i + " : " + pierw.element(i) + " rozmiar tablicy: " + pierw.size());
            }
            Console.ReadLine();
        } 
    }
}
