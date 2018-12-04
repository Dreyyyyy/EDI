/*11. Escreva um programa que a partir da leitura de duas Strings qualquer, informe o número de
caracteres iguais contidos nas duas Strings.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aloca_string();
int	caracteres_iguais(char *string1, char *string2);

int main() {
	char *string1 = NULL, *string2 = NULL;
	int res = 0;
	string1 = aloca_string();
	string2 = aloca_string();
	printf("\nDigite a primeira palavra: ");
	scanf("%s", string1);
	printf("\nDigite a segunda palavra: ");
	scanf("%s", string2);	
	res = caracteres_iguais(string1, string2);
	printf("\nQuantidade de caracteres iguais: %d\n\n", res);
	return 0;
}

char *aloca_string() {
	char *string = (char*)malloc(sizeof(char) * 30);
	if (string == NULL) return NULL;
	else return string;
}

int	caracteres_iguais(char *string1, char *string2) {
	int i, j, tam = 0, cont = 0;
	tam = strlen(string1);
	for (i = 0; i < tam; i++) {
		for (j = 0; j < tam; j++)
			if (string1[i] == string2[j]) { 
				cont++;
			}
	}
	return cont;
}
