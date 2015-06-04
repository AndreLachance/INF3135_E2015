#include "stdio.h"
#include "string.h"
#include "errno.h"

#define TAILLE_TAMPON 255
#define TAILLE_MOT_MAX 50

int main(int argc, char** argv)
{
	
	FILE* fichierEntree;
	FILE* fichierSortie;
	char* tampon[TAILLE_TAMPON+1];
	char commande;
	char* motRechercher[TAILLE_MOT_MAX+1];
	char* pointeurString;
	
	if (argc != 3) {
		
		fprintf(stderr, "Nombre invalide d'arguments!\n");
		return 1;
		
	}
		
	fichierEntree = fopen(argv[1], "r");
	if(fichierEntree == NULL) {
		fprintf(stderr,"Erreur d'ouverture du fichier: %s\n", strerror(errno));
		return 1;
	}
	
	fichierSortie = fopen(argv[2], "w");
	if(fichierSortie == NULL) {
		fprintf(stderr,"Erreur d'ouverture du fichier: %s\n", strerror(errno));
		return 1;
	}
	
	printf("Bienvenue au programme de manipulation des fichiers\n Veuillez entrer une lettre parmis les suivantes: \n");
	printf("a: Copie le fichier entree dans le fichier sortie\n");
	printf("s: permet d'ajouter des lignes de texte manuellement au fichier de sortie\n");
	printf("r: recherche d'un mot dans le fichier d'entrée");
	printf("h: affiche le menu des commandes\n");
	printf("q: Quitte le programme\n");
	printf("Entrez votre lettre:\n");

	do{
		
		commande = getchar();
		
		switch(commande){
			
			case 'a' :
				break;
			
			case 's' :
				break;
				
			case 'r' :
				//lecture du mot rechercher
				while (fgets(tampon, TAILLE_TAMPON, fichierEntree) != NULL) {
				while (strstr(tampon, motRechercher) != NULL) {
				pointeurString = strstr(tampon, motRechercher) + strlen(motRechercher);
				nbOccurences++;
				strcpy(tampon, pointeurString);
				}
			
				break;
				
			case 'h' :
				printf("a: Copie le fichier entree dans le fichier sortie\n");
				printf("s: permet d'ajouter des lignes de texte manuellement au fichier de sortie\n");
				printf("r: recherche d'un mot dans le fichier d'entrée");
				printf("h: affiche le menu des commandes\n");
				printf("q: Quitte le programme\n");
				break;
		}
	}while(commande != 'q' && commande != 'Q' );
	
	
	if(fclose(fichierEntree) == EOF)
	{
		printf("Erreur de fermeture du fichier d'entree\n");
		return 1;
	}
	
	if(fclose(fichierSortie) == EOF)
	{
		printf("Erreur de fermeture du fichier de sortie\n");
		return 1;
	}
	
		return 0;
}

