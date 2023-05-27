#include "wyswietl.h"


/**
* Funkcja wyswietla pojedynczy element listy album
* element przyjmuje element
*/
void wyswietl_jeden(struct album *element)
{
    if(element==NULL)
    {
        return;
    }
    printf("ID: %d\n", element->id);
    printf("TYTUL: %s\n", element->tytul);
    printf("ARTYSTA: ");
    wyswietlArtystowZAlbumu(element->artysci);
    printf("ROK: %d\n", element->rok);
    printf("GATUNEK: ");
    wyswietlGatunkiZAlbumu(element->gatunki);
    printf("STAN: %s\n", element->stan);
    printf("PRZESLUCHANY: %s\n", element->przesluchany);

}


/**
* Funkcja wyswietla zawartosc artystow z albumu.
* element liste artystow albumu
*/
void wyswietlArtystowZAlbumu(struct artysta* artysci)
{
    if (artysci == NULL)
    {
        printf("BRAK ARTYSTOW");
    }

    while (artysci != NULL)
    {
        printf("%d. %s %s, ", artysci->dane->artysta_id, artysci->dane->imie, artysci->dane->nazwisko);
        artysci = artysci->next;
    }
    printf("\n");
}


/**
* Funkcja wyswietla zawartosc gatunku z albumu.
* element liste gatunkow albumu
*/
void wyswietlGatunkiZAlbumu(struct gatunekMuzyczny* gatunki)
{
    if (gatunki == NULL)
    {
        printf("BRAK GATUNKOW");
    }

    while (gatunki != NULL)
    {
        printf("%s  ", gatunki->nazwa);
        gatunki = gatunki->next;
    }
    printf("\n");
}

/**
* Funkcja wyswietla zawartosc listy album.
* przy uzyciu funkcji wyswietl_jeden
* element przyjmuje liste albumow
*/

void wyswietl(struct album *lista)
{
    printf("\nLista albumow: \n");
    if (lista == NULL)
    {
        printf("LISTA JEST PUSTA, DODAJ NOWE ALBUMY\n\n");
    }

    while (lista)
    {
        wyswietl_jeden(lista);
        lista = lista->next;
        printf("\n");
    }
}
