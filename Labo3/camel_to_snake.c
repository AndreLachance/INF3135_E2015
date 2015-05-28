#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CHAINE_MAX 50

void camelToSnake (char*, char*);

int main() {
	char entree[CHAINE_MAX + 1];
	char buffer[CHAINE_MAX + 1];
	char* sortie = buffer;
	
	printf("Se programme convertie une chaine de charactere camel case en snake case\n\n");
	
	do{
		printf("Entrez la chaine a transformer: ");
		scanf("%s", entree);
		printf("\n\n");
		if (strcmp(entree, "q") !=0){
			sortie[0] = '\0';
			camelToSnake (sortie, entree);
			printf("La chaine transformee est: %s", sortie);
			printf("\n\n");
		}
	} while (strcmp(entree, "q") != 0);
	
	return 0;
}

void camelToSnake (char* sortie, char* entree){
	unsigned i = 0;
	unsigned j = 0;
	unsigned longueur = strlen(entree);
	while (j < longueur){
		if (!isupper(entree[i])){
			i++;
			j++;
		} else {
			entree[i] = (char)tolower(entree[i]);
			strncat(sortie, entree, i);
			strcat(sortie, "_");
			entree += i;
			i = 0;
		}
	}
	strncat(sortie, entree, i);
}
