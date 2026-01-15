## 1. Diagonais

Escreva um programa em linguagem C que trabalhe com uma matriz quadrada de inteiros.

**Requisitos do programa**:

1. Solicite ao usuário um número inteiro n, que representará a **quantidade de linhas e colunas da matriz** (matriz n × n).

2. Crie uma matriz bidimensional de inteiros com dimensão **n × n**.

3. Preencha a matriz com **valores inteiros aleatórios** entre 0 e 99.

4. Mostre a matriz completa na tela.

5. Construa um procedimento (função) para:

    * Exibir a **diagonal principal** da matriz.

6. Construa outro procedimento (função) para:

    * Exibir a **diagonal secundária** da matriz.

Observações:

* A diagonal principal é formada pelos elementos em que o índice da linha é igual ao índice da coluna (`matriz[i][i]`).

* A diagonal secundária é formada pelos elementos em que a soma dos índices da linha e da coluna é igual a `n - 1` (`matriz[i][n - 1 - i]`).

* Utilize a função `rand()` para gerar os valores aleatórios e `srand(time(NULL))` para inicializar o gerador.

Utilize procedimentos, ou seja, funções do tipo `void`.

Exemplo:
Para uma matriz 4 × 4:

```
 12  45  78  10
  3  89  22  56
 90  11  67  34
 25  44  98  71
```
Diagonal principal: 12 89 67 71

Diagonal secundária: 10 22 11 25

Draft version 