#include <stdio.h>
#include <stdlib.h> //Used to import "malloc" function
#include <liste.h>
#include <coureur.h>

Liste_Coureurs* Creer_Liste(){
	Liste_Coureurs* liste_coureurs = NULL; 
	liste_coureurs = malloc(sizeof(Liste_Coureurs));
	liste_coureurs->debut = NULL;
	liste_coureurs->courant=NULL;
	liste_coureurs->nb_coureurs = 0;
	return liste_coureurs;
} 

/**
* Ramène le pointeur courant au début de la liste
*/
void Aller_Debut(Liste_Coureurs *liste_coureurs) 
{
	liste_coureurs->courant = liste_coureurs->debut;
}

/**
* Avance le pointeur courant d'un cran dans la liste
*/
void Avancer(Liste_Coureurs *liste_coureurs)
{
	if (liste_coureurs->courant == NULL){
		Aller_Debut(liste_coureurs);
	}
	else 
	{
		liste_coureurs->courant = liste_coureurs->courant->suivant; //courant pointe sur un Liste* 
	}
}

/**
* Ajoute un coureur en fin de liste 
*/
Liste* Ajouter_Coureur(Coureur *coureur, Liste_Coureurs* liste) {
	if (coureur != NULL )
	{
		Liste* tmp=liste->debut;
		/* On crée un nouvel élément */
		Liste* nouveauCoureur = malloc(sizeof(Liste));
		/* On assigne la valeur au nouvel élément */
		nouveauCoureur->coureur = coureur;
	 
		/* On ajoute en fin, donc aucun élément ne va suivre */
		nouveauCoureur->suivant = NULL;
		
		liste->nb_coureurs += 1;
		if (liste->debut == NULL)
		{
			return nouveauCoureur;
		}
		else 
		{
	 
			while (tmp->suivant != NULL)
			{
				tmp = tmp->suivant; 
			}
			tmp->suivant = nouveauCoureur;
			return liste->debut;
		}
	}
	else 
	{
		printf("Ajout d'un coureur NULL dans la liste \n");
	}
}

/**
* Renvoie 1 si nous sommes en fin de liste
* 0 sinon 
*/
int Fin(Liste_Coureurs* liste_coureurs) 
{
	if (liste_coureurs->courant->suivant == NULL )
		return 1;
	else 
		return 0;
	
}

/**
* Supprime le coureur pointé par le pointeur courant
*/
void Supprimer_Coureur(Liste_Coureurs* liste_coureurs)
{	
	if (liste_coureurs->courant != NULL)
	{
		/* cas ou le coureur est le premier de la liste */
		if (liste_coureurs->courant == liste_coureurs->debut) 
		{
			printf("Suppression du premier coureur  : \n");
			Afficher_Coureur(liste_coureurs->courant->coureur);
			liste_coureurs->debut = liste_coureurs->debut->suivant;
			free(liste_coureurs->courant->coureur);
			free(liste_coureurs->courant);
			liste_coureurs->courant=liste_coureurs->debut;
		}
		else
		{
			Liste* temp = liste_coureurs->debut;
			while(temp->suivant != liste_coureurs->courant)
			{
				temp = temp->suivant;
			}
				printf("Suppression du coureur : ");
				Afficher_Coureur(temp->suivant->coureur);
				temp->suivant = temp->suivant->suivant;
				free(liste_coureurs->courant->coureur);
				free(liste_coureurs->courant);
				liste_coureurs->courant=liste_coureurs->debut;
		}
		liste_coureurs->nb_coureurs -= 1; //on retire un coureur
	}
}

/**
* Renvoie le coureur pointer par le pointeur courant. 
*/
Coureur* Get_Coureur(Liste_Coureurs* liste_coureurs)
{
	if (liste_coureurs->courant != NULL)  
	{
		return liste_coureurs->courant->coureur;
	}
	else
	{
		printf("ERREUR : pas de coureur ici ! \n");
		return NULL; 
	}
	
}
	

/**
* Retire un coureur de la liste
// */
// void supprimer_coureur(int dossard, Liste *courant){
	// if (dossard > 0)
		// if (courant->liste->coureur->dossard == dossard)
			// courant->
// }

/**
* Affiche la liste des coureurs
*/
void Afficher_Liste(Liste* liste)
{
    Liste *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        Afficher_Coureur(tmp->coureur);
        /* On avance d'une case */
        tmp = tmp->suivant;
    }
}




