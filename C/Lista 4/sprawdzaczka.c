#include <stdio.h>

int poczatek[512],koniec[512];

unsigned int czas(int miesiac,int dm,int g,int m, int s)
{
        unsigned int wynik=0;
        wynik=wynik | miesiac;
        wynik=wynik<<5;
        wynik=wynik | dm;
        wynik=wynik<<5;
        wynik=wynik | g;
        wynik=wynik<<6;
        wynik=wynik | m;
        wynik=wynik<<6;
        wynik=wynik | s;
        return wynik;
}

unsigned int getmiesiac(unsigned int liczba)
{
    liczba=liczba>>22;
    return liczba;
}

unsigned int getdzienmiesiaca(unsigned int liczba)
{
    liczba=liczba<<10;
    liczba=liczba>>27;
    return liczba;
}

unsigned int getgodzina(unsigned int liczba)
{
    liczba=liczba<<15;
    liczba=liczba>>27;
    return liczba;
}

unsigned int getminuta(unsigned int liczba)
{
    liczba=liczba<<20;
    liczba=liczba>>26;
    return liczba;
}

unsigned int getsekunda(unsigned int liczba)
{
    liczba=liczba<<26;
    liczba=liczba>>26;
    return liczba;
}

void wczytaj_graczy(int ilosc)
{
    int pm,pdm,pg,pmin,ps;

    for(int i=0;i<ilosc;i++)
    {
            scanf("%d %d %d %d %d",&pm,&pdm,&pg,&pmin,&ps);
            poczatek[i]=czas(pm,pdm,pg,pmin,ps);
            scanf("%d %d %d %d %d",&pm,&pdm,&pg,&pmin,&ps);
            koniec[i]=czas(pm,pdm,pg,pmin,ps);
    }
}

int main()
{
    int g1,g2,g3,g4;
    int gracze;
    int przedzialmax=0,poczmax,konmax,przedzialpp,przedzialkp,przedzialpd,przedzialpt,przedzialpc,przedzialkd,przedzialkt,przedzialkc;

    scanf("%d\n",&gracze);

    wczytaj_graczy(gracze);

    for(int p=0; p<gracze-3;p++)
    {
        przedzialpp=poczatek[p];
        przedzialkp=koniec[p];
        for(int d=p+1;d<gracze-2;d++)
        {
            przedzialpd=przedzialpp;
            przedzialkd=przedzialkp;
            if(poczatek[d]>przedzialkd || koniec[d]<przedzialpd)
                continue;
            if(przedzialpd<poczatek[d])
            {
                przedzialpd=poczatek[d];
            }
            if(przedzialkd>koniec[d])
            {
                przedzialkd=koniec[d];
            }

            for(int t=d+1;t<gracze-1;t++)
            {
                przedzialpt=przedzialpd;
                przedzialkt=przedzialkd;
                if(poczatek[t]>przedzialkt || koniec[t]<przedzialpt)
                    continue;
                if(przedzialpt<poczatek[t])
                {
                    przedzialpt=poczatek[t];
                }
                if(przedzialkt>koniec[t])
                {
                    przedzialkt=koniec[t];
                }

                for(int c=t+1;c<gracze;c++)
                {
                    przedzialpc=przedzialpt;
                    przedzialkc=przedzialkt;
                    if(poczatek[c]>przedzialkc || koniec[c]<przedzialpc)
                        continue;
                    if(przedzialpc<poczatek[c])
                        przedzialpc=poczatek[c];
                    if(przedzialkc>koniec[c])
                        przedzialkc=koniec[c];

                    if(przedzialmax<przedzialkc-przedzialpc)
                    {
                        g1=p;
                        g2=d;
                        g3=t;
                        g4=c;
                        przedzialmax=przedzialkc-przedzialpc;
                        poczmax=przedzialpc;
                        konmax=przedzialkc;
                    }
                }
            }
        }
    }
    if(przedzialmax==0)
        printf("NOT FOUND!");
    else
    {
        printf("%d %d %d %d %d\n",przedzialmax,g4,g3,g2,g1);

        int pm=getmiesiac(poczmax);
        int pdm=getdzienmiesiaca(poczmax);
        int pg=getgodzina(poczmax);
        int pmin=getminuta(poczmax);
        int ps=getsekunda(poczmax);
        printf("%d: %d %d %d %d %d\n",poczmax,pm,pdm,pg,pmin,ps);

        pm=getmiesiac(konmax);
        pdm=getdzienmiesiaca(konmax);
        pg=getgodzina(konmax);
        pmin=getminuta(konmax);
        ps=getsekunda(konmax);
        printf("%d: %d %d %d %d %d",konmax,pm,pdm,pg,pmin,ps);
    }

    return 0;
}
