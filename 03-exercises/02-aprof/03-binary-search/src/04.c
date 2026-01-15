#include <stdio.h>

/*
Um vetor foi ordenado e depois rotacionado (direita) Encontre x em O(log n)

para rotacionar um vetor para direita:
1. reversão do vetor todo
2. reversão dos primeiros d elementos
3. reversão dos últimos (n - d) elementos

para (des)rotacionar um vetor que foi rotacionado para direita:
1. reversão dos primeiros d elementos
2. reversão dos últimos (n - d) elementos
3. reversão do vetor inteiro

dessa forma, temos o array ordenado. se ele está ordenado, podemos encontrar o elemento x por busca binária (O(log n))
*/

void printArr(int *arr, int n) {
    printf(" { ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        printf("%s", i < n - 1 ? ", " : "");
    }
    printf(" } \n");
}

// algoritmo de reversão
void reverse(int *arr, int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

// implementação do algoritmos de rotação

void reverseBy(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotate(int arr[], int n, int d) {
    // reverse all array
    reverseBy(arr, 0, n - 1);

    // reverse the first d elements
    reverseBy(arr, 0, d - 1);

    //reverse the last (n - d) elements
    reverseBy(arr, d, n - 1);
}

void desRotate(int arr[], int n, int d) {
    // reverse the first d elements
    reverseBy(arr, 0, d - 1);

    //reverse the last (n - d) elements
    reverseBy(arr, d, n - 1);

    // reverse all array
    reverseBy(arr, 0, n - 1);
}

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos == x) {
            return middle;
        } else if (pos < x) {
            left = middle + 1;
        } else { // pos > x
            right = middle - 1; 
        }
    }

    return -1;
}


int main() {

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int n = sizeof(arr) / sizeof(arr[0]);
    
    // printArr(arr, n);
    // reverseBy(arr, 0, n - 1);
    // printArr(arr, n);

    int arr[] = { 2, 3, 6, 12, 15, 18 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, n);

    rotate(arr, n, 2);
    printArr(arr, n);

    desRotate(arr, n, 2);
    printArr(arr, n);

    printf("%d\n", binarySearch(arr, n, 6));

    return 0;
}