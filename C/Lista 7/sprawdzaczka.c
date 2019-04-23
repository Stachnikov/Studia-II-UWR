#include <stdio.h>

void dokonca()
{
    char enter[10];
    fgets(enter,10,stdin);
}

int czytaj(int n,int m,char tab[n][m])
{
    int ile=0;
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<m;j++)
        {
            scanf("%c",&tab[i][j]);
            if(tab[i][j]=='-')
                ile++;
        }
        dokonca();
    }
    return ile;
}

int zalewasz(int n,int m, char tab[n][m])
{
    int zalane=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( tab[i][j]=='!')
            {
                if(tab[i-1][j]=='-' && (i-1)>=0)
                {
                    tab[i-1][j]='^';
                    zalane++;
                }
                if(tab[i+1][j]=='-' && (i+1)<n)
                {
                    tab[i+1][j]='^';
                    zalane++;
                }
                if(tab[i][j-1]=='-' && (j-1)>=0)
                {
                    tab[i][j-1]='^';
                    zalane++;
                }
                if(tab[i][j+1]=='-' && (j+1)<m)
                {
                    tab[i][j+1]='^';
                    zalane++;
                }
            }
        }
    }
    return zalane;
}

void zmien(int n,int m, char tab[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if( tab[i][j]=='^')
                tab[i][j]='!';
        }
    }
}
void wypisz(int n,int m, char tab[n][m])
{
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<m;j++)
        {
            printf("%c",tab[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n,m,ile,zalane=0,czas=0;
    scanf("%d %d",&n,&m);
    dokonca();
    char tab[n][m];
    ile=czytaj(n,m,tab);
    while((zalane-ile)!=0)
    {
        int czy_zalane=zalane;
        zalane+=zalewasz(n,m,tab);
        czas++;
        zmien(n,m,tab);
        if(czy_zalane==zalane)
        {
            czas=-1;
            break;
        }
    }
    printf("%d",czas);
    return 0;
}