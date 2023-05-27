#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "album.h"
#include "artysta.h"
#include "gatunek.h"

void wyswietl(struct album *lista);
void wyswietl_jeden(struct album *element);
void wyswietlGatunkiZAlbumu(struct gatunekMuzyczny* gatunki);
void wyswietlArtystowZAlbumu(struct artysta* artysci);
