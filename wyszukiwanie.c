#include "wyszukiwanie.h"
#include "album.h"
/**
* Funkcja porownuje czy id sa rowne .
* element przyjmuje element listy
* idJakoString przyjmuje id jako string i go porownuje z liczba
* zwraca prawde gdy sa rowne false gdy nie
*/

bool sprawdzCzyIdRowne(struct album* element, char idJakoString[])
{
    int id = atoi(idJakoString);
    if (element->id==id)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
* Funkcja porownuje czy rok sa rowne .
* element przyjmuje element listy
* rokJakoString przyjmuje id jako string i go porownuje z liczba
* zwraca true gdy sa rowne false gdy nie
*/
bool sprawdzCzyRokRowne(struct album* element, char rokJakoString[])
{
    int rok = atoi(rokJakoString);
    if (element->rok==rok)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
* Funkcja porownuje czy tytuly sa takie same za pomoca stricmp .
* element przyjmuje element listy
* rokJakoString przyjmuje id jako string i go porownuje z liczba
* zwraca true gdy sa rowne false gdy nie
*/
bool sprawdzCzyTytulRowne(struct album* element,char tytul[])
{
    int wynikPorownania =  stricmp(element->tytul, tytul);

    if (wynikPorownania == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/**
* sprawdza czy element fragment zankow w polu artysta jak podany jak podany za pomoca funkcji stricmp
* element jest elementem listy album
* nazwisko podane nazwisko przez uzytkownika
* zwraca true gdy sa rowne false gdy nie
*/
bool sprawdzCzyPosiadaArtyste(struct album* element, char* imie, char* nazwisko) {
    struct artysta* artysci = element->artysci;

    while (artysci != NULL) {
        int imieRowne = stricmp(artysci->dane->imie, imie);
        int nazwiskoRowne = stricmp(artysci->dane->nazwisko, nazwisko);
        if (imieRowne == 0 && nazwiskoRowne == 0) {
            return true;
        }
        artysci = artysci->next;
    }

    return false;
}

/**
* Funkcja sprawdza za pomoca funkcji strstr czy w danym elemencie znajduje sie artysta o podanym fragmencie
* element przyjmuje element listy album
* szukanyFragmentImieniaLubNazwiska szukany fragment podany przez uzytkownika
*/
bool sprawdzCzyPosiadaArtysteZawierajacegoPodanyFragment(struct album* element, char* szukanyFragmentImieniaLubNazwiska) {
    struct artysta* artysci = element->artysci;

    while (artysci != NULL) {
        char* imieRowne = strstr(artysci->dane->imie, szukanyFragmentImieniaLubNazwiska);
        char* nazwiskoRowne = strstr(artysci->dane->nazwisko, szukanyFragmentImieniaLubNazwiska);
        if (imieRowne != NULL || nazwiskoRowne != NULL) {
            return true;
        }
        artysci = artysci->next;
    }

    return false;
}

/**
* sprawdza czy element fragment zankow w polu gatunek jak podany za pomoca funkcji stricmp
* element jest to elementem listy album
* nazwisko podane nazwisko przez uzytkownika
* zwraca true gdy sa rowne false gdy nie
*/
bool sprawdzCzyPosiadaGatunek(struct album* element, char* nazwaGatunku)
{   struct gatunekMuzyczny* gatunki = element->gatunki;

    while (gatunki != NULL) {
        char* nazwa = gatunki->nazwa;
        int nazwaRowna = stricmp(nazwa, nazwaGatunku);
        if (nazwaRowna == 0) {
            return true;
        }
         gatunki = gatunki->next;
    }

    return false;
}

/**
* Funkcja szuka elementu wybranego w menu ,
* funkcja przyjmuje wskaznik na funkcje
* liste albumow oraz ciag znakow
* poprzez przekazanie odpowiedniej funkcji do funkcji sprawdza zosta³a zworcona wartosc true jesli zwraca liste
* zwraca liste ze znalzionym elementem
*
*/
struct album* znajdz_element(bool(*rowne)(struct album* element, char* szukane ), struct album* lista, char* str)
{
    system("cls");
    while(lista)
    {
        if (rowne(lista,str)==true)
        {
            return lista;
            break;
        }
        else
        {
            lista = lista->next;
        }

    }

    printf("nie znaleziono");
    return NULL;
}

/** Kopiuje album w pamieci ze wszystkimi danymi i referencjami do list innych struktur
* zwraca skopiowany album
*/
struct album* kopiujAlbum(struct album* doSkopiowania) {
    struct album* nowy = alokujAlbum();
    memcpy(nowy, doSkopiowania, sizeof(struct album));
    nowy->next = NULL;
    return nowy;
}
/**Wyszukuja wszystkie albumy, ktore spelniaja wyszukiwanie
* parametrem pierwszym jest wskaznik na funkcjie
* lista albumow
* zwraca znaleziony album
*/
struct album* znajdzWszystkieAlbumy(bool(*rowne)(struct album* element, char* szukane), struct album* lista, char* str)
{
    struct album* znalezioneAlbumy = NULL;
    system("cls");
    while(lista)
    {
        if (rowne(lista,str) == true)
        {

            struct album* znaleziony = kopiujAlbum(lista);
            znalezioneAlbumy = dodaj_element(znalezioneAlbumy, znaleziony);
            break;
        }
        else
        {
            lista = lista->next;
        }

    }


    return znalezioneAlbumy;
}

/** Zwalnia pamiec zuzywana przez tymczasowo budowana liste albumow */

void zwolnijPamiecListy(struct album* lista) {
    if (lista == NULL) {
        return;
    } else if (lista->next == NULL) {
        free(lista);
    } else {
        zwolnijPamiecListy(lista->next);
    }
    return;
}

/**
 *wyszukuje i wywsietla liste elementow ktora pasuje do wprowadzonych danych
 * przujmuje wskzanik na funkcje albumow
*/
void wyborDoPolaDoSzukaniaWieluElementow(struct album *lista)
{
    char bufor[50];
    int wybor;
    printf("WYBIERZ PO KTORYM POLU CHCESZ SZUKAC\n ");
    printf("1.ID\n 2.TYTUL\n 3.ARTYSTA\n 4.ROK\n 5.GATUNEK\n 6.MENU\n");
    scanf("%d", &wybor);
    struct album* znalezione;

    switch(wybor)
    {
    case 1:
        printf("Podaj ID ktore chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n Znalezione istniejace albumy:\n");
        znalezione = znajdzWszystkieAlbumy(sprawdzCzyIdRowne,lista,bufor);
        wyswietl(znalezione);
        zwolnijPamiecListy(znalezione);
        return;
    case 2:
        printf("Podaj TYTUL ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n Znalezione istniejace albumy:\n");
        znalezione = znajdzWszystkieAlbumy(sprawdzCzyTytulRowne,lista,bufor);
        wyswietl(znalezione);
        zwolnijPamiecListy(znalezione);
        return;
    case 3:
        printf("Podaj ARTYSTA ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n Znalezione istniejace albumy:\n");
        znalezione = znajdzWszystkieAlbumy(sprawdzCzyPosiadaArtysteZawierajacegoPodanyFragment,lista,bufor);
        wyswietl(znalezione);
        zwolnijPamiecListy(znalezione);
        return;
    case 4:
        printf("Podaj ROK ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n Znalezione istniejace albumy:\n");
        znalezione = znajdzWszystkieAlbumy(sprawdzCzyRokRowne,lista,bufor);
        wyswietl(znalezione);
        zwolnijPamiecListy(znalezione);
        return;
    case 5:
        printf("Podaj GATUNEK ktory chcesz wyszukac\n");
        scanf("%s", bufor);
        printf("\n Znalezione istniejace albumy:\n");
        znalezione = znajdzWszystkieAlbumy(sprawdzCzyPosiadaGatunek,lista,bufor);
        wyswietl(znalezione);
        zwolnijPamiecListy(znalezione);
        return;
    case 6:
        return;

        break;
    default:
        printf("Wprowadzono niepoprawna opcje. Powrot do menu.\n");
    }

}

/**Funkcja wywoluje interatywne menu sluzace do wyboru pola albumu, ktore chcemy wyszukac.
*   lista: przyjmuje liste albumow
*/
void wyborDoPolaDoSzukania(struct album *lista)
{
    char bufor[50];
    int wybor;
    printf("WYBIERZ PO KTORYM POLU CHCESZ SZUKAC\n ");
    printf("1.ID\n 2.TYTUL\n 3.ARTYSTA\n 4.ROK\n 5.GATUNEK\n 6.MENU\n");
    scanf("%d",&wybor);

    switch(wybor)
    {
    case 1:
        printf("Podaj ID ktore chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n");
        wyswietl_jeden(znajdz_element(sprawdzCzyIdRowne,lista,bufor));
        return;
    case 2:
        printf("Podaj TYTUL ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n");
        wyswietl_jeden(znajdz_element(sprawdzCzyTytulRowne,lista,bufor));
        return;
    case 3:
        printf("Podaj ARTYSTA ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n");
        wyswietl_jeden(znajdz_element(sprawdzCzyPosiadaArtysteZawierajacegoPodanyFragment,lista,bufor));
        return;
    case 4:
        printf("Podaj ROK ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        wyswietl_jeden(znajdz_element(sprawdzCzyRokRowne,lista,bufor));
        return;
    case 5:
        printf("Podaj GATUNEK ktory chcesz wyszukac\n");
        scanf("%s",bufor);
        printf("\n");
        wyswietl_jeden(znajdz_element(sprawdzCzyPosiadaGatunek,lista,bufor));
        return;
    case 6:
        return;

        break;
    }

}
