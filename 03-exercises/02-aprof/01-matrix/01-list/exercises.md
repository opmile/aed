## Bloco 1: Fundamentos e Estatística

**Objetivo:** Praticar a alocação, preenchimento aleatório e a navegação básica por toda a matriz.

### Exercício 1: O Grande Panorama

**Enunciado:** Escreva um programa que solicite ao usuário as dimensões  (linhas) e  (colunas) de uma matriz. O programa deve processar dados estatísticos básicos.

* **O que deve ser implementado:**
* Função de alocação dinâmica que retorna um `int**`.
* Procedimento para preencher a matriz com valores aleatórios entre 0 e 100.
* Procedimento que encontre e imprima o **maior**, o **menor** e a **média** de todos os elementos.
* Procedimento de liberação de memória.


* **Restrições:**
* Não usar variáveis globais.
* A função de média deve percorrer a matriz usando apenas aritmética de ponteiros (ex: `*(*(M + i) + j)`).

---

## Bloco 2: Análise de Diagonais e Validação

**Objetivo:** Manipular índices de matrizes quadradas e validar dimensões.

### Exercício 2: O "X" da Questão

**Enunciado:** Dada uma matriz quadrada de ordem `n`, implemente funções para analisar suas diagonais.

* **O que deve ser implementado:**
* Função para validar se a matriz é quadrada antes de iniciar o processamento.
* Procedimento que imprima os elementos da **diagonal principal**.


* Procedimento que imprima os elementos da **diagonal secundária**.
* Cálculo da soma total dos elementos que formam o "X" (união das duas diagonais), garantindo que o elemento central (se houver) não seja somado duas vezes.


* **Restrições:**
* Utilizar funções separadas para cada tarefa.
* A ordem  deve ser definida dinamicamente em tempo de execução.

---

## Bloco 3: Operações por Regiões

**Objetivo:** Controlar os limites dos laços de repetição para acessar partes específicas da estrutura.

### Exercício 3: Triângulos de Dados

**Enunciado:** Em uma matriz quadrada, os elementos acima e abaixo da diagonal principal definem regiões distintas (triangular superior e inferior).

* **O que deve ser implementado:**
* Procedimento para calcular a soma de todos os elementos **estritamente acima** da diagonal principal.

* Procedimento para contar quantos elementos **estritamente abaixo** da diagonal principal são números pares.


* **Restrições:**
* Os laços `for` devem ser otimizados para percorrer apenas a região necessária, evitando percorrer a matriz inteira com um `if` dentro.

---

## Bloco 4: Transformações e Memória

**Objetivo:** Trabalhar com a criação de novas estruturas a partir de matrizes existentes.

### Exercício 4: Transposição Dinâmica

**Enunciado:** Implemente o conceito de matriz transposta (onde linhas se tornam colunas).

* **O que deve ser implementado:**
* Uma função que recebe uma matriz  () e retorna uma **nova** matriz  (), alocada dinamicamente, sendo esta a transposta de .
* Procedimento para exibir ambas as matrizes lado a lado.


* **Restrições:**
* Garantir que a memória da matriz original e da transposta sejam liberadas corretamente ao final.
* O usuário deve poder entrar com valores de .

---

## Bloco 5: Desafio de Simetria

**Objetivo:** Comparar elementos em posições espelhadas e validar propriedades lógicas.

### Exercício 5: Verificador de Simetria

**Enunciado:** Uma matriz é simétrica se  para todos os índices.

* **O que deve ser implementado:**
* Função booleana (ou que retorne `int` 0/1) que verifique se uma matriz dinâmica quadrada é simétrica.
* Procedimento que receba a matriz e, caso não seja simétrica, a transforme em simétrica substituindo  e  pela média aritmética entre os dois valores originais.


* **Restrições:**
* Uso obrigatório de `safeMalloc` (ou similar) para garantir que a alocação ocorreu com sucesso.
* A lógica de comparação não deve acessar a diagonal principal (pois ela é sempre simétrica em relação a si mesma).

---