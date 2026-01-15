#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// reverse array
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

// rotate array clockwise
/*
The idea is based on the observation that if we right rotate the array by d positions, the last d elements will be in the front and first (n - d) elements will be at the end. 
*/

void reverseBy(int *arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int d) {
    if (n <= 0) return;

    // handle the case where d > n
    d %= n;
    if (d == 0) return;

    // reverse the entire array
    reverseBy(arr, 0, n - 1);

    // reverse que first d elements
    reverseBy(arr, 0, d - 1);

    // reverse the last n - d elements
    reverseBy(arr, d, n - 1);
} 

// rotate array counterclockwise
/*
The idea is based on the observation that if we left rotate the array by d positions, the last (n - d) elements will be at the front and the first d elements will be at the end. 
*/

void rotateLeft(int arr[], int n, int d) {
    // reverse the first d elements
    reverseBy(arr, 0, d - 1);

    // reverse the last (n - d) elements
    reverseBy(arr, d, n - 1);

    // reverse all array
    reverseBy(arr, 0, n - 1);
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed");
        exit(1);
    }
    return ptr;
}

int generateRandom() {
    return rand() % 10 + 1;
}

int* arrAlloc(int n) {
    int* arr = (int*) safeMalloc(n);
    for (int i = 0; i < n; i++) {
        arr[i] = generateRandom();
    }
    return arr;
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int n = 5;
    int *arr = arrAlloc(n);

    printArray(arr, n);

    reverse(arr, n);

    printArray(arr, n);

    printf("\n");

    int array[] = { 1, 2, 3, 4, 5 };
    int d = 2;

    printArray(array, n);

    rotateRight(array, n, d);
    printf("roteted %d times to right = \n", d);
    printArray(array, n);

    printf("\n");

    rotateLeft(array, n, d);
    printf("roteted %d times to left = \n", d);
    printArray(array, n);

    return 0;
}