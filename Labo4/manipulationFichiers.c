#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "errno.h"

#define TAILLE_TAMPON 255
#define TAILLE_MOT_MAX 50

FILE* ouvrirFichier (char*, char*);
void fermerFichier (FILE*);
void afficherMenu();
void copieFichier(FILE*, FILE*);
void ajoutLigne(FILE*);
void nombreMot(FILE*);

int main(int argc, char** argv)
{
	
	FILE* fichierEntree;
	FILE* fichierSortie;
	char commande;
	
	if (argc != 3) {
		
		fprintf(stderr, "Nombre invalide d'arguments!\n");
		return 1;
		
	}
	
	printf("Bienvenue au programme de manipulation des fichiers\n");
	afficherMenu();

	do{
		
		commande = getchar();
		printf("\n");
		
		switch(commande){
			
			case 'a' :
				fichierEntree = ouvrirFichier (argv[1], "r");
				fichierSortie = ouvrirFichier (argv[2], "w");

				copieFichier(fichierEntree, fichierSortie);

				fermerFichier (fichierEntree);
				fermerFichier (fichierSortie);
				break;
			
			case 's' :
				fichierSortie = ouvrirFichier (argv[2], "a");

				ajoutLigne(fichierSortie);

				fermerFichier (fichierSortie);
				break;
				
			case 'r' :
				fichierEntree = ouvrirFichier (argv[1], "r");

				nombreMot(fichierEntree);

				fermerFichier (fichierEntree);
				break;
				
			case 'h' :
				afficherMenu();
				break;
		}
	}while(commande != 'q' && commande != 'Q' );
	
		return 0;
}

FILE* ouvrirFichier (char* adresseFichier, char* mode)
{
	FILE* fichier;

	fichier = fopen(adresseFichier, mode);
	if(fichier == NULL) {
		fprintf(stderr,"Erreur d'ouverture du fichier: %s\n", strerror(errno));
		exit (1);
	}

	return fichier;
}

void fermerFichier (FILE* fichier)
{
	if(fclose(fichier) == EOF)
	{
		printf("Erreur de fermeture du fichier\n");
		exit (1);
	}
}

void afficherMenu()
{
	printf("Veuillez entrer une lettre parmis les suivantes: \n");
	printf("a: Copie le fichier entree dans le fichier sortie\n");
	printf("s: permet d'ajouter des lignes de texte manuellement au fichier de sortie\n");
	printf("r: recherche d'un mot dans le fichier d'entrée");
	printf("h: affiche le menu des commandes\n");
	printf("q: Quitte le programme\n");
	printf("Entrez votre lettre:");
}

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
	unsigned nbOccurences= 0;

	printf("Veuillez entrer le mot a rechercher:");
	fgets(motRechercher, TAILLE_MOT_MAX, stdin);
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

