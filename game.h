#ifndef __GAME__H__
#define __GAME__H__
int deplacement_bas(int taille,VALEUR tableau[][taille]);

int deplacement_droite(int taille,VALEUR tableau[][taille]);

int deplacement_gauche(int taille,VALEUR tableau[][taille]);

int deplacement_haut(int taille,VALEUR tableau[][taille]);

int verification(int taille, int tableau[][taille]);

int placement_aleatoire(int taille, int tableau[][taille]);

#endif
