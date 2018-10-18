#include <stdio.h>
#include "coureur.h"
typedef struct liste Liste;
struct liste {
	Liste *suivant;
	Coureur *coureur;	
};

typedef struct liste_coureurs Liste_Coureurs;
struct liste_coureurs {
	Liste* debut; 
	Liste* courant;
	int nb_coureurs;
};

Liste_Coureurs* Creer_Liste(); 
void Aller_Debut(Liste_Coureurs* liste_coureurs);
Liste* Ajouter_Coureur(Coureur *coureur, Liste_Coureurs *liste); // Ajoute un coureur en fin de liste
int Fin(Liste_Coureurs* liste_coureurs);//Donne l'information de fin de liste 
void supprimer_coureur(int dossard, Liste *liste); //retire un coureur de la liste
void Afficher_Liste(Liste *liste);
Coureur* Get_Coureur(Liste_Coureurs* liste_coureurs);