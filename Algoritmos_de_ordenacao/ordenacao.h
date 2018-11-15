#ifndef _H_ORDENACAO_
#define _H_ORDENACAO_

#include <stdio.h>
#include <stdlib.h>

void Troca(int *x, int *y);

int Busca_menor(int *v, int i, int fim);

//void Merge(int *v, int ini, int meio, int fim);

void BubbleSort(int *v, int ini, int fim);

void SelectionSort(int *v, int ini, int fim);

void InsertionSort(int *v, int ini, int fim);

void QuickSort(int *v, int ini, int fim);

/*void ShellSort(int *v, int ini, int fim);

void MergeSort(int *v, int ini, int fim);*/

#endif
