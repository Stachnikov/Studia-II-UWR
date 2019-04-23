#include <stdio.h>
#include <stdbool.h>
//Mikolaj Stachnik  Zadanie 2 lista 4
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

bool Miesiac_31(TypDaty x)  //czy miesiac ma 31 dni
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
            return 0;
    }
    else
    {
        TypDaty zmiana=data;
        if((dzien_t(data)>7))       //przypisuje 111 polu dzien tygodnia
        {
            zmiana |= (1<<0);
            zmiana |= (1<<1);
            zmiana |= (1<<2);
        }
        if(((dzien_m(data)>31) && Miesiac_31(miesiac(data))==1) || ((dzien_m(data)>30) && Miesiac_31(miesiac(data))==0) || (dzien_m(data)>28 && (miesiac(data)==2)))
        {
            zmiana |= (1<<3);
            zmiana |= (1<<4);
            zmiana |= (1<<5);
            zmiana |= (1<<6);
            zmiana |= (1<<7);
        }
        if(miesiac(data)>12)     //przypisuje 1111 polu miesiac
        {
            zmiana |= (1<<8);
            zmiana |= (1<<9);
            zmiana |= (1<<10);
            zmiana |= (1<<11);
        }
        if(rok(data)>12)         //przypisuje 1111 polu rok
        {
            zmiana |= (1<<12);
            zmiana |= (1<<13);
            zmiana |= (1<<14);
            zmiana |= (1<<15);
        }
        return zmiana;
    }
}

TypDaty ZrobDate(short dt, short d, short m, short rok)
{
    TypDaty wynik=0;
    if(dt>=1 && dt<=7 && m>=1 && m<=12 && rok>=1 && rok<=12 && ((d>=1 && d<=31 && Miesiac_31(m)==1) || ((d>=1 && d<=30 && Miesiac_31(m)==0) && (d>=1 && d<=28 && m==2))))   //jezeli data poprawna
    {
        wynik=wynik | rok;
        wynik=wynik<<4;
        wynik=wynik | m;
        wynik=wynik<<5;
        wynik=wynik | d;
        wynik=wynik<<3;
        wynik=wynik |dt;
        return wynik;
    }
    else
    {
        if(dt>7)    //przypisuje 111 polu dzien tygodnia
            wynik |= (1<<0);
            wynik |= (1<<1);
            wynik |= (1<<2);
        if(((d>31) && Miesiac_31(m)==1) || ((d>30) && Miesiac_31(m)==0) || ((d>28) && m==2))     //przypisuje 11111 polu dzien miesiaca
            wynik |= (1<<3);
            wynik |= (1<<4);
            wynik |= (1<<5);
            wynik |= (1<<6);
            wynik |= (1<<7);
        if(m>12)     //przypisuje 1111 polu miesiac
            wynik |= (1<<8);
            wynik |= (1<<9);
            wynik |= (1<<10);
            wynik |= (1<<11);
        if(rok>12) //przypisuje 1111 polu rok
            wynik |= (1<<12);
            wynik |= (1<<13);
            wynik |= (1<<14);
            wynik |= (1<<15);
        return wynik;
    }
}

int Odleglosc(TypDaty d1, TypDaty d2)
{
    int ile=0,dm,m,r;
    if(d1>d2)           //ustawia tak zeby d1<d2
    {
        int zmien;
        zmien=d1;
        d1=d2;
        d2=zmien;
        goto etykieta;  //przejscie do else
    }
    else
    {
        etykieta:
        dm=dzien_m(d1);
        m=miesiac(d1);
        r=rok(d1);
        while(m!=miesiac(d2) || r!=rok(d2))     //dopoki w obu datach nie zgadzaja sie miesiac i rok wykonuje petle
        {
                if(Miesiac_31(m)==1)    //dla miesiecy ktore maja 31 dni
                {
                    ile=ile+(31-dm)+1;
                    m++;       //przechodzi do kolejnego miesiaca
                    if(m>12)
                    {
                        r++;        // jezeli miesiac przekroczy grudzien zwieksza rok o 1 i miesiac przypisuje 1
                        m=1;
                    }
                    dm=1;
                }
                else
                {
                    if(m==2)        //dla lutego
                    {
                        ile=ile+(28-dm)+1;
                        m++;
                        if(m>12)
                        {
                            r++;
                            m=1;
                        }
                        dm=1;
                    }
                    else
                    {
                        ile=ile+(30-dm)+1;  //dla miesiecy ktore maja 30 dni
                        m++;
                        if(m>12)
                        {
                            r++;
                            m=1;
                        }
                        dm=1;
                    }
                }
            }
            if(m==miesiac(d2) && r==rok(d2)) //sprawdza ostatni miesiac
                ile=ile+(dzien_m(d2)-dm)-1;
        }
    return ile;
}

void WypiszDate(TypDaty data)
{
    char *DniTyg[]={[1]="pon,",[2]="wto,",[3]="sro,",[4]="czw,",[5]="pia,",[6]="sob,",[7]="nie,"};
    char *Miesiac[]={[1]="sty,",[2]="lut,",[3]="mar,",[4]="kwi,",[5]="maj,",[6]="cze,",[7]="lip,",[8]="sie,",[9]="wrz,",[10]="paz,",[11]="lis,",[12]="gru,"};
    char *Rok[]={[1]="rok malpy(1)",[2]="rok koguta(2)",[3]="rok swini(3)",[4]="rok szczura(4)",[5]="rok tygrysa(5)",[6]="rok krolika(6)",[7]="rok smoka(7)",[8]="rok weza(8)",[9]="rok konia(9)",[10]="rok owcy(10)",[11]="rok kozy(11)",[12]="rok psa(12)"};
    printf("%s %d %s %s\n",DniTyg[dzien_t(data)],dzien_m(data),Miesiac[miesiac(data)],Rok[rok(data)]);
}

bool Poprawnosc(TypDaty data)
{
        if((dzien_t(data)>=1 && dzien_t(data)<=7) && (miesiac(data)>=1 && miesiac(data)<=12) && (rok(data)>=1 && rok(data)<=12) && ((dzien_m(data)>=1 && dzien_m(data)<=31 && Miesiac_31(miesiac(data))==1) || (dzien_m(data)>=1 && dzien_m(data)<=30 && Miesiac_31(miesiac(data))==0) || (dzien_m(data)>=1 && dzien_m(data)<=28 && miesiac(data)==2)))
        {
            return 1;
        }
        else
        {   //W ktorym polu blad
            if(bit_jedynka(data,0) && bit_jedynka(data,1) && bit_jedynka(data,2) && dzien_t(data)!=7)
            {
                printf("Blad w polu dzien tygodnia\n");
            }
            if(bit_jedynka(data,3) && bit_jedynka(data,4) && bit_jedynka(data,5) && bit_jedynka(data,6) && bit_jedynka(data,7))
            {
                printf("Blad w polu dzien miesiaca\n");
            }
            if(bit_jedynka(data,8) && bit_jedynka(data,9) && bit_jedynka(data,10) && bit_jedynka(data,11) && bit_jedynka(data,12))
            {
                printf("Blad w polu miesiac\n");
            }
            if(bit_jedynka(data,13) && bit_jedynka(data,14) && bit_jedynka(data,15))
            {
                printf("Blad w polu rok\n");
            }
            return 0;
        }
}


int main()
{
    TypDaty dt1,dt2,dm1,dm2,m1,m2,r1,r2;    //dwie daty skladajace sie z 4 liczb
    while(scanf("%hu %hu %hu %hu",&dt1,&dm1,&m1,&r1) && scanf("%hu %hu %hu %hu",&dt2,&dm2,&m2,&r2) && dt1!=0 && dt2!=0)
    {
        int blad1=0,blad2=0;
        TypDaty data1=ZrobDate(dt1,dm1,m1,r1);
        TypDaty data2=ZrobDate(dt2,dm2,m2,r2);
        if(Poprawnosc(data1)==1)
        {
            WypiszDate(data1);
            printf("%hu %hu %hu %hu\n",dt1,dm1,m1,r1);
        }
        else
            blad1=1;
        if(Poprawnosc(data2)==1)
        {
            WypiszDate(data2);
            printf("%hu %hu %hu %hu\n",dt2,dm2,m2,r2);
        }
        else
            blad2=1;
        if(blad1!=1 && blad2!=1)
        {
            int ile_dni=Odleglosc(data1,data2);
            printf("%s %d\n","Ilosc dni pomiedzy datami: ",ile_dni);
        }
    }
    return 0;
}
