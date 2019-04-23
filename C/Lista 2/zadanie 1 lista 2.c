#include <stdio.h>
//Miko³aj Stachnik lista 2 zadanie 1 grupa pon.

int NumInput( int baza)
{
    int c=0,liczba=0;
    char kod=baza+'0';
    c=getchar();
    while ((c<48 || c>=kod) && c!=43 && c!=45)  //pomijanie niedozwolonych znakow
    {
        c=getchar();
    }
    if(c==43 || c ==45)     //sprawdza czy zaczyna sie od + lub -
    c=getchar();
    while (c!=46 && c>=48 && c<kod)    //obliczanie liczby
    {
            liczba=(liczba*(baza))+c-'0';
            c=getchar();
    }
    return liczba;
}

void NumOutput( int baza, int liczba)
{
    if(liczba>0)
    {
        NumOutput(baza,(liczba/baza));
        putchar((liczba%baza)+'0');
    }

}


int main()
{
    int liczba=1;
    while((liczba=NumInput(10))!=0)
    {
        NumOutput(10,liczba);
        putchar('.');
        putchar(' ');
        NumOutput(2,liczba);
        putchar('.');
        putchar('\n');
    }
    return 0;
}
