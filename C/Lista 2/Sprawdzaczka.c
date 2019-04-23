#include <stdio.h>
#define MAX 6002 //maksymalna dlugosc wiersza + 2 znaki na koniec wiersza i zero

void kopiuj(char cel[], char zrodlo[])
{
    for (int i = 0; (cel[i] = zrodlo[i]) != '\0'; ++i) ;
}

int czytaj_wiersz(char wiersz[], int max)
{
    int c,i=0;
    for (i = 0; i < max-1 && (c = getchar()) != EOF; ++i)
        if ((wiersz[i] = c) == '\n')
        {
            ++i;
            break;
        }
    wiersz[i] = '\0';
    return i;
}

int porownaj(char wiersz1[], char wiersz2[])
{
    int i=0;
    while(wiersz1[i] == wiersz2[i])
    {
        i++;
        if(wiersz1[i]=='\0')
            return 1;
    }
    return 0;
}

int main()
{
    char poprzedni[MAX]={0};
    char kolejny[MAX]={0};
    czytaj_wiersz(poprzedni,MAX);

    while (czytaj_wiersz(kolejny, MAX))
    {
        if(porownaj(poprzedni,kolejny)==1)
        {
            kopiuj(poprzedni,kolejny);
        }
        else
        {
            printf("%s\n",poprzedni);
            kopiuj(poprzedni,kolejny);
        }
    }

    return 0;
}
