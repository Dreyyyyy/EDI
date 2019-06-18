#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	time_t current_time;
	struct tm *time_info;
	char year[5];
	current_time = time(NULL);//Pega a hora atual do sistema e a armazena numa variável do tipo time_t, passada como parâmetro.
	time_info = localtime(&current_time);//Converte um valor do tipo time_t em uma estrutura tm.
	strftime(year, 5, "%Y", time_info);//Formata um valor do tipo time_t e armazena o valor numa string (deve se passar para a função a variável de destino, o número de elementos que irá para o vetor char (incluindo \0), o tipo da variável, (no caso %Y de Year) e o ponteiro contendo o horário para conversão.	
	printf("Ano corrente: %s\n", year);	
	return 0;
}
