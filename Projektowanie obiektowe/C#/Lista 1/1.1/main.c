#include "definitions.h"

int main()
{
    Figura* g[3];
    Figura* f;
    Figura fig1,fig2,fig3;

    fig1= *Kwadrat(0,0,5);
    fig2= *Kolo(14,1,10);
    fig3= *Trojkat(0,4,10,40);

    g[0]=&fig1;
    g[1]=&fig2;
    g[2]=&fig3;

    f=&fig1;
    printf("Pole kwadrat = %f\n",pole(f));
    przesun(f,10,5);
    printf("x = %f y = %f \n",f->x, f->y);

    f=&fig2;
    printf("\nPole kolo = %f\n",pole(f));
    przesun(f,12,2);
    printf("x = %f y = %f \n", f->x, f->y);

    f=&fig3;
    printf("\nPole trojkat = %f\n",pole(f));
    przesun(f,4,7);
    printf("x = %f y = %f \n",f->x, f->y);

    printf("\nSUMA POL = %f ",sumapol(g,3));


    return 0;
}
