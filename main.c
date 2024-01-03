#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "def.h"
#include "game.h"
#include "graphics.h"

// Variables globales de graphics
extern Ecrans ecran;


int main(){
    int taille = 4;
    creation_fenetre();
    VALEUR** tableau = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    VALEUR** tableau_2 = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    init_tableau(taille, tableau);
    init_tableau(taille, tableau_2);
    while (!WindowShouldClose()){
        if (dessin_fenetre(&taille, tableau, tableau_2)){
        	free(tableau);
        	free(tableau_2);
			tableau = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    		tableau_2 = (VALEUR**) malloc(sizeof(VALEUR)*taille*taille);
    		init_tableau(taille, tableau);
    		init_tableau(taille, tableau_2);
    	}
        if (ecran == SOLO || ecran == PUZZLE){
        	jouer(taille, tableau);
        }
		else if (ecran == DUO){
			jouer(taille, tableau);
			jouer(taille, tableau_2);
		}
    }
    free(tableau);
    free(tableau_2);
    CloseWindow();
}

