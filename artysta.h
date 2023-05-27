#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef ARTYSTA
#define ARTYSTA
/** Struktura daneArtysty
* artysta_id id artysty
* imie przechowuje imie w dynamicznej tablicy znakow
* next wskaznik na nastepny element listy
*/
struct daneArtysty {
	int artysta_id; /**artysta_id id artysty*/
	char* imie;     /** imie przechowuje imie w dynamicznej tablicy znakow */
	char* nazwisko; /*** next wskaznik na nastepny element listy*/
};
/** Struktura artysta jest wezlem listy
* dane przechowuje strukture daneArtsty w liscie
* next wskaznik na nastepny element listy
*/
struct artysta {
    struct daneArtysty* dane;
    struct artysta* next;
};
#endif


struct daneArtysty* znajdzArtyste(struct artysta* lista, int id);
int najwieksze_id_artysta(struct artysta* list);
int nastepneIdArtysty();
struct artysta* alokujArtysta();
struct daneArtysty* alokujDaneArtysty();
struct artysta* dodajArtysteNaPoczatekListy(struct artysta* lista, struct daneArtysty* nowyElement);
struct daneArtysty* utworzNowegoArtyste(void);
void wyswietlArtystow(struct artysta* lista);
struct artysta* wczytajArtystowZPliku();
struct artysta* inicjalizujArtystow();
struct artysta* tworzenieArtystowZKonsoli(struct artysta** listaWszystkichArtystow);
void zapiszArtystowDoPilku(struct artysta* listaArtystow);
struct artysta* polaczListyArtysta(struct artysta* lista, struct artysta* drugaLista);
struct artysta* usunArtysteZListy(struct artysta* listaArtystow, int idDoUsuniecia);
