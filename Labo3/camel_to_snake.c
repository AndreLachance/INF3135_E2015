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
			camelToSnake (sortie, entree);
			printf("La chaine transformee est: %s", sortie);
			sortie[0] = '\0';
			printf("\n\n");
		}
	} while (strcmp(entree, "q") != 0);
	
	return 0;
}

void camelToSnake (char* sortie, char* entree){
	unsigned i = 0;
	unsigned j;
	char* pointeur = entree;
	for (j = 0; j < strlen(entree); j++){
		if (!isupper(pointeur[i])){
			i++;
		} else {
			pointeur[i] = (char)tolower(pointeur[i]);
			strncat(sortie, pointeur, i);
			strcat(sortie, "_");
			pointeur += i;
			i = 0;
		}
	}
	strncat(sortie, pointeur, i + 1);
}
