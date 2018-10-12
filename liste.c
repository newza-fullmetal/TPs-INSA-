#include <stdio.h>
#include <stdlib.h> //Used to import "malloc" function
#include <liste.h>
#include <coureur.h>

Liste *Creer_Liste(){
	Liste *liste; 
	liste = malloc(sizeof(Liste));
	liste->liste = NULL;
	liste->coureur=NULL;
	return liste;
} 
/**
* Ajoute un coureur en fin de liste 
*/
void Ajouter_Coureur(Coureur *coureur, Liste *liste) {
	Liste *courant=liste;
	while Fin(liste) != 1
		courant = courant->liste; 
	
	courant->coureur = coureur; 
	courant->liste = Creer_Liste();
}

/**
* Renvoie 1 si nous sommes en fin de liste
* 0 sinon 
*/
int Fin(Liste *liste) {
	if liste->liste == NULL 
		return 1;
	else 
		return 0;
	
}

/**
* Retire un coureur de la liste
*/
void supprimer_coureur(int dossard, Liste *courant){
	if dossard > 0 
		if courant->liste->coureur->dossard == dossard 
			courant->
}

/**
* Affiche la liste des coureurs
*/
void afficher_Liste(Liste *liste)
{
    Liste *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        Afficher_Coureur(tmp->coureur);
        /* On avance d'une case */
        tmp = tmp->liste;
    }
}




