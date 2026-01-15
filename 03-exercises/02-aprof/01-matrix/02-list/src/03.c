#include <stdio.h>

int sumBorder(int **matrix, int rows, int cols) {
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // guarantee that corners wont be duplicated in the sum
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

int main() {

    return 0;
}