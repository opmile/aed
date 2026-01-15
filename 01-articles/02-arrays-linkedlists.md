## estrutura de dados

uma estrutura de dados pode ser representada como uma coleção tanto de valores (e seus relacionamentos) quanto de operações (sobre os valores e estruturas decorrentes)

### arrays
* armazenamento contíguo na memória
* acesso direto por índice (complexidade constante: O(1))
* inserir/remover no início ou no meio exige deslocamento de memória, proporcional ao tamanho de itens n do array (complexidade linear O(n))

### linked list
* é não contígua, baseada em nós ligados por ponteiros na memória
    1. single linked list - o nó carrega o endereço do próximo nó
    2. double linked list - o nó carrega o endereço do nó anterior e do próximo nó
* inserções e remoções instantâneas podem ser muito rápidas (com O(1), já que só trocamos o ponteiro)
* como não tem acesso direto por índice, precisa percorrer nó por nó para acessar ou buscar um dado (tempo linear O(n))

### arrays x linked lists

**arrays**
1. acesso rápido via índice
2. poucas inserções/remoções

**linked lists**
1.  inserções e remoções são utilizadas quando se tem controle do início e fim da lista
2. indiferente ao acesso direto 

linkedlist| leitura  | inserção | remoção  |
|---------|----------|----------|----------|
|  best   |   O(1)   |   O(1)   |   O(1)   |
|  worst  |   O(n)   |   O(n)   |   O(n)   |