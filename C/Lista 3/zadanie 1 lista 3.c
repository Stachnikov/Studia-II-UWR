#include <stdio.h>

void DrawElip(int x0, int y0, int r)    //RYSOWANIE KOLA
{
    //j==x  i==y
    for(int i=0;i<y0*r;i++)
    {
        for(int j=0;j<x0*r;j++)
        {
            if(((j-x0)*(j-x0) + (i-y0)*(i-y0)) <= r*r)
            {
                putchar('X');
            }
            else
            {
                putchar('.');
            }
        }
        putchar('\n');
    }
}


void DrawRect(int x0, int y0, int w, int h) //RYSOWANIE PROSTOKATA
{
    //j==x  i==y
    for(int i=0;i<=y0+h;i++)
    {
        for(int j=0;j<=x0+w;j++)
        {
            if(j>=x0 && j<x0+w && i>=y0 && i<y0+h)
            {
                    putchar('X');
            }
            else
            {
                    putchar('.');
            }
        }
        putchar('\n');
    }
}


int main()
{
    char znak='c';  // zeby weszlo do petli
    int x=5,y=4,w=2,h=0;
    char napis[1000];
    printf("%s\n","Witaj!");
    printf("%s\n","Oto przyklad kola:");
    DrawElip(x,y ,w);
    while(znak=='r' || znak=='c' || znak=='q')  //sprawdza czy zawiera literke komendy
    {
        fgets (napis, 1000, stdin);
        sscanf(napis,"%c %d %d %d %d",&znak,&x,&y,&w,&h);
        while(znak!='r' && znak!='c' && znak!='q')  //czeka na odpowiednia komende
        {
            fgets (napis, 1000, stdin);
            sscanf(napis,"%c %d %d %d %d",&znak,&x,&y,&w,&h);
        }
        if(znak=='c')   //kolo
        {
            DrawElip(x,y,w);
        }
        else
        {
            if(znak=='r')   //prostokat
            {
                DrawRect(x,y,w,h);
            }
            else
            {
                if(znak=='q')   //wyjscie
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}
