#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*2.
Faça uma função que receba uma palavra como parâmetro de entrada e a imprima de tras-para-frente.*/

void fromstarttofinish(char *palavra);

int main() {
	char palavra[50];
	printf("\nDigite uma palavra qualquer(máximo 50 caracteres): ");
	scanf("%[^\n]", palavra);
	fromstarttofinish(palavra);
	return 0;
}

void fromstarttofinish(char *palavra) {
	int i = 0, tam = 0;
	tam = strlen(palavra);
	printf("\nPalavra de trás para frente: ");
	for (i = tam; i >= 0; i--) {
		printf("%c", palavra[i]);
	}
	printf("\n\n");
}
