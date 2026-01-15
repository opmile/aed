#include <stdio.h>

void printReverse(int *arr, int len) {
    if (len == 0) {
        return;
    }
    printReverse(arr + 1, len - 1);

    printf("%d ", arr[0]);
}

void printSecondHalfReversed(int *arr, int len) {
    if (len == 0) {
        return;
    } 

    int half = len / 2;
    printReverse(arr + half, len - half);
}

int main() {
    return 0;
}