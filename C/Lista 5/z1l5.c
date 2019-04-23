#include <stdio.h>
//Mikolaj Stachnik zadanie 1 lista 5

void spiral(int n,int wiersz)
{
    if(wiersz>n)
    {
        for(int i=0; i<n;i++)
        {
            printf("%4d",(n+1)*(n+1)-2*(n+1)+2+i);
        }
    }
    else
    {
        if(wiersz==0)
        {
            for(int i=1; i<=n;i++)
            {
                printf("%4d",(n+1)*(n+1)-(n+1)+1-i);
            }
        }
        else
        {
            if(n%2==0)      //parzysta
            {
                spiral(n-1,wiersz);
                printf("%4d",n*n-(wiersz-1));
            }
            else
            {
                if(n%2==1)  //nieparzysta
                {
                    printf("%4d",n*n-n+1+(wiersz-1));
                    spiral(n-1,wiersz-1);
                }
            }
        }
    }
}

int main(int argc, char * argv[])
{
    int N=17;   //domyslna wartosc
    if(argc>1)
    {
        sscanf(argv[1],"%d",&N);    //pobranie argumentu N z funkcji main
    }
    for(int i=1; i<=N; i++) //spirala
    {
        spiral(N,i);
        printf("%c",'\n');
    }
    return 0;
}
