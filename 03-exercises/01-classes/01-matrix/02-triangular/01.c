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

int** generateMatrix(int n) {
    int **matrix = (int**) safeMalloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) safeMalloc(n * sizeof(int));
    } 

    fillMatrix(matrix, n);

    return matrix;
}

// lower triangular ==  i > j
void showLowerTriangularMatrix(int **matrix, int n) {
    printf("{\n");
    for (int i = 0; i < n; i++) {
        printf("  { ");
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                printf("%d", matrix[i][j]);
            } else {
                printf("0");
            }
            if (j < n - 1) printf(", ");
        }
        printf(" }%s\n", i < n - 1 ? ", " : "");
    }
    printf("}\n");
}

// upper triangular ==  i < j
void showUpperTriangularMatrix(int **matrix, int n) {
    printf("{\n");
    for (int i = 0; i < n; i++) {
        printf("  { ");
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                printf("%d", matrix[i][j]);
            } else {
                printf("0");
            }
            if (j < n - 1) printf(", ");
        }
        printf(" }%s\n", i < n - 1 ? ", " : "");
    }
    printf("}\n");
}

int main() {
   srand(time(NULL));

   int n = 0;
   printf("Informe a dimensão da matriz: ");
   scanf("%d", &n);

   int **matrix = generateMatrix(n);

   printMatrix(matrix, n);
   printf("\n");

   printf("Lower Triangular Matrix = \n");
   showLowerTriangularMatrix(matrix, n);
   
   printf("\n");

   printf("Upper Triangular Matrix = \n");
   showUpperTriangularMatrix(matrix, n);

   
   return 0;
}