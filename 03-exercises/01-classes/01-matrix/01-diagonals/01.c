#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom();

void* safeMalloc(size_t size);

int** matrixAllocation(int rows, int cols);

void freeMatrix(int **matrix, int rows);

void printMatrix(int** matrix, int rows, int cols);

void fillMatrix(int** matrix, int rows, int cols);

void printMainDiagonal(int** matrix, int rows, int cols);

void printSecondaryDiagonal(int** matrix, int rows, int cols);

int main() {
    srand(time(NULL));

    int n = 0;
    printf("enter matrix dimension: ");
    scanf("%d", &n);

    int** matrix = matrixAllocation(n, n); // matrix n x n

    printMatrix(matrix, n, n);

    printf("Main Diagonal: ");
    printMainDiagonal(matrix, n, n);

    printf("Secondary Diagonal: ");
    printSecondaryDiagonal(matrix, n, n);

    freeMatrix(matrix, n);

    return 0;
}

int generateRandom() {
    return rand() % 100; // generates a random integer between 0 and 99
}

void* safeMalloc(size_t size) {
    void *ptr = (void*) malloc(size);

    if (ptr == NULL) {
        printf("allocation error!");
        exit(1);
    }
    return ptr;
}

int** matrixAllocation(int rows, int cols) {
    int** matrix = (int**) safeMalloc(rows * sizeof(int*)); // alloc 

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) safeMalloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols);

    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int** matrix, int rows, int cols) {
    printf("{\n");
    for (int i = 0; i < rows; i++) {
        printf("  {");
        for (int j = 0; j < cols; j++) {
            printf("%d", matrix[i][j]);
            if (j < cols - 1) printf(", ");
        }
        printf("}%s\n", i < rows - 1 ? ", " : "");
    }
    printf("}\n");
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom();
        }
    }
}

void printMainDiagonal(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

// function only works by assuming that the analized matrix is quadratic
void printSecondaryDiagonal(int** matrix, int rows, int cols) {
    if (rows != cols) {
        printf("non quadratic matrix!");
        return;
    }

    int n = rows;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i + j == n - 1) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}