#include <stdio.h>

// 01 - fatorial
int fatorial(int n) {
    if (n == 0) { // base case
        return 1; 
    } else {
        return n * fatorial(n - 1);
    }
}

// 02 - sum to value
int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}

// 03 - recursive array sum
int sumArray(int *arr, int len) {
    if (len == 0) {
        return 0;
    } else {
        return arr[0] + sumArray(arr + 1, len - 1);
    }
}
/*
arr[0] é como uma janela móvel que enxerga apenas um pedaço do vetor original, é o elemento atual que está sendo somado naquele nível da recursão
*/

// 04 - recursive for even elements in array
int sumEvenArr(int *arr, int len) {
    if (len == 0) {
        return 0;
    } 

    if (arr[0] % 2 == 0) {
        return arr[0] + sumEvenArr(arr + 1, len - 1);
    } 
    
    return sumEvenArr(arr + 1, len - 1);
}

int main() {

}