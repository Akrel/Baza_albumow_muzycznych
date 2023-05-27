#include <stdbool.h>
#include "album.h"


bool sprawdzCzyIdRowne(struct album* element, char idJakoString[]);
bool sprawdzCzyRokRowne(struct album* element, char rokJakoString[]);
bool sprawdzCzyTytulRowne(struct album* element,char tytul[]);
bool sprawdzCzyPosiadaArtysteZawierajacegoPodanyFragment(struct album* element, char* szukanyFragmentImieniaLubNazwiska);
bool sprawdzCzyPosiadaGatunek(struct album* element, char* nazwaGatunku);
struct album* znajdz_element(bool(*rowne)(struct album* element, char* szukane ), struct album* lista, char* str);
bool sprawdzCzyPosiadaArtyste(struct album* element, char* imie, char* nazwisko);
void wyborDoPolaDoSzukania(struct album *lista);
void wyborDoPolaDoSzukaniaWieluElementow(struct album *lista);
