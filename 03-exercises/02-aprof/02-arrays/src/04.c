#include <stdio.h>
#include <stdlib.h>

int* removeDuplicates(int arr[], int n) {
    int* temp = (int*) malloc(n * sizeof(int));
    if (temp == NULL) {
        exit(1);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        for (; j < count; j++) {
            if (arr[i] == temp[j]) {
                break;
            }
        }

        if (j == count) {
            temp[count] = arr[i]; // non duplicate
            count++;
        }
    }

    int* result = (int*) realloc(temp, count * sizeof(int));
    if (result == NULL) {
        exit(1);
    }

    return result;
}

void removeDuplicatesInPlace(int arr[], int n) {
    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[pos]) {
            arr[pos] = arr[i];
            pos++;
        }
    }
}

/*
Em linhas gerais, essa função **remove duplicatas in-place mantendo a ordem**, usando dois índices com papéis bem diferentes.

A ideia central é: **`pos` marca a posição do próximo elemento único**, enquanto `i` percorre o array inteiro.

* `i` é o leitor: varre todos os elementos do início ao fim.
* `pos` é o escritor: aponta para onde o próximo valor “novo” deve ser colocado.

A cada iteração, o código compara `arr[i]` com o último valor único já aceito (`arr[pos]`):

* Se forem iguais, significa duplicata → ignora.
* Se forem diferentes, encontrou um novo valor → escreve em `arr[pos]` e avança `pos`.

No final:

* As posições `0` até `pos - 1` contêm apenas valores únicos.
* O resto do array fica irrelevante (lixo lógico).

Pontos importantes que **não estão explícitos no código**, mas são pressupostos:

* O array **precisa estar ordenado**, porque o algoritmo só detecta duplicatas comparando elementos adjacentes; se o array não estiver ordenado, valores iguais podem aparecer separados e não serão identificados como duplicados.
* A função **não retorna o novo tamanho**, mas o valor correto seria `pos`.

Em essência: é um algoritmo linear (`O(n)`), in-place (`O(1)`), que troca espaço extra por um controle cuidadoso de índices — exatamente o tipo de técnica que você vê o tempo todo em C, Java e entrevistas técnicas.
*/

int main() {

    return 0;
}