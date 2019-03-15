#include <stdio.h>
#include <stdlib.h>

/*1.
-Defina funções para as quatro operações aritméticas elementares
-Defina o nome do arquivo como main.c
-Antes da função apresente um comentário explicando o que a função 
faz e sob que circunstâncias dá a resposta correta.*/

float soma(float a, float b);
float sub(float a, float b);
float multi(float a, float b);
float divi(float a, float b);

int main() {
	float a = 0, b = 0, res = 0;
	printf("\nDigite dois número para ser feito as quatro operações aritméticas elementares: ");
	scanf("%f%f", &a, &b);
	res = soma(a, b);
	printf("\nSoma = %.2f\n", res);
	res = sub(a, b);
	printf("Subtração = %.2f\n", res);
	res = multi(a, b);
	printf("Multiplicação = %.2f\n", res);
	res = divi(a, b);
	printf("Divisão = %.2f\n\n", res);
	return 0;
}

//Retorna a soma do número a com b;
float soma(float a, float b) {
	return (a+b);
}

//Retorna a subtração do primeiro número informado com o segundo
float sub(float a, float b) {
	return (a-b);
}

//Retorna a multiplicação do número a com b;
float multi(float a, float b) {
	return (a*b);
}

//Retorna a divisão do número a pelo b;
float divi(float a, float b) {
	return (a/b);
}
