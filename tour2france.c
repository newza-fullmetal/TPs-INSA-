#include <stdio.h>
#include <coureur.h>
#include <liste.h>

int main (int argc, char *argv[])
{
	Coureur *coureur1 = Creer_Coureur("Coustillas","Julien","ECO");
	Afficher_Coureur(coureur1);
	Ajouter_Temps(coureur1, 3600);
	Afficher_Coureur(coureur1);
}