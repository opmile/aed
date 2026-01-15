#ifndef ALUNO_H
#define ALUNO_H

#define MAX_ALUNOS 5
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int matricula;
} Aluno;

void cadastrarAluno(Aluno* alunos, int* tamanhoTotal);
void listarAlunos(Aluno* alunos, int total);

#endif