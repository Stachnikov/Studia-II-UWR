#include <stdlib.h>
#include <stdio.h>

// Miko³aj Stachnik zadanie 1 lista 1

int cyfra(int n,int k)
{
    int wynik=0;
    for (int i=1; i<=k ; i++)
    {
        wynik=n%10;
        n=n/10;
    }
    return wynik;
}

int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    if(a!=0 && b!=0)
    {
        for(int i=1;i<=b;i++)
            printf("%d",cyfra(a,i));
        printf("\n");
    }

    while(a!=0 && b!=0)
    {
        scanf("%d",&a);
        scanf("%d",&b);

        for(int i=1;i<=b;i++)
            printf("%d",cyfra(a,i));
        printf("\n");
    }
    return 0;
}
