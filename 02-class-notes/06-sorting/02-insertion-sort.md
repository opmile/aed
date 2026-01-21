# Insertion Sort

---

## Ideia central do Insertion Sort

O Insertion Sort funciona como você organiza cartas na mão.

Você:

1. Assume que uma parte do vetor já está ordenada
2. Pega o próximo elemento
3. **Insere esse elemento na posição correta dentro da parte ordenada**

Formalmente:

* O vetor é dividido logicamente em duas partes:

  * **à esquerda**: subvetor ordenado
  * **à direita**: subvetor ainda não processado
* A cada iteração, o subvetor ordenado cresce **uma posição**

No início:

* Um único elemento já é considerado ordenado por definição

---

## Análise segundo os critérios de ordenação

Agora vamos usar exatamente os critérios que você pediu antes.

---

### A. Estratégia de ordenação

A estratégia é **incremental por inserção**.

O algoritmo:

* Seleciona um elemento (chave)
* Compara essa chave com os elementos anteriores
* Desloca os maiores para a direita
* Insere a chave na posição correta

Não há troca direta repetida de pares; o que acontece é **deslocamento**.

Esse detalhe importa.

---

### B. Estabilidade

O Insertion Sort é **estável**.

Por quê?

* Ele só desloca elementos **estritamente maiores** que a chave
* Elementos com chaves iguais **não trocam de posição relativa**

Isso faz dele uma escolha segura quando:

* há múltiplos campos
* a ordem anterior importa

Esse é um dos grandes méritos do Insertion Sort.

---

### C. Complexidade de tempo

Depende fortemente do estado inicial do vetor.

* **Melhor caso (vetor já ordenado)**
  O(n)
  Apenas uma comparação por elemento.

* **Caso médio**
  O(n²)

* **Pior caso (vetor em ordem inversa)**
  O(n²)
  Cada novo elemento precisa ser comparado com todos os anteriores.

Tradução prática:

> Insertion Sort é excelente para dados quase ordenados e péssimo para dados grandes e caóticos.

---

### D. Complexidade de trocas (ou movimentações)

Esse ponto é interessante.

* O Insertion Sort **não faz muitas trocas**
* Ele faz **deslocamentos** e uma única inserção por iteração

Em termos práticos:

* Menos custo de escrita
* Bom quando copiar elementos é caro

Por isso ele ainda aparece em implementações reais como complemento de algoritmos mais complexos.

---

### E. Complexidade de espaço

O Insertion Sort é **in-place**.

* Usa apenas variáveis auxiliares constantes
* Não cria estruturas adicionais

Complexidade de espaço:

* O(1)

Simples, limpo e econômico.

---

### F. Uso de recursividade

* Não utiliza recursão
* É totalmente iterativo

Isso o torna:

* previsível
* seguro para pilha
* fácil de implementar em baixo nível (como C)

---

## Implementação em C

Agora o código, **sem truques e sem atalhos**, exatamente como o algoritmo pensa.

```c
#include <stdio.h>

void insertionSort(int v[], int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i];      // elemento a ser inserido
        j = i - 1;

        // desloca os elementos maiores que a chave
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        // insere a chave na posição correta
        v[j + 1] = chave;
    }
}

int main() {
    int v[] = {7, 3, 5, 2, 9, 1};
    int n = sizeof(v) / sizeof(v[0]);

    insertionSort(v, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}
```

---

## Núcleo do entendimento (isso é o que você tem que enxergar)

O ponto-chave do algoritmo é este laço:

```c
while (j >= 0 && v[j] > chave)
```

Ele garante duas coisas ao mesmo tempo:

1. Não ultrapassa o início do vetor
2. Preserva a estabilidade (usa `>` e não `>=`)

Esse detalhe separa quem **entende** de quem só copia código.

---

## Detalhamento do Código

---

## Estrutura geral do código

```c
void insertionSort(int v[], int n) {
```

* `v[]` → vetor a ser ordenado
* `n` → quantidade de elementos

---

## Variáveis principais

```c
int i, j, chave;
```

* `i` → percorre o vetor da esquerda para a direita
* `j` → percorre o **subvetor ordenado**, da direita para a esquerda
* `chave` → elemento que estamos tentando **inserir na posição correta**

A palavra *chave* é importante:

> ela representa o valor que precisa encontrar seu lugar.

---

## Laço externo: quem escolhe a chave

```c
for (i = 1; i < n; i++) {
```

Por que começa em `1`?

* `v[0]` sozinho já está ordenado
* a partir do índice `1`, começamos a inserir elementos no trecho ordenado

Estado mental:

* Antes de cada iteração, o intervalo `v[0..i-1]` está ordenado
* `v[i]` é o elemento novo

---

## Capturando a chave

```c
chave = v[i];
j = i - 1;
```

Tradução direta:

* Guardo o valor que quero inserir
* Começo comparando com o último elemento do trecho ordenado

Exemplo concreto:

Vetor inicial:

```
[7, 3, 5, 2]
```

Primeira iteração (`i = 1`):

* `chave = 3`
* `j = 0`
* trecho ordenado: `[7]`

---

## O coração do algoritmo (não pule isso)

```c
while (j >= 0 && v[j] > chave) {
    v[j + 1] = v[j];
    j--;
}
```

Leia isso como uma frase:

> Enquanto eu não passei do início do vetor **e** o elemento atual for maior que a chave, empurre esse elemento para a direita.

Isso **não é troca**, é **deslocamento**.

### O que realmente acontece?

Com o exemplo:

```
[7, 3, 5, 2]
```

* `j = 0`
* `v[0] = 7`
* `7 > 3` → verdadeiro

Então:

```c
v[1] = v[0];   // [7, 7, 5, 2]
j--;           // j = -1
```

Sai do `while` porque `j < 0`.

---

## Inserção da chave

```c
v[j + 1] = chave;
```

Aqui acontece o momento mais importante.

* `j` parou **uma posição antes** de onde a chave deve entrar
* por isso usamos `j + 1`

Continuando o exemplo:

* `j = -1`
* `j + 1 = 0`

Resultado:

```
[3, 7, 5, 2]
```

Agora o trecho `v[0..1]` está ordenado.

---

## Segunda iteração completa (para fixar)

Agora:

```
[3, 7, 5, 2]
```

`i = 2`

* `chave = 5`
* `j = 1`

Comparações:

* `v[1] = 7 > 5` → desloca

```
[3, 7, 7, 2]
```

* `j = 0`
* `v[0] = 3 > 5` → falso

Sai do `while`.

Insere:

```
v[1] = 5
```

Resultado:

```
[3, 5, 7, 2]
```

---

## O padrão que você precisa enxergar

A cada iteração:

1. Existe um **buraco lógico** no vetor
2. Os elementos maiores vão sendo empurrados
3. A chave cai exatamente no lugar certo

Visualmente:

```
[ 3 | 5 | _ | 7 | 2 ]
           ↑
        buraco
```

---

## Por que `>` e não `>=`?

```c
v[j] > chave
```

Se fosse `>=`:

* elementos iguais seriam deslocados
* a estabilidade seria quebrada

Esse detalhe não é cosmético, é conceitual.

---

## Versão comentada do código (leia como pseudocódigo)

```c
for (i = 1; i < n; i++) {
    chave = v[i];        // elemento novo
    j = i - 1;           // último do trecho ordenado

    while (j >= 0 && v[j] > chave) {
        v[j + 1] = v[j]; // empurra para a direita
        j--;
    }

    v[j + 1] = chave;    // insere no lugar correto
}
```

---

## Sugestão prática 

Pegue um papel e escreva:

```
[8, 4, 6, 2]
```

Simule manualmente:

* valores de `i`
* valores de `j`
* estado do vetor após cada deslocamento

---

```c
void insertionSort(int arr[], int n) {
    int i, j, key;
    
    for (i = 1; i < n; i++) { // left to right
        key = arr[i];
        j = i - 1; // adjust index for correct displacement

        while (j >= 0 && v[j] > chave) { // right to left
            v[j + 1] = v[j]; // throw biggest element to right
            j--;
        }

        v[j + 1] = key; // insert into the right position
    }
}
```