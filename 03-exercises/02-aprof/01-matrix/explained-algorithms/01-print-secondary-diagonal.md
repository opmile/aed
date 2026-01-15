# Diagonal Secondária

Para imprimir a **diagonal secundária** de uma matriz não quadrada (retangular), precisamos primeiro entender que, diferente de uma matriz quadrada, o caminho diagonal não terminará necessariamente no "canto oposto", mas sim quando atingirmos o limite de uma das dimensões (seja o fim das linhas ou o início das colunas).

Aqui está o processo lógico passo a passo:

---

### 1. Entendendo a Trajetória

A diagonal secundária é aquela que percorre a matriz do **canto superior direito** em direção ao **canto inferior esquerdo**.

* Em uma matriz bidimensional `M` com `L` linhas e `C` colunas:

* O ponto de partida é sempre a primeira linha (`i = 0`).
* A coluna inicial é a última disponível (`j = C - 1`).

### 2. A Regra dos Índices

Para cada passo dado na diagonal, você deve:

1. **Aumentar** o índice da linha (`i++`): descendo na matriz.
2. **Diminuir** o índice da coluna (`j--`): movendo-se para a esquerda.

A relação matemática constante para os elementos desta diagonal é dada por: `j = (C - 1) - i`

### 3. O Limite de Parada (O "Pulo do Gato")

Em matrizes não quadradas, você deve garantir que o processo pare assim que encontrar a primeira borda da matriz. Existem dois cenários:

* **Se a matriz é "alta" (`L > C`):** Você ficará sem colunas antes de acabar as linhas.
* **Se a matriz é "larga" (`L < C`):** Você ficará sem linhas antes de percorrer todas as colunas.

Portanto, a condição de continuidade do seu laço de repetição deve ser:

> Enquanto (`i < L`) **E** (`j >= 0`)

---

### Resumo do Algoritmo Didático

1. **Identifique as dimensões:** Saiba o total de linhas (`L`) e colunas (`C`).
2. **Inicie os ponteiros:** Comece com a linha `i = 0` e a coluna `j = C - 1`.
3. **Percorra com segurança:**
* Acesse o elemento na posição atual `M[i][j]`.
* Imprima o valor.
* Incremente `i` e decremente `j`.
* **Pare** se `i` chegar em `L` ou se `j` se tornar menor que 0.

---
