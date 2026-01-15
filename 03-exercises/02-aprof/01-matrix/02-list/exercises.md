# Lista ALgoritmica de Matrizes

Esta lista de exercícios foi desenhada para treinar o seu cérebro a "enxergar" os dados antes mesmo de escrever a primeira linha de código. O foco aqui é o **raciocínio lógico** e a **manipulação de índices**.

---

### Exercício 1: O Rastreador de Frequência

**Descrição:** Dada uma lista de números inteiros e um "valor alvo", você deve descobrir quantas vezes esse valor aparece na lista.

* **Exemplo de Entrada:** Lista: `[10, 5, 20, 5, 5, 30]`, Alvo: `5`
* **Exemplo de Saída:** `3`
* **Para pensar:** Se você estivesse olhando para uma fileira de caixas fechadas, como você organizaria sua busca para não esquecer nenhuma caixa e como faria para "anotar" cada vez que encontrasse o que procura?

### Exercício 2: O Saldo Mais Alto (Inspirado no LeetCode 1672)

**Descrição:** Imagine uma tabela onde cada **linha** representa uma pessoa e cada **coluna** representa uma conta bancária dessa pessoa em diferentes bancos. Seu objetivo é descobrir qual é o maior patrimônio total entre todas as pessoas.

* **Exemplo de Entrada:** * Pessoa 1: `[1, 2, 3]` (Total: 6)
* Pessoa 2: `[3, 2, 1]` (Total: 6)
* Pessoa 3: `[8, 0, 0]` (Total: 8)


* **Exemplo de Saída:** `8`
* **Para pensar:** Você precisa somar os valores de cada linha individualmente. Enquanto você calcula a soma de uma pessoa, como você faz para lembrar se ela é "mais rica" do que a pessoa anterior que você já analisou?

### Exercício 3: O Guardião da Fronteira

**Descrição:** Dada uma matriz (tabela) de qualquer tamanho, você deve calcular a soma apenas dos elementos que estão nas "bordas" (a primeira linha, a última linha, a primeira coluna e a última coluna).

* **Exemplo de Entrada:** Matriz 3x3
```
[1, 1, 1]
[1, 0, 1]
[1, 1, 1]

```


* **Exemplo de Saída:** `8`
* **Para pensar:** Como você identifica matematicamente se um elemento está na "beirada"? Pense nos índices: qual é o número da primeira linha? E da última? Se um elemento está na primeira linha, ele automaticamente faz parte da borda, independente da coluna?

### Exercício 4: O "X" no Mapa (Inspirado no LeetCode 1572)

**Descrição:** Em uma matriz quadrada (mesmo número de linhas e colunas), você deve somar todos os valores que pertencem às duas diagonais (principal e secundária). **Atenção:** se houver um elemento no cruzamento (centro), ele só deve ser somado uma vez.

* **Exemplo de Entrada:** Matriz 3x3
```
[1, 0, 1]
[0, 1, 0]
[1, 0, 1]

```

* **Exemplo de Saída:** `5`
* **Para pensar:** Tente encontrar o padrão: na diagonal principal, o que há de comum entre o número da linha e o da coluna? E na secundária, como a coluna se comporta à medida que a linha aumenta? Como você detecta se está exatamente no meio do "X"?

### Exercício 5: O Teste do Espelho

**Descrição:** Uma matriz é considerada "simétrica" se ela for idêntica à sua versão transposta (quando as linhas viram colunas). Seu objetivo é dizer se uma matriz é um "espelho" perfeito dela mesma.

* **Exemplo de Entrada (Simétrica):**
```
[1, 2]
[2, 1]

```

* **Exemplo de Saída:** `Sim`
* **Exemplo de Entrada (Não Simétrica):**
```
[1, 2]
[3, 4]

```

* **Exemplo de Saída:** `Não`
* **Para pensar:** Para que a matriz seja simétrica, o valor na posição `(linha 1, coluna 2)` deve ser igual ao valor em qual outra posição? Se você encontrar um único par de valores que não combina, você precisa continuar verificando o resto da tabela?

---

### Dicas para resolver:

1. **Desenhe os índices:** Antes de pensar na lógica, desenhe a matriz no papel e escreva os números das linhas (0, 1, 2...) e das colunas por fora.
2. **Rastreio Manual:** Pegue os exemplos de entrada e tente resolvê-los passo a passo, como se você fosse um robô que só consegue ver uma célula da tabela por vez.
3. **Identifique o "Gatilho":** O que faz um número ser somado ou ignorado? Escreva essa regra em português simples antes de tentar montar a estrutura lógica.