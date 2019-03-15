/*4. Crie um programa que receba três valores (obrigatoriamente maiores que
zero), representando as medidas dos trâs lados de um triângulo. Elabore
funções para:
a. Determinar se eles lados formam um triangulo, sabendo que: o
comprimento de cada lado de um triângulo, deve ser menor do
que a soma dos outros dois lados. Essa função deve retornar 0
caso negativo e 1 caso positivo.
b. Determinar e mostrar o tipo de triangulo, caso as medidas
formem um triângulo. Sendo que:
i. Chama-se equilátero o triângulo que tem três lados iguais.
ii. Denominam-se isósceles o triângulo que tem o
comprimento de dois lados iguais.
iii. Recebe o nome de escaleno o triangulo que tem os três
lados diferentes.*/

#include <stdio.h>
#include <stdlib.h>

int verifica_triangulo(int a, int b, int c);
void denomina_triangulo(int a, int b, int c);

int main() {
	int a = 0, b = 0, c = 0, res = 0;
	do {
		printf("\nDigite 3 valores seguidos maiores que 0: ");
		scanf("%d%d%d", &a, &b, &c);
	}while (a < 0 || b < 0 || c < 0);
	res = verifica_triangulo(a, b, c);
	if (res == 1) {
		denomina_triangulo(a, b, c);
	}
	return 0;
}

int verifica_triangulo(int a, int b, int c) {
	if (a < b+c) {
		if (b < a+b) {
			if (c < a+b) {
				return 1;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void denomina_triangulo(int a, int b, int c) {
	if (a == b && b == c) {
		printf("\nOs valores informados formam um triângulo equilátero.\n\n");
		return;
	}
	if (a != b && a != c && b != c) {
		printf("\nOs valores informados formam um triângulo escaleno.\n\n");
		return;
	}
	printf("\nOs valores informados formam um triângulo isósceles.\n\n");
	return;
}
