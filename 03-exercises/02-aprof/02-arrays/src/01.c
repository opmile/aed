#include <stdio.h>
#include <string.h>

// 01
int strLen(const char* str) {
    int len = 0;
    while (*str) {
        len++;
        str++;
    }
    return len;
}

// 02
int isPalindrome(const char* str)  {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main() {

    const char str[] = "mutum";
    int len =  strLen(str);

    printf("%s\n", str);
    printf("%d\n", len);
    
    int result = isPalindrome(str);
    if (result == 1) {
        printf("palindrome\n");
    } else {
        printf("not a palindrome\n");
    }

    return 0;
}