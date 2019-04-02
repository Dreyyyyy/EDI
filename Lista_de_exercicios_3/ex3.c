/*3. Crie  uma  estrutura  representando  os  alunos  de  um  determinado  curso. 
A  estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova. 
(a) Permita ao usuário entrar com os dados de 5 alunos. 
(b) Encontre o aluno com maior nota da primeira prova. 
(c) Encontre o aluno com maior media geral. 
(d) Encontre o aluno com menor media geral 
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct alunos {
    int RA;
    char nome[60];
    float nota[3];
}aluno;

aluno *aloca(int n);
void busca_medias(aluno *curso);

int main () {
    int i = 0, j = 0;
    aluno *curso = NULL;
    curso = aloca(5);
    for (i = 0; i < 5; i++) {
        printf("\nDigite o RA do %dº aluno: ", i+1);
        scanf("%d", &curso[i].RA);
        setbuf(stdin, NULL);
        printf("\nDigite o nome do %dº aluno: ", i+1);
        scanf("%[^\n]", curso[i].nome);
        printf("\nDigite a %dº, %dº e a %dº nota do %dº aluno: ", j+1, j+2, j+3, i+1);
        scanf("%f%f%f", &curso[i].nota[j], &curso[i].nota[j+1], &curso[i].nota[j+2]);
        if ((curso[i].nota[0] + curso[i].nota[1] + curso[i].nota[2])/3 >= 6.0) {
            printf("\nAprovado!\n");
        }
        else printf("\nReprovado.\n");
    }
    busca_medias(curso);
    return 0;
}

aluno *aloca(int n) {
	aluno *aux = NULL;
	aux = (aluno*)malloc(sizeof(aluno) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

void busca_medias(aluno *curso) {
    int i = 0;
    float maior_nota = curso[0].nota[0], media[5], maior_media = 0, menor_media = 0;
    int RA = curso[0].RA, RA2 = curso[0].RA, RA3 = curso[0].RA;
    for (i = 0; i < 5; i++) {
        media[i] = (curso[i].nota[0] + curso[i].nota[1] + curso[i].nota[2])/3;
        if (maior_nota <= curso[i].nota[0]) {
            maior_nota = curso[i].nota[0];
            RA = curso[i].RA;
        }   
    }
    maior_media = media[0];
    menor_media = media[0];
    printf("\nRA do aluno com a maior nota da 1º prova: %d\n", RA);
    for (i = 0; i < 5; i++) {
        if (maior_media <= media[i]) {
            maior_media = media[i];
            RA2 = curso[i].RA;
        }
        if (menor_media >= media[i]) {
            menor_media = media[i];
            RA3 = curso[i].RA;
        }        
    }
    printf("\nRA do aluno com a maior media: %d\n", RA2);
    printf("\nRA do aluno com a menor media: %d\n", RA3);
}
