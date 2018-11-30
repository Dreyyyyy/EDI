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

int main(int argc, char const *argv[]) {
  char frase[500];
  printf("\nDigite uma frase qualquer: ");
  scanf("%[^\n]", frase);
  codifica(frase);
  return 0;
}

void codifica(char *frase) {
  char codificada[500], fraseAjustada[500];
  int i, tam = strlen(frase);
  printf("\nFrase codificada abaixo:\n");
  for (i = 0; i < tam; i++) {
    if ((int)frase[i] == 32) printf("%c", frase[i]);
    else {
      fraseAjustada[i] = toupper(frase[i]);
      codificada[i] = (int)fraseAjustada[i] + 3;
      printf("%c", codificada[i]);
    }
  }
  printf("\n\n");
}
