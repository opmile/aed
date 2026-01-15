# Array Ordenado e Rotacionado

---

Um vetor foi ordenado e depois rotacionado:

```
[15, 18, 2, 3, 6, 12]
```

Encontre `x` em `O(log n)`.

---

* um array ordenado e rotacionado pode ser restaurado ao estado ordenado

* usando o algoritmo de reversões (3 reversões), é possível desfazer a rotação

* uma vez restaurado, a busca binária funciona normalmente

Isso é verdade matemática e algorítmica.

Mas reverter o algoritmo custa `O(n)`, mesmo que a reversão seja simples. O algoritmo como um todo vira O(n), não O(log n).

Outra questão é que não conhecemos quantas posições o array foi rotacionado, e precisamos dessa informação para aplicar corretamente a "rotação ao contrário", mas aí descobrir isso se torna outro problema:

---

O truque é entender que em um array ordenado e rotacionado, pelo menos uma das metades sempre está ordenada em qualquer intervalo `[left, right]`, e é isso que deve guiar a busca

* identifica-se qual parte está ordenada

* verifica se `x` pode estar dentro dessa metade

* se sim, descarte a outra

* se não, descarta essa

Em cada iteração:

1. Calcula `middle`

2. Verifica qual lado está ordenado:

    * esquerda (`arr[left] <= arr[middle]`)

    * ou direita

3. Decide se `x` pode estar dentro da parte ordenada

4. Descarta metado do array

---

```c
int searchRotated(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        // metade esquerda está ordenada
        if (arr[left] <= arr[mid]) {

            // x está dentro da parte ordenada?
            if (x >= arr[left] && x < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        // metade direita está ordenada
        else {

            // x está dentro da parte ordenada?
            if (x > arr[mid] && x <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1;
}
```

## 1. Esquece o algoritmo por 2 minutos

Olha **apenas** para a estrutura do problema.

Você tem um array que era **ordenado**:

```
[2, 3, 6, 12, 15, 18]
```

E ele foi **rotacionado**:

```
[15, 18, 2, 3, 6, 12]
```

Repara numa coisa essencial:
Ele virou **duas partes ordenadas**.

* parte A: `[15, 18]`
* parte B: `[2, 3, 6, 12]`

Só existe **um ponto de quebra**.

Em qualquer momento da busca, você olha para três valores:

```
arr[left], arr[mid], arr[right]
```

E pergunta **uma única coisa**:

> A metade esquerda está ordenada **ou** a metade direita está ordenada?

Isso sempre tem resposta. Nunca é “nenhuma”.

---

Array:

```
[15, 18, 2, 3, 6, 12]
```

Índices:

```
 0   1   2  3  4   5
```

Suponha:

```
left = 0
right = 5
mid = 2
arr[mid] = 2
```

Agora compara:

```
arr[left] = 15
arr[mid]  = 2
```

Pergunta:

* `15 <= 2`?
  ❌ Não.

Conclusão lógica:
👉 a metade **esquerda NÃO está ordenada**
👉 então a metade **direita está**

Olha a direita:

```
[2, 3, 6, 12]
```

Está claramente ordenada.

---

## 4. Agora entra o valor que você procura

Suponha que você procura:

```
x = 6
```

Pergunta:

> 6 pode estar dentro dessa metade ordenada?

Critério simples:

```
arr[mid] <= x <= arr[right]
2 <= 6 <= 12  → SIM
```

Então:
👉 joga fora a metade esquerda inteira
👉 continua só na direita

Você **descartou metade do array com certeza lógica**, não por tentativa.

---

Neste bloco:

```c
// metade direita está ordenada
else {
    if (x > arr[mid] && x <= arr[right]) {
        left = mid + 1;
    } else {
        right = mid - 1;
    }
}
```

> “Se eu caí nesse `else`, a metade direita está ordenada.
Então por que eu preciso do `else { right = mid - 1; }`?”

> **porque metade ordenada não significa metade correta**.

---

**O que significa “metade direita está ordenada”?**

Significa apenas isso:

```
arr[mid] <= arr[mid+1] <= ... <= arr[right]
```

Você não quer saber se está ordenado.
Você quer saber:

> `x` pode estar **dentro dessa metade ordenada**?


Você só mantém a metade direita se **x estiver dentro do intervalo dela**:

```
arr[mid] < x <= arr[right]
```

Se isso for verdadeiro:

* faz sentido continuar ali
* você não descartou nenhuma possibilidade válida

Por isso:

```c
left = mid + 1;
```

---

E quando esse teste falha?

Se:

```
x <= arr[mid]  OU  x > arr[right]
```

Então **x não pode estar na metade direita ordenada**.

* toda a metade direita pode ser descartada
* sobra apenas a metade esquerda

```c
right = mid - 1;
```

---

Array:

```
[15, 18, 2, 3, 6, 12]
```

Suponha:

```
left = 0
mid = 2
right = 5
```

Metade direita ordenada:

```
[2, 3, 6, 12]
```

Agora procure:

```
x = 18
```

Teste:

```
2 < 18 <= 12   → FALSO
```

Conclusão lógica inevitável:

* 18 **não está** na metade direita
* logo, só pode estar na esquerda

Então:

```c
right = mid - 1;
```

Se você **não tivesse esse else**, você ficaria sem movimento válido — ou pior, continuaria procurando no lugar errado.

---