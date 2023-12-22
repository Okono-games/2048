#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum {X=-1} VALEUR;

int deplacement_bas(int taille,VALEUR tableau[][taille]){
    int changement = 0;
    for (int i=0; i<taille; i++){
        int curseur = taille-1;
        int cible = taille-2;
        while (cible >= 0){
            if (tableau[curseur][i]==X){
                curseur--;
                cible--;
            }
            else if (tableau[cible][i]==X){
                curseur = cible - 1;
                cible = curseur - 1;
            }
            else if (tableau[curseur][i]==0){
                tableau[curseur][i]=tableau[cible][i];
                tableau[cible][i]=0;
                cible--;
                if (!changement){changement=1;};
            }
            else if (tableau[curseur][i]==tableau[cible][i]){
                tableau[curseur][i] += tableau[cible][i];
                tableau[cible][i] = 0;
                cible--;
                curseur--;
                if (!changement){changement=1;};
            }
            else if (tableau[curseur][i]!=tableau[cible][i]){
                if ( (curseur-1) != cible){
                    tableau[curseur-1][i]=tableau[cible][i];
                    tableau[cible][i]=0;
                    if (!changement){changement=1;};
                }
                curseur--;
                cible--;
            }
        }
    }
    return changement;
}

int deplacement_droite(int taille,VALEUR tableau[][taille]){
    int changement = 0;
    for (int i=0; i<taille; i++){
        int curseur = taille-1;
        int cible = taille-2;
        while (cible >= 0){
            if (tableau[i][curseur]==X){
                curseur--;
                cible--;
            }
            else if (tableau[i][cible]==X){
                curseur = cible - 1;
                cible = curseur - 1;
            }
            else if (tableau[i][curseur]==0){
                tableau[i][curseur]=tableau[i][cible];
                tableau[i][cible]=0;
                cible--;
                if (!changement){changement=1;};
            }
            else if (tableau[i][curseur]==tableau[i][cible]){
                tableau[i][curseur] += tableau[i][cible];
                tableau[i][cible] = 0;
                cible--;
                curseur--;
                if (!changement){changement=1;};
            }
            else if (tableau[i][curseur]!=tableau[i][cible]){
                if ( (curseur-1) != cible){
                    tableau[i][curseur-1]=tableau[i][cible];
                    tableau[i][cible]=0;
                    if (!changement){changement=1;};
                }
                curseur--;
                cible--;
            }
        }
    }
    return changement;
}

int deplacement_gauche(int taille,VALEUR tableau[][taille]){
    int changement = 0;
    for (int i=0; i<taille; i++){
        int curseur = 0;
        int cible = 1;
        while (cible < taille){
            if (tableau[i][curseur]==X){
                curseur++;
                cible++;
            }
            else if (tableau[i][cible]==X){
                curseur = cible + 1;
                cible = curseur + 1;
            }
            else if (tableau[i][curseur]==0){
                tableau[i][curseur]=tableau[i][cible];
                tableau[i][cible]=0;
                cible++;
                if (!changement){changement=1;};
            }
            else if (tableau[i][curseur]==tableau[i][cible]){
                tableau[i][curseur] += tableau[i][cible];
                tableau[i][cible] = 0;
                cible++;
                curseur++;
                if (!changement){changement=1;};
            }
            else if (tableau[i][curseur]!=tableau[i][cible]){
                if ( (curseur+1) != cible){
                    tableau[i][curseur+1]=tableau[i][cible];
                    tableau[i][cible]=0;
                    if (!changement){changement=1;};
                }
                curseur++;
                cible++;
            }
        }
    }
    return changement;
}

int deplacement_haut(int taille,VALEUR tableau[][taille]){
    int changement = 0;
    for (int i=0; i<taille; i++){
        int curseur = 0;
        int cible = 1;
        while (cible < taille){
            if (tableau[curseur][i]==X){
                curseur++;
                cible++;
            }
            else if (tableau[cible][curseur]==X){
                curseur = cible + 1;
                cible = curseur + 1;
            }
            else if (tableau[curseur][i]==0){
                tableau[curseur][i]=tableau[cible][i];
                tableau[cible][i]=0;
                cible++;
                if (!changement){changement=1;};
            }
            else if (tableau[curseur][i]==tableau[cible][i]){
                tableau[curseur][i] += tableau[cible][i];
                tableau[cible][i] = 0;
                cible++;
                if (!changement){changement=1;};
            }
            else if (tableau[curseur][i]!=tableau[cible][i]){
                if ( (curseur+1) != cible){
                    tableau[curseur+1][i]=tableau[cible][i];
                    tableau[cible][i]=0;
                    if (!changement){changement=1;};
                }
                curseur++;
                cible++;
            }
        }
    }
    return changement;
}




int main(){
    int taille = 3;
    VALEUR tableau[][3] = {{X,2,2},
                           {2,2,X},
                           {2,2,4}};
    deplacement_haut(3,tableau);
    for (int i=0;i<taille;i++){
        for (int j=0;j<taille; j++){
            printf("%d",tableau[i][j]);
        }
        printf("\n");
    }
}
