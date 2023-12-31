#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

/* DEFINITION D'ENUM */
typedef enum {X=-1} VALEUR;

typedef enum Ecrans {
    MENU = 0,
    SOLO,
    DUO,
    PUZZLE
} Ecrans;

/* VARIABLES GLOBALES*/
Vector2 positionSouris;
Ecrans ecran = MENU;

/* DEFINITION DE FONCTIONS */

void creation_fenetre(){
    InitWindow(LARGEUR_ECRAN, LONGUEUR_ECRAN, "menu selection d'ecran");
    SetTargetFPS(60);
}

void affichage_matrice(int taille, VALEUR matrice[][taille], int decallage){

    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            
            if(matrice[i][j] == 0){

                DrawRectangle(decallage + i*TAILLE_CARRE, j*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, LIGHTGRAY);

            }else if(matrice[i][j] == X){

                DrawText("X", decallage + i*TAILLE_CARRE, j*TAILLE_CARRE,TAILLE_POLICE, PURPLE);
                DrawRectangle(decallage + i*TAILLE_CARRE, j*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, MAGENTA);

            }else{

                char result[7] = {0};
                sprintf(result, "%d", (int) matrice[i][j]);
                DrawText(result, decallage + i*TAILLE_CARRE, j*TAILLE_CARRE,TAILLE_POLICE, RAYWHITE);
                DrawRectangle(decallage + i*TAILLE_CARRE, j*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, RED);
            }
        }
    }

}

void affichage_double_matrices(int taille, VALEUR m_1[][taille], VALEUR m_2[][taille]){
    int x_2 = LARGEUR_ECRAN - taille*TAILLE_CARRE - DECALLAGE_DE_BASE;
    affichage_matrice(taille, m_1, DECALLAGE_DE_BASE);
    affichage_matrice(taille, m_2, x_2);
    
}

int affichage_choix_taille(int taille){

    Vector2 positionSouris = GetMousePosition();
    ClearBackground(RAYWHITE);
    DrawText("Taille de la grille", 20, 20, 40, RED);
    DrawText("+", 20, 120, 40, GREEN);
    DrawText("-", 20, 320, 40, PURPLE);

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(positionSouris.x > 0 && positionSouris.x <= 220 &&
          (positionSouris.y > 120 && positionSouris.y <= 150)){
            if(taille < 9){
                taille++;
            }
        }
        if(positionSouris.x > 0 && positionSouris.x <= 270 &&
          (positionSouris.y > 320 && positionSouris.y <= 350)){
            if(taille > 4)
                taille--;
        }
    }
    char texte_taille[2];
    sprintf(texte_taille, "%d", taille);
    DrawText(texte_taille,20,220,40,BLUE);
    return taille;
}

int choix_taille(int* taille){
    int choix_fait = 0;
    if(IsKeyPressed(KEY_ENTER)){
        choix_fait = 1;
        DrawText("taille choisie!",20,620,40, ORANGE);
    }
    
    if(!choix_fait)
        *taille = affichage_choix_taille(*taille);

    return choix_fait;
}

void dessin_fenetre(int taille, VALEUR matrice[][taille], VALEUR matrice_2[][taille]){
    BeginDrawing();

    ClearBackground(RAYWHITE);
    positionSouris = GetMousePosition();
    switch(ecran){
        case MENU:
            {

            //printf("[DEBUG] Coordonnées de souris: x:%f y:%f\n", positionSouris.x, positionSouris.y);
            DrawText("Menu Principal", 20, 20, 40, RED);
            DrawText("Mode Solo", 20, 120, 40, GREEN);
            DrawText("Mode Duo", 20, 220, 40, BLUE);
            DrawText("Mode Puzzle", 20, 320, 40, PURPLE);

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(positionSouris.x > 0 && positionSouris.x <= 220 &&
                  (positionSouris.y > 120 && positionSouris.y <= 150)){
                    ecran = SOLO;
                }
                if(positionSouris.x > 0 && positionSouris.x <= 210 &&
                  (positionSouris.y > 220 && positionSouris.y <= 250)){
                    ecran = DUO;
                }
                if(positionSouris.x > 0 && positionSouris.x <= 270 &&
                  (positionSouris.y > 320 && positionSouris.y <= 350)){
                    ecran = PUZZLE;
                }
            }
        }
            break;
        case SOLO:
            affichage_matrice(taille, matrice, DECALLAGE_DE_BASE);
            DrawText("Mode Solo", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, GREEN);
            break;
        case DUO:
            affichage_double_matrices(taille, matrice, matrice_2);
            DrawText("Mode Duo", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, BLUE);
            break;
        case PUZZLE:
            affichage_matrice(taille, matrice, DECALLAGE_DE_BASE);
            DrawText("Mode Puzzle", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, PURPLE);
            break;
    }
    EndDrawing();
}

