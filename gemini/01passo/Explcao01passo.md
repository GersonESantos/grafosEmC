Essa é a base fundamental para representar grafos em computação. Vamos dissecar o código por partes, focando no que acontece na memória do computador, algo que ajuda muito quem está revisitando os conceitos de **Ciência da Computação**.

---

## 1. Cabeçalho e Definições
```c
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5
```
* **`#define MAX_VERTICES 5`**: Aqui você define uma constante. Em grafos, é comum saber o número de nós (vértices) antes de criar a matriz. No seu caso, o grafo tem 5 nós (0, 1, 2, 3 e 4).

---

## 2. Declaração e Inicialização (Limpeza da Memória)
```c
int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];

for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
        matrizAdjacencia[i][j] = 0;
    }
}
```
* **A Matriz**: Imagine uma tabela de 5x5. Na memória, o C reserva um bloco contínuo para 25 inteiros ($5 \times 5 = 25$).
* **O Loop Aninhado**: Quando você declara um array em C, ele pode vir com "lixo de memória". Esse loop percorre cada linha (`i`) e cada coluna (`j`), garantindo que todas as células comecem com **0**. 
    * **0** significa: "Não existe aresta (conexão) entre o vértice `i` e o vértice `j`".

---

## 3. Montagem das Arestas (O Coração do Grafo)
```c
matrizAdjacencia[0][1] = 1;
matrizAdjacencia[1][0] = 1;
```
Aqui você está definindo as conexões. 
* **Grafo Não-Direcionado**: Como o seu grafo não tem setas, a conexão é mútua. Se o nó `0` é vizinho do `1`, o nó `1` obrigatoriamente é vizinho do `0`. 
* Por isso, para cada conexão, você faz **duas atribuições**. Isso cria uma **Matriz Simétrica** (se você traçasse uma linha diagonal nela, os dois lados seriam iguais).

---

## 4. Exibição Visual
```c
for (int i = 0; i < MAX_VERTICES; i++) {
    printf("%d | ", i); // Imprime o índice da linha lateral
    for (int j = 0; j < MAX_VERTICES; j++) {
        printf("%d ", matrizAdjacencia[i][j]);
    }
    printf("\n");
}
```
Este trecho serve para você "enxergar" o grafo. O resultado no terminal será:

```text
    0 1 2 3 4
    ---------
0 | 0 1 1 1 0 
1 | 1 0 0 1 0 
2 | 1 0 0 0 0 
3 | 1 1 0 0 1 
4 | 0 0 0 1 0 
```

### Como ler o resultado:
* Olhe para a **Linha 0**: Você vê o número `1` nas colunas `1, 2 e 3`. Isso confirma que o nó `0` está conectado aos nós `1, 2 e 3`.
* Olhe para a **Linha 4**: Só existe o número `1` na coluna `3`. Isso confirma que o nó `4` só tem um vizinho: o nó `3`.

---

## 💡 Pontos Importantes para o seu estudo (Cormen):

1.  **Complexidade de Espaço**: Esta matriz ocupa $\Theta(V^2)$ de memória. No seu caso, $5^2 = 25$. Se o grafo tivesse 1.000 nós, seriam 1.000.000 de espaços.
2.  **Vantagem**: Você consegue responder à pergunta: *"O nó 2 está conectado ao nó 4?"* instantaneamente, apenas checando `matrizAdjacencia[2][4]`. O tempo de resposta é **constante**, ou $O(1)$.
3.  **Uso no DFS**: Quando você for implementar o DFS, o algoritmo vai olhar para uma linha (ex: linha 0) e perguntar: *"Para quais colunas aqui o valor é 1?"*. Essas colunas são os vizinhos que ele deve visitar.

Deseja que eu prepare agora um código que permita ao usuário digitar as conexões pelo teclado, em vez de deixá-las fixas?