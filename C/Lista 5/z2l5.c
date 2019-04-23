#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//Mikolaj Stachnik zadanie 2 lista 5

FILE *fp;

bool CzyPierwsza(int liczba)    //czy liczba jest liczba pierwsz¹
{
    for(int i = 2; i <=(sqrt(liczba)); i++)
    {
        if(liczba % i == 0)
        {
            return 0;
        }
    }
    if(liczba==1)
        return 0;
    return 1;
}

void piksel(int liczba)     //Jaki piksel
{
    if(CzyPierwsza(liczba)==1)
        fprintf(fp,"255 0 0\n");    //czerwony
    else
        fprintf(fp,"0 0 255\n");     //niebieski
}

void spiral(int n,int wiersz, int argc)
{
    if(wiersz>n)
    {
        for(int i=0; i<n;i++)
        {
            if(argc>2)
                piksel((n+1)*(n+1)-2*(n+1)+2+i);
            printf("%4d",(n+1)*(n+1)-2*(n+1)+2+i);
        }
    }
    else
    {
        if(wiersz==0)
        {
            for(int i=1; i<=n;i++)
            {
                if(argc>2)
                    piksel((n+1)*(n+1)-(n+1)+1-i);
                printf("%4d",(n+1)*(n+1)-(n+1)+1-i);
            }
        }
        else
        {
            if(n%2==0)      //parzysta
            {
                spiral(n-1,wiersz,argc);
                if(argc>2)
                    piksel(n*n-(wiersz-1));
                printf("%4d",n*n-(wiersz-1));
            }
            else
            {
                if(n%2==1)  //nieparzysta
                {
                    if(argc>2)
                        piksel(n*n-n+1+(wiersz-1));
                    printf("%4d",n*n-n+1+(wiersz-1));
                    spiral(n-1,wiersz-1,argc);
                }
            }
        }
    }
}

int main(int argc, char * argv[])
{
    int N=17;   //domyœlna wartosc
    if(argc>1)
    {
        sscanf(argv[1],"%d",&N);    //pobranie N
        if(argc>2)
        {
            fp=fopen(argv[2],"w");
            fprintf(fp,"P3\n");     //naglowek
            fprintf(fp,"%d %d\n",N,N);
            fprintf(fp,"255\n");

        }
        goto spirala;
    }
    else
    {
        spirala:
        for(int i=1; i<=N; i++)
        {
            spiral(N,i,argc);
            if(argc>2)
                fprintf(fp,"\n");
            printf("%c",'\n');
        }
    }
    return 0;
}
