#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Estrutura de cada aluno
struct tipoAluno {
    char nome[80];
    int ra[10];
    struct tipoAluno *aluno;
    struct tipoAproveitamento *aproveitamento;
}
;typedef struct tipoAluno aluno;

//Estrutura de cada aproveitamento
struct tipoAproveitamento {
    float notas[3];
    float frequencia;
    struct tipoTurma *turma;
    struct tipoAproveitamento *aproveitamento;
}
;typedef struct tipoAproveitamento aproveitamento;

//Estrutua de cada disciplina
struct tipoDisciplina {
    int codigo, cargahoraria;
    char nome[20];
    struct tipoDisciplina *disciplina;
}
;typedef struct tipoDisciplina disciplina;

//Estrutura de cada turma
struct tipoTurma{
    int codigo;
    int ano;
    char semestre;
    char situacao;
    struct tipoProfessor *professor;
    struct tipoDisciplina *disciplina;
    struct tipoAluno *Alunos;
    struct tipoTurma *turma;
}
;typedef struct tipoTurma turma;

//Estrutura de cada professor
struct tipoProfessor {
    char nome[80];
    int anoEntrada;
    int anoSaida;
    struct tipoTurma *turmas;
    struct tipoProfessor *professor;
}
;typedef struct tipoProfessor professor;
