#include <stdio.h>
#include <stdlib.h>

struct No {
    int chave;
    struct No *prox;
}
;typedef struct No no;

struct InicioFim {
    struct No *ini;
    struct No *fim;
}
;typedef struct InicioFim iniciofim;

iniciofim *aloca();

void printa_fila(iniciofim *fila);

void printa_pilha(iniciofim *pilha);

int cria_cabeca(iniciofim *fila);

int verifica_vazia_fila(iniciofim *fila);

int insere_ini_fila(iniciofim *fila, int chave);

int remove_ini_fila(iniciofim *fila);

int remove_toda_fila(iniciofim *fila);

int verifica_vazia_pilha(iniciofim *pilha);

int insere_topo_pilha(iniciofim *pilha, int chave);

int remove_topo_pilha(iniciofim *pilha);

int remove_toda_pilha(iniciofim *pilha);

iniciofim *concatena_filas(iniciofim *f, iniciofim *g);

iniciofim *concatena_pilhas(iniciofim *pilha1, iniciofim *pilha2);

iniciofim *concatena_fila_pilha(iniciofim *f, iniciofim *p);
