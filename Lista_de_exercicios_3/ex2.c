/*2.
Faça uma agenda de compromissos:
a.Crie e leia um vetor de n estruturas de dados contendo: compromisso 
(máximo 60 letras) e data. 
b.A data deve ser outra estrutura de dados contendo dia, mês e ano. 
c.Leia  dois  inteiros m(mês) e a(ano)
.Apresente todos  os  compromissos  do mês m do ano a
.Repita o procedimento até ler m = 0.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoData{
	int m;
	int a;
}tipo_data;

typedef struct agenda_compromissos {
	char compromisso[60];
	tipo_data data;
}agenda;

agenda *aloca(int n);
void printa_compromissos(agenda *cmp, int n);

int main() {
	int n = 0, i = 0;
	printf("\nInforme o número de compromissos desejados para sua agenda: ");
	scanf("%d", &n);
	agenda *cmp = NULL;
	cmp = aloca(n);
	for (i = 0; i < n; i++) {
		printf("\nDigite o nome do %dº compromisso(máximo de 60 caracteres): ", i+1);
        setbuf(stdin, NULL);
		scanf("%[^\n]", cmp[i].compromisso);
		printf("\nAgora, digite a data em que este irá ocorrer(mês e ano, sequencialmente): ");
		scanf("%d%d", &cmp[i].data.m, &cmp[i].data.a);
	}
	printa_compromissos(cmp, n);
	return 0;
}

agenda *aloca(int n) {
	agenda *aux = NULL;
	aux = (agenda*)malloc(sizeof(agenda) * n);
	if (aux == NULL) return NULL;
	else return aux;
}

void printa_compromissos(agenda *cmp, int n) {
    int i = 0, ano = 0;
    printf("\nInforme o ano ao qual deseja ver os compromissos: ");
    scanf("%d", &ano);
    for (i = 0; i < n; i++) {
        if (cmp[i].data.a == ano) {
            printf("\nCompromisso: %s, Mês: %d, Ano: %d\n\n", cmp[i].compromisso, cmp[i].data.m, cmp[i].data.a);
        }
    }
}
