#include <stdio.h>
#include <stdlib.h> //Used to import "malloc" function
#include <string.h>
#include <coureur.h>

Coureur *Creer_Coureur(char* nom, char* prenom, char* equipe, int dossard){
	Coureur *coureur; 
	coureur = malloc(sizeof(Coureur));
	strcpy(coureur->nom,nom); // equal to (*coureur).nom
	strcpy(coureur->prenom,prenom);
	strcpy(coureur->equipe,equipe);
	coureur->dossard=dossard; 
	coureur->temps_cumule=0;
	return coureur;
} 
/**
* Ajoute du temps à un coureur donné 
*/
void Ajouter_Temps(Coureur *coureur, int temps_sup){
	coureur->temps_cumule = coureur->temps_cumule + temps_sup;
}

void Afficher_Coureur(Coureur *coureur){
	int minutes = 0;
	int secondes = coureur->temps_cumule; 
	int heures = 0;
	minutes = secondes / 60 ;
	secondes = secondes % 60 ;
	heures = minutes / 60 ;
	minutes = minutes % 60  ;
	printf("%s	%s	%s	%i	%ih%im%is",coureur->nom, coureur->prenom,coureur->equipe, coureur->dossard, heures, minutes, secondes);
	printf("\n");
}