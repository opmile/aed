# O que é ordenação interna?

Ordenação é a operação de **rearranjar um conjunto de dados** para que seus elementos fiquem em uma **ordem previamente definida** ao final do processo.

Essa ordem quase nunca é “aleatória” ou estética:
ela é definida a partir de **um atributo específico de cada elemento**, chamado de **chave de ordenação**.

Exemplos de chaves:

* idade de uma pessoa
* nota de um aluno
* preço de um produto
* matrícula, ID, CPF

Ou seja:

> **não se ordenam dados “puros”, ordenam-se dados com base em um critério.**

### Por que “ordenação interna”?

Porque **todo o conjunto de dados cabe na memória principal (RAM)** durante o processo.
Isso muda completamente as decisões de projeto quando comparado à ordenação externa (arquivos gigantes, disco, etc.).

---

## Critérios de classificação dos algoritmos de ordenação

Agora vem a parte importante: **não existe “o melhor algoritmo de ordenação”**.
Existem **algoritmos melhores para determinados contextos**, e é por isso que usamos critérios.

---

## A. Estratégia de ordenação

Esse critério responde à pergunta:

> **Como o algoritmo decide a ordem correta entre dois elementos?**

Ou seja, qual é a **estratégia de comparação das chaves**.

Algumas ideias gerais (sem entrar em algoritmos):

* Comparar pares de elementos adjacentes
* Escolher um elemento como referência e reorganizar os demais
* Dividir o conjunto em partes menores e ordenar separadamente
* Inserir elementos gradualmente em uma estrutura já ordenada

Aqui não importa *qual* algoritmo faz isso, mas **o padrão mental por trás da ordenação**.

Minha opinião forte:

> entender a estratégia é muito mais valioso do que decorar passos.

---

## B. Estabilidade (ponto crucial)

Esse é um dos critérios mais ignorados por iniciantes — e um dos mais importantes na prática.

### O que é estabilidade?

Um algoritmo de ordenação é **estável** se ele **preserva a ordem relativa dos elementos que possuem a mesma chave**.

Exemplo conceitual:

Suponha registros:

```
(Ana, nota 8)
(Carlos, nota 10)
(João, nota 8)
```

Se você ordenar por **nota**, um algoritmo **estável** garante que:

```
(Ana, nota 8)
(João, nota 8)
(Carlos, nota 10)
```

A Ana continua antes do João porque **ela já estava antes** no conjunto original.

### Algoritmos não estáveis

Um algoritmo **não estável** pode produzir:

```
(João, nota 8)
(Ana, nota 8)
(Carlos, nota 10)
```

Mesmo com as notas corretas, a ordem interna dos iguais foi quebrada.

### Por que isso importa?

* Ordenações em múltiplos níveis (ex: ordenar por nome depois por idade)
* Sistemas reais (cadastros, relatórios, bancos de dados)
* Interfaces que o usuário espera consistência visual

Opinião direta:

> estabilidade não é detalhe acadêmico, é requisito de sistema real.

---

## C. Complexidade de tempo

Aqui analisamos **quanto tempo o algoritmo leva**, em função do tamanho do conjunto de dados (`n`).

Normalmente observamos:

* Melhor caso
* Caso médio
* Pior caso

As classes mais comuns que aparecem:

* Linear — O(n)
* Logarítmica — O(log n)
* Log-linear — O(n log n)
* Quadrática — O(n²)

Esse critério responde:

> **Esse algoritmo escala bem quando os dados crescem?**

E sim:

> tempo costuma ser mais importante que elegância.

---

## D. Complexidade de trocas (swaps)

Esse critério analisa **quantas movimentações físicas de elementos** o algoritmo realiza.

Por que isso é relevante?

* Trocar elementos custa tempo
* Em estruturas grandes, trocas excessivas degradam desempenho
* Em memória ou cache, movimentar dados é caro

Dois algoritmos podem ter:

* Mesma complexidade de tempo
* Mas números de trocas completamente diferentes

Esse critério é muito valorizado quando:

* Os elementos são grandes
* O custo de cópia é alto

---

## E. Complexidade de espaço (memória)

Aqui perguntamos:

> **O algoritmo precisa de memória extra além do próprio conjunto de dados?**

Classificação comum:

* **In-place**: usa memória constante ou quase constante
* **Não in-place**: precisa de estruturas auxiliares

Trade-off clássico:

* Menos memória → mais comparações ou trocas
* Mais memória → algoritmos mais rápidos e organizados

Opinião honesta:

> memória barata não significa memória infinita — esse critério ainda importa muito.

---

## F. Uso de recursividade

Alguns algoritmos de ordenação:

* São naturalmente recursivos
* Outros são totalmente iterativos

A recursividade impacta:

* Uso da pilha de execução
* Legibilidade do código
* Risco de estouro de pilha em grandes entradas

Aqui não se discute se recursão é “boa” ou “ruim”, mas:

> **se o algoritmo depende dela como parte central da estratégia.**

---

## Fechando a ideia

Antes de estudar qualquer algoritmo específico, guarde isso:

* Ordenação é sobre **chaves**
* Algoritmos diferem por **estratégia**, não só por código
* Estabilidade é um divisor de águas
* Tempo, espaço e trocas são sempre trade-offs
* Recursividade não é detalhe, é decisão de projeto

---