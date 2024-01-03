#include "def.h"
#include "game.h"
#include "raylib.h"

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
            else if (tableau[cible ][i]==0){
            	cible --;
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
            else if (tableau[i][cible]==0){
            	cible --;
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
            else if (tableau[i][cible]==0){
            	cible ++;
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
            else if (tableau[cible][i]==X){
                curseur = cible + 1;
                cible = curseur + 1;
            }
            else if (tableau[cible][i]==0){
            	cible ++;
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

int verification(int taille, int tableau[][taille]){
    int copie[taille][taille];

    for(int i = 0; i < taille; i++){
        for(int j = 0; j < taille; j++){
            copie[i][j] = tableau[i][j];
        }
    }

    if(  deplacement_gauche(taille, copie)
      || deplacement_droite(taille, copie)
      || deplacement_haut(taille, copie)
      || deplacement_bas(taille, copie) ){
        return 1;
    }else {return 0;}
}

int placement_aleatoire(int taille, int tableau[][taille]){
    // on cherche le nombre de case vide dans le tableau actuel
    int nb_cases_vides = 0;
    for (int i = 0; i<taille; i++){
        for (int j = 0; j<taille; j++){
            if (tableau[i][j]==0){
                nb_cases_vides += 1;
            }
        }
    }
    if (nb_cases_vides == 0){return 0;}
    int valeur_inseree;
    if (rand()%9<2){
        valeur_inseree = 4; // 20% de chance d'avoir 4
    }else{ valeur_inseree = 2;} // 80% de chance d'avoir 2
    
    int distance_indice = rand() % nb_cases_vides; // nb_cases_vides jamais égal à 0 par le test précédent
    
    // on parcourt alors une dernière fois le tableau pour placer la valeur
    for (int i = 0; i<taille; i++){
        for (int j = 0; j<taille; j++){
            if (tableau[i][j]==0){
                if(distance_indice == 0){
                    tableau[i][j] = valeur_inseree;
                }
                distance_indice--;
            }
        }
    }
    return 1;
}

void init_tableau(int taille, VALEUR tableau[][taille]){
    for (int i = 0; i<taille; i++){
       for (int j = 0; j<taille; ++j){
          tableau[i][j] = 0;
       }
    }
    placement_aleatoire(taille, tableau);
}

int jouer_entree(int taille, VALEUR tableau[][taille]){
	if (IsKeyPressed(KEY_RIGHT)) {deplacement_droite(taille, tableau);return 1;}
    else if (IsKeyPressed(KEY_LEFT)) {deplacement_gauche(taille, tableau);return 1;}
    else if (IsKeyPressed(KEY_UP)) {deplacement_haut(taille, tableau);return 1;}
    else if (IsKeyPressed(KEY_DOWN)) {deplacement_bas(taille, tableau);return 1;}
    return 0;
}

int jouer(int taille, VALEUR tableau[][taille]){
	if (jouer_entree(taille, tableau)){
		if (verification(taille, tableau)) {
			placement_aleatoire(taille, tableau);}		
		return 1;
	}
	else {return 0;}
}




