#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "album.h"


void swap(struct album* lista1,struct album* lista2);

void sort(int(*porownaj)(struct album* pierwszy, struct album* drugi),struct album* lista);
//rosnace
int sortuj_id_rosnaco(struct album* pierwszy,struct album* drugi);

int sortuj_rok_rosnaco(struct album* pierwszy,struct album* drugi);

int sortuj_stan_rosnaco(struct album* album1,struct album* album2);
int sortuj_przesluchane_rosnaco(struct album* album1,struct album* album2);
int sortuj_tytul_rosnaco(struct album* album1,struct album* album2);
//malejace
int sortuj_id_malejaco(struct album* pierwszy,struct album* drugi);

int sortuj_rok_malejaco(struct album* pierwszy,struct album* drugi);

int sortuj_stan_malejaco(struct album* album1,struct album* album2);
int sortuj_przesluchane_malejaco(struct album* album1,struct album* album2);
int sortuj_tytul_malejaco(struct album* album1,struct album* album2);
void rosnace(struct album* lista);
void malejace(struct album* lista);
void sortowanie(struct album* lista);

int sortuj_artysta_rosnaco(struct album* album1, struct album* album2);

int sortuj_gatunek_malejaco(struct album* album1, struct album* album2);
int sortuj_gatunek_rosnaco(struct album* album1, struct album* album2);
