#include <stdio.h>

// menor elemento maior ou igual a x
// menor elemento -- indices menores, direciona para esquerda
int findLowerBound(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos >= x) {
            result = pos;
            right = middle - 1;
        } else { // pos < x
            left = middle + 1;
        }
    }

    return result;
}

// maior elemento menor ou igual a x
// maior elemento -- índices maiores, direciona para a direita
int findUpperBound(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];
        
        if (pos <= x) {
            result = pos;
            left = middle + 1;
        } else { // pos > x
            right = middle - 1;
        }   
    }
    return result;
}



int main() {

    return 0;
}