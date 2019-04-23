using System;

namespace pracownia2
{

    class IntStream
    {
        protected int n = -1;

        virtual public int next()
        {
            n += 1;
            return n;
        }

        virtual public bool eos()
        {
            if(n < Int32.MaxValue)
                return true;
            else
                return false;
        }

        virtual public void reset()
        {
            n = -1;
        }
    }


    class PrimeStream : IntStream
    {
        protected int n = 2;

        override public int next()
        {
            while (true)
            {
                bool czypier = true;
                int liczba = n;
                if (liczba == Int32.MaxValue)
                    this.eos();
                for (int k = 2; k <= Math.Sqrt(liczba); k++)
                {
                    if (liczba % k == 0)
                    {
                        czypier = false;
                        break;
                    }
                }

                if (czypier == true)
                {
                    n = liczba + 1;
                    return liczba;
                }
                else
                {
                    n++;
                }
            }
        }

        override public bool eos()
        {
            if (n < Int32.MaxValue)
                return false;
            else
                return true;
        }

        override public void reset()
        {
            n = 2;
        }


    }

    /*class RandomStream : IntStream
    {

        override public int next()
        {
            return n;
        }

        override public bool eos()
        {
            return false;
        }

        override public void reset()
        {
            n = 0;
        }
    }

    class RandomWordStream
    {


    }
    */

    class Program
    {
        static void Main(string[] args)
        {
             IntStream testI = new IntStream();
             for (int i=0; i <20; i++)
             {
                 Console.WriteLine("Liczba : " + testI.next());
             }
             testI.reset();
             Console.WriteLine("RESET");
             for (int i = 0; i < 20; i++)
             {
                 Console.WriteLine("Liczba : " + testI.next());
             }

            Console.WriteLine("PRIMESTREAM:");

            PrimeStream testP = new PrimeStream();

            for (int i = 0; i < 20; i++)
            {
                Console.WriteLine("Liczba : " + testP.next());
            }
            testP.reset();
            Console.WriteLine("RESET");
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Liczba : " + testP.next());
            }
            Console.ReadLine();
        }
    }
}