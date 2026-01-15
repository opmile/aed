#include <stdio.h>

int calculateSumXFromQuadraticForm(int **matrix, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
        if (i != n - 1 - i) sum += matrix[i][n - 1 - i];
    }
    
    return sum;
}

int main() {

    return 0;
}