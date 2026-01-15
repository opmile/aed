# Algoritmos de busca

---

## 1. Busca Linear

Busca linear, ou busca sequencial, é um algoritmo de busca que:

* Percorre um array comparando a chave de busca com os valores dos elementos de cada uma das posições

* Se a chave de busca for igual a algum dos elementos na lista, a função retorna (cessa recursos computacionais desnecessários na busca de elementos restantes) a **posição** correspondente na lista

* Quando não encontrado, o valor retornado é `-1`

**Análise de Eficiência**

A análise da eficiência sempre parte partindo do pior cenário e, na pior hipótese, a chave é o último elemeno ou não pertence à lista e, portanto, acessamos todos os `n` elementos da lista

*Complexidade* -- O(n)

```c
int linearSearch(int *array, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (key == array[i]) {
            return i;
        }
    }
    return -1;
}


```
---

## 2. Busca binária

Sempre parte do pressuposto que os dados estão ordenados!

A cada tentativa de busca, temos a eliminação da metade dos elementos a serem buscados, sempre partindo do meio do array ou subarray gerado.

**Análise de Eficiência**

A escala de resolução do problema ocorre à uma taxa logarítmica.

No pior cenário, teremos que dividir o aray até chegar no último elemento (último acesso realizado no array)

A quantidade de vezes que um número pode ser divido por dois até que ele se torne igual a `1` é exatamente o resultado da definição de `log` na base 2. No pior caso, o número de acesso é igual a `log2 n`

*Complexidade* -- O(log n)

**Implementação**

Matematicamente, `right - left` calcula o tamanho do intervalo, dividir por `2` encontra o deslocamento até o meio, e somar `left` move esse meio para a posição correta dentro do intervalo [left,right].

```c
int binarySearch(int *array, int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = array[middle];

        if (key == pos) {
            return middle;
        } else if (key > pos) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}
```