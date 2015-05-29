#include "stdio.h"
#include "string.h"
#include "errno.h"

#define TAILLE_TAMPON 255
#define TAILLE_MOT_MAX 50

int main(int argc, char** argv)
{
	
	FILE* fichier;
	char motRechercher[TAILLE_MOT_MAX +1];
	char tampon[TAILLE_TAMPON +1];
	int nbOccurences = 0;
	char* pointeur;
	
	printf("entrez un mot a rechercher\n");
	scanf("%s", motRechercher);
	
	fichier = fopen(argv[1], "r");
	if(fichier == NULL) {
		printf("Erreur d'ouverture du fichier %d\n", errno);
		return 1;
	}
	
	while (fgets(tampon, TAILLE_TAMPON, fichier) != NULL) {
		while (strstr(tampon, motRechercher) != NULL) {
			pointeur = strstr(tampon, motRechercher) + strlen(motRechercher);
			nbOccurences++;
			strcpy(tampon, pointeur);
		}
	}
	
	if(fclose(fichier) == EOF)
	{
		printf("Erreure lors de la fermeture du fichier. \n");
		return 1;
	}
		printf("%s se retrouve %d fois dans le document: %s\n", motRechercher, nbOccurences, argv[1]);
		return 0;
}
