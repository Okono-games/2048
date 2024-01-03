#ifndef __EXTRAC__FICHIER__H__
#define __EXTRAC__FICHIER__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// utilisé par taille_matrice()
#define TAILLE_MAX_TAMPON 100

/*
 * taille_matrice() est utilisée pour la copie des valeurs du fichier 
 * dans la matrice de jeu.
 */
int taille_matrice(char *nom_du_fichier);

/*
 * lecture_csv() remplit la matrice passée en paramètre avec les valeurs
 * du fichier.
*/

void lecture_csv(char *nom_du_fichier, int taille, VALEUR matrice[][taille]);

int existe(char *fnom);

#endif
