#ifndef DEFIN
#define DEFIN

#include <stdio.h>
#include <stdlib.h>

typedef  struct ulamki{
    int licz;
    int mian;
}Ulamki;

    int NWD(int a, int b);
    int NWW(int a, int b);
    void poprawnosc(Ulamki* a);
    Ulamki* dodawanie1(Ulamki a, Ulamki b);
    Ulamki* odejmowanie1(Ulamki a, Ulamki b);
    Ulamki* mnozenie1(Ulamki a, Ulamki b);
    Ulamki* dzielenie1(Ulamki a, Ulamki b);
    void dodawanie2(Ulamki* a,Ulamki* zwroc);
    void odejmowanie2(Ulamki* a,Ulamki* zwroc);
    void mnozenie2(Ulamki* a,Ulamki* zwroc);
    void dzielenie2(Ulamki* a,Ulamki* zwroc);

#endif
