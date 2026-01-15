#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *str, char start, char end) {
    if (start < end) {
        if (str[start] == str[end]) {
            return isPalindrome(str + 1, start + 1, end - 2);
        } else {
            return false;
        }
    }
    return true;
}

int binarySearchRecursive(int *arr, int x, int low, int high) {
    if (low > high) {
        return -1;
    }

    int middle = low + (high - low) / 2;

    if (arr[middle] == x) {
        return middle;
    }

    if (arr[middle] > x) {
        return binarySearchRecursive(arr, x, low, middle - 1);
    } else { // arr[middle] < x
        return binarySearchRecursive(arr, x, middle + 1, high);
    }
}

int main() {

    return 0;
}