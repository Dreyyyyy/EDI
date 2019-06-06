#include "lib.h"

int main(void) {
    char login[50], senha[50], *temp = NULL, loginTemp[50], senhaTemp[50], lpP[] = "Professor", lpA[] = "Student", lpG[] = "Gerenciador", sp[] = "BCC%20#19&*";
    FILE *bancoSenhas = NULL;
    printf("\n=>Gerenciador de banco de dados - DAINF\n");
    printf("=>Digite seu login e senha:\n");
    printf("=>LOGIN: ");
    scanf("%[^\n]", login);
    setbuf(stdin, NULL);
    printf("=>SENHA: ");
    scanf("%[^\n]", senha);
    setbuf(stdin, NULL);
    bancoSenhas = fopen("banco_senhas.txt", "r");
    if (bancoSenhas == NULL) {
        printf("\n=>O arquivo de dados contendo as senhas salvas não pode ser aberto!\n");
        return 1;
    }
    else {
        while (!feof(bancoSenhas)) {
            fscanf(bancoSenhas, "%s %s", loginTemp, senhaTemp);
            if (strcmp(loginTemp, login) == 0 && strcmp(senhaTemp, senha) == 0) {
                //IMPLEMENTAR FUNÇÕES AQUI
                return 1;
            }
        }
        fclose(bancoSenhas);
        do {
            printf("=>Usuário não encontrado no banco de dados.\n");
            printf("=>Caso seja seu primeiro login, digite o login e senha padrões recebidos pelo e-mail para criar um acesso pessoal:\n");
            printf("=>Digite seu login e senha:\n");
            printf("=>LOGIN: ");
            scanf("%s", login);
            printf("=>SENHA: ");
            scanf("%s", senha);
        }while (strcmp(login, lpP) != 0 && strcmp(senha, sp) || strcmp(login, lpA) != 0 && strcmp(senha, sp)|| strcmp(login, lpG) != 0 && strcmp(senha, sp));
        bancoSenhas = fopen("banco_senhas.txt", "a");
        if (bancoSenhas == NULL) {
            printf("\n=>O arquivo de dados contendo as senhas salvas não pode ser aberto!\n");
            return 1;
        }
        else {
            if (strcmp(login, lpP) == 0) {
                printf("=>Professor logado com sucesso, agora, informe qual será o seu login e senhas pessoais: ]\n"); 
                printf("=>LOGIN: ");
                scanf("%s", login);
                printf("=>SENHA: ");
                scanf("%s", senha);
                fprintf(bancoSenhas, "%s %s\n", login, senha);   
            }
            else if (strcmp(login, lpA) == 0) {
                printf("=>Aluno logado com sucesso, agora, informe qual será o seu login e senhas pessoais:\n");
                printf("=>LOGIN: ");
                scanf("%s", login);
                printf("=>SENHA: ");
                scanf("%s", senha);    
                fprintf(bancoSenhas, "%s %s\n", login, senha);   
            }
            else if (strcmp(login, lpG) == 0) {
                printf("=>Gerenciador logado com sucesso, agora, informe qual será o seu login e senhas pessoais:\n");
                printf("=>LOGIN: ");
                scanf("%s", login);
                printf("=>SENHA: ");
                scanf("%s", senha);
                fprintf(bancoSenhas, "%s %s\n", login, senha);    
            }
            fclose(bancoSenhas);
            //IMPLEMENTAR FUNÇÕES AQUI
        }
    }
    return 0;
}
