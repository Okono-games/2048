#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"
#include "def.h"
#include "graphics.h"
#include "extrac_fichier.h"


/* VARIABLES GLOBALES*/
Ecrans ecran = MENU;
static int erreur_fichier = 0;
static Vector2 positionSouris;
static int nbChars = 0;
static char input[MAX_CHARS + 1] = "\0";
static int entree_csv = 0;

/* DEFINITION DE FONCTIONS */

void creation_fenetre(){
    InitWindow(LARGEUR_ECRAN, LONGUEUR_ECRAN, "2048");
    SetTargetFPS(60);
}

void affichage_matrice(int taille, VALEUR matrice[][taille], int decallage){
    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            if(matrice[i][j] == 0){

                DrawRectangle(decallage + j*TAILLE_CARRE, i*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, LIGHTGRAY);

            }else if(matrice[i][j] == X){

                DrawRectangle(decallage + j*TAILLE_CARRE, i*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, MAGENTA);
                DrawText("X", decallage + j*TAILLE_CARRE+TAILLE_POLICE, i*TAILLE_CARRE+15,TAILLE_POLICE, PURPLE);

            }else{

                char result[7] = {0};
                sprintf(result, "%d", (int) matrice[i][j]);
                DrawRectangle(decallage + j*TAILLE_CARRE, i*TAILLE_CARRE, TAILLE_CARRE, TAILLE_CARRE, RED);
                DrawText(result, decallage + j*TAILLE_CARRE+TAILLE_POLICE-0.25*TAILLE_POLICE*((int) ( (logf( (float) matrice[i][j]) ) / (logf(10.0)) ) ), i*TAILLE_CARRE+15,TAILLE_POLICE, YELLOW);
                //((int) ( (logf( N ) ) / (logf( B )) )+1)) est une formule qui permet d'avoir le nombre de chiffre du nombre N en base B
            }
        }
    }
}

void affichage_double_matrices(int taille, VALEUR m_1[][taille], VALEUR m_2[][taille]){
    int x_2 = LARGEUR_ECRAN - taille*TAILLE_CARRE - DECALLAGE_DE_BASE;
    affichage_matrice(taille, m_1, DECALLAGE_DE_BASE);
    affichage_matrice(taille, m_2, x_2);
    
}

int dessin_fenetre(int* taille, VALEUR matrice[][*taille], VALEUR matrice_2[][*taille]){
    // retourne 1 si la taille a changé
    int changement_taille = 0;
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
            DrawText("Mode Puzzle - Entrez le nom du fichier :", 20, 320, 40, PURPLE);
            char taille_char = *taille + '0';
            char texte_taille[] = "Taille  +  -  :   ";
            DrawText(strcat(texte_taille,&taille_char), 20, 420, 40, ORANGE);
			
			DrawRectangle(850, 315, 300, 45, LIGHTGRAY);
			int key = GetCharPressed();
            while (key > 0){
                if ((key >= 32) && (key <= 125) && (nbChars < MAX_CHARS)){
                    input[nbChars] = (char)key;
                    input[nbChars+1] = '\0'; 
                    nbChars++;
                }

                key = GetCharPressed(); 
            }

            if (IsKeyPressed(KEY_BACKSPACE)){
                nbChars--;
                if (nbChars < 0) nbChars = 0;
                input[nbChars] = '\0';
            }
            DrawRectangleLines(850, 315, 300, 45, PURPLE);
            DrawText(input, 855, 320, 40, PURPLE);
            if (((int) (GetTime())%2) == 0) DrawText("_", 855 + MeasureText(input, 40), 324, 40, PURPLE);
            Rectangle rect = { 850, 315, 300, 45 };
            Rectangle point = { positionSouris.x, positionSouris.y, 1, 1 };
            if (CheckCollisionRecs(rect, point)){SetMouseCursor(MOUSE_CURSOR_IBEAM);}else{SetMouseCursor(MOUSE_CURSOR_DEFAULT);}
			if (IsKeyPressed(KEY_ENTER) || (entree_csv)){
				if (existe(input)){
					if (*taille != taille_matrice(input)){
						*taille = taille_matrice(input);
						printf("[%d]",taille_matrice(input));
						changement_taille = 1;
						entree_csv = 1;
					}else{
						*taille = taille_matrice(input);
						lecture_csv(input, *taille, matrice);
						ecran = PUZZLE; 
						entree_csv = 0;
					}
				}else{
					erreur_fichier = 1;
					
				}
			}
			if (erreur_fichier == 1){
				DrawText("Fichier Introuvable", 825, 365, 40, RED);
			}

			
			
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(positionSouris.x > 0 && positionSouris.x <= 220 &&
                  (positionSouris.y > 120 && positionSouris.y <= 150)){
                    ecran = SOLO;
                }
                if(positionSouris.x > 0 && positionSouris.x <= 210 &&
                  (positionSouris.y > 220 && positionSouris.y <= 250)){
                    ecran = DUO;
                }
                if(positionSouris.x > 157 && positionSouris.x <= 192 &&
                  (positionSouris.y > 420 && positionSouris.y <= 455)){
                	if (*taille < 9){
                	*taille += 1;changement_taille = 1;}
                }
                if(positionSouris.x > 210 && positionSouris.x <= 245 &&
                  (positionSouris.y > 420 && positionSouris.y <= 455)){
                	if (*taille > 4 ){
                	*taille -= 1;changement_taille = 1;}
                }
            }
        }
            break;
        case SOLO:
            affichage_matrice(*taille, matrice, DECALLAGE_DE_BASE);
            DrawText("Mode Solo", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, GREEN);
            DrawText("<--", LARGEUR_ECRAN-100, LONGUEUR_ECRAN-100, 40,GREEN);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		        if (positionSouris.x > LARGEUR_ECRAN-100 && positionSouris.x <= LARGEUR_ECRAN-50 &&
		              (positionSouris.y > LONGUEUR_ECRAN-100 && positionSouris.y <= LONGUEUR_ECRAN-50)){
		            	 ecran = MENU;
		            	 entree_csv = 0;
		            	 erreur_fichier = 0;
		            	 changement_taille = 1;
		        }
		    }
            break;
        case DUO:
            affichage_double_matrices(*taille, matrice, matrice_2);
            DrawText("Mode Duo", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, BLUE);
            DrawText("<--", LARGEUR_ECRAN-100, LONGUEUR_ECRAN-100, 40,GREEN);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		        if (positionSouris.x > LARGEUR_ECRAN-100 && positionSouris.x <= LARGEUR_ECRAN-50 &&
		              (positionSouris.y > LONGUEUR_ECRAN-100 && positionSouris.y <= LONGUEUR_ECRAN-50)){
		            	 ecran = MENU;
		            	 entree_csv = 0;
		            	 erreur_fichier = 0;
		            	 changement_taille = 1;
		        }
		    }   
            break;
        case PUZZLE:
            affichage_matrice(*taille, matrice, DECALLAGE_DE_BASE);
            DrawText("Mode Puzzle", DECALLAGE_DE_BASE, LONGUEUR_ECRAN - 50, 40, PURPLE);
            DrawText("<--", LARGEUR_ECRAN-100, LONGUEUR_ECRAN-100, 40,GREEN);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		        if (positionSouris.x > LARGEUR_ECRAN-100 && positionSouris.x <= LARGEUR_ECRAN-50 &&
		              (positionSouris.y > LONGUEUR_ECRAN-100 && positionSouris.y <= LONGUEUR_ECRAN-50)){
		            	 ecran = MENU;
		            	 entree_csv = 0;
		            	 erreur_fichier = 0;
		            	 changement_taille = 1;
		        }
		    }   
            break;
    }
    EndDrawing();
    return changement_taille;
}

