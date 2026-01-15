#include <stdio.h>

int iterativeBinarySearch(int arr[], int n, int k, int *hints) {
    int left = 0;
    int right = n - 1;

    *hints = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2; // prevent integer overflow
        int pos = arr[middle]; // kick

        (*hints)++;

        if (k == pos) {
            return middle;
        } else if (k > pos) { // low kick
            left = middle + 1; // adjust upper boundary
        } else { // high kick -- k < pos
            right = middle - 1; // ajust lower boundary
        }
    }

    return -1;
}

int recursiveBinarySearch(int arr[], int n, int k, int left, int right) {
    if (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (k == pos) {
            return middle; // at some point it will get here
        }

        if (k < pos) { // high kick -- fix right side: middle to left 
            return recursiveBinarySearch(arr, n, k, left, middle - 1);
        }

        // else (k > pos)
        return recursiveBinarySearch(arr, n, k, middle + 1, right); // low kick -- fix left side: middle to right
    }

    return -1;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    int hint = 0;

    int result = iterativeBinarySearch(arr, n, k, &hint);
    if (result != 1) {
        printf("found %d at %d after %d guesses\n", k, result, hint);
    } else {
        printf("nothing found!!\n");
    }

    return 0;
}

/*
1.
Usar
left + (right - left) / 2
evita overflow inteiro.

Quando você faz
(left + right) / 2,
a soma pode ultrapassar o valor máximo que um int suporta se o vetor for grande, gerando um índice errado.

Já right - left sempre cabe no intervalo válido, porque representa apenas o tamanho da janela de busca. Somar isso a left é matematicamente equivalente, mas computacionalmente mais seguro.

2.
Usar
left <= right
garante que o intervalo de busca inclui todos os índices ainda possíveis, inclusive quando resta exatamente um único elemento (left == right, pior cenário)

Quando você faz
left < right
o loop termina antes de verificar o último elemento possível, pois quando left == right a condição falha e o laço é interrompido sem comparação
*/