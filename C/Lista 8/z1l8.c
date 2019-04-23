#include <stdio.h>
#include <stdlib.h>
//MIKO£AJ STACHNIK  ZADANIE 1 LISTA 8
struct uroj
{
    float a;
    float b;
};

struct uroj dodaj(struct uroj x,struct uroj y)      //DODAWANIE
{
    struct uroj suma;
    suma.a = x.a + y.a;
    suma.b = x.b + y.b;
    return suma;
}

struct uroj odejm(struct uroj x,struct uroj y)      //ODEJMOWANIE
{
    struct uroj roz;
    roz.a=x.a-y.a;
    roz.b=x.b-y.b;
    return roz;
}

struct uroj mno(struct uroj x,struct uroj y)        //MNOZENIE
{
    struct uroj ilo;
    ilo.a=(x.a*y.a)-(x.b*y.b);
    ilo.b=(x.a*y.b)+(x.b*y.a);
    return ilo;
}

void wypisz(int w, int s,struct uroj c)             //WYPISYWANIE
{
    struct uroj zn;
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<s;j++)
        {
            zn.a=(j-(s-1)/2.0)/(0.5*(s-1));         //WYZNACZA CZESC RZECZYWISTA
            zn.b=(i-(w-1)/2.0)/(0.5*(w-1));         //WYZNACZA CZESC UROJONA
            for(int k=0;k<200;k++)
            {
                zn=(odejm(mno(zn,zn),c));           //ITERACJA
            }
            if((zn.a*zn.a) + (zn.b*zn.b)<4)
                printf("O");
            else
                printf(" ");

        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int w=25,s=40 ;
    struct uroj c;
    c.a=0.1;
    c.b=0.83;
    if(argc>2)
    {
        w=atoi(argv[1]);
        s=atoi(argv[2]);
    }
    if(argc>4)
    {
        c.a=atof(argv[3]);
        c.b=atof(argv[4]);
    }
    wypisz(w,s,c);
    return 0;
}
