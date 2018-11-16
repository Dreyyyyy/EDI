#include "lib.h"

//Todo o código é comentado, pois este é o único método de estudo (para aprender, memorizar e fixar) que eu encontrei até então.

// Recebe como parametro de entrada uma fila ou pilha x
// e cria um no cabeca em x.
int Cabeca(InicioFim *x) {
  TipoCelula *cabeca = (TipoCelula*)malloc(sizeof(TipoCelula));//Alocação dinâmica de memória
  if (cabeca == NULL) return 0;//Verifica se foi bem sucedida a alocação
  else {
    cabeca->chave = -1;//Valor qualquer apenas para representar o nó "head"
    cabeca->prox = NULL;//Como a cabeça é o primeiro é único nó da lista (em sua criação) o "->prox" aponta para nulo
    x->inicio = x->fim = cabeca;//Os ponteiros que marcam o início e o fim da lista apontam para o único nó criado até então
    return 1;
  }
}

// Recebe como parametro de entrada uma fila x
// e verifica se x esta vazia.
int Vazia(InicioFim *x) {
  if (x->inicio->prox == NULL) return 1;//Verifica se os ponteiros marcadores apontam para algum nó que seja nulo, caso positivo a lista está vazia
  else return 0;//Caso contrário, a lista possui nós com dados inseridos
}

// Recebe como parametro de entrada uma fila f e um inteiro k.
// Insere um item na fila f com valor chave k.
int InsereFila(InicioFim *f, int k) {
  TipoCelula *novoNo = (TipoCelula*)malloc(sizeof(TipoCelula));//Alocação dinâmica de memória
  if (novoNo == NULL) return 0;//Verifica se foi bem sucedida a alocação
  else {
    novoNo->chave = k;//Valor informado pela main é alocado ao novo nó
    novoNo->prox = NULL;//Próximo nó é nulo
    f->fim->prox = novoNo;//O último nó aponta para o novo último nó
    f->fim = novoNo;//O ponteiro marcado do fim da lista passa a apontar para o novo último nó
    return 1;//"Return" apenas para verificação
  }
}

// Recebe como parametro de entrada uma fila f.
// Remove um item da fila f.
int RemoveFila(InicioFim *f) {
  if (Vazia(f) == 1) return 0;//Chama a função que verifica se a fila está vazia, caso verdadeiro não há o que remover
  else {
    TipoCelula *noAux = f->inicio;//Auxiliar recebe o início da fila (no caso, o nó que será removido)
    f->inicio = f->inicio->prox;//Início da fila passa a ser o próximo nó
    free(noAux);//Libera o nó para o qual o ponteiro auxiliar apontava
    noAux = NULL;//Evita leitura e escrita ilegal
    return 1;//"Return" apenas para verificação
  }
}

// Recebe como parametro de entrada uma fila f.
// Remove todos os itens da fila f.
int FFVazia(InicioFim *f) {
  while (Vazia(f) != 1) {//Condição do laço: Enquanto a fila não estiver vazia, remove nó por nó
    RemoveFila(f);
  }
  return 1;//"Return" apenas para verificação
}

// Recebe como parametro de entrada uma fila f.
// Imprime todos os elementos de f.
void ImprimeFila(InicioFim *f) {
  TipoCelula *filaAux = f->inicio->prox;//Ponteiro auxiliar para não alterar o endereço da fila original
  if (filaAux == NULL) {//Caso a fila esteja vazia, não há como printar elementos
    printf("Lista vazia!\n");
    return;//"Return" para finalizar o procedimento
  }
  do {
    printf("Chave %d\n", filaAux->chave);//Printa a chave da fila
    filaAux = filaAux->prox;//Avança pelos nós da fila
  }while (filaAux != NULL);//Condição do laço: enquanto não chegar ao fim da fila
}

// Recebe como parametro de entrada uma pilha p e um inteiro k.
// Insere um item na pilha p com valor chave k.
int InserePilha(InicioFim *p, int k) {
  TipoCelula *novoNo = (TipoCelula*)malloc(sizeof(TipoCelula));//Alocação dinâmica de memória
  if (novoNo == NULL) return 0;//Verifica se foi bem sucedida a alocação
  else {
    novoNo->chave = k;//Novo nó recebe o valor informado na main
    novoNo->prox = p->fim;//Novo nó aponta seu ponteiro "->prox" para o fim da fila que já estava criada
    p->fim = novoNo;//Fim da fila passa a ser o novo nó;
    return 1;//"Return" apenas para verificação
  }
}

// Recebe como parametro de entrada uma pilha x
// e verifica se x esta vazia.
int VaziaP(InicioFim *p) {
    if (p->inicio == p->fim) return 1;//Caso o ínicio da pilha e o fim sejam o mesmo nó, a pilha está vazia
    else return 0;//"Return" apenas para verificação
}

// Recebe como parametro de entrada uma pilha p.
// Remove um item da pilha p.
int RetiraPilha(InicioFim *p) {
  if (VaziaP(p) == 1) return 0;//Verifica se a pilha já está vazia
  else {
    TipoCelula *noAux = p->fim;//Auxiliar aponta para o último nó da pilha
    p->fim = p->fim->prox;//Último nó passa a ser o próximo do fim (Bem semelhante a uma recursiva, interessante...)
    free(noAux);//Libera o nó onde o ponteiro auxiliar apontava
    noAux = NULL;//Evita leitura e escrita ilegal
    return 1;//"Return" apenas para verificação
  }
}

// Recebe como parametro de entrada uma pilha p.
// Remove todos os itens da pilha p.
int FPVazia(InicioFim *f) {
  while (VaziaP(f) != 1) {//Enquanto a pilha não estivar vazia, a função "RetiraPilha" remove nó por nó
    RetiraPilha(f);
  }
  return 1;//"Return" apenas para verificação
}

// Recebe como parametro de entrada uma pilha p.
// Imprime todos os elementos de p.
void ImprimePilha(InicioFim *p) {
  TipoCelula *pilhaAux = p->fim;//Auxiliar para não alterar o endereço da pilha original
  if (p->inicio == p->fim) {//Se a pilha estiver vazia, não há o que printar
    printf("Pilha vazia!\n");
    return;//Return para encerrar o procedimento
  }
  while(pilhaAux != p->inicio) {//Enquanto a pilha Auxiliar for diferente do ínicio da original, printa todos os nós
    printf("Chave: %d\n", pilhaAux->chave);
    pilhaAux = pilhaAux->prox;//Avança entre a pilha em direção ao começo (Que nesse caso é o final)
  }
}

// Lista de Exercicios de Fila e pilha

// Exercicio 1
InicioFim *ConcatenaPilha(InicioFim *f, InicioFim *g);

// Exercicio 2
//Concatena duas filas f e g
InicioFim *ConcatenaFila(InicioFim *f, InicioFim *g) {
  f->fim->prox = g->inicio->prox;//O último nó da fila aponta para o primeiro nó da segunda fila, assim unindo ambas as filas
  f->fim = g->fim;//O Ponteiro marcador do fim da primeira fila aponta para onde o ponteiro marcador do fim da segunda fila aponta
  free(g);//Libera a segunda fila, pois este não terá mais utilidade
  return f;//Retorna ambas as filas concatenada em f
}

// Exercicio 3
InicioFim *ConcatenaFilaPilha(InicioFim *f, InicioFim *p);

// Exercicio 4
InicioFim *ConcatenaPilhaFila(InicioFim *p, InicioFim *f);

// Exercicio 5
int QuantidadeElementosFP(InicioFim *fp);

// Exercicio 6
InicioFim *FilaInversa(InicioFim *f) {

}

// Exercicio 7
InicioFim *PilhaInversa(InicioFim *p);

// Exercicio 8
InicioFim *FilaImparPar(InicioFim *p);

// Exercicio 9
InicioFim *PilhaImparPar(InicioFim *p);

// Exercicio 10
InicioFim *FilaParRemovidos(InicioFim *f);

// Exercicio 11
InicioFim *PilhaImparRemovidos(InicioFim *p);

// Exercicio 12
int SomaElementosFila(InicioFim *p);

// Exercicio 13
int ProdutoElementosPilha(InicioFim *p);

// Exercicio 14-a
int buscaSequencial(int *v, int k, int ini, int fim);

// Exercicio 14-b
int buscaBinaria(int *v, int k, int ini, int fim);

// Exercicio 15-a
int buscaMaior(int *v, int n);

// Exercicio 15-b
int buscaMenor(int *v, int n);

// Exercicio 15-c
int buscaSomaPares(int *v, int n);

// Exercicio 15-d
int buscaSomaImpares(int *v, int n);

// Exercicio 15-e
int buscaMaiorPar(int *v, int n);

// Exercicio 15-f
int buscaMaiorImpar(int *v, int n);

// Exercicio 15-g
int buscaMenorTrocaPrimeira(int *v, int n);

// Exercicio 15-h
int buscaMaiorTrocaUltima(int *v, int n);
