#include <stdio.h>
typedef struct liste Liste;
struct liste {
	Liste *liste;
	Coureur *coureur;	
}
Liste *Creer_Liste(); 
void Ajouter_Coureur(Coureur *coureur, Liste *liste); // Ajoute un coureur en fin de liste
int Fin(Liste *liste);//Donne l'information de fin de liste 
void supprimer_coureur(int dossard, Liste *liste); //retire un coureur de la liste
void afficher_Liste(Liste *liste);