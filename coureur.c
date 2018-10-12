#include <stdio.h>
#include <stdlib.h> //Used to import "malloc" function
#include <coureur.h>

Coureur *Creer_Coureur(char* nom, char* prenom, char* equipe){
	Coureur *coureur; 
	coureur = malloc(sizeof(Coureur));
	coureur->nom=nom; // equal to (*coureur).nom
	coureur->prenom=prenom;
	coureur->equipe=equipe;
	coureur->dossard=0; 
	coureur->temps_cumule=0;
	
} 
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