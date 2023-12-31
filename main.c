#include <stdio.h>
#include "game.h"
#include "graphics.c"


typedef enum {X=-1} VALEUR;

int main(){
    int taille = 4;
    creation_fenetre();
    while (!choix_taille(&taille) && !WindowShouldClose()){}
    VALEUR** tableau = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    VALEUR** tableau_2 = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    while (!WindowShouldClose()){
        dessin_fenetre(taille, VALEUR tableau[][taille], VALEUR tableau_2[][taille]);
    }
}
