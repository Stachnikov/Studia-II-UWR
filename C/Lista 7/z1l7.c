#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//MIKOLAJ STACHNIK ZADANIE 1 LISTA 7

typedef struct PtList
{
    float x;
    float y;
    float z;
    char name[36];
    struct PtList * next;
} lista_t;

void wypisz_punkt(lista_t* head)
{
    printf("%f %f %f %s\n",head->x,head->y,head->z,head->name);
}


int main()
{
    char tak[10];
    lista_t * head = NULL;
    head = malloc(sizeof(lista_t));
    if (head == NULL)
    {
        return 1;
    }                                                                       //TWORZENIE LISTY
    scanf("%f %f %f %[^\n]s",&head->x,&head->y,&head->z,head->name);
    head->next=NULL;
    int ile=1;              //ZLICZA ILOSC WCZYTANYCH
    do
    {                                   //CZYTANIE KOLEJNYCH ELEMENTOW
        lista_t* temp=head->next;
        head->next =malloc(sizeof(lista_t));
        head->next->next=temp;
        scanf("%f %f %f %[^\n]s",&head->next->x,&head->next->y,&head->next->z,head->next->name);
        ile++;
    }
    while(!feof(stdin) && (strcmp("KONIEC",head->next->name))!=0);

    printf("\nIlosc wczytanych elementow: %d\n",ile);       //ILOSC WCZYTANYCH ELEMENTOW
    printf("\nPIERWSZY : ");                                //PIERWSZY WCZYTANY ELEMENT
    wypisz_punkt(head);
    printf("\nOSTATNI : ");                                 //OSTATNI WCZYTANY ELEMENT
    wypisz_punkt(head->next);
    printf("\n\nWypisac wszystkie elementy listy...?\n");   //CZY WYPISAC?
    fscanf(stdin,"%s",tak);
    if(strcmp("tak",tak)==0)
    {
        while(head->next!=NULL)             //WYPISYWANIE CALEJ LISTY
        {
            wypisz_punkt(head);
            head=head->next;
        }
        wypisz_punkt(head);
    }


    return 0;
}
