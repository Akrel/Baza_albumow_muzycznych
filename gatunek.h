#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef GATUNEK
#define GATUNEK
/** Struktura gatunek
* nazwa przechowuje nazwe w dynamicznej tablicy znakow
* next wskaznik na nastepny element listy
*/
struct gatunekMuzyczny {
	char* nazwa;
	struct gatunekMuzyczny* next;
};
#endif

void wyswietlListeGatunkow(struct gatunekMuzyczny* lista);


struct gatunekMuzyczny* dodajGatunek(struct gatunekMuzyczny* lista, const char* nazwa) ;
 struct gatunekMuzyczny* wybierzGatunki();
struct gatunekMuzyczny* usunGatunekZListy(struct gatunekMuzyczny* listaGatunkow,const char* nazwaDoUsuniecia);
const char* wybierzGatunekDoUsuniecia();
struct gatunekMuzyczny* polaczListyGatunku(struct gatunekMuzyczny* lista, struct gatunekMuzyczny* drugaLista);
