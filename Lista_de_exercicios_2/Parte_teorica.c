/*
1.
Seja o seguinte trecho de programa:
int i=3, j=5;
int *p, *q;
p= &i;
q= &j;
Qual é o valor das expressões?
a) p == &i
b) *p-*q
d) 3*-*p/(*q-2)

Respostas:
a)Verdadeiro
b)-2
d)-3
*/

/*2.
Qual  é  a  instrução  que  deve  ser  adicionada  ao  programa  abaixo  para  que  ele
funcione corretamente?
void main() {
	int i, *ptri;
	*ptri = 0;
}

Resposta:Para inicializar o ponteiro sem atribuir nenhum endereço a este, deve ser usado "NULL" e não zero:
*ptri = NULL;
*/

/*3. **invox, *vox
Assumindo que o endereço de vox foi atribuído a um ponteiro variável invox, quais
das seguintes expressões são verdadeiras?
a) vox == &invox
b) vox == *invox
c) invox == *vox
d) invox == vox
e) &vox == &invox

Resposta:
A expressão "c" está correta, sendo c: o Conteúdo do endereço armazenado em invox é igual ao conteúdo de voz
*/

/*
4.
Na expressão float *fptr; o que é do tipo float?
(a) A variável fptr
(b) O endereço de fptr
(c) A variável apontada por fptr
(d) Nenhuma das anteriores

Resposta:
c
*/

/*5.
Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões
referenciam o valor do terceiro elemento do vetor?
(a) *(pulo + 2);
(b) *(pulo + 4);
(c) pulo + 4;
(d) pulo + 2;

Resposta:
a
*/

/*6.
Considerando a declaração abaixo, quais das
seguintes expressões são válidas? Justifique.
int mat[4], *p, x;
(a) p = mat + 1;
(b) p = mat++;
(c) p = ++mat;
(d) x = (*mat)++;

Resposta:
A expressão "a" é valida, pois está sendo passado o endereço de uma posição do vetor para o ponteiro
A expressão "b" é falsa, pois não há como incrementar uma posição do vetor sem seu índice, apenas com "++"
A expressão "c" é falsa, pelo mesmo motivo da anterior
A expressão "d" é verdadeira, pois "x" receberá a posição 0+1 do vetor, no caso a posição 1
*/

/*7. O que fazem os seguintes programas em C?
int main(){
 int vet[] = {4,9,13};
 int i;
 for(i=0;i<3;i++){
 printf("%d ",*(vet+i));
 }
}

int main(){
 int vet[] = {4,9,13};
 int i;
 for(i=0;i<3;i++){
 printf("%X ",vet+i);
 }
}

Resposta:
O primeiro programa printa o conteúdo de cada posição do vetor, andando com o índice de 1 em 1, já o segundo printa o endereço de cada posição, também andando de 1 a 1.
*/

/*8. Seja x um vetor de 4 elementos, declarado da forma TIPO x[4];. Suponha que
depois da declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o
endereço de x[0]). Suponha também que na máquina seja usada uma variável do tipo
char ocupa 1 byte, do tipo int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo
double ocupa 8 bytes. Quais serão os valores de x+1, x+2 e x+3 se:
(a) x for declarado como char?
(b) x for declarado como int?
(c) x for declarado como float?
(d) x for declarado como double?

Resposta:
(a)x+1=4093, x+2=4094, x+3=4095
(b)x+1=4096, x+2=4100, x+3=4104
(c)x+1=4096, x+2=4100, x+3=4104
(d)x+1=4100, x+2=4108, x+3=4116
*/

/*9. Seja o código abaixo:
#include <stdio.h>
int main(void) {
int mat[3] = {5, 9 , 11};
int *ptr;
ptr = mat;
printf(“ %d”, *ptr + 1);
printf(“ %d”, *(ptr + 1));
return 0; 1
}
O que será impresso? E para o código abaixo?
ptr = mat;
printf(“ %d”, *(ptr));
printf(“ %d”, *(ptr + 2));

Resposta:
No primeiro printf será printado o valor 5, e no segundo print será printado o valor 11
*/

/*10. Levando em consideração o trecho a seguir:
int *p;
int i;
int k;
i = 42;
k = i;
p = &i;
Qual das alternativas irá alterar o valor de i para 120?
a) k = 120;
b) *k = 120;
c) p = 120;
d) *p = 120;
e) Mais de uma resposta ira mudar o valor de i para 120.

Resposta:
Alternativa d
*/

/*11. Dado o programa abaixo, diga o valor das variáveis após cada atribuição. Tome um
valor aleatório como endereço de vetor.
int main()
{
char vetor[3] = {’A’,’B’,’C’};
char *j = &vetor[0];
char aux;
aux = vetor[0];//A
aux = *(vetor + 2);//C
aux = *(j + 1);//B
aux = *j;//A
j = vetor + 1;//B
aux = *j;//B
aux = *(j + 1);//C
j = vetor;//A
aux = *++j;//B
aux = ++*j;//B
aux = *j++;//B
aux = *j;//A
return 0;
}*/

/*12. Critique o codigo abaixo.
void troca (int *i, int *j)
{
  int *temp;//Ponteiro auxiliar criado
  *temp = *i;//Ponteiro auxiliar recebe o conteúdo de "i", no caso o endereço de "a"
  *i = *j;//Ponteiro "i" recebe o conteúdo do ponteiro "j", no caso o endereço de "b"
  *j = *temp;//Ponteiro "j" recebe o conteúdo da variável "temp", no caso o endereço de "a"
}

int main ()
{
  int a, b;
  a = 0;
  b = 1;
  troca(&a, &b);//Troca os endereços das variáveis "a" e "b"
  return 0;
}
*/
