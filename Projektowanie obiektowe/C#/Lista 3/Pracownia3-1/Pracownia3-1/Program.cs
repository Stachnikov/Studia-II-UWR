using System;

namespace Pracownia3_1
{
    public class slownik<K, V> where K : IComparable
    {
        protected K klucz = default(K);
        protected V wartosc = default(V);
        slownik<K, V> nast = null;

        public void dodaj(K klucz, V wartosc)
        {       if(this.nast == null && this.klucz.Equals(default(K)))
                {
                    this.nast = null;
                    this.wartosc = wartosc;
                    this.klucz = klucz;
                }
                else if (this.nast == null && (this.klucz.CompareTo(klucz) < 0))
                {
                    this.nast = new slownik<K, V>();
                    this.nast.klucz = klucz;
                    this.nast.wartosc = wartosc;
                }
                else if(this.nast != null && (this.nast.klucz.CompareTo(klucz) > 0))
                {
                    slownik<K, V> slowniczek = new slownik<K, V>();
                    slowniczek.wartosc = wartosc;
                    slowniczek.klucz = klucz;
                    slowniczek.nast = this.nast;
                    this.nast = slowniczek;
                }
                else if(this.nast != null)
                this.nast.dodaj(klucz, wartosc);
        }

        public V znajdz(K klucz)
        {
            if (this.klucz.Equals(klucz))
            {
                return this.wartosc;
            }
            else if (this.nast != null)
            {
                return this.nast.znajdz(klucz);
            }
            else
            {
                Console.WriteLine("Brak elementu...");
                return default(V);

            }
        }

        public void usun(K klucz)
        {
            if (this.nast.klucz.Equals(klucz))
            {
                this.nast = this.nast.nast;
            }
            else if (this.nast.nast != null)
            {
                this.nast.usun(klucz);
            }
            else
                Console.WriteLine("Nie ma takego elementu...");
        }
    }
}
