/*11. Escreva um programa que a partir da leitura de duas Strings qualquer, informe o número de caracteres iguais contidos nas duas Strings.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aloca(int n);
int conta_iguais(char *stringA, char *stringB);
void libera(char **ponteiro);

int main () {	
	char *stringA = NULL, *stringB = NULL;
	int cont = 0;
	stringA = aloca(100);
	stringB = aloca(100);
	printf("\nDigite duas strings, separadas por espaço: ");
	scanf("%s%s", stringA, stringB);
	cont = conta_iguais(stringA, stringB);
	printf("\nNúmero de caracteres iguais entre as duas strings: %d\n\n", cont);
	libera(&stringA);
	libera(&stringB);
    return 0;
}

char *aloca(int n) {
	char *aux = NULL;
	aux = (char*)malloc(sizeof(char) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

void libera(char **ponteiro) {
	free(*ponteiro);
	*ponteiro = NULL;
}

int conta_iguais(char *stringA, char *stringB) {
	int tamA = 0, tamB = 0, i = 0, j = 0, cont = 0;
	tamA = strlen(stringA);
	tamB = strlen(stringB);
	for (i = 0; i < tamA; i++) {
		for (j = 0; j < tamB; j++) {
			if ((int)stringA[i] == (int)stringB[j]) {
				cont++;
			}
		}
	}
	return cont;
}
