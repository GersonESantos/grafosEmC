Perfeito, Gerson. Vamos focar exclusivamente na **Matriz de Adjacência**. 

Diferente da Lista de Adjacência (que usa ponteiros), a **Matriz** é mais intuitiva: é uma tabela onde $1$ significa que existe uma conexão e $0$ significa que não existe.

Aqui está o código em **C** focado apenas na criação e montagem dessa matriz:




### 💡 O que você deve observar:

* **Espaço em Memória:** Note que para 5 vértices, criamos 25 espaços ($5 \times 5$). Se você tivesse 10.000 vértices, seriam 100 milhões de espaços! É por isso que o Cormen e o vídeo do Reducible mencionam que a matriz é boa para grafos "densos" (muitas conexões), mas ruim para grafos "esparsos".
* **Simetria:** Como o seu grafo não tem setas (é não-direcionado), a matriz é espelhada. Se você olhar a linha 0 e a coluna 0, elas terão os mesmos valores.
* **Acesso Rápido:** A grande vantagem aqui é que, para saber se o vértice `3` está conectado ao `4`, basta checar `if (matrizAdjacencia[3][4] == 1)`, o que é instantâneo ($O(1)$).

gcc main.c -o main
./main 

Quer que a próxima parte seja como integrar essa matriz com a função de busca **DFS**?