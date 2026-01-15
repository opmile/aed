#include <stdio.h>

/*
seq fiboncci = cada número corresponde a soma dos seus dois anteriores
0, 1, 1, 2, 3, 5, 8, 13, 21, ...

parametro p = indica a posição do elemento na sequência (a partir de 1)
f(5) = 3
f(8) = 13

case base
* se p == 1 -> return 0
* se p == 2 -> return 1

passo recursivo
a função deve retornar a soma dos dois números anteriores na sequência
f(5) = f(3) + f(4)
f(3) = f(1) + f(2)
*/

int fibonacci(int p) {
    if (p == 1) {
        return 0;
    }
    if (p == 2) {
        return 1;
    }
    return fibonacci(p - 1) + fibonacci(p - 2);
}

/*
complexidade exponencial! O(2^n)
fib(5)
├── fib(4)
│   ├── fib(3)
│   │   ├── fib(2)
│   │   │   ├── fib(1)
│   │   │   └── fib(0)
│   │   └── fib(1)
│   └── fib(2)
│       ├── fib(1)
│       └── fib(0)
└── fib(3)
    ├── fib(2)
    │   ├── fib(1)
    │   └── fib(0)
    └── fib(1)

* muitas chamadas repeditas! (ex: fib(1) chamada 5 vezes)

resolvendo usando memoization: gardar os resultados já calculados em um vetor, evitando recálculos
*/

int fibOt(int n, int *memo) {
    if (memo[n] != -1) {
        return memo[n]; // resultado guardado
    }

    // caso base
    if (n == 0) return memo[0] = 0;
    if (n == 1) return memo[1] = 1;

    // passo recursivo
    memo[n] = fibOt(n - 1, memo) + fibOt(n - 2, memo);
    return memo[n];
}

int main() {

    return 0;
}