#include <stdio.h>
//Mikołaj Stachnik lista 2 zadanie 2 grupa pon.

int silnia (int n)  //obliczanie silni
{
    if (n == 0)
        return 1;
    else
        return n*silnia(n-1);
}

int NumInput( int baza)
{
    int c=0,liczba=0,liczba2=0;
    char kod=10+'0';
    c=getchar();
    while ((c<48 || (c>=kod && c<65) || c>70) && c!=43 && c!=45)    //pomijanie niedozwolonych znkow
    {
        c=getchar();
    }
    if(c==43 || c ==45) //jezeli zaczyna sie od znaku
        c=getchar();
    while (c==46 || ((c>=48 && c<kod) || (baza==16 && c>=65 && c<=70) || c==32 || c=='+' || c=='-' || c=='*' || c=='/' || c=='!'))    //sprawdza czy jest dozowolona cyfra lub znak
    {
        if(c==32 || c=='.')   //pomijanie spacji
        {
            c=getchar();
        }
        else
        {
            if(c=='+')  //DODAWANIE
            {
                c=getchar();
                if(c>=65) //dodawanie cyfry wiekszej od 9
                {
                    liczba2=(liczba2*(baza))+(c-55);
                    c=getchar();
                }
                else    //dodawanie cyfr od 0 do 9
                {
                    liczba2=(liczba2*(baza))+c-'0';
                    c=getchar();
                }
                return liczba + liczba2;
            }
            if(c=='-')  //ODEJMOWANIE
            {
                c=getchar();
                if(c>=65) //dodawanie cyfry wiekszej od 9
                {
                    liczba2=(liczba2*(baza))+(c-55);
                    c=getchar();
                }
                else    //dodawanie cyfr od 0 do 9
                {
                    liczba2=(liczba2*(baza))+c-'0';
                    c=getchar();
                }
                return liczba - liczba2;
            }
            if(c=='*')  //Mno¿enie
            {
                c=getchar();
                if(c>=65) //dodawanie cyfry wiekszej od 9
                {
                    liczba2=(liczba2*(baza))+(c-55);
                    c=getchar();
                }
                else    //dodawanie cyfr od 0 do 9
                {
                    liczba2=(liczba2*(baza))+c-'0';
                    c=getchar();
                }
                return liczba * liczba2;
            }
            if(c=='/')  //DZIELENIE
            {
                c=getchar();
                if(c>=65) //dodawanie cyfry wiekszej od 9
                {
                    liczba2=(liczba2*(baza))+(c-55);
                    c=getchar();
                }
                else    //dodawanie cyfr od 0 do 9
                {
                    liczba2=(liczba2*(baza))+c-'0';
                    c=getchar();
                }
                return liczba / liczba2;
            }
            if(c=='!')  //SILNIA
            {
                return silnia(liczba);
            }
            if(c>=65) //dodawanie cyfry wiekszej od 9
            {
                liczba=(liczba*(baza))+(c-55);
                c=getchar();
            }
            else    //dodawanie cyfr od 0 do 9
            {
                liczba=(liczba*(baza))+c-'0';
                c=getchar();
            }
        }
    }
    return liczba;
}

void NumOutput( int baza, int liczba)
{
    if(liczba>0)
    {
        if(liczba%baza>9)
        {
            NumOutput(baza,(liczba/baza));
            putchar((liczba%baza)+55);
        }
        else
        {
            NumOutput(baza,(liczba/baza));
            putchar((liczba%baza)+'0');
        }
    }
}


int main()
{
    int liczba=1;
    while((liczba=NumInput(16))!=0)
    {
        NumOutput(16,liczba);
        putchar('.');
        putchar('\n');
    }
    return 0;
}
