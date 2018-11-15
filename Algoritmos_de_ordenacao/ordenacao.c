#include "ordenacao.h"

//Meu código está todo comentado, pois essa foi a minha forma de memorizar, entender e estudar o que eu fiz.

void Troca(int *x, int *y) {
  int aux;//Variável para auxiliar no "sort"
  aux = *x;//Auxiliar recebe o conteúdo de "x"
  *x = *y;//O conteúdo de "x" passa a ser o conteúdo de "y"
  *y = aux;//O conteúdo de "y" passa a ser a variável auxiliar
}

//void Merge(int *v, int ini, int meio, int fim);

void BubbleSort(int *v, int ini, int fim) {
//Esta função percorre o vetor por completo verificando sempre de dois em dois, e vendo se estes estão em ordem crescente, até que este seja organizado.
  int i = 0, j = 0;//Variáveis para laço inicializadas em zero por precaução
  for (i = ini; i < fim; i++) {//Condição do laço: Enquanto "i" for menor que o fim
    for (j = 0; j < fim; j++) {//Condição do laço: Enquanto o "j" for menor que o fim
      if (*(v+j) >= *(v+j+1)) {//Caso no vetor que está sendo percorrido, o elemento da posição "j" for maior que o seu sucessor, a função "Troca" será chamada
        Troca(v+j, v+j+1);//Tal função mudará as posições, para deixar o vetor em ordem crescente no final das iterações
      }
    }
  }
}

void SelectionSort(int *v, int ini, int fim) {
  //Esta função percorre o vetor inicialmente buscando o menor elemento, e depois sempre o trocando pela primeira posição não ordenada, de forma que isso a ordenará (Outra explicação que só deve fazer sentido pra mim)
  int i = 0, j = 0, menor = 0, aux;//Variáveis para laço inicializadas em zero por precaução
  for(i = 0; i < fim; i++) {//Condição do laço: Enquanto "i" for menor que o fim
    menor = i;//menor elemento começa como o primeiro do vetor
    for (j= i+1; j < fim+1; j++) {//Condição do laço: Enquanto o "j" for menor que o fim+1
      if (v[j] < v[menor]) {//Caso o vetor na posição "j" seja menor do que o atual índice que contém o menor vetor
        menor = j;//O novo menor passará a ser tal índice
      }
    }
    if (menor != i) {//Verifica se o menor índice já não é o primeiro elemento do vetor
      Troca(v+i, v+menor);//Caso não for, troca o primeiro elemento com o elemento encontrado
    }
  }
}

void InsertionSort(int *v, int ini, int fim) {
  //Esta função percorre todo o vetor, e ordena o parte por parte, colocando sempre o vetor em questão no auxiliar, verifica se este é menor que seus anteriores e o coloca em seu lugar correto;
  int i = 0, j = 0, aux;//Variáveis para laço inicializadas em zero por precaução
  for (i = (ini+1); i <= fim; i++) {//Condição do laço: Enquanto "i" for menor ou igual ao fim
    aux = v[i];//Auxiliar recebe o elemento em questão, para ser comparado aos seus anteriores
    j = i-1;//j recebe a posição i-1
    while (j >= ini && aux < v[j]) {//Enquanto o j for maior que o início e o auxiliar ser menor do que o elemento do vetor na posição j
      Troca(v+j+1, v+j);//Tal elemento é trocado com o seu anterior, e isso repete a cada iteração até que a parte inicial seja ordenada
      j = j-1;//j recebe a posição i-1
    }
  }
}

void QuickSort(int *v, int ini, int fim) {
  //Esta função tem como objetivo dividir a organização em partes menores, assim sendo mais fácil de se organizar, logo inicia-se com o pivo, e este vai sendo comparado com todos, e os elemeento são ordenados por ordem crescente, menores antes do pivo e maiores depois, até que tudo seja organizado.
  int i = ini, j = fim, pivo = v[ini];//Variáveis inicializadas
  while (i <= j) {//Condição do laço: Enquanto "i" for menor igual a "j"
    while (v[i] < pivo) {//Condição do laço: Enquanto vetor no índice "i" for menor que pivo
      i = i+1;//i é incrementado(Busca um elemento da esquerda para direita que seja menor que meu pivo)
    }
    while (v[j] > pivo) {//Condição do laço: Enquanto vetor no índice "j" for maior que o pivo
      j = j-1;//j é decrementado(Busca um elemento da direita para esquerda que seja maior que meu pivo)
    }
    if (i <= j) {//Se o meu índice da esquerda for menor que o da direita, entra nessa condição e troca os elementos, para organizá-los de forma que os menores fiquem na esquerda do pivo e os maiores na direita
      Troca(v+i, v+j);
      i = i+1;
      j = j-1;
    }
  }
  if (ini < j) {
    QuickSort(v, ini, j);//Esta recursividade organiza um lado do vetor
  }
  if (i < fim) {
    QuickSort(v, i, fim);//Esta recursividade organiza o outro lado do vetor
  }
}

/*void ShellSort(int *v, int ini, int fim);

void MergeSort(int *v, int ini, int fim);*/
