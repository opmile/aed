#include <stdio.h>
#include "aluno.h"


void cadastrarAluno(Aluno* alunos, int* tamanhoTotal) {
    if (*tamanhoTotal >= MAX_ALUNOS) {
        printf("limite de alunos atingidos!");
        return;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", alunos[*tamanhoTotal].nome);

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &alunos[*tamanhoTotal].matricula);

    (*tamanhoTotal)++;

    printf("\nAluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno* alunos, int tamanhoTotal) {
    if (tamanhoTotal == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    printf("\n--------- Lista de Alunos ---------\n");
    for (int i = 0; i < tamanhoTotal; i++) {
        printf("\n");
        printf("ALUNO: %s\n", alunos[i].nome);
        printf("MATRÍCULA: %d\n", alunos[i].matricula);
        printf("\n");
    }
}