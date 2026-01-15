#include <stdio.h>
#include "aluno.h"
#include "menu.h"

int main() {

    Aluno alunos[MAX_ALUNOS];
    int total = 0;
    int opcao = 0;

    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &total);
                break;
            case 2:
                listarAlunos(alunos, total);
                break;
            case 0:
                printf("Encerrando...");
                break;
        }
    } while (opcao != 0);

    return 0;
}