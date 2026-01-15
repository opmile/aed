#include <stdio.h>

// potenciation == a^b

// 01 - linear O(b)
int pot(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * pot(a, b - 1);
    }
}

// 02 - exponentiation by squaring O(log b)
/*
a^b = 
    * (a^(b/2)^2 se b for par
    * a * (a^((b-1)/2)^2 se b for ímpar
isso implica usar quadrado ao invés da multiplicação em cadeia, o que reduz o problema pela metade a cada chamada recursiva (O(log b))

ex) a = 2, b = 5
2^5 = 2 * (2^4) = 2 * (2^2 * 2^2) = 2 * ((2^2)^2)
    = 2 * (4)^2 = 2 * 16 = 32

em cadeia:
2^5 = 2 * 2 * 2 * 2 * 2
    = 4 * 2 * 2 * 2
    = 8 * 2 * 2
    = 16 * 2
    = 32

b par: a^b = (a^(b/2) * a^(b/2)) = (a^(b/2))²
b impar: a * a^(b-1) = a * (a^((b-1/2))² --> "quebramos" um a e deixamos o resto par
*/
int potOt(int a, int b) {
    if (b == 0) {
        return 1;
    }

    int half = potOt(a, b / 2); // (a^(b/2)

    if (b % 2 == 0) { // par == (a^(b/2) * a^(b/2))
        return half * half;
    } else { // impar == a * (a^((b-1)/2))^2 (half^2)
        return a * half * half;
    }
}

int main() {
    return 0;
}