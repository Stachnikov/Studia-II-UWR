#ifndef DEFINITIONS
#define DEFINITIONS

#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159

typedef enum typ_f {trojkat, kolo, kwadrat} typfig;


typedef  struct figura{
	typfig typ_f;
    float x;
    float y;
    float a; //      (bok kwadratu, podstawa trojkata lub promien kola)
    float h; //      (wysokosc trojkata)
}Figura;

//funkcje
float pole(Figura *f);
void przesun(Figura *f, float x, float y);
float sumapol(Figura *f[], int size);
//inicjalizacje
Figura* Kwadrat(float x, float y, float a);
Figura* Kolo(float x, float y, float a);
Figura* Trojkat(float x, float y, float a, float h);

#endif
