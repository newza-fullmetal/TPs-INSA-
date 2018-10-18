#include <stdio.h>
#include "coureur.h"
/**
Structure représeantant un coureur et un lien vers le suivant
*/
typedef struct liste Liste;
struct liste {
	Liste *suivant;
	Coureur *coureur;	
};

/**
Structure représentant différentes infos d'une liste (peut être modifiée)
*/
typedef struct liste_coureurs Liste_Coureurs;
struct liste_coureurs {
	Liste* debut; 
	Liste* courant;
	int nb_coureurs;
};

/**
Initialise une liste de coureurs 
*/
Liste_Coureurs* Creer_Liste(); 

void Aller_Debut(Liste_Coureurs* liste_coureurs);

/* Ajoute un coureur en fin de liste */
Liste* Ajouter_Coureur(Coureur *coureur, Liste_Coureurs *liste); 

/* Donne l'information de fin de liste  */
int Fin(Liste_Coureurs* liste_coureurs);

/* retire un coureur de la liste */
void supprimer_coureur(int dossard, Liste *liste); 

/* Affiche la liste*/
void Afficher_Liste(Liste_Coureurs *liste);

Coureur* Get_Coureur(Liste_Coureurs* liste_coureurs);