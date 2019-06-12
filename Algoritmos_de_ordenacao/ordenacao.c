#include "ordenacao.h"

//Meu código está todo comentado, pois essa foi a minha forma de memorizar, entender e estudar o que eu fiz(E tentar explicar mas acho que tem coisas ali que só vão fazer sentido para mim :")).

void Troca(int *x, int *y) {
  int aux;//Variável para auxiliar no "sort"
  aux = *x;//Auxiliar recebe o conteúdo de "x"
  *x = *y;//O conteúdo de "x" passa a ser o conteúdo de "y"
  *y = aux;//O conteúdo de "y" passa a ser a variável auxiliar
}

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

void ShellSort(int *v, int ini, int fim) {
  int tam = fim-ini+1;//fórmula para o tamanho do vetor
  int dist = tam / 2;//o "gap" ou a distância entre o elemento escolhido e o próximo será representado aqui
  while (dist > 0) {//Condição do laço: enquanto a distância for maior que zero (pois se já for zero não há mais elementos para comparar)
    int i = 0, j = 0;//Variáveis para laço inicializadas em zero por precaução
    //Sinceramente eu não entendi muito o que acontece daqui, vi vários tutoriais e todos eram muito semelhantes com essa parte, então eu a coloquei e testei e deu certo, mas não consegui entender as iterações de forma completa
    for (int i = dist; i < tam; i++) {
      int varAux = v[i];
      for (j = i; j >= dist && v[j-dist] > varAux; j -= dist) {
        v[j] = v[j-dist];
      }
      v[j] = varAux;
    }
    dist = dist / 2;//A distância sempre deve ser a metade da distância anterior para a próxima iteração
  }
}

void MergeSort(int *v, int ini, int fim) {
  //Essa função serve primeiramente para dividir os dados em duas partes, para depois ser aplicado a função "Merge"
  int meio = 0;
  if (ini < fim) {//Verifica se é possível fazer a divisão
    meio = floor((ini + fim)/ 2);//Divide no meio usando a função piso para arredondar
    MergeSort(v, ini, meio);//Divide a parte do começo para o meio
    MergeSort(v, meio+1, fim);//Divide do meio para o fim
    Merge(v, ini, meio, fim);//Finalmente, com o meio já encontrado e o vetor divido, a função merge é chamada
  }
}

void Merge(int *v, int ini, int meio, int fim) {
  int i, j, k, *vetorAux, tam = fim-ini+1, fim1 = 0, fim2 = 0;
  int parte1 = ini;//1ª parte do vetor que foi separado anteriormente
  int parte2 = meio+1;//2ª parte do vetor que foi separado anteriormente
  vetorAux = (int*)malloc(sizeof(int));//vetor temporário onde será feita a organização destes dois vetores
  if (vetorAux == NULL) return;//Verifica se o sitema alocou memória
  else {
    for (i = 0; i < tam; i++) {//Condição do laço: enquanto i for menor que o tamanho do vetor
      if (!fim1 && !fim2) {//If para verificar se é 1 ou 0 a condição de fim, caso já tenha chegado no final dos vetores repartidos (como se fosse uma booleana)
        if (v[parte1] < v[parte2]) {//Se o elemento da parte 1 for menor que o elemento da parte 2, este será colocado no auxiliar, e logo após é incrementado a parte 1
          vetorAux[i] = v[parte1++];
        }
        else vetorAux[i] = v[parte2++];//Caso contrário, o menor será a parte 2, então ela sera colocada, por conseguinte já é incrementado a parte 2
        if (parte1 > meio) fim1 = 1;//Verifica se a parte 1 já chegou ao seu fim (serve para o if lá de cima)
        if (parte2 > fim) fim2 = 1;//Verifica se a parte 2 já chegou ao seu fim (serve para o if lá de cima)
      }
      else {//Caso o if (o primeiro lá de cima) seja falso, então um dos vetores já chegou ao final, logo não há necessidade de ficar comparando, então entra nesse else e termina de colocar os elementos no vetor auxiliar
        if (!fim1) vetorAux[i] = v[parte1++];
        else vetorAux[i] = v[parte2++];
      }
    }
    for (j = 0, k = ini; j < tam; j++, k++) {//Último laço, serve para colocar os elementos do auxiliar no vetor original
      v[k] = vetorAux[j];
    }
  }
  free(vetorAux);//Após já ter sido copiado os elementos, o vetor auxiliar tem sua memória liberada
  vetorAux = NULL;//Evita leitura e escrita ilegal
}
