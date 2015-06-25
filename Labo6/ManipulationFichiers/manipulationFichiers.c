#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "stdlib.h"
#include "manipulationFichiers.h"


void copieFichier(FILE* fichierEntree, FILE* fichierSortie)
{
	char tampon[TAILLE_TAMPON+1];
	while (fgets(tampon, TAILLE_TAMPON, fichierEntree) != NULL) {
		fputs(tampon, fichierSortie);
	}
}

void ajoutLigne(FILE* fichier)
{
	char tampon[TAILLE_TAMPON+1];

	printf("Veuillez entrer la ligne a ajouter:");

	fgets(tampon, TAILLE_TAMPON, stdin);
	fputs(tampon, fichier);

	printf("\n");
}

void nombreMot(FILE* fichier)
{
	char tampon[TAILLE_TAMPON+1];
	char motRechercher[TAILLE_MOT_MAX+1];
	char* pointeurString;
	int nbOccurences= 0;
	int longeurMot;

	printf("Veuillez entrer le mot a rechercher:");
	fgets(motRechercher, TAILLE_MOT_MAX, stdin);
	longeurMot = strlen(motRechercher) - 1;
	motRechercher[longeurMot] = '\0';
	printf("\n");

	while (fgets(tampon, TAILLE_TAMPON, fichier) != NULL) {
		pointeurString = tampon;
		while (strstr(pointeurString, motRechercher) != NULL) {
			pointeurString = strstr(pointeurString, motRechercher) + strlen(motRechercher);
			nbOccurences++;
		}
	}

	printf("IL y a %d %s dans le fichier\n", nbOccurences, motRechercher);
}

