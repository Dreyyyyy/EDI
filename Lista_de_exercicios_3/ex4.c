/*4. Faça um programa que simule uma rede social. Leia um inteiro n de usuários e: 
a)Leia  um  vetor  de  n  usuários,  sendo  que  cada  um  tem  nome  (máximo  de  15 letras), quantidade de amigos e lista de amigos. 
b)A lista de amigos é um vetor de strings com nomes dos amigos (máximo de 15 letras cada nome). 
c)Calcule e mostre a popularidade de cada usuário da rede social, sendo que a popularidade é o número de vezes que aparece na lista de amigos de todos os usuários*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_amigo {
    char nome[15];
}amigos;

typedef struct tipo_usuario{
    char nome[15];
    int amigos;
    amigos *lista_amigos;
}usuario;

usuario *aloca(int n);
amigos *aloca_amigos(int n);
void popularidade(usuario *vetor, int n);

int main() {
    int n = 0, i = 0, j = 0;
    printf("\nDigite o número de usuários desejados: ");
    scanf("%d", &n);
    setbuf(stdin, NULL);
    usuario *vetor = aloca(n);
    for (i = 0; i < n; i++) {
        printf("\n**usuário %d (nome/quantidade/amigos) **\n", i+1);
        scanf("%s%d", (vetor+i)->nome, &(vetor+i)->amigos);
        setbuf(stdin, NULL);    
        (vetor+i)->lista_amigos = aloca_amigos((vetor+i)->amigos);
        for (j = 0; j < (vetor+i)->amigos; j++) {
            scanf("%s", (vetor+i)->lista_amigos[j].nome);
            setbuf(stdin, NULL);
        }
    }
    popularidade(vetor, n);
    return 0;
}

usuario *aloca(int n) {
	usuario *aux = NULL;
	aux = (usuario*)malloc(sizeof(usuario) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

amigos *aloca_amigos(int n) {
    amigos *aux = NULL;
	aux = (amigos*)malloc(sizeof(amigos) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

void popularidade(usuario *vetor, int n) {
    int i = 0, j = 0, k = 0, pop = 0;
    printf("\n** Popularidade **\n");
    for (i = 0; i < n; i++) {
        pop = 0;
        for (j = 0; j < n; j++) {
            for (k = 0; k < (vetor+j)->amigos; k++) {
                if (strcmp((vetor+i)->nome, (vetor+j)->lista_amigos[k].nome) == 0) {
                    pop++;
                }
            }
        }
        printf("\n%s %d\n", (vetor+i)->nome, pop);
    }
	printf("\n");
}
