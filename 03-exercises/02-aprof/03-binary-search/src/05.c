#include <stdio.h>

int binarySearchRotated(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (arr[middle] == x) {
            return middle;
        }

        // left half is sorted
        if (arr[left] <= arr[middle]) {

            // is x present in this half?
            if (x >= arr[left] && x < arr[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }  
        
        // right half is sorted
        else { 

            // is x present in this half?
            if (x > arr[middle] && x <= arr[right]) {
                // discard the other half
                left = middle + 1;
            } else { // x not present in the right half
                // discard
                right = middle - 1;
            }
        }


    }

    return -1;
}

int main() {

    return 0;
}