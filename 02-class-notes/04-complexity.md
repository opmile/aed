# Padrões de Complexidade

---

## 1. Como identificar a complexidade de um algoritmo 

### Regra zero 

> **Complexidade temporal mede crescimento, não tempo real.**
> Ignora constantes, ignora hardware, ignora linguagem.

---

### 1.1 A pergunta certa a se fazer

Sempre comece com:

> **Quantas vezes o trecho mais interno do código executa em função de `n`?**

Não é “quantas linhas”, é **quantas iterações relevantes**.

---

### 1.2 Padrões de Reconhecimento Imediato

---

### Padrão A — Um loop simples → **O(n)**

```c
for (int i = 0; i < n; i++) {
    // algo constante - O(1)
}
```

Pensamento automático:

* Anda de 0 até n
* Executa n vezes
  → **Linear**

---

### Padrão B — Loop que divide por 2 → **O(log n)**

```c
while (n > 1) {
    n = n / 2;
}
```

Ou:

```c
for (int i = 1; i < n; i *= 2) {
}
```

Pensamento automático:

* Não percorre elemento por elemento
* Reduz o problema pela metade
  → **Logarítmica**

Se divide, é log.

* Cuidado! Pode ser que a base do log não seja 2!

```c
for (int i = 1; i < n; i *= 3) {
}
```
Isso é O(log3 n)

---

### Padrão C — Loop dentro de loop → **Multiplica**

```c
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    }
}
```

* Loop externo: n
* Loop interno: n
  → **n × n = n² → Quadrática**

Regra prática:

> Loops aninhados normalmente **multiplicam** complexidades.

---

### Padrão D — Loop + log → **O(n log n)**

```c
for (int i = 0; i < n; i++) { // O(n)
    binarySearch(v, n); // O(log n)
}
// O(n log n)
```

* Loop externo: n
* Busca binária: log n
  → **n log n (log-linear)**

Clássico de provas.

---

### Padrão E — Recursão que dobra chamadas → **Exponencial**

```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

Pensamento automático:

* Cada chamada gera **duas outras**
* Árvore explode
  → **O(2ⁿ)**

Se o número de chamadas cresce em forma de árvore, desconfie de exponencial.

---

### Padrão F — Todas as permutações → **Fatorial**

```c
permuta(v, n)
```

Se o algoritmo:

* Testa **todas as ordens possíveis**
* Gera todas as permutações
  → **O(n!)**

Não tem conversa.

---

## 2. Exemplos práticos para treinar o “bater o olho”

Agora vem a parte importante: **análise guiada**.

---

### Exemplo 1 — Linear

```c
int soma(int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    return s;
}
```

Análise mental:

* Um único loop
* Executa n vezes
  → **O(n)**

---

### Exemplo 2 — Logarítmico

```c
int busca(int v[], int n, int x) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (v[m] == x) return m;
        if (v[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
```

Análise mental:

* Intervalo reduz pela metade
* Cada iteração corta o problema
  → **O(log n)**

---

### Exemplo 3 — Quadrática

```c
void pares(int v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d %d\n", v[i], v[j]);
        }
    }
}
```

Análise mental:

* Dois loops dependentes de n
* Total de iterações ~ n²
  → **O(n²)**

---

### Exemplo 4 — Log-linear

```c
void ordenaEBusca(int v[], int n) {
    mergeSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }
}
```

* Merge sort: **n log n**
* Loop final: **n**

Regra de ouro:

> Soma → fica o termo dominante

→ **O(n log n)**

---

### Exemplo 5 — Exponencial

```c
int subsetSum(int v[], int n) {
    if (n == 0) return 0;
    return subsetSum(v, n - 1) + subsetSum(v, n - 1);
}
```

Análise:

* Cada chamada gera duas
* Altura da recursão: n
  → **O(2ⁿ)**

---

### Exemplo 6 — Fatorial

```c
void permuta(int v[], int l, int r) {
    if (l == r) {
        imprime(v);
    } else {
        for (int i = l; i <= r; i++) {
            swap(&v[l], &v[i]);
            permuta(v, l + 1, r);
            swap(&v[l], &v[i]);
        }
    }
}
```

Análise mental:

* Testa todas as permutações
* n escolhas × (n−1) × (n−2)…
  → **O(n!)**

---

## 3. Checklist 

Quando bater o olho em um algoritmo, faça isso **sempre na mesma ordem**:

1. Tem loop?

   * Sim → quantas vezes roda?
2. Loop dentro de loop?

   * Multiplica
3. Divide o problema?

   * Log
4. Recursão gera múltiplas chamadas?

   * Exponencial
5. Gera todas as permutações?

   * Fatorial
6. Soma de termos?

   * Fica o maior

Isso vira reflexo.

---