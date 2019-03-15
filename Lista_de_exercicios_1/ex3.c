/*3. O código de César é uma das mais simples e conhecidas técnicas de
criptografia. É um tipo de substituição na qual cada letra do texto é
substituída por outra, que se apresenta no alfabeto abaixo dela um numero
fixo de vezes. Por exemplo, com uma troca de três posições, ‘A’ seria
substituído por ‘D’, ‘B’ se tornaria ‘E’, e assim por diante. Implemente uma
função que faça uso desse Código de César (3 posições), a função recebe
como parâmetro de entrada uma string e apresenta a string codificada.
Exemplo:
String: a ligeira raposa marrom saltou sobre o cachorro cansado
Nova string: D OLJHLUD UDSRVD PDUURP VDOWRX VREUH R
FDFKRUUR FDQVDGR3.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void codifica(char *frase);

int main() {
	char frase[300];
	printf("\nDigite uma frase qualquer(máximo 300 caracteres):\n");
	scanf("%[^\n]", frase);
	codifica(frase);
	return 0;
}

void codifica(char *frase) {
	int i = 0, tam = 0;
	tam = strlen(frase);
	char fraseAj[tam];
	for (i = 0; i < tam; i++) {
		fraseAj[i] = toupper (frase[i]);
	}
	printf("\nFrase codificada:\n");
	for (i = 0; i< tam; i++) {
		if ((int)fraseAj[i] > 64 && (int)fraseAj[i] < 90) {
			fraseAj[i] = (int)fraseAj[i]+3;
			printf("%c", fraseAj[i]);
		}	
		else printf("%c", fraseAj[i]);
	}
	printf("\n\n");
}



