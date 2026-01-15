#include <stdio.h>
#include "menu.h"

int menu() {
    int op = 0;

    do {
        printf("\n======= MENU =======\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Alunos\n");
        printf("0 - Sair\n");

        printf("Opção: ");
        scanf("%d", &op);

        if (op < 0 || op > 2) {
            printf("Opção inválida! Informe a opção do menu novamente!\n");
        }

    } while (op < 0 || op > 2);
    return op;
}
