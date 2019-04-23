#include "def.h"

int main(){

    Ulamki a,b;
    Ulamki* wynik;
    a.licz=1;
    a.mian=2;
    b.licz=1;
    b.mian=4;

    printf("WERSJA 1:\n");
    wynik=dodawanie1(a,b);
    printf("%d/%d + %d/%d = %d/%d\n",a.licz,a.mian,b.licz,b.mian,wynik->licz,wynik->mian);
    wynik=odejmowanie1(a,b);
    printf("%d/%d - %d/%d = %d/%d\n",a.licz,a.mian,b.licz,b.mian,wynik->licz,wynik->mian);
    wynik=mnozenie1(a,b);
    printf("%d/%d * %d/%d = %d/%d\n",a.licz,a.mian,b.licz,b.mian,wynik->licz,wynik->mian);
    wynik=dzielenie1(a,b);
    printf("%d/%d : %d/%d = %d/%d\n",a.licz,a.mian,b.licz,b.mian,wynik->licz,wynik->mian);


    a.licz=1;
    a.mian=2;
    b.licz=1;
    b.mian=4;
    printf("\nWERSJA 2:\n");
    printf("%d/%d + %d/%d =",a.licz,a.mian,b.licz,b.mian);
    dodawanie2(&a,&b);
    printf(" %d/%d\n",b.licz,b.mian);

    a.licz=1;
    a.mian=2;
    b.licz=1;
    b.mian=4;
    printf("%d/%d - %d/%d =",a.licz,a.mian,b.licz,b.mian);
    odejmowanie2(&a,&b);
    printf(" %d/%d\n",b.licz,b.mian);

    a.licz=1;
    a.mian=2;
    b.licz=1;
    b.mian=4;
    printf("%d/%d * %d/%d =",a.licz,a.mian,b.licz,b.mian);
    mnozenie2(&a,&b);
    printf(" %d/%d\n",b.licz,b.mian);

    a.licz=1;
    a.mian=2;
    b.licz=1;
    b.mian=4;
    printf("%d/%d : %d/%d =",a.licz,a.mian,b.licz,b.mian);
    dzielenie2(&a,&b);
    printf(" %d/%d\n",b.licz,b.mian);
    return 0;

}
