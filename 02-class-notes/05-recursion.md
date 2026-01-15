# Recursividade

---

Mecanismo pelo qual é possível definir uma função em termos de si mesma.

* Recursividade é só um problema se resolvendo em versões menores de si mesmo, até chegar num ponto em que não dá mais para quebrar o problmea, e é aí que você para.

---

## 1. **Caso Base** (freio de mão)

É a condição que encerra a recursão. Sem isso você pode acabar criando um loop infinito (stack overflow)

> Em que situação o problema é tão simples que já sei a resposta direto? 

> Quais são os pressupostos que já sei?

Exemplos clássicos:

* fatorial(0) = 1

* soma de lista vazia = 0

* árvore vazia não tem nós

---

## 2. **Passo Recursivo** (auto-chamada com progresso)

Aqui você resolve uma parte do problema e delega o resto para uma versão menor.

> Cada chamada precisa estar mais próxima do caso base do que a anterior

Isso geralmente acontece ao:

* diminuir um número (`n-1`)

* avançar um índice

* remover um elemento

* descer um nível na árvore

---

## 3. **Combinação do resultado**

Depois que a chamada recursiva retorna (agrupamento na pilha), você usa esse retorno para construir a resposta final

* a função volta empilhando resultados

* a lógica acontece na subida da pila, não só na descida

> O que eu faço com o valor que a chamada recursiva me devolveu?

---

## Desmontando o problema recursivo

1. Defina o menor caso possível (caso base)

2. Descreva o problema em uma frase recursiva:

    * a resposta de `N` depende da resposta de `N - 1`

3. Garanta progresso explícito rumo ao caso base

4. Decida se a lógica está antes ou depois da chamada recursiva

---

## Exemplos 

### Fatorial

```c
#include <stdio.h>

int main() {

    return 0;
}
```