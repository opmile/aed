#include <stdio.h>

// shift zeros to end

// two crossings
void twoCrossings(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i]; // arr[count++]
            count++;
        }
    }
    
    while (count < n) {
        arr[count] = 0; // arr[count++]
        count++;
    }
}

// one crossing
void oneCrossing(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {

            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp;

            count++;
        }
    }
}

int main() {

    return 0;
}