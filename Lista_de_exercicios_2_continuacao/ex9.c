/*9. 
Crie uma função que receba uma string como parâmetro (de tamanho desconhecido) e retorne uma
cópia da mesma. A assinatura da função deve ser: char *strcopy(char *str);*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *aloca(char tam);
char *strcopy(char *str);

int main() {
	char *string = NULL, *copia = NULL;
	string = aloca(20);
	if (string == NULL) printf("\nO S.O não alocou memória!\n");
	else {	
		printf("\nDigite uma palavra: ");
		scanf("%[^\n]", string);
		copia = strcopy(string);
		printf("\nPalavra printada pela cópia da string: %s\n\n", copia);
	}
	return 0;
}

char *aloca(char tam) {
	char *aux = NULL;
	aux = (char*)malloc(sizeof(char) * tam);
	if (aux == NULL) return NULL;
	else return aux;
}

char *strcopy(char *str) {
	int i = 0, tam = 0;
	char *copia = NULL;
	tam = strlen(str);
	copia = aloca(tam);
	for (i = 0; i < tam; i++) {
		*(copia+i) = *(str+i);
	}
	return copia;
}
