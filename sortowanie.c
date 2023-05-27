#include "sortowanie.h"
#include "album.h"

/** Funkcja zamienia lementy listy miedzy soba,
*   w wyniku czego przestawia element
* lista1 przyjmuje jeden element listy do zamiany
* lista2 przyjmuje drugi element listy do zamiany
*/
void swap(struct album* lista1, struct album* lista2)
{
    struct album* temp=alokujAlbum();
    temp->id = lista1->id;
    temp->tytul = lista1->tytul;
    temp->gatunki = lista1->gatunki;
    temp->artysci = lista1->artysci;
    temp->rok = lista1->rok;
    temp->stan = lista1->stan;
    temp->przesluchany = lista1->przesluchany;

    lista1->id = lista2->id;
    lista1->tytul = lista2->tytul;
    lista1->gatunki = lista2->gatunki;
    lista1->artysci = lista2->artysci;
    lista1->rok = lista2->rok;
    lista1->stan = lista2->stan;
    lista1->przesluchany = lista2->przesluchany;

    lista2->id = temp->id;
    lista2->tytul = temp->tytul;
    lista2->gatunki = temp->gatunki;
    lista2->artysci = temp->artysci;
    lista2->rok = temp->rok;
    lista2->stan = temp->stan;
    lista2->przesluchany = temp->przesluchany;

    free(temp);
}

/** Funkcja sortujaca
 *  przyjmuje wskaznik na funkcje,ktora  przyjmuje elementy listy
 * lista wskaznik na liste albumow
 */

void sort(int(*porownaj)(struct album* pierwszy, struct album* drugi), struct album* lista)
{
    int zamiana;
    struct album* tempLista;
    if (lista == NULL) {
        return;
    }

    do {
        zamiana=0;
        tempLista = lista;
        while (tempLista->next!=NULL)
        {
            if (porownaj(tempLista, tempLista->next) > 0)
            {
                swap(tempLista->next, tempLista);
                zamiana = 1;
            }
            tempLista = tempLista->next;
        }

    } while(zamiana);
}

/** rosnace */
/**Funkcja sortuj_id_rosnaco porownuje pola id zwraca gdy 1 gdy pierwszy element jest wiekszy od drugiego
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_id_rosnaco(struct album* pierwszy,struct album* drugi)
{
    if (pierwszy->id > drugi->id) {
        return 1;
    } else if(pierwszy->id == drugi->id) {
        return 0;
    } else {
        return -1;
	}
}
/**Funkcja sortuj_rok_rosnaco porownuje pola rok zwraca gdy 1 gdy pierwszy element jest wiekszy od drugiego
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_rok_rosnaco(struct album* pierwszy,struct album* drugi)
{
    if (pierwszy->rok > drugi->rok) {
        return 1;
	} else if (pierwszy->rok == drugi->rok) {
        return 0;
    } else {
        return -1;
	}
}
/**Funkcja sortuj_stan_rosnaco porownuje pola stan za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_stan_rosnaco(struct album* album1, struct album* album2)
{
    return stricmp(album1->stan, album2->stan);
}
/**Funkcja sortuj_przesluchane_rosnaco porownuje pola przesluchany za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_przesluchane_rosnaco(struct album* album1, struct album* album2)
{
    return stricmp(album1->przesluchany, album2->przesluchany);
}
/**Funkcja sortuj_tytul_rosnaco porownuje pola tytul za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_tytul_rosnaco(struct album* album1, struct album* album2)
{
    return stricmp(album1->tytul, album2->tytul);
}
/**Funkcja sortuj_artysta_rosnaco porownuje pola nazwisko za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_artysta_rosnaco(struct album* album1, struct album* album2)
{
    return stricmp(album1->artysci->dane->nazwisko, album2->artysci->dane->nazwisko);
}
/**Funkcja sortuj_gatunek_rosnaco porownuje pola gatunek za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_gatunek_rosnaco(struct album* album1, struct album* album2)
{
    return stricmp(album1->gatunki->nazwa, album2->gatunki->nazwa);
}


/** malejace */
/**Funkcja sortuj_id_malejaco porownuje pola id zwraca gdy -1 gdy pierwszy element jest mniejszy od drugiego
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_id_malejaco(struct album* pierwszy,struct album* drugi)
{
    if (pierwszy->id < drugi->id) {
        return 1;
    } else {
        return -1;
	}

	return 0;
}
/**Funkcja sortuj_rok_malejaco porownuje pola rok zwraca gdy -1 gdy pierwszy element jest mniejszy od drugiego
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_rok_malejaco(struct album* pierwszy,struct album* drugi)
{
    if (pierwszy->rok<drugi->rok) {
        return 1;
	} else {
        return -1;
	}
	return 0;
}

/**Funkcja sortuj_stan_malejaco porownuje pola stan za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_stan_malejaco(struct album* album1,struct album* album2)
{
    return -1 * stricmp(album1->stan, album2->stan);
}
/**Funkcja sortuj_przesluchane_malejaco porownuje pola przesluchany za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_przesluchane_malejaco(struct album* album1,struct album* album2)
{
    return -1 * stricmp(album1->przesluchany, album2->przesluchany);
}
/**Funkcja sortuj_tytul_malejaco porownuje pola tytul za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_tytul_malejaco(struct album* album1,struct album* album2)
{
    return -1 * stricmp(album1->tytul, album2->tytul);
}
/**Funkcja sortuj_artysta_malejaco porownuje pola nazwisko za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_artysta_malejaco(struct album* album1, struct album* album2)
{
    return -1* stricmp(album1->artysci->dane->nazwisko, album2->artysci->dane->nazwisko);
}
/**Funkcja sortuj_gatunek_malejaco porownuje pola gatunek za pomoca funkcji stricmp
* w parametrach przyjmuje elementy do porownania
*/
int sortuj_gatunek_malejaco(struct album* album1, struct album* album2)
{
    return -1* stricmp(album1->gatunki->nazwa, album2->gatunki->nazwa);
}

/**
  * Funkcja wywoluje interatywne menu sluzace do wyboru pola do posortowania rosnacego albumu.
  *parametr lista przyjmuje liste albumow
 */
void rosnace(struct album* lista)
{
    system("cls");
    int wybor;

    printf("WYBIERZ, PO KTORYM POLU CHCESZ SORTOWAC:\n 1.ID\n 2.TYTUL\n 3.ROK\n 4.STAN\n 5.PRZESLUCHANY\n 6.ARTYSTA\n 7.GATUNEK\n 8.MENU\n");


    do
    {
		    char term;
       fflush(stdin);
       int czyPoprawne = scanf("%d%c", &wybor, &term);


		   if (czyPoprawne != 2 || term != '\n') {
		       printf("Bledna opcja, podaj liczbe\n");
	         continue;
        }

		switch (wybor)
        {
        case 1:
            sort(sortuj_id_rosnaco, lista);
            return;
        case 2:
            sort(sortuj_tytul_rosnaco, lista);
            return;
        case 3:
            sort(sortuj_rok_rosnaco, lista);
            return;
        case 4:
            sort(sortuj_stan_rosnaco, lista);
            return;
        case 5:
            sort(sortuj_przesluchane_rosnaco, lista);
            return;
		case 6:
            sort(sortuj_artysta_rosnaco, lista);
            return;
        case 7:
		    sort(sortuj_gatunek_rosnaco, lista);
            return;
		case 8:
			return;
        default:
            printf("Podaj dobre pole!");
        }

    }
    while (1);

}

/**
  * Funkcja wywoluje interatywne menu sluzace do wyboru pola do posortowania malejacego albumu.
  * parametr lista przyjmuje liste albumow
 */
void malejace(struct album* lista)
{
    int wybor;

    printf("WYBIERZ, PO KTORYM POLU CHCESZ SORTOWAC:\n 1.ID\n 2.TYTUL\n 3.ROK\n 4.STAN\n 5.PRZESLUCHANY\n 6.ARTYSTA\n 7.GATUNEK\n 8.MENU\n");

    do
    {
           char term;
       fflush(stdin);
       int czyPoprawne = scanf("%d%c", &wybor, &term);


		   if (czyPoprawne != 2 || term != '\n') {
		       printf("Bledna opcja, podaj liczbe\n");
	         continue;
        }

        switch(wybor)
        {
        case 1:
            sort(sortuj_id_malejaco,lista);
            return;
        case 2:
            sort(sortuj_tytul_malejaco,lista);
            return;
        case 3:
            sort(sortuj_rok_malejaco,lista);
            return;
        case 4:
            sort(sortuj_stan_malejaco,lista);
            return;
        case 5:
            sort(sortuj_przesluchane_malejaco,lista);
            return;
        case 6:
            sort(sortuj_artysta_malejaco, lista);
            return;
        case 7:
		    sort(sortuj_gatunek_malejaco, lista);
            return;
		case 8:
			return;
        default:
            printf("Podaj dobre pole!");
        }

    }
    while (1);
}

/**
  * Funkcja wywoluje interatywne menu sluzace do wyboru w jaki sposob chcemu posortowac dane.
  * parametr lista przyjmuje liste albumow
 */
void sortowanie(struct album* lista)
{
    system("cls");
    int wybor;

    printf("SORTOWANIE:\n 1.ROSNACO\n 2.MALEJACO\n 3.MENU ");

    do
    {
       char term;
       fflush(stdin);
       int czyPoprawne = scanf("%d%c", &wybor, &term);


		   if (czyPoprawne != 2 || term != '\n') {
		       printf("Bledna opcja, podaj liczbe\n");
	         continue;
        }

        switch(wybor)
        {
        case 1:
            rosnace(lista);
            return;
        case 2:
            malejace(lista);
            return;
        case 3:
            return;
        default:
            printf("Podaj dobre pole! ");
        }
    }
    while (1);
}
