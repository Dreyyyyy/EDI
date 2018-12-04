/*9. Crie uma função que receba uma string como parâmetro (de tamanho desconhecido) e retorne uma 
cópia da mesma. A assinatura da função deve ser: char *strcopy(char *str);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcopy(char *str);

int main() {
	char *string, *copia;
	string = (char*)malloc(sizeof(char)* 20);
	if (string == NULL) return 0;
	else {
		printf("\nDigite uma palavra: ");
		scanf("%s", string);
		copia = strcopy(string);
		printf("\nPalavra copiada: %s\n\n", copia);
	}	
	return 0;
}

char *strcopy(char *str) {
	int tam = strlen(str);
	char *copia = (char*)malloc(sizeof(char) * tam);
	if (copia == NULL) return NULL;
	else {
		copia = str;
		return copia;
	} 
}
