#include "gatunek.h"
#include "album.h"
/**
* Stala globalna wykorzystywana do struktury gatunek
*/
const char* ROCK = "rock";
const char* METAL = "metal";
const char* POP = "pop";
const char* INDIE = "indie";
const char* BLUES = "blues";
const char* JAZZ = "jazz";
const char* KLASYCZNA = "muzyka klasyczna";
const char* HIPHOP = "hip hop";

/**Funkcja pomocnicza, alokuje miejsce dla struktury gatunek.
 *
 * Funkcja wywoluje malloc, aby zaalokowac odpowiednia ilosc miejsca w pamieci potrzebnego
 * na przechowanie struktury gatunek. Adres zaalokowanego miejsca jest rzutowany na odpowiedni typ.
 *
 * return			wskaznik na nowo zaalokowana pamiec, przeznaczona na przechowanie struct gatunek
 */
struct gatunekMuzyczny* alokujGatunek() {
	return (struct gatunekMuzyczny*) malloc(sizeof(struct gatunekMuzyczny));
}


/** Funkcja wyswietla zawartosc listy gatunkow,
* parametr lista przyjuje liste gatunkow
*/
void wyswietlListeGatunkow(struct gatunekMuzyczny* lista) {
	if (lista == NULL) {
		printf("Brak gatunkow na liscie!\n");
		return;
	}

	printf("Lista gatunkow:\n");
	while(lista != NULL) {
		printf("%s  ", lista->nazwa);
		lista = lista->next;
	}
	printf("\n");
}

/** Funkcja dodaje element na poczatek listy.
 *
 * Funkcja przyjmuje wskaznik na liste oraz dane elementu, ktory ma zostac dodany.
 * Tworzy nowy element, przypisuje dane i wstawia go na poczatek listy ustawiajac jego pole next na podana liste.
 *
 * param lista			wskaznik na liste
 * param nowyElement	dane elementu ktory ma zostac wstawiony na poczatek listy
 * return 				wskaznik na nowy poczatek listy
 */
struct gatunekMuzyczny* dodajGatunek(struct gatunekMuzyczny* lista, const char* nazwa) {
	struct gatunekMuzyczny* gatunek = alokujGatunek();
	gatunek->nazwa = nazwa;
	gatunek->next = lista;
	return gatunek;
}

/** Funkcja laczy ze soba stara liste gatunkow z nowa lista,
*  przypisujac na pole next ostatniego elementu poczatek drugiej listy
*  parametr lista: lista gatunkow do niej bedzie dolaczana druga lista
*  parametr drugaLista: druga lista bedzie dolaczana do pierwszej listy
*   return zwraca polaczona liste
*/
struct gatunekMuzyczny* polaczListyGatunku(struct gatunekMuzyczny* lista, struct gatunekMuzyczny* drugaLista){
    struct gatunekMuzyczny* temp = lista;
    if (temp == NULL) {
    	return drugaLista;
    }
    while(temp) {
            if(temp->next==NULL){
                temp->next = drugaLista;
                return lista;
            }
            else {
                temp = temp->next;
            }
    }

    return lista;

};

/**
  * Funkcja wywoluje interatywne menu sluzace do dodoawania gatunku do struktury .
  * return zwraca liste wybranych gatunkow
 */

struct gatunekMuzyczny* wybierzGatunki() {

	printf("\nDostepne gatunki:\n");
	printf("\t%s: %s\n", "1", ROCK);
	printf("\t%s: %s\n", "2", METAL);
	printf("\t%s: %s\n", "3", POP);
	printf("\t%s: %s\n", "4", INDIE);
	printf("\t%s: %s\n", "5", BLUES);
	printf("\t%s: %s\n", "6", JAZZ);
	printf("\t%s: %s\n", "7", KLASYCZNA);
	printf("\t%s: %s\n", "8", HIPHOP);

	printf("\nWybierz numer:  ");

	int wybor;

	struct gatunekMuzyczny* listaGatunkow = NULL;

	do {
		scanf("%d", &wybor);
		switch (wybor) {
		case 0:
			if (listaGatunkow == NULL) {
				printf("Musisz wybrac przynajmniej jeden gatunek!\n");
				continue;
			}
			printf("Zakonczono dodawanie gatunkow.\n");
			wyswietlListeGatunkow(listaGatunkow);
			return listaGatunkow;
		case 1:
			listaGatunkow = dodajGatunek(listaGatunkow, ROCK);
			break;
		case 2:
			listaGatunkow = dodajGatunek(listaGatunkow, METAL);
			break;
		case 3:
			listaGatunkow = dodajGatunek(listaGatunkow, POP);
			break;
		case 4:
			listaGatunkow = dodajGatunek(listaGatunkow, INDIE);
			break;
		case 5:
			listaGatunkow = dodajGatunek(listaGatunkow, BLUES);
			break;
		case 6:
			listaGatunkow = dodajGatunek(listaGatunkow, JAZZ);
			break;
		case 7:
			listaGatunkow = dodajGatunek(listaGatunkow, KLASYCZNA);
			break;
		case 8:
			listaGatunkow = dodajGatunek(listaGatunkow, HIPHOP);
			break;
		default:
		    printf("Wprowadzono niepoprawne dane, sprobuj ponownie.\n");
			break;

		}


		printf("\nWybierz kolejny numer lub wpisz 0 aby zakonczyc:  ");

	} while (1);


}


/**
  * Funkcja wywoluje interatywne menu sluzace do wyboru gatunku do usuniecia.
  * return gatunek do usuniecia.
 */


const char* wybierzGatunekDoUsuniecia(){
      int wybor;
    printf("Podaj jaki gatunek chcesz edytoac:\n ");
	printf("\t%s: %s\n", "1", ROCK);
	printf("\t%s: %s\n", "2", METAL);
	printf("\t%s: %s\n", "3", POP);
	printf("\t%s: %s\n", "4", INDIE);
	printf("\t%s: %s\n", "5", BLUES);
	printf("\t%s: %s\n", "6", JAZZ);
	printf("\t%s: %s\n", "7", KLASYCZNA);
	printf("\t%s: %s\n", "8", HIPHOP);
do{
    scanf("%d",&wybor);
     switch(wybor){
 case 1:
    return ROCK;
    break;
    case 2:
        return METAL;
        break;
    case 3:
        return POP;
        break;
    case 4:
        return INDIE;
        break;
    case 5:
        return BLUES;
        break;
    case 6:
        return JAZZ;
        break;
    case 7:
        return KLASYCZNA;
        break;
    case 8:
        return HIPHOP;
        break;
    default:
            printf("Wprowadzono niepoprawne dane, sprobuj ponownie.\n");
			break;

	}


		printf("\nWybierz kolejny numer lub wpisz 0 aby zakonczyc:  ");

	} while (1);


    }


/** Funkcja usuwa gatunek z listy gatunkow ze struktury album
  * zwraca liste gatunkow po usunieciu
 */

struct gatunekMuzyczny* usunGatunekZListy(struct gatunekMuzyczny* listaGatunkow,const char* nazwaDoUsuniecia){
    struct gatunekMuzyczny* temp = listaGatunkow;
    struct gatunekMuzyczny* poprzedni = NULL;

   while(temp){
        if(strcmp(nazwaDoUsuniecia,temp->nazwa)==0){

                if(poprzedni == NULL){
                    struct gatunekMuzyczny* nowypoczatek = temp->next;
                    temp->next = NULL;
                    return nowypoczatek;
                }
                    else{
                        poprzedni->next=temp->next;
                        temp->next = NULL;
                        return listaGatunkow;
                    }
        }
            else{
                poprzedni = temp;
                temp = temp->next;
            }
   }
printf ("Nie znaleziono gatunku: %s. Element nie zostal zmodyfikowany.\n", nazwaDoUsuniecia);
   return listaGatunkow;
};





