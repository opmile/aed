# Menor elemento >= x

> Encontre o menor valor do vetor que seja maior ou igual a x.

---

Dado um vetor ordenado:

```c
int arr[] = { 1, 3, 3, 5, 7 };
```

Valor buscado: `x = 4` 

* Não precisa necessariamente estar presente no vetor, já que queremos o menor índice `i` (esse presente) que `x >= arr[i]`

*Estado inicial*:

```c
left = 0;
right = 4; // n - 1 = 5 - 1 = 4
result = -1;
```

### Iteração 1:

```c
middle = 2 // left + (right - left) / 2 = 0 + (4 - 0) / 2 = 2
arr[middle] = 3 
```

Comparação:

* `3 < 4` -- pequeno demais! 

Conclusão Lógica: 

* nenhum elemento à esquerda ou no `middle` poderia servir

* descartamos tudo até `middle` 

```c
left = middle + 1 = 3;
```

### Iteração 2:

```c
left = 3;
right = 4;
middle = 3 + (4 - 3) / 2 = 3;
arr[middle] = 5;
```

Comparação:

* `5 >= 4` -- primeiro candidato válido

Mas atenção!

* pode existe outro valor >= 4 menor que 5

* esse valor só poderia estar à esquerda

* precisamos atualizar o valor do resultado e continuar procurando à esquerda, atualizando o ponteiro da direita

```c
result = 5;
right = middle - 1 = 2
```

### Fim do Loop

Como:

```c
left = 3;
right = 2;
```

Condição `left <= right` falha e o loop termina

Resultado final => `result = 5`, que é exatamente o valor do vetor que é maior ou igual a 4.

### Por que funciona

Porque sempre que encontramos um valor >= `x`:

* não descartamos a possiblidade

* mas tentamos melhorar a resposta, buscando algo menor

E sempre que encontramos um valor < `x`:

* descartamos com segurança

* porque ele nunca poderá satisfazer a condição

---

## Ideia Central

Queremos o menor índice `i` tal que `arr[i] >= x`

Então o raciocínio é:

* se `arr[middle] >= x`

    - `middle` é um candidato válido

    - mas pode existir outro menor ainda à esquerda

    - força a busca para a esquerda

* se `arr[middle] < x`

    - todos à esquerda são pequenos demais

    - vai para a direita

---

## Implementação do C (iterativa)

```c
int lowerBound(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        int pos = arr[middle];

        if (pos >= x) {
            result = pos; // candidato válido
            right = middle - 1; // tenta buscar um valor menor ainda
        } else { // pos < x
            left = middle + 1; // descarta a possibilidade
        }
    }

    return result;
}
``