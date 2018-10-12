#include <stdio.h>
typedef struct coureur Coureur;
struct coureur {
	char* nom; 
	char* prenom; 
	int dossard;
	char* equipe; 
	int temps_cumule;
}; 

Coureur *Creer_Coureur(char* nom, char* prenom, char* equipe); 
void Ajouter_Temps(Coureur *coureur, int temps_sup);
void Afficher_Coureur(Coureur *coureur);
