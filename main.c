/**
\mainpage Temat proejktu: Baza albumow muzycznych.
<h2><b>Politechnika Swietokrzyska</b></h2>
<h3>Kierunek: Informatyka</h3>
<b>Studai stacjonarne I stopnia</b>
<b> Grupa: 1ID16</b>
<b>Tworcy: Wojciech Grelewicz, Adrian Krzeminski, Bartek Wiczorek </b>

*/
#include "album.h"
#include "artysta.h"
#include "gatunek.h"
#include "sortowanie.h"
#include "wyswietl.h"
#include "wyszukiwanie.h"
/**Stala globalna wykorzystywana do pola Stan */
const char* ZAKUPIONY = "Zakupiony";
/**Stala globalna wykorzystywana do pola Stan */
const char* DOZAKUPU = "Do zakupienia";
/**Stala globalna wykorzystywana do pola przesluchany */
const char* TAK = "TAK";
/**Stala globalna wykorzystywana do pola przesluchany */
const char* NIE = "NIE";

/**Zmienna globalna w ktorej przechowywane jest nastepne id,
*  kolejne id jakie zostanie nadane nastepnemu stworzonemu albumowi
 */
int NASTEPNE_ID=1;

/**Stala globalna wykorzystywaia do zapisu i odczytu pliku*/
const char* PLIK_Z_BAZA="baza.csv";




/**
  *  Funkcja, ktora po wczytaniu pliku do listy wyszukuje najwieksze ID albumu z listy
  *  by zachowac kolejnosc tworzonych albumow
  *
  *  parametr lista wskaznik na liste albumow
  *  return zwraca najwieksze znalezione id
*/

int najwieksze_id_album(struct album* list)
{
    if (list == NULL)
    {
        return 0;
    }

    if (list->next == NULL)
    {
        return list->id;
    }

    int najwiekszy_id = list->id;
    struct album* nastepny = list->next;

    while (nastepny != NULL)
    {
        if (nastepny->id > najwiekszy_id)
        {
            najwiekszy_id = nastepny->id;
        }

        nastepny = nastepny->next;
    }

    return najwiekszy_id;
}


/** Funkcja pomocnicza, alokuje miejsce dla struktury album.
 *
 * Funkcja wywoluje malloc, aby zaalokowac odpowiednia ilosc miejsca w pamieci potrzebnego
 * na przechowanie struktury album. Adres zaalokowanego miejsca jest rzutowany na odpowiedni typ.
 *
 * return			wskaznik na nowo zaalokowana pamiec, przeznaczona na przechowanie struct album
 */
struct album* alokujAlbum()
{
    return (struct album*) malloc(sizeof(struct album));
};

/** Funkcja zwraca zainktementowana zmienna globalna NASTEPNE_ID;*/
int nastepne_id()
{
    return NASTEPNE_ID++;
}


/** Funkcja dodaje element na poczatek listy.
 *
 * Funkcja przyjmuje wskaznik na liste oraz dane elementu, ktory ma zostac dodany.
 * Tworzy nowy element, przypisuje dane i wstawia go na poczatek listy ustawiajac jego pole next na podana liste.
 *
 * parametr lista			wskaznik na liste
 * parametr nowyElement	dane elementu ktory ma zostac wstawiony na poczatek listy
 * return 				wskaznik na nowy poczatek listy
 */

struct album* dodaj_element(struct album* lista, struct album* nowyElement)
{
    struct album* temp_stary_poczatek_listy = lista;
    struct album* nowy_poczatek = nowyElement;
    nowy_poczatek->next = temp_stary_poczatek_listy;
    return nowy_poczatek;
}
/**
  * Funkcja wywoluje interatywne menu sluzace do wyboru pola stanu albumu.
  * return zwraca wybrany przez uzytkownika stan(zakupiony, do kupienia).
 */

const char* StanWybor(){
        do{
            printf("Podaj Stan:\n 1.Zakupiony\n 2.Do kupienia\n");
            int wybor;
            scanf("%d",&wybor);

            if(wybor==1){
            return ZAKUPIONY;
        }
        else if(wybor==2){
            return DOZAKUPU;
        }
            else{
             printf("Zle wybrano, wybierz jeszcze raz\n ");
            }

        }while(1);
}
/** Funkcja wywoluje interatywne menu sluzace do wyboru  gatunkow.
*   return zwraca czy album zostal przesluchany (TAK lub NIE).
*/

const char* przesluchanyWybor(){
        do{
            printf("Czy utwor zostal przesluchany?\n 1.TAK\n 2.NIE\n");
            int wybor;
            scanf("%d",&wybor);

            if(wybor==1){

            return TAK;
        }
        else if(wybor==2){

            return NIE;
        }
            else{
             printf("Zle wybrano, wybierz jeszcze raz\n ");
            }

        }while(1);
}
/** Funkcja wywoluje interatywne menu sluzace do wyboru pola albumu, ktore chcemy edytowac.
*   parametr edytowanyElement wskaznik na element do edycji
*   parametr listaWszystkichArtystow wskaznik na pocz¹tek listy wszystkich artystow
*   uzyty "**" poniewaz mozliwe, ze pocz¹tek listy zmieni siê wewnatrz funkcji
*   return zwraca zedytowaæ element
*/

struct album* edytuj(struct album* edytowanyElement,struct artysta** listaWszystkichArtystow)
{
    if(edytowanyElement==NULL)
    {
        printf("\nNie ma elementu\n");
    }
     wyswietl_jeden(edytowanyElement);

    int wybor;
    printf("\nWybierz, ktore pole chcesz edytowac: \n");
    printf("1.Tytul\n");
    printf("2.Artysta\n");
    printf("3.Rok\n");
    printf("4.Gatunek\n");
    printf("5.Stan\n");
    printf("6.Przesluchany\n");
    printf("7.Wroc do menu\n");
    struct gatunekMuzyczny* tempGatunek;
    struct artysta* tempArtysty;
    do
    {
        scanf("%d",&wybor);

        switch(wybor)
        {
        case 1:
            printf("Podaj tytul: ");
            char tytul[50];
            fflush(stdin);
            free(edytowanyElement->tytul);
            scanf("%[^\t\n]",tytul);
            edytowanyElement->tytul=malloc(sizeof(char)*strlen(tytul)+1);
            strcpy(edytowanyElement->tytul,tytul);
            return edytowanyElement;
        case 2:
            printf("Podaj artysta: ");
                 printf("\n1.Dodaj\n2.Usun\n ");
                    scanf("%d",&wybor);
                if(wybor == 1){
                    tempArtysty = tworzenieArtystowZKonsoli(listaWszystkichArtystow);
                        polaczListyArtysta(edytowanyElement->artysci,tempArtysty);
                }
                    else if(wybor == 2){
                        wyswietlArtystowZAlbumu(edytowanyElement->artysci);
                        printf("Wybierz id artysty do usuniecia:\n");
                        scanf("%d", &wybor);

                        edytowanyElement->artysci = usunArtysteZListy(edytowanyElement->artysci, wybor);
						printf("Aktualna lista artystow:\n");
						wyswietlArtystowZAlbumu(edytowanyElement->artysci);
                    }

            return edytowanyElement;
        case 3:
            printf("Podaj rok: ");
            fflush(stdin);
            int licz_buf;
            scanf("%d",&licz_buf);
            edytowanyElement->rok=licz_buf;
            return edytowanyElement;
        case 4:

            do{
                printf("1.Dodaj\n2.Usun\n3.Menu\n");
                scanf("%d",&wybor);

                    if(wybor == 1){
                        tempGatunek = wybierzGatunki();
                        polaczListyGatunku(edytowanyElement->gatunki,tempGatunek);
                    }
                        else if(wybor == 2){
                            wyswietlGatunkiZAlbumu(edytowanyElement->gatunki);
                            edytowanyElement->gatunki = usunGatunekZListy(edytowanyElement->gatunki,wybierzGatunekDoUsuniecia());
                        }
                            else if(wybor == 3){
                                break;
                            }
                                else {
                                     printf("Wprowadzono niepoprawne dane, sprobuj ponownie.\n");
                                }

                }while(1);
            return edytowanyElement;
        case 5:
            printf("Podaj stan: ");
            edytowanyElement->stan = StanWybor();
            return edytowanyElement;
        case 6:
            printf("Podaj przesluchany: ");
            edytowanyElement->przesluchany = przesluchanyWybor();

            return edytowanyElement;
        case 7:
            return edytowanyElement;
        default:
            printf("Podaj prawidlowa wartosc!");
        }
    }
    while(1);
    return edytowanyElement;
}

/** Funkcja pobiera od uzytkownia dane do albumu
*   parametr listaWszystkichArtystow wskaznik na pocz¹tek listy wszystkich artystow
*   uzyty "**" poniewaz mozliwe, ze pocz¹tek listy zmieni siê wewnatrz funkcji
*   return nowo utworzony element.
*/


struct album* dodaj(struct artysta** listaWszystkichArtystow)
{
    system("cls");
    int licz_buf;
    struct album* nowy_el = alokujAlbum();
    fflush(stdin);
    char bufor[50];
    printf("Tytul: ");
    scanf("%[^\t\n]", bufor);
    nowy_el->tytul = malloc(sizeof(char)*strlen(bufor)+1);
    strcpy(nowy_el->tytul, bufor);

    printf("Artysta: \n");
    nowy_el->artysci = tworzenieArtystowZKonsoli(listaWszystkichArtystow);

    printf("Rok: ");
    fflush(stdin);
    scanf("%d", &licz_buf);
    nowy_el->rok = licz_buf;

    printf("Gatunek: ");
    nowy_el->gatunki = wybierzGatunki();

    printf("Stan: ");
    nowy_el->stan = StanWybor();

    printf("Przesluchany: ");
    nowy_el->przesluchany = przesluchanyWybor();

    nowy_el->id=nastepne_id();

    return nowy_el;
}


/** Funkcja usuwa podany przez uzytkownia element
*  lista: przyjmuje wskaznik na liste
*   a: przyjmuje id elementu do usuniecia
*   return zwraca liste pozostalych elementow
*/

struct album* usun_element(struct album* lista,int a)
{

    system("cls");
    struct album* poprzedni = NULL;
    struct album* temp = lista;
    if(lista==NULL)
    {
        printf("Brak elementow na liscie!");
        return NULL;
    }
    while(temp)
    {
        if(temp->id==a)
        {
            if(poprzedni==NULL)
            {
                struct album* nowy_poczatek=temp->next;
                temp->next=NULL;
                return nowy_poczatek;
            }
            else
            {
                poprzedni->next=temp->next;
                temp->next=NULL;
                return lista;
            }
        }
        else
        {
            poprzedni=temp;
            temp=temp->next;
        }
    }
    return NULL;
};

/** Funkcja zapisuje liste albumow do pliku "baza.csv"
 *lista: przyjmuje liste albumow
*/
void zapisz_do_pliku(struct album* lista)
{
    system("cls");


    FILE *baza=fopen(PLIK_Z_BAZA,"w");
    while(lista)
    {
        fprintf(baza,"%d,", lista->id);
        fprintf(baza,"%s,", lista->tytul);


        struct artysta* tempArtysty = lista->artysci;
        fprintf(baza,"%d", tempArtysty->dane->artysta_id);
        tempArtysty = tempArtysty->next;
        while(tempArtysty != NULL)
        {
            fprintf(baza,";%d", tempArtysty->dane->artysta_id);
            tempArtysty = tempArtysty->next;
        }
        fprintf(baza,",");


        fprintf(baza,"%d,",lista->rok);


        struct gatunekMuzyczny* tempGatunku=lista->gatunki;
        fprintf(baza, "%s", tempGatunku->nazwa);
        tempGatunku = tempGatunku -> next;
        while(tempGatunku != NULL)
        {
            fprintf(baza, ";%s", tempGatunku->nazwa);
            tempGatunku = tempGatunku->next;
        }
        fprintf(baza,",");

        fprintf(baza, "%s,", lista->stan);
        fprintf(baza, "%s\n", lista->przesluchany);
        lista = lista->next;
    }
    fclose(baza);
}
/** Funkcja wczytuje z pliku "baza.csv" do listy
 *  parametr: listaArtystow przyjmuje liste wszystkich artystow
 *  return zwraca liste z wczytanymi albumami
*/
struct album* wczytaj_z_pliku(struct artysta* listaArtystow)
{
    int id;
    FILE *baza=fopen(PLIK_Z_BAZA,"r");
    struct album* list_z_pliku=NULL;

    while(fscanf(baza,"%d,",&id)==1)
    {
        struct album* wczytany = alokujAlbum();
        wczytany->id = id;

        char tytul[64];
        fscanf(baza,"%[^,],", tytul);
        wczytany->tytul = malloc(strlen(tytul)*sizeof(char)+1);
        strcpy(wczytany->tytul, tytul);




        char idArtystow[50];
        struct artysta* artysciDoAlbumu = NULL;
        fscanf(baza,"%[^,],", idArtystow);

        char* idArtysty = strtok(idArtystow,";");
        while(idArtysty != NULL )
        {

            int idArtystyJakoInt = atoi(idArtysty);
            struct daneArtysty* wczytanyArtysta = znajdzArtyste(listaArtystow,idArtystyJakoInt);
            if (wczytanyArtysta != NULL)
            {
                artysciDoAlbumu = dodajArtysteNaPoczatekListy(artysciDoAlbumu, wczytanyArtysta);
            }
            else{
                printf("Odczytano niepoprawne dane: nie znaleziono artysty o id %s \n",idArtysty);
            }
            idArtysty = strtok(NULL,";");

        }
        wczytany->artysci = artysciDoAlbumu;

       fscanf(baza,"%d,", &wczytany->rok);

        char gatunek[64];
        struct gatunekMuzyczny* listaGatunkowDoAlbumu = NULL;
        fscanf(baza, "%[^,],", gatunek);
        char* nazwaGatunku = strtok(gatunek, ";");
        while (nazwaGatunku != NULL)         {

           char* zaalokowanaNazwaGatunku = malloc(strlen(nazwaGatunku)*sizeof(char)+1);
            strcpy(zaalokowanaNazwaGatunku, nazwaGatunku);
            listaGatunkowDoAlbumu = dodajGatunek(listaGatunkowDoAlbumu, zaalokowanaNazwaGatunku);

            nazwaGatunku = strtok(NULL,";");
        }
        wczytany->gatunki = listaGatunkowDoAlbumu;



        char stan[64];
        fscanf(baza,"%[^,],",stan);
        wczytany->stan=malloc(strlen(stan)*sizeof(char)+1);
        strcpy(wczytany->stan,stan);

        char przesluchany[64];
        fscanf(baza,"%s\n\r",przesluchany);
        wczytany->przesluchany=malloc(strlen(przesluchany)*sizeof(char)+1);
        strcpy(wczytany->przesluchany,przesluchany);

        wczytany->next=NULL;
        list_z_pliku=dodaj_element(list_z_pliku,wczytany);
    }

    fclose(baza);
    return list_z_pliku;
}

/** Funkcja wywoluje sie wraz ze startem programu,
 *  wczytuje dane z pliku i szuka najwiekszego id
 *  parametr listaArtystow lista wszystkich artystow
 *  return zwraca liste albumow z wczytanymi albumami
*/

struct album* inicjalizuj(struct artysta* listaArtystow)
{
    struct album* lista=wczytaj_z_pliku(listaArtystow);
    NASTEPNE_ID=najwieksze_id_album(lista)+1;
    return lista;
};

/**Funkcja wywoluje glwne menu programu.
 * parametr lista przekazywana jest lista wszystkich albumow
 * parametr listaArtystow przyjmuje liste wszystkich artystow
 * return zwraca liste albumow
*/
struct album* menu(struct album* lista, struct artysta** listaArtystow)
{
    int wybor;
    int bufor;
    char wybor_s[3];
    struct album* dodany;

    printf("\t \nWITAJ W BAZIE ALBUMOW\t\n");
    printf(" 1. Dodaj album\n");
    printf(" 2. Usun album\n");
    printf(" 3. Wyswietl albumy\n");
    printf(" 4. Edytuj\n");
    printf(" 5. Sortuj\n");
    printf(" 6. Szukaj\n");
    printf(" 7. Wyswietl artystow\n");
    printf(" 8. Zapisz i zakoncz\n");
    printf("Wybierz: ");
    fflush(stdin);
    scanf("%d",&wybor);


    switch(wybor)
    {
    case 1:
        dodany = dodaj(listaArtystow);
        printf("\nDODANO:\n");
        wyswietl_jeden(dodany);
        return dodaj_element(lista, dodany);

    case 2:
        system("cls");
        wyswietl(lista);
        printf("podaj id elementu, ktorego chcesz usunac: ");
        scanf("%d",&bufor);
        return usun_element(lista,bufor);
    case 3:
        system("cls");
        wyswietl(lista);
        return lista;
    case 4:
        system("cls");
        do{
        wyswietl(lista);
        printf("Podaj, ktory element chcesz edytowac: ");
        scanf("%s", wybor_s);
        edytuj(znajdz_element(sprawdzCzyIdRowne, lista, wybor_s),listaArtystow);
             printf("\nChcesz edytowac jeszcze?\n1.TAK\n2.NIE\n");
             scanf("%d",&wybor);
                if(wybor!=1){
                    break;
                }
        }while(1);
        return lista;
    case 5:
        system("cls");
        sortowanie(lista);
        wyswietl(lista);
        return lista;
    case 6:
        system("cls");
        wyborDoPolaDoSzukaniaWieluElementow(lista);
        return lista;
    case 7:
        system("cls");
        wyswietlArtystow(*listaArtystow);
        return lista;
    case 8:
        zapisz_do_pliku(lista);
        zapiszArtystowDoPilku(*listaArtystow);
        exit(0);
        break;
    default:
        printf("wybrano nieporawna opcje");
        return lista;
    }

}




int main()
{
    /** zmienna w ktorej jest przechowywany jest poczatek listy artystow */
    struct artysta* listaArtystow = inicjalizujArtystow();
     /**zmienna w ktorej jest przechowywany jest poczatek listy albumow  */
    struct album* lista = inicjalizuj(listaArtystow);
     /**wywolanie funkcji main*/
    while(1)
    {
        lista = menu(lista, &listaArtystow);
    }

    return 0;
}
