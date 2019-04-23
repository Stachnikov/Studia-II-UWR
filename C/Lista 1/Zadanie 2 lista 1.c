#include <stdio.h>
#include <stdbool.h>

// Mikolaj Stachnik zadanie 2 lista 1
int potega(float podstawa, float n) //funkcja zwracajaca potege o podstawie podstawa do potegi n
{
    int pow=1;
    if(n==0)
    {
        return 1;
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            pow *= podstawa;
        }
        return pow;
    }
}


bool Czy_palindrom(int liczba, int rewers)  //funkcja sprawdzajaca czy liczba jest palindromem
{
    if(liczba==rewers)
        return 1;
    else
        return 0;
}

int ilosc_cyfr(int liczba)  //funkcja zwracajaca dlugosc liczby
{
    int dlugosc=1;
    while (liczba>9)
    {
        liczba=liczba/10;
        dlugosc++;
    }
    return dlugosc;
}

int cyfra(int n,int k) //funkcja zwracajaca k-ta cyfre od prawej liczby n
{
    int wynik=0;
    for (int i=1; i<k ; i++)
    {
        n=n/10;
    }
    wynik=n%10;
    return wynik;
}

int main()
{
    int a=1,b=1;

    while((a!=0) && (b!=0))
    {
        int rewers=0;
        printf("Podaj liczbe(rozna od zera): \n");
        scanf("%d",&a);
        b=ilosc_cyfr(a);

        if(a!=0 && b!=0)
        {
            int j=b-1;
            for(int i=1;i<=b;i++)   //tworzenie rewersu
            {
                rewers = rewers + (cyfra(a,i)*potega(10,j));
                j--;
            }
            printf("Rewers liczby to: \n"); //wypisuje rewers
            printf("%d",rewers);
            printf("\n\nCzy palindrom: (jezeli 1 - tak, jezeli 0 - nie)\n");    //Sprawdza czy liczba jest palindromem
            printf("%d\n\n",Czy_palindrom(a,rewers));
        }
    }
    return 0;
}
