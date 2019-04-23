#include <stdio.h>
#include <stdbool.h>
//Mikolaj Stachnik  Zadanie 1 lista 4
typedef unsigned short TypDaty;

TypDaty dzien_t(TypDaty liczba)     //Jaki dzien tygodnia
{
    unsigned short wynik=liczba << 13;
    wynik=wynik >> 13;
    return wynik;
}

TypDaty dzien_m(TypDaty liczba)     //Jaki dzien miesiaca
{
    unsigned short wynik=liczba << 8;
    wynik=wynik >> 11;
    return wynik;
}

TypDaty miesiac(TypDaty liczba)     //Jaki miesiac
{
    unsigned short wynik=liczba << 4;
    wynik=wynik >> 12;
    return wynik;
}

TypDaty rok(TypDaty liczba)     //Jaki rok
{
    unsigned short wynik=liczba >> 12;
    return wynik;
}

bool Miesiac_31(TypDaty x)  //czy miesiac ma 31 dni     x=miesiac(data)
{
    if(x==1 || x==3 || x==5 || x==7 || x==8 || x==10 || x==12)
        return 1;
    else
        return 0;
}

bool bit_jedynka(TypDaty liczba, int k) //czy bit jest jedynka
{
    return liczba & (1 << k);
}

TypDaty BladDaty(TypDaty data)  //Poprawnosc daty
{
    if((dzien_t(data)>=1 && dzien_t(data)<=7) && (miesiac(data)>=1 && miesiac(data)<=12) && (rok(data)>=1 && rok(data)<=12) && ((dzien_m(data)>=1 && dzien_m(data)<=31 && Miesiac_31(miesiac(data))==1) || (dzien_m(data)>=1 && dzien_m(data)<=30 && Miesiac_31(miesiac(data))==0) || (dzien_m(data)>=1 && dzien_m(data)<=28 && miesiac(data)==2)))
    {
            return 0;       //Poprawna
    }
    else
    {
        TypDaty zmiana=data;
        if((dzien_t(data)<1 || dzien_t(data)>7))    //przypisuje 111 polu dzien tygodnia
        {
            zmiana |= (1<<0);
            zmiana |= (1<<1);
            zmiana |= (1<<2);
        }
        if(((dzien_m(data)<1 || dzien_m(data)>31) && Miesiac_31(miesiac(data))==1) || ((dzien_m(data)<1 || dzien_m(data)>30) && Miesiac_31(miesiac(data))==0) || (dzien_m(data)>28 && (miesiac(data)==2)))
        {
            zmiana |= (1<<3);
            zmiana |= (1<<4);
            zmiana |= (1<<5);
            zmiana |= (1<<6);
            zmiana |= (1<<7);
        }
        if(miesiac(data)<1 || miesiac(data)>12)     ////przypisuje 1111 polu miesiac
        {
            zmiana |= (1<<8);
            zmiana |= (1<<9);
            zmiana |= (1<<10);
            zmiana |= (1<<11);
        }
        if(rok(data)<1 || rok(data)>12)     ////przypisuje 1111 polu rok
        {
            zmiana |= (1<<12);
            zmiana |= (1<<13);
            zmiana |= (1<<14);
            zmiana |= (1<<15);
        }
        return zmiana;
    }
}

void WypiszDate(TypDaty data)   //Wypisanie daty
{
    char *DniTyg[]={[1]="pon,",[2]="wto,",[3]="sro,",[4]="czw,",[5]="pia,",[6]="sob,",[7]="nie,"};
    char *Miesiac[]={[1]="sty,",[2]="lut,",[3]="mar,",[4]="kwi,",[5]="maj,",[6]="cze,",[7]="lip,",[8]="sie,",[9]="wrz,",[10]="paz,",[11]="lis,",[12]="gru,"};
    char *Rok[]={[1]="rok malpy(1)",[2]="rok koguta(2)",[3]="rok swini(3)",[4]="rok szczura(4)",[5]="rok tygrysa(5)",[6]="rok krolika(6)",[7]="rok smoka(7)",[8]="rok weza(8)",[9]="rok konia(9)",[10]="rok owcy(10)",[11]="rok kozy(11)",[12]="rok psa(12)"};
    printf("%s %d %s %s\n",DniTyg[dzien_t(data)],dzien_m(data),Miesiac[miesiac(data)],Rok[rok(data)]);
}

int main()
{
    int liczba;
    while(scanf("%d",&liczba) && liczba!=0 && liczba!=EOF)
    {
        TypDaty zmiana=BladDaty(liczba);
        if(zmiana==0)   //Poprawne
            WypiszDate(liczba);
        else
        {
            //sprawdza w ktorym polu jest blad
            if(bit_jedynka(zmiana,0) && bit_jedynka(zmiana,1) && bit_jedynka(zmiana,2) && dzien_t(liczba)!=7)
            {
                printf("Blad w polu dzien tygodnia\n");
            }
            if(bit_jedynka(zmiana,3) && bit_jedynka(zmiana,4) && bit_jedynka(zmiana,5) && bit_jedynka(zmiana,6) && bit_jedynka(zmiana,7))
            {
                printf("Blad w polu dzien miesiaca\n");
            }
            if(bit_jedynka(zmiana,8) && bit_jedynka(zmiana,9) && bit_jedynka(zmiana,10) && bit_jedynka(zmiana,11) && bit_jedynka(zmiana,12))
            {
                printf("Blad w polu miesiac\n");
            }
            if(bit_jedynka(zmiana,13) && bit_jedynka(zmiana,14) && bit_jedynka(zmiana,15))
            {
                printf("Blad w polu rok\n");
            }
        }
    }
    return 0;
}
