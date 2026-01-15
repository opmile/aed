#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandom();

void* safeMalloc(size_t size);

int** matrixQAlloction(int n); // working with quadratic form

void fillMatrix(int **matrix, int n);

void printMatrix(int **matrix, int n);

int sumUpperMainDiagonal(int **matrix, int n);

int countEvenLowerMainDiagonal(int **matrix, int n);

int main() {
    srand(time(NULL));

    int n = 0;
    printf("enter matrix dimension: ");
    scanf("%d", &n);

    int **matrix = matrixQAlloction(n);

    printMatrix(matrix, n);
    printf("\n");

    int sumUpper = sumUpperMainDiagonal(matrix, n);
    printf("Sum of all elements from above main diagonal = %d\n", sumUpper);

    int countLower = countEvenLowerMainDiagonal(matrix, n);
    printf("Count of all even elements from below main diagonal = %d\n", countLower);

    return 0;
}

int generateRandom() {
    return rand() % 10 + 1; // 0 to 10
}

void *safeMalloc(size_t size) {
    void *ptr = (int*) malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

int** matrixQAlloction(int n) {
    int **matrix = (int**) safeMalloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) safeMalloc(n * sizeof(int));
    }

    fillMatrix(matrix, n);

    return matrix;
}

void fillMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = generateRandom();
        }
    }
}

void printMatrix(int **matrix, int n) {
    printf("{\n");
    for (int i = 0; i < n; i++) {
        printf("  {");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(", ");
        }
        printf("}%s\n", i < n - 1 ? ", " : "");
    }
    printf("}\n");
}


// element from main diagonal (i, i) --- assuming quadratic form
int sumUpperMainDiagonal(int **matrix, int n) {
    int sum  = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int countEvenLowerMainDiagonal(int **matrix, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                matrix[i][j] % 2 == 0 ? count++ : 0;
            }
        }
    }
    return count;
}