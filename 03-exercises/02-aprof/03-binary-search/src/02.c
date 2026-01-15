#include <stdio.h>

/*
dado um vetor ordenado com repetidos, encontre o índice da primeira ocorrência de x

destaques:
* vetor ordenado
* implementar binary search

int arr[] = { 1, 1, 2, 2, 2, 3, 4, 4, 5, 6 }
int x = 4
output == 6 (index)
*/

/*
encontraremos x por pesquisa binária
como temos elementos repetidos, pode não ser a primeira ocorrência desse x que achamos
então guardamos o resultado em uma variável e continuamos a busca para a esquerda, descartando os elementos da direita
isso porque a primeira ocorrência do elemento x ocorre em índices menores, mais à esquerda, ao passo que índices maiores se encontram a direita
*/

int findFirstOccurence(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos == x) {
            result = middle;
            right = middle - 1;
        } else if (pos < x) {
            left = middle + 1;
        } else { // pos > x
            right = middle - 1;
        }
    }

    return result;
}

/*
a mesma lógica de encontrar o elemento da primeira occorência se aplica para a da última ocorrência
a única diferença é que ao encontrar o elemento x, pode ser que essa não seja sua última ocorrência
da mesma forma, guardaremos o resultado como um candidato válido, eliminamos os candidatos à esquerda do meio e partimos a busca para os elementos à direita
isso porque, a última ocorrência de x só pode estar em índices maiores, esses que estarão sempre à direita
*/

int findLastOccurrence(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos == x) {
            result = middle;
            left = middle + 1;
        } else if (pos > x) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    } 

    return result;
}

int main() {


}