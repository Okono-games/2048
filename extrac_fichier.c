#include "def.h"
#include "extrac_fichier.h"

// calcul la taille que fera la matrice
int taille_matrice(char *nom_du_fichier){
    FILE *fichier_temp = fopen(nom_du_fichier, "r");
    char tampon[3];
    fgets(tampon, sizeof(tampon), fichier_temp);

    fclose(fichier_temp);

    char valeur[2];
    valeur[0] = tampon[0];

    return atoi(valeur);
}


int existe(char *fnom){
    FILE *fichier;
    if ((fichier = fopen(fnom, "r")))
    {
        fclose(fichier);
        return 1;
    }
    return 0;
}


void lecture_csv(char *nom_du_fichier, int taille, VALEUR matrice[][taille]){

    char tampon[TAILLE_MAX_TAMPON];
    char *ligne;
    FILE *fichier = fopen(nom_du_fichier, "r");

    fgets(tampon, sizeof(tampon), fichier);

    int i = 0;
    while(fgets(tampon, sizeof(tampon), fichier)){

        ligne = strtok(tampon, ",");

        int j = 0;
        while(ligne != NULL){
            if(strcmp(ligne, "x") == 0) {
                matrice[i][j] = X;
            }else{
                matrice[i][j] = atoi(ligne);
            }
            ligne = strtok(NULL, ",");
            j++;
        }
        i++;
    }
}



