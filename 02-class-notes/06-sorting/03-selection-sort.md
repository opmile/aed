# Selection Sort

---

Selection Sort é o contraponto perfeito ao Insertion Sort. Onde um insere, o outro seleciona. Onde um desloca, o outro troca.

---

Ótimo. **Selection Sort é o contraponto perfeito ao Insertion Sort**. Onde um *insere*, o outro *seleciona*. Onde um desloca, o outro troca. Se você entender essa diferença conceitual, metade da matéria de ordenação fica óbvia.

Vou seguir **exatamente os mesmos critérios** e depois destrinchar o código com o mesmo nível de detalhe.

---

# Selection Sort — ideia central

O Selection Sort funciona como alguém procurando o menor item e colocando ele “no lugar certo”, uma posição por vez.

A lógica é:

1. Escolha uma posição do vetor
2. Procure o **menor elemento** a partir dessa posição
3. Troque esse menor elemento com o elemento da posição atual
4. Avance a posição e repita

Estado mental:

* À esquerda: parte **ordenada**
* À direita: parte **não ordenada**
* A cada passo, **um elemento é fixado definitivamente**

---

## A. Estratégia de ordenação

A estratégia é **seleção direta**.

Em vez de mover vários elementos (como o Insertion Sort):

* O Selection Sort faz **varreduras completas**
* Ele **escolhe o menor (ou maior)** e coloca no lugar certo

Característica forte:

> cada posição do vetor recebe exatamente **um elemento definitivo**

Isso torna o algoritmo simples, previsível e fácil de provar correto.

---

## B. Estabilidade

Aqui está o ponto fraco clássico.

### Selection Sort **não é estável**

Por quê?

* Ele realiza **trocas diretas**
* Um elemento pode pular para frente de outro com chave igual

Exemplo conceitual:

```
(A, 5) (B, 3) (C, 5)
```

Na primeira seleção:

* menor = (B, 3)
* troca com (A, 5)

Resultado:

```
(B, 3) (A, 5) (C, 5)
```

A ordem entre A e C foi preservada por acaso.
Mas em outras configurações ela quebra.

Conclusão direta:

> se estabilidade importa, Selection Sort é uma escolha ruim.

---

## C. Complexidade de tempo

Aqui vem algo contraintuitivo.

O Selection Sort:

* **sempre** percorre o vetor inteiro
* **independente** do estado inicial

Complexidade:

* Melhor caso: O(n²)
* Caso médio: O(n²)
* Pior caso: O(n²)

Não há atalhos.
Ele sempre compara tudo.

---

## D. Complexidade de trocas (swaps)

Esse é o ponto onde ele brilha.

* Exatamente **n − 1 trocas**
* Uma troca por posição

Comparação:

* Insertion Sort → muitas movimentações
* Selection Sort → pouquíssimas trocas

Por isso ele é citado quando:

* custo de troca é muito alto
* custo de comparação é aceitável

---

## E. Complexidade de espaço

* Algoritmo **in-place**
* Usa apenas variáveis auxiliares simples

Complexidade:

* O(1)

Nenhuma memória extra relevante.

---

## F. Uso de recursividade

* Não utiliza recursão
* Implementação totalmente iterativa

---

# Implementação em C (versão clara e correta)

```c
#include <stdio.h>

void selectionSort(int v[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // procura o menor elemento no trecho não ordenado
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // troca apenas se necessário
        if (minIndex != i) {
            temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
        }
    }
}
```

---

# Agora vamos desmontar o código (sem pressa)

## Laço externo — posição fixa

```c
for (i = 0; i < n - 1; i++) {
```

* `i` indica **a posição que será preenchida**
* Tudo antes de `i` já está ordenado

Mentalidade:

> vou descobrir qual valor merece estar na posição `i`

---

## Assumindo o mínimo

```c
minIndex = i;
```

Você começa sendo otimista:

* “por enquanto, o menor é o próprio `v[i]`”

---

## Laço interno — busca do menor

```c
for (j = i + 1; j < n; j++) {
    if (v[j] < v[minIndex]) {
        minIndex = j;
    }
}
```

Aqui acontece a **seleção** de verdade.

* Varre o trecho não ordenado
* Atualiza o índice do menor elemento encontrado
* Não faz trocas aqui, só decide

Esse detalhe é importante:

> o algoritmo separa **decisão** de **ação**

---

## Troca final

```c
if (minIndex != i) {
    temp = v[i];
    v[i] = v[minIndex];
    v[minIndex] = temp;
}
```

A troca acontece:

* uma única vez
* somente se necessário

Depois disso:

* `v[i]` está definitivamente correto
* nunca mais será tocado

---

## Exemplo passo a passo

Vetor:

```
[7, 3, 5, 2]
```

### i = 0

* menor = 2 (índice 3)
* troca com 7

```
[2, 3, 5, 7]
```

### i = 1

* menor = 3 (já está certo)
* nenhuma troca

### i = 2

* menor = 5
* nenhuma troca

Fim.

---

# Comparação mental com Insertion Sort

| Aspecto     | Insertion Sort         | Selection Sort    |
| ----------- | ---------------------- | ----------------- |
| Estratégia  | Inserção gradual       | Seleção do mínimo |
| Estável     | Sim                    | Não               |
| Trocas      | Muitas (deslocamentos) | Pouquíssimas      |
| Melhor caso | O(n)                   | O(n²)             |
| Uso real    | Dados quase ordenados  | Troca cara        |

> Selection Sort é conceitualmente simples, mas praticamente inútil em produção.
> Ele existe para ensinar **critérios de análise**, não para ser usado.

---

```c
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = v[i];
            v[i] = v[minIndex];
            v[minIndex] = temp;
        }
    }
}
```