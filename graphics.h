#define TAILLE_CARRE 50
#define DECALLAGE_DE_BASE 20
#define LARGEUR_ECRAN 1280
#define LONGUEUR_ECRAN 720
#define TAILLE_POLICE 40

void creation_fenetre();

void affichage_matrice(int taille, VALEUR matrice[][taille], int decallage);

void affichage_double_matrices(int taille, VALEUR m_1[][taille], VALEUR m_2[][taille]);

int affichage_choix_taille(int taille);

int choix_taille(int* taille);

void dessin_fenetre(int taille, matrice[][taille], matrice_2[][taille]);


