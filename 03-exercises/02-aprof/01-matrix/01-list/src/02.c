#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandom();
void* safeMalloc(size_t size);
int** matrixAllocation(int rows, int cols);
void fillMatrix(int **matrix, int rows, int cols);
void printM(int **matrix, int rows, int cols);
void printMainDiagonal(int **matrix, int rows, int cols);
void printSecondaryDiagonal(int **matrix, int rows, int cols);
int calculateSumXForQuadratic(int **matrix, int rows, int cols);
int calculateSumX(int **matrix, int rows, int cols);

int main() {
    srand(time(NULL));

    int rows = 0, cols = 0;

    printf("enter number of rows: ");
    scanf("%d", &rows);
    
    printf("enter number of cols: ");
    scanf("%d", &cols);

    int **matrix = matrixAllocation(rows, cols);

    printM(matrix, rows, cols);

    printf("\n");

    printf("Main Diagonal = ");
    printMainDiagonal(matrix, rows, cols);

    printf("Secondary Diagonal = ");
    printSecondaryDiagonal(matrix, rows, cols);

    int sumX = calculateSumX(matrix, rows, cols);
    printf("Soma x = ");
    printf("%d\n", sumX);
    
    return 0;
}

int generateRandom() {
    return rand() % 100 + 1; // 0 to 100
}

void* safeMalloc(size_t size) {
    void *ptr = (int*) malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

int** matrixAllocation(int rows, int cols) {
    int **matrix = (int**) safeMalloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) safeMalloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols);

    return matrix;
}

void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = generateRandom();
        }
    }
}

void printM(int **matrix, int rows, int cols) {
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

void printMainDiagonal(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                printf("%d ", matrix[i][j]);
            }
        }
    }
    printf("\n");
}

void printSecondaryDiagonal(int **matrix, int rows, int cols) {
    int i = 0; // start at first row
    int j = cols - 1; // start at final column
    // pointer will be at top right corner

    while (i < rows && j >= 0) {
        printf("%d ", matrix[i][j]);
        i++;
        j--;
    }
    printf("\n");
}

int calculateSumXForQuadratic(int **matrix, int rows, int cols) {
    if (rows != cols) {
        printf("non quadric matrix");
        return 0;
    }
    int n = rows;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i]; // main diagonal
        if (i != n - 1 - i) sum += matrix[i][n - 1 - i]; // secondary diagonal
        // protected from summing the main value (x) twice
    }

    return sum;
}

int calculateSumX(int **matrix, int rows, int cols) {
    int sum = 0;
    // stablish limit min(rows, cols)
    int limit = (rows < cols) ? rows : cols;

    for (int i = 0; i < limit; i++) {
        sum += matrix[i][i];
        if (i != cols - 1 - i) sum += matrix[i][cols - 1 - i];
    }

    return sum;
}