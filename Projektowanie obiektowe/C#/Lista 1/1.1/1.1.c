#include "definitions.h"

Figura* Kwadrat(float x, float y, float a){
    Figura* fig=malloc(sizeof(Figura));
    fig->typ_f=kwadrat;
    if(a>0)
    {
        fig->a=a;
        fig->x=x;
        fig->y=y;
        return fig;
    }
    else
        printf("\n Ujemna wartosc \n Bledne dane...");
        return NULL;
}

Figura* Kolo(float x, float y, float a){
    Figura* fig=malloc(sizeof(Figura));
    fig->typ_f=kolo;
    if(a>0)
    {
        fig->a=a;
        fig->x=x;
        fig->y=y;
        return fig;
    }
    else
        printf("\n Ujemna wartosc \n Bledne dane...");
        return NULL;
}

Figura* Trojkat(float x, float y, float a, float h){
    Figura* fig=malloc(sizeof(Figura));
    fig->typ_f=trojkat;
    if(a>0)
    {
        fig->a=a;
        fig->h=h;
        fig->x=x;
        fig->y=y;
        return fig;
    }
    else
        printf("\n Ujemna wartosc \n Bledne dane...");
        return NULL;
}


float pole(Figura *f)
{
    switch (f->typ_f){
        case kolo:
        {
            return ((f->a)*(f->a)*M_PI) + (0*f->h);
        }
          break;

        case kwadrat:
        {
            return ((f->a)*(f->a))+ (0*f->h);
        }
          break;

        case trojkat:
        {
            return ((f->a)*(f->h))/2.0;
        }
          break;

       default:
        printf("ERROR!");
        return 0;
         break;
    }

}

void przesun(Figura *f, float nx, float ny)
{
	f->x += nx;
	f->y += ny;
}

float sumapol(Figura *f[], int size){
    float suma=0;
    for(int i=0; i<size;i++){
        suma += pole(f[i]);
    }
    return suma;
}
