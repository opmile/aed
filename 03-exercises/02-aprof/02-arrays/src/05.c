#include <stdatomic.h>
#include <stdio.h>

/*
dado um array de inteiros, retorne true se qualquer valor aparecer pelo menos uma vez no array, e retorne false se todos os elementos são distintos

c :
1 - true
0 - false
*/

int containsDuplicate(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 1, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = containsDuplicate(arr, n);
    if (result == 1) {
        printf("contem duplicatas\n");
    } else {
        printf("não contem duplicatas\n");
    }

    return 0;
}