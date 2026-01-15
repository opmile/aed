# Primeira Ocorrência

> Dado um vetor ordenado com repetidos, encontre o índice da primeira ocorrência de x.

---

Detalhes:

* Array ordenado

* "Encontrar índice de elemento" == Algoritmo de Busca

== Pesquisa Binária

---

## Ideia Central

A ideia central do algoritmo é que você não pode parar quando encontrar `x`.
Encontrar `x` só prova que ele existe, não que seja a primeira ocorrência desse elemento

O raciocínio muda da implementação original da pesquisa binária de uma tal forma que:

1. Existe o controle do resultado encontrado

    * Atribuindo primeiramente `result = -1`, dessa forma garantimos o caso em que o elemento não existe dentro do array

    * Quando existe correspondência, `chute == x`, guardamos o índice em `result` e continuamos a busca **à esquerda**

2. A pesquisa binária é natural para os casos em que o chute é menor ou maior que valor do elemento a ser encontrado.

---

### Porquê da movimentação sempre para **à esquerda**?

O problema nunca foi achar `x`, o problema é sobre achar o **menor índice** `i` tal que `arr[i] == x`

* O menor índice sempre se direciona para posições menores no array, mais à esquerda

* Se `x` foi encontrado na posição `middle`, qualquer ocorrência mais à direita é automaticamente pior do que essa

* A primeira ocorrência te leva a apenas uma única direção relevante: a esquerda, e, na aplicação da busca binária, reduz-se o espaço de busca sem descartar nenhuma solução válida

---

## Implementação em C (intervalo fechado)

```c
int firstOccurrence(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos == x) {
            result = middle; // candidato à primeira occorrência
            right = middle - 1; // força busca para a esquerda
        } else if (pos < x) {
            left = middle + 1;
        } else { // pos > x
            right = middle - 1;
        }
    }

    return result;
}
```

---

## O Problema da Última Ocorrência

> Dado um vetor ordenado com repetidos, encontre o índice da primeira ocorrência de x.

A lógica é conceitualmente a mesma da aplicada para o caso da primeira occorrência, a modificação ocorre unicamente na direção do fluxo de procura, que agora é para a direita.

* **Primeira Ocorrência** -- encontra `x` no meio, guarda o índice, continua a procura à esquerda (ajuste `right = middle - 1`)

* **Última Ocorrência** -- encontra `x` no meio, guar o índice, continua a procura à direita (ajuste `left = middle + 1`)

---

### Implementação em C (intervalo fechado)

```c
int lastOccorrence(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos == x) {
            result = middle; // candiato a última ocorrência
            left = middle + 1; // força busca para a esquerda
        } else if (pos < x) {
            left = middle + 1;
        } else { // pos > x
            right = middle - 1;
        }
    }

    return result
}
```

---

### Observação: **Invariantes**

Um **invariante** é uma condição que permanece verdadeira durante toda a execução de um algoritmo, especialmente antes e depois de cada iteração de um laço. 

* Ele funciona como uma “regra de segurança”: o algoritmo pode avançar, mas nunca pode violar essa condição.

**Exemplo (busca binária):**
Durante a execução do algoritmo, **mantém-se o invariante** de que, se o valor procurado `x` existir no vetor, então ele está sempre contido no intervalo delimitado por `[left, right]`. A cada iteração, o algoritmo reduz esse intervalo, mas nunca elimina uma posição onde `x` ainda poderia estar, garantindo a correção do resultado final.
