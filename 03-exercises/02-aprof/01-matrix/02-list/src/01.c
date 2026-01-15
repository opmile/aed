#include <stdio.h>

int countFrequency(int *arr, int n, int target) {
    int freq = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            freq++;
        }
    }
    return freq;
}

int main() {

    int arr[] = {1, 2, 3, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    printf("frequency of %d = %d\n", target, countFrequency(arr, n, target));

    return 0;
}