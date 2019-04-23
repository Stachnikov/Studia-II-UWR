#include "def.h"

int NWD(int a, int b)
{
    int pom;
    while(b!=0)
    {
     pom = b;
     b = a%b;
     a = pom;
    }
    return a;
}

int NWW(int a, int b)
{
    return a/NWD(a,b)*b;
}

void poprawnosc(Ulamki* a){
    if(a->mian<0){
        a->mian *= -1;
        a->licz *= -1;
    }
    if(a->mian==0)
    {
        printf("Mianownik nie moze byc zerem...");
    }
}

Ulamki* dodawanie1(Ulamki a, Ulamki b){

    Ulamki* wynik=malloc(sizeof(Ulamki));

    wynik->mian = NWW(a.mian, b.mian);
    int pom = wynik->licz = wynik->mian/a.mian*a.licz + wynik->mian/b.mian*b.licz;

    wynik->licz /= NWD(pom,wynik->mian);
    wynik->mian /= NWD(pom,wynik->mian);
    poprawnosc(wynik);
    return wynik;
}

Ulamki* odejmowanie1(Ulamki a, Ulamki b){

    Ulamki* wynik=malloc(sizeof(Ulamki));

    wynik->mian = NWW(a.mian, b.mian);
    int pom = wynik->licz = wynik->mian/a.mian*a.licz - wynik->mian/b.mian*b.licz;

    wynik->licz /= NWD(pom,wynik->mian);
    wynik->mian /= NWD(pom,wynik->mian);
    poprawnosc(wynik);

    return wynik;
}

Ulamki* mnozenie1(Ulamki a, Ulamki b){

    Ulamki* wynik=malloc(sizeof(Ulamki));
    wynik->licz=a.licz*b.licz;
    wynik->mian=a.mian*b.mian;

    int n;
    n=NWD(wynik->licz,wynik->mian);
    wynik->licz /= n;
    wynik->mian /= n;
    poprawnosc(wynik);

    return wynik;
}

Ulamki* dzielenie1(Ulamki a, Ulamki b){

    Ulamki* wynik=malloc(sizeof(Ulamki));
    wynik->licz=a.licz*b.mian;
    wynik->mian=a.mian*b.licz;

    int n;
    n=NWD(wynik->licz,wynik->mian);
    wynik->licz /= n;
    wynik->mian /= n;
    poprawnosc(wynik);

    return wynik;
}

void dodawanie2(Ulamki* a,Ulamki* zwroc){

    zwroc->mian = NWW(a->mian, zwroc->mian);
    int pom = zwroc->licz = zwroc->mian/a->mian*a->licz + zwroc->mian/zwroc->mian*zwroc->licz;

    zwroc->licz /= NWD(pom,zwroc->mian);
    zwroc->mian /= NWD(pom,zwroc->mian);
    poprawnosc(zwroc);
}

void odejmowanie2(Ulamki* a,Ulamki* zwroc){

    zwroc->licz=(a->licz*zwroc->mian)-(zwroc->licz*a->mian);
    zwroc->mian=(a->mian*zwroc->mian);

    zwroc->mian = NWW(a->mian, zwroc->mian);
    int pom = zwroc->licz = zwroc->mian/a->mian*a->licz - zwroc->mian/zwroc->mian*zwroc->licz;

    zwroc->licz /= NWD(pom,zwroc->mian);
    zwroc->mian /= NWD(pom,zwroc->mian);
    poprawnosc(zwroc);
}

void mnozenie2(Ulamki* a,Ulamki* zwroc){

    zwroc->licz=a->licz*zwroc->licz;
    zwroc->mian=a->mian*zwroc->mian;

    int n;
    n=NWD(zwroc->licz,zwroc->mian);
    zwroc->licz /= n;
    zwroc->mian /= n;
    poprawnosc(zwroc);
}

void dzielenie2(Ulamki* a,Ulamki* zwroc){

    int pom = zwroc->licz;
    zwroc->licz=a->licz*zwroc->mian;
    zwroc->mian=a->mian*pom;

    int n;
    n=NWD(zwroc->licz,zwroc->mian);
    zwroc->licz /= n;
    zwroc->mian /= n;
    poprawnosc(zwroc);
}
