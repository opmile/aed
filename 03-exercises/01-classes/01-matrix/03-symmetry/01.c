#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printMatrix(int **matrix, int n) {
    printf("{\n");
    for (int i = 0; i < n; i++) {
        printf("  { ");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(", ");
        }
        printf(" }%s\n", i < n - 1 ? ", " : "");
    }
    printf("}\n");
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

int generateRandom() {
    return rand() % 100; // 0 to 99
}

void fillMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = generateRandom();
        }
    }
}

int** matrixAllocation(int n) {
    int **matrix = (int**) safeMalloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) safeMalloc(n * sizeof(int));
    } 

    return matrix;
}

void freeMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i ++) {
        free(matrix[i]);
    }
    free(matrix);
}

int** copyM(int **matrix, int n) {
    int **copyMatrix = matrixAllocation(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copyMatrix[i][j] = matrix[i][j];
        }
    }
    return copyMatrix;
}

// lower triangular == i > j
void lowerSymmetry(int **matrix, int n) {
    int **matrixLowerSymmetry = copyM(matrix, n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            matrixLowerSymmetry[j][i] = matrixLowerSymmetry[i][j];
        }
    }

    printMatrix(matrixLowerSymmetry, n);
    freeMatrix(matrixLowerSymmetry, n);
}

// upper triangular == i < j
void upperAntisymmetry(int **matrix, int n) {
    int **matrixUpperAntisymmetry = copyM(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            matrixUpperAntisymmetry[j][i] = - matrixUpperAntisymmetry[i][j];
        }
    }

    printMatrix(matrixUpperAntisymmetry, n);
    freeMatrix(matrixUpperAntisymmetry, n); 
}

int main() {
    srand(time(NULL));

    int n = 0;
    printf("enter matrix dimension = ");
    scanf("%d", &n);

    int **matrix = matrixAllocation(n);
    fillMatrix(matrix, n);

    printMatrix(matrix, n);

    printf("Symmetric matrix (from lower triagular) = \n");
    lowerSymmetry(matrix, n);

    printf("Antisymmetric matrix (from upper triagular) = \n");
    upperAntisymmetry(matrix, n);

    freeMatrix(matrix, n);

    return 0;
}