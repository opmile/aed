# Guia de Implementação: Soma em "X" (Diagonais)

O cálculo da soma em "X" consiste em unir a **diagonal principal** e a **diagonal secundária**. O maior desafio em Estrutura de Dados é garantir que o algoritmo seja genérico o suficiente para tratar matrizes quadradas e retangulares, sem acessar memória inválida e sem duplicar o elemento central.

### Sobre o elemento central

Mesmo em matrizes retangulares, pode haver um cruzamento. O cruzamento ocorre na linha `i` quando a posição da diagonal principal é a mesma da secundária.

* Posição na Principal: `(i, i)`
* Posição na Secundária: `(i, cols - 1 - i)`

Eles são o mesmo elemento se: `i = cols - 1 - i` (*ponto de encontro*)

### 1. A Regra do Limite (Segurança de Memória)

Em uma matriz retangular, a diagonal termina assim que você atinge a **menor dimensão**.

* Se a matriz tem 3 linhas e 10 colunas, as diagonais só terão 3 elementos.

* Se a matriz tem 10 linhas e 3 colunas, as diagonais também só terão 3 elementos.

Por isso, o laço de repetição deve ir de `0` até o `menor(rows, cols)`.

Formalmente, em uma matriz dinâmica `int **matrix` de dimensões `L x C`, as diagonais são limitadas pela **menor dimensão**. Se você tentar percorrer além disso, ocorrerá um erro de segmentação (*segmentation fault*).

* **Definição do Limite:** `limite = (rows < cols) ? rows : cols;`

### 2. Identificação dos Índices

Para cada linha `i` dentro do limite:

* **Elemento da Principal:** Está sempre na coluna `j = i`.
* **Elemento da Secundária:** Está sempre na coluna `j = (cols - 1) - i`.

### 3. O Problema da Interseção (O Elemento Central)

O elemento central só existe (e só é repetido) se a **matriz for quadrada** e tiver **ordem ímpar** (ex: 3x3, 5x5). Se a matriz for 4x4, as diagonais se cruzam, mas não compartilham nenhuma célula.

O elemento central só deve ser somado **uma vez**. Ele ocorre quando a coluna da diagonal principal é idêntica à coluna da secundária na mesma linha.

**A Condição Lógica:**

> Só somamos o elemento da secundária se o seu índice de coluna for **diferente** do índice da principal.
> `if ( (cols - 1 - i) != i )`

---

### 4. Algoritmo Refinado (Lógica C)

```c
void calcularSomaX(int **matrix, int rows, int cols) {
    int soma = 0;
    
    // 1. Definir o limite seguro para não sair da memória alocada
    int limite = (rows < cols) ? rows : cols;

    // 2. Percorrer as diagonais em um único laço
    for (int i = 0; i < limite; i++) {
        
        // Soma o elemento da diagonal principal: M[i][i]
        soma += matrix[i][i];

        // 3. Define a coluna da secundária para esta linha
        int colSecundaria = (cols - 1) - i;

        // 4. Verificação de Interseção:
        // Se a coluna da secundária for a mesma da principal (i),
        // ignoramos para não somar o centro duas vezes.
        if (colSecundaria != i) {
            soma += matrix[i][colSecundaria];
        }
    }

    printf("Soma total do X: %d\n", soma);
}

```

---

### Por que esta solução é a mais eficiente?

1. **Complexidade O(n):** Você percorre a matriz uma única vez, tocando apenas nos elementos necessários (as diagonais), em vez de percorrer toda a matriz com `if`s dentro.
2. **Universalidade:** * Em **Matrizes Quadradas Ímpares (3x3, 5x5)**: O `if` captura o centro exato.
* Em **Matrizes Quadradas Pares (4x4)**: O `if` nunca é acionado no centro (pois as diagonais se cruzam "no vazio" entre os pixels), somando todos os elementos.
* Em **Matrizes Retangulares**: O `limite` garante que você não tente acessar uma coluna negativa ou uma linha inexistente.