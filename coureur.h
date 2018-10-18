#ifndef COUREUR_H_
# define COUREUR_H_
#include <stdio.h>
#define TAILLE_MAX 20
typedef struct coureur Coureur;
struct coureur {
	char nom[TAILLE_MAX]; 
	char prenom[TAILLE_MAX]; 
	int dossard;
	char equipe[TAILLE_MAX]; 
	int temps_cumule;
}; 

Coureur *Creer_Coureur(); 
void Ajouter_Temps(Coureur *coureur, int temps_sup);
void Afficher_Coureur(Coureur *coureur);
#endif