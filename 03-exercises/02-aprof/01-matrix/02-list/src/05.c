#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generateRandom() {
    return rand() % 10 + 1;
}

void* safeMalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

// quadratic form

void fill(int **matrix, int n) {
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

int** giveTransposed(int **matrix, int n) {
    int **transposed = matrixAllocation(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    return transposed;
}

void print(int **matrix, int n) {
    printf("{\n");
    for(int i = 0; i < n; i++) {
        printf("  {");
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) printf(", ");
        }
        printf("}%s\n", i < n - 1 ? ", " : "");
    }
    printf("}\n");
}

int main() {
    srand(time(NULL));

    printf("n = ");
    int n = 0;
    scanf("%d", &n);

    int **matrix = matrixAllocation(n);
    fill(matrix, n);
    print(matrix, n);

    int **transposed = giveTransposed(matrix, n);
    print(transposed, n);

    return 0;
}