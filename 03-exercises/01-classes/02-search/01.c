#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void exibirVetor(int n, int vetor[]){
    printf("Exibindo os elementos do Vetor:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaBinaria(int vetor[], int n, int valorBuscado) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = vetor[middle];

        if (valorBuscado == pos) {
            return middle; // index
        } else if (valorBuscado > pos) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

    }

    return -1;
}

int main() {
    int vetor[TAM];
    int valorBuscado;
    int resultado = -1;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Geração do vetor com valores aleatórios entre 0 e 99
    for (int i = 0; i < TAM; i++) {
        vetor[i] = rand() % 100;
    }

    // Ordenando o vetor
     for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    exibirVetor(TAM, vetor);
    // Solicita ao usuário o valor a ser buscado
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valorBuscado);

    // IMPLEMENTAR AQUI
    resultado = buscaBinaria(vetor, TAM, valorBuscado);

    // Exibição do resultado
    if (resultado != -1) {
        printf("Valor encontrado na posição %d do vetor.\n", resultado);
    } else {
        printf("Valor não encontrado no vetor.\n");
    }

    return 0;
}