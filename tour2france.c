#include <stdlib.h>
#include <stdio.h>
#include <coureur.h>
#include <liste.h>


/**
* tri la liste des coureurs des plus rapide au plus lent suivant l'algorythme de tri à bulle optimisé
*/
void tri_a_bulle(Liste_Coureurs* liste_coureurs)
{
	printf("Tri des coureurs \n");
	int coureur_classe = 1;
	int coureurs_parcourus;
	int liste_trie;
	Coureur* tmp = NULL;
	for(coureur_classe = 1 ; liste_coureurs->nb_coureurs - 1 ; coureur_classe ++)
	{
		liste_trie = 1;
		Aller_Debut(liste_coureurs);
		for(coureurs_parcourus = 0; coureurs_parcourus < liste_coureurs->nb_coureurs - coureur_classe; coureurs_parcourus ++)
		{
			if (liste_coureurs->courant->coureur->temps_cumule > liste_coureurs->courant->suivant->coureur->temps_cumule)
			{
				tmp = liste_coureurs->courant->suivant->coureur;
				liste_coureurs->courant->suivant->coureur = liste_coureurs->courant->coureur;
				liste_coureurs->courant->coureur = tmp;
				liste_trie = 0;
			}
			Avancer(liste_coureurs);
			
		}
		if (liste_trie) // si parcours sans modif alors liste triée
		{
			break;
		}
	}
}

/**
* Ajoute du temps à chaque coureur dans la liste
*/
void Temps_Etape(Liste_Coureurs* liste_coureurs)
{
	/* temps maximale de l'etape 4H en secondes*/
	int duree_max = 14400; 
	time_t t;   
	/* Initialise le générateur de nombre aléatoire */
	srand((unsigned) time(&t));
	
	liste_coureurs->courant = liste_coureurs->debut;
	printf("Fin d'etape, ajout du temps \n");
	while (liste_coureurs->courant != NULL)
	{
		Ajouter_Temps (Get_Coureur(liste_coureurs), rand() % duree_max);
		liste_coureurs->courant = liste_coureurs->courant->suivant;
	}
}

/**
* supprime aléatoirement un coureur dopée
*/
void Dopage_Aleatoire(Liste_Coureurs* liste_coureurs)
{
	/* proportion de tomber sur un cas de dopage*/
	float chance_dopage = 0.2; 
	time_t t;   
	/* Initialise le générateur de nombre aléatoire */
	srand((unsigned) time(&t));
	
	if (rand() / RAND_MAX < chance_dopage) 
	{
		int coureur_dope  = rand() % liste_coureurs-> nb_coureurs + 1;
		printf("Discalification du coureur %d sur %d \n", coureur_dope, liste_coureurs-> nb_coureurs);
		int tmp = 1;
		Aller_Debut(liste_coureurs);
		while (tmp != coureur_dope)
		{
			tmp +=1 ;
			Avancer(liste_coureurs);
		}
		Supprimer_Coureur(liste_coureurs);
	}
}

int main (int argc, char *argv[])
{	
	Liste_Coureurs* liste_coureurs = Creer_Liste();
	// Liste* liste_coureurs = NULL;
	// Liste* courant = NULL;
	printf("--- OUVERTURE DU FICHIER COUREURS ---\n");
	FILE* fichier = NULL;
	fichier = fopen("coureurs.txt", "r");
	char chaine[TAILLE_MAX] = "";
	int nb_etape;
	int nb_equipe;
	char nom_equipe[15];
	int nb_val_lues;
	int dossard;
	char nom[15];
	char prenom[15];
	
	if (fichier != NULL) 
	{
		printf("--- CHARGEMENT DES COUREURS ---\n");
		
		while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
			sscanf(chaine, "nb_etape:%d",&nb_etape);
			sscanf(chaine, "nb_equipe:%d",&nb_equipe);
			sscanf(chaine,"nom_equipe:%s",nom_equipe);
			nb_val_lues = sscanf(chaine,"%d,%[^,],%s",&dossard, nom, prenom);
			if ( nb_val_lues==3 )
			{
				Coureur *coureur = Creer_Coureur(nom, prenom, nom_equipe, dossard);
				liste_coureurs->debut = Ajouter_Coureur(coureur, liste_coureurs);
				
			}
			
        }
		printf("nom d'equipe : %s", nom_equipe);
		printf("nb etape : %d \n",nb_etape);
		Afficher_Liste(liste_coureurs);
		fclose(fichier);
		printf("--- FIN RECUPERATION DONNEES COUREURS---\n");
	}
	else 
	{
		printf("Erreur ouverture fichier coureurs.txt, fin du programme\n");
		return 0;
	}
	
	
	int etape ; 
	for(etape = 1; etape<nb_etape; etape++){
		printf("--- ETAPE %d ---\n", etape);
		Temps_Etape(liste_coureurs); //calcul le temps
		tri_a_bulle(liste_coureurs); //tri et classe
		Afficher_Liste(liste_coureurs);
	}
	Dopage_Aleatoire(liste_coureurs);
	printf("--- CLASSEMENT FINALE ---\n", etape);
	Afficher_Liste(liste_coureurs);
	return 0;
}

