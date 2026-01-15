#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int findRichestAccount(int **matrix, int n, int *p) {
  int highestSum = 0;
  *p = 0;

  for (int i = 0; i < n; i++) {
    int parcialSum = 0;

    for (int j = 0; j < n; j++) {
      parcialSum += matrix[i][j];
    }

    if (highestSum < parcialSum) {
      highestSum = parcialSum;
      *p = i;
    }
  }

  return highestSum;
}

int main() {
  int n = 3;
  int **table = (int**) malloc(n * sizeof(int *));
  if (table == NULL) {
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    table[i] = (int*) malloc(n * sizeof(int));
  }
  
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        table[i][j] = rand() % 5 + 1;
    }
  }

  printMatrix(table, n, n);

  int p = 0;
  int totalAmount = findRichestAccount(table, n, &p);

  printf("RICHEST ACCOUNT: %d\n", p);
  printf("TOTAL AMOUNT = %d\n", totalAmount);

  return 0;
}