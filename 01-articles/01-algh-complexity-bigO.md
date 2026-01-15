# big O notatoin -- a escalabilidade de algoritmos

## o que é big O?
big O é uma notação matemática que descreve como o tempo (ou espaço) de execução de um algoritmo cresce conforme aumenta o tamanho da entrada (n).

é a forma que temos de analisar escalabilidade e performance de forma assintótica, ou seja, ignorando constantes e focando no crescimento com grandes dados.

estudar um algoritmo de forma assintótica significa analisar seu comportamento quando o tamanho da entrada tende ao infinito (n -> ∞), ou seja, no pior dos cenários, o que garante o limite superior

---

## tipos de complexidade
1. **complexidade temporal:** diz respeito ao tempo de execução/runtime em relação ao crescimento do número de entradas

2. **complexidade espacial:** diz respeito ao alocamento de espaço na memória

### obs: a notapção O(1): constante
constante, independente do tempo e memória necessária

- **tempo**
o tempo para acessar o índice de um array é sempre constante, não importa o tamanho do input ou a posição do elemento na memória

- **espaço**
se queremos achar o índice do maior elemeno em uma lista, estaremos sempre alocando o mesmo espaço na memória:
```java
public class ArrayPractice {
    public static void main(String[] args) {

        int arr[] = {1, 7, 5, 2, 6, 3};

        int max = arr[0];
        for (int i = 1; i < arr.lenght; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }
}
```
* o array original continua intacto
* a única variável extra usada é `max`
* o tempo de execução é linear para percorrer os n elementos de um array O(n) e decidir qual o maior 



