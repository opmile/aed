#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int generateRandom();

void* safeMalloc(size_t size);

int **matrixAllocation(int rows, int cols);

void fillMatrix(int **matrix, int rows, int cols);

void freeMatrix(int **matrix, int rows);

int findGreater(int **matrix, int rows, int cols);

int findLowest(int **matrix, int rows, int cols);

float calculateAverage(int **matrix, int rows, int cols);

void printMatrix(int **matrix, int rows, int cols);

int main() {
    srand(time(NULL));

    int rows = 0, cols = 0;

    printf("enter number of rows: ");
    scanf("%d", &rows);

    printf("enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = matrixAllocation(rows, cols);

    printf("M[%d x %d] = \n", rows, cols);
    printMatrix(matrix, rows, cols);

    printf("\n");

    printf("* Biggest Element = %d\n", findGreater(matrix, rows, cols));
    printf("* Lowest Element = %d\n", findLowest(matrix, rows, cols));
    printf("* Average = %.2f\n", calculateAverage(matrix, rows, cols));

    return 0;
}

int generateRandom() {
    return rand() % 100 + 1; // generates a random number between 0 to 100
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

int **matrixAllocation(int rows, int cols) {
    int **matrix = (int**) safeMalloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i ++) {
        matrix[i] = (int*) safeMalloc(cols * sizeof(int));
    }

    fillMatrix(matrix, rows, cols);

    return matrix;
}

void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = generateRandom(); // using pointers arithmetics
        }
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i ++) {
        free(matrix[i]);
    }
    free(matrix);
}

int findGreater(int **matrix, int rows, int cols) {
    int biggestElement = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > biggestElement) {
                biggestElement = matrix[i][j];
            }
        }
    }
    return biggestElement;
}

int findLowest(int **matrix, int rows, int cols) {
    int lowestElement = 100; // adjusting to higest possible value
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < lowestElement) {
                lowestElement = matrix[i][j];
            }
        }
    }
    return lowestElement;
}

float calculateAverage(int **matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }

    int totalLength = rows * cols;
    return (float) sum / totalLength;
}

void printMatrix(int **matrix, int rows, int cols) {
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