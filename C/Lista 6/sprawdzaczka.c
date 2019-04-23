#include <stdio.h>

void sprawdz(int wy, int sz, int tab[wy][sz],int w,int s)
{
    for(int i=w-1;i<=w+1;i++)
    {
        for(int j=s-1;j<=s+1;j++)
        {
            if(i<0 || j<0 || i>w+1 || j>s+1)
                continue;
            if(tab[i][j]==1)
            {
                tab[i][j]=0;
                sprawdz(wy,sz,tab,i,j);
            }
        }
    }
}

int ile_spoj(int s,int w, int tab[w][s])
{
    int ile=0;
    for(int i=0;i<w ;i++)
    {
        for(int j=0;j<s ;j++)
        {
            if(tab[i][j]==1)
            {
                tab[i][j]=0;
                sprawdz(w,s,tab,i,j);
                ile++;
            }
        }
    }
    return ile;
}

int main()
{
    char typ[2];
    int w,s;
    fgets(typ,2*sizeof(typ),stdin);
    scanf("%d %d",&s,&w);
    int tab[w][s];                  //CALKOWITE A NIE BOOL !
    for(int i=0;i<w ;i++)
    {
        for(int j=0;j<s ;j++)
        {
            scanf("%d",&tab[i][j]);
        }
    }

    int x=ile_spoj(s,w,tab);
    printf("%d",x);



    return 0;
}
