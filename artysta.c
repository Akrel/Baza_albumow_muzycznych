#include "artysta.h"

/**Zmienna globalna w ktorej przechowywane jest nastepne id,
*  kolejne id jakie zostanie nadane nastepnemu stworzonemu albumowi
 */
const char* PLIK_Z_ARTYSTAMI="artysci.csv";
/**Stala globalna wykorzystywaia do zapisu i odczytu pliku*/
int NASTEPNE_ID_ARTYSTY = 1;

/**
  *  Funkcja, ktora po wczytaniu pliku do listy wyszukuje najwieksze ID albumu z listy
  *  by zachowac kolejnosc tworzonych artystow
  *
  *  parametr lista wskaznik na liste artystow
  *  return zwraca najwieksze znalezione id
*/
int najwieksze_id_artysta(struct artysta* list)
{
    if (list == NULL)
    {
        return 0;
    }

    if (list->next == NULL)
    {
        return list->dane->artysta_id;
    }

    int najwiekszy_id = list->dane->artysta_id;
    struct artysta* nastepny = list->next;

    while (nastepny != NULL)
    {
        if (nastepny->dane->artysta_id > najwiekszy_id)
        {
            najwiekszy_id = nastepny->dane->artysta_id;
        }

        nastepny = nastepny->next;
    }

    return najwiekszy_id;
}

int nastepneIdArtysty()
{
    return NASTEPNE_ID_ARTYSTY++;
}


/**Funkcja pomocnicza, alokuje miejsce dla struktury artysta.
 *
 * Funkcja wywoluje malloc, aby zaalokowac odpowiednia ilosc miejsca w pamieci potrzebnego
 * na przechowanie struktury artysta. Adres zaalokowanego miejsca jest rzutowany na odpowiedni typ.
 *
 * return			wskaznik na nowo zaalokowana pamiec, przeznaczona na przechowanie struct artysta
 */
struct artysta* alokujArtysta() {
	return (struct artysta*) malloc(sizeof(struct artysta));
};


/** Funkcja pomocnicza, alokuje miejsce dla struktury daneArtysty.
 *
 * Funkcja wywoluje malloc, aby zaalokowac odpowiednia ilosc miejsca w pamieci potrzebnego
 * na przechowanie struktury artysta. Adres zaalokowanego miejsca jest rzutowany na odpowiedni typ.
 *
 * return			wskaznik na nowo zaalokowana pamiec, przeznaczona na przechowanie struct daneArtysty
 */
struct daneArtysty* alokujDaneArtysty() {
	return (struct daneArtysty*) malloc(sizeof(struct daneArtysty));
};

/** Funkcja dodaje element na poczatek listy.
 *
 * Funkcja przyjmuje wskaznik na liste oraz dane elementu, ktory ma zostac dodany.
 * Tworzy nowy element, przypisuje dane i wstawia go na poczatek listy ustawiajac jego pole next na podana liste.
 *
 * param lista			wskaznik na liste
 * param nowyElement	dane elementu ktory ma zostac wstawiony na poczatek listy
 * return 				wskaznik na nowy poczatek listy
 */
struct artysta* dodajArtysteNaPoczatekListy(struct artysta* lista, struct daneArtysty* nowyElement) {
  struct artysta* nowyArtysta = alokujArtysta();
  nowyArtysta->dane = nowyElement;
  nowyArtysta->next = lista;
  return nowyArtysta;

};

/** Funkcja pobiera od uzytkownika dane do zapisania do struktury,
  zwraca strukture
 */
struct daneArtysty* utworzNowegoArtyste(void) {
	struct daneArtysty* nowyArtysta = alokujDaneArtysty();
	char bufor[50];                             /** fflush deklaracja bufora na dane wczytane z stdin*/
	fflush(stdin);                              /** czysci bufor wejscia, zeby dane sie poprawnie wczytaly*/

	printf("Podaj imie artysty: ");
	scanf("%[^\t\n]", bufor);
	nowyArtysta->imie = malloc(sizeof(char)*strlen(bufor)+1);
	strcpy(nowyArtysta->imie, bufor);

	printf("Podaj nazwisko: ");
	fflush(stdin);
	scanf("%[^\t\n]",bufor);
	nowyArtysta->nazwisko = malloc(sizeof(char)*strlen(bufor)+1);
	strcpy(nowyArtysta->nazwisko, bufor);

	nowyArtysta->artysta_id = nastepneIdArtysty();

	return nowyArtysta;
};

/** Funkcja wyswietla zawartosc listy artystow,
* parametr lista przyjuje liste artystow
*/
void wyswietlArtystow(struct artysta* lista) {

	if (lista == NULL){
		printf ("LISTA JEST PUSTA\n");
		return;
	}

    printf ("\nLISTA ARTYSTOW\n\n");
	while (lista != NULL)
	{
 		printf("ID: %d\n", lista->dane->artysta_id);
 		printf("IMIE: %s\n", lista->dane->imie);
		printf("NAZWISKO: %s\n\n", lista->dane->nazwisko);
		lista=lista->next;
	}
}

/** Funkcja laczy ze soba stara liste artystow z nowa lista,
*  przypisujac na pole next ostatniego elementu poczatek drugiej listy
*  parametr lista: lista artystow do niej bedzie dolaczana druga lista
*  parametr drugaLista: druga lista bedzie dolaczana do pierwszej listy
*   return zwraca polaczona liste
*/
struct artysta* polaczListyArtysta(struct artysta* lista, struct artysta* drugaLista){
    struct artysta* temp = lista;
    if (temp == NULL) {
    	return drugaLista;
    }

    while (temp) {
            if (temp->next == NULL) {
                temp->next = drugaLista;
                return lista;
            }  else {
                temp = temp->next;
            }
    }
		return lista;
};

/** Funkcja zapisuje liste artystow do pliku "artysci.csv"
 *  parametr lista przyjmuje liste artystow
*/
void zapiszArtystowDoPilku(struct artysta* lista) {
	FILE *baza = fopen(PLIK_Z_ARTYSTAMI, "w");

	if (baza == NULL) {
		printf("Blad otwarcia pliku\n");
		return;
	}

	while (lista) {
		fprintf(baza,"%d,", lista->dane->artysta_id);
		fprintf(baza,"%s,", lista->dane->imie);
		fprintf(baza,"%s\n",lista->dane->nazwisko);
		lista = lista->next;
	}

	fclose(baza);
}
/** Funkcja wczytuje z pliku "artysci.csv" do listy
 *  return zwraca liste z wczytanymi artystami
*/
struct artysta* wczytajArtystowZPliku() {
	FILE * baza = fopen(PLIK_Z_ARTYSTAMI, "r");

	if (baza == NULL) {
		printf("Blad otwarcia pliku\n");
		return NULL;
	}

	int id;
	struct artysta* listaArtystow = NULL;

	while (fscanf(baza,"%d,",&id) == 1) {
		struct daneArtysty* wczytany = alokujDaneArtysty();
		wczytany->artysta_id = id;

		char imie[50];
		fscanf(baza,"%[^,],", imie);
		wczytany->imie = malloc(strlen(imie)*sizeof(char)+1);
		strcpy(wczytany->imie, imie);

		char nazwisko[50];
		fscanf(baza,"%s\r\n", nazwisko);
		wczytany->nazwisko = malloc(strlen(nazwisko)*sizeof(char)+1);
		strcpy(wczytany->nazwisko, nazwisko);


        listaArtystow = dodajArtysteNaPoczatekListy(listaArtystow, wczytany);
	}

	fclose(baza);
	return listaArtystow;

};
/** Funkcja wywoluje sie wraz ze startem programu,
 *  wczytuje dane z pliku i szuka najwiekszego id w liscie artystow
 *  return zwraca liste albumow z wczytanymi artystami
*/
struct artysta* inicjalizujArtystow()
{
    struct artysta* lista = wczytajArtystowZPliku();
    NASTEPNE_ID_ARTYSTY = najwieksze_id_artysta(lista) + 1;
    return lista;
};
/**
 * Funkcja wyszukuje artyste po id
 * lista lista artystow
 * id id artysty do wyszukania
 * zwraca znalezionego artyste
*/
struct daneArtysty* znajdzArtyste(struct artysta* lista, int id) {
    while (lista != NULL) {
        if (lista->dane->artysta_id == id) {
            return lista->dane;
        }
        lista = lista->next;
    }
    return NULL;
}
/** Funkcja pobiera od uzytkownia dane dla artysty
*   parametr listaWszystkichArtystow wskaznik na pocz¹tek listy wszystkich artystow
*   uzyty "**" poniewaz mozliwe, ze pocz¹tek listy zmieni siê wewnatrz funkcji
*   return nowo utworzony element.
*/
struct artysta* tworzenieArtystowZKonsoli(struct artysta** listaWszystkichArtystow) {
	wyswietlArtystow(*listaWszystkichArtystow);

	struct artysta* listaArtystowDoAlbumu = NULL;
	int wybor;

	bool dodanoPrzynajmniejJednego = false;
	while (true) {
        printf("Podaj id artysty, wpisz 0 aby dodac nowego lub -1 aby zakonczyc dodawanie: ");
        scanf("%d", &wybor);
        if (wybor == -1 && dodanoPrzynajmniejJednego) {
            printf("Zakonczono dodawanie artystow. Utworzona lista: \n");
            wyswietlArtystow(listaArtystowDoAlbumu);
            return listaArtystowDoAlbumu;
        } else if (wybor == -1 && !dodanoPrzynajmniejJednego) {
            printf("Wymagane jest dodanie przynajmniej jednego artysty.\n");
        } else if (wybor == 0) {
            struct daneArtysty* dodanyArtysta = utworzNowegoArtyste();
            listaArtystowDoAlbumu = dodajArtysteNaPoczatekListy(listaArtystowDoAlbumu, dodanyArtysta);
            *listaWszystkichArtystow = dodajArtysteNaPoczatekListy(*listaWszystkichArtystow, dodanyArtysta);
            dodanoPrzynajmniejJednego = true;
        } else {

            struct daneArtysty* znaleziony = znajdzArtyste(*listaWszystkichArtystow, wybor);
            if (znaleziony == NULL) {

                printf("Brak artysty o id rownym %d. Sprobuj ponownie.\n", wybor);
            } else {

                printf("Dodano artyste: %s %s\n", znaleziony->imie, znaleziony->nazwisko);
                listaArtystowDoAlbumu = dodajArtysteNaPoczatekListy(listaArtystowDoAlbumu, znaleziony);
                dodanoPrzynajmniejJednego = true;
            }
        }
	}

	return listaArtystowDoAlbumu;
};

/** Funkcja usuwa podanego przez uzytkownia artyste
*   listaArtystow przyjmuje wskaznik na liste artystow
*   idDoUsuniecia przyjmuje id elementu do usuniecia
*   return zwraca liste pozostalych elementow
*/
struct artysta* usunArtysteZListy(struct artysta* listaArtystow, int idDoUsuniecia) {
    struct artysta* temp = listaArtystow;
    struct artysta* poprzedni = NULL;

   while (temp) {
		if (temp->dane->artysta_id == idDoUsuniecia) {
            if (poprzedni == NULL){
                struct artysta* nowypoczatek = temp->next;
                temp->next = NULL;
				free(temp);
                return nowypoczatek;
            } else {
                poprzedni->next = temp->next;
                temp->next = NULL;
                return listaArtystow;
            }
        } else {
            poprzedni = temp;
            temp = temp->next;
        }
   }

    printf("Nie znaleziono artysty o id %d. Nie zmodyfikowano albumu.\n", idDoUsuniecia);
   return listaArtystow;

};


