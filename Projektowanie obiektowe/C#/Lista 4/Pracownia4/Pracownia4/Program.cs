using System;
using System.Collections;

namespace Pracownia4
{
    class Element
    {
        public int val=0;
        public Element next=null;
    }

    class PrimeCollectionEnum : IEnumerator
    {
        Element lista = null;
        //private int current = 1;
        private int current = 2147483400;

        public PrimeCollectionEnum(Element lista)
        {
            this.lista = lista;
        }

        public bool Prime(int val)
        {
            int g = (int)Math.Sqrt(val);
            for (int i = 2; i <= g; i++)
            {
                if (val % i == 0)
                {
                    return false;
                }
            }
            return true;
        }

        public bool MoveNext()
        {
            if (current == Int32.MaxValue)
                throw new SystemException("Przekroczono zakres");
            current++;
            while(Prime(current) == false)
            {
                current++;
            }
            return current <= Int32.MaxValue;
        }

        public object Current
        {
            get
            {
                return current;
            }
        }

        public void Reset()
        {
            current = 1;
        }
    }

    class PrimeCollection : IEnumerable
    {
        Element lista= null;
        int current = 1;


        public IEnumerator GetEnumerator()
        {
            return new PrimeCollectionEnum(lista);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Zaczynamy");
            PrimeCollection pc = new PrimeCollection();
            foreach (int p in pc)
            {
                Console.WriteLine(p);
                Console.ReadLine();
            }
        }
    }
}
