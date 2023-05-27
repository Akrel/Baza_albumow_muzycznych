#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gatunek.h"
#include "artysta.h"

#ifndef ALBUM
#define ALBUM
/** Struktura album
* id przechowuje id albumu
* tytul przechowuje tytul w dynamicznej tablicy znakow
* rok przechowuje rok albumu
* gatunekMuzyczny przechowuje lsite gatunkow
* stan przechowuje stan w dynamicznej tablicy znakow
* przesluchany przechowuje przesluchany w dynamicznej tablicy znakow
* next wskaznik na nastepny element listy
*/
struct album
{
    int id;/**id przechowuje id albumu */
    char* tytul;/**tytul przechowuje tytul w dynamicznej tablicy znakow */
    struct artysta* artysci;/**przechowuje liste artystow dla albumu */
    int rok;/**id przechowuje id albumu */
    struct gatunekMuzyczny* gatunki;/**przechowuje liste gatunkow dla albumu */
    char* stan;/**stan przechowuje stan w dynamicznej tablicy znakow */
    char* przesluchany;/**przesluchany przechowuje przesluchany w dynamicznej tablicy znakow */
    struct album* next;/**next wskaznik na nastepny element listy*/
};
#endif


struct album* alokujAlbum();
struct album* dodaj_element(struct album* lista, struct album* elementDoDodania);
void wyswietl_jeden(struct album* element);
void wyswietl(struct album* lista);


