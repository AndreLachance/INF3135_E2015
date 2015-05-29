#include "stdio.h"
#include "string.h"


void impressionMot(char* mot);


int main(int argc, char** argv)
{
	
	char* mot = "Bonjour";
	
	impressionMot(mot);
	impressionMot(mot + 3);
	
	return 0;
}

void impressionMot(char* mot) 
{
	
	size_t i;
	size_t longeurMot = strlen(mot);
	
	for (i = 0; i < longeurMot; i++)
	{
		printf("%c",*mot);
		mot++;
	}
	printf("\n");
	
}




