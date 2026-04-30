# grafosEmC

Com certeza. O código que você forneceu representa uma forma comum de implementar um grafo na linguagem C: usando uma **Matriz de Adjacência**.

Aqui está o código completo, exatamente como na imagem:

```c
#include <stdio.h>
#include <stdlib.h>

#define QTD_VERTICES 4 // Definir o número de vértices

// Estrutura de grafo
typedef struct {
    int matriz[QTD_VERTICES][QTD_VERTICES]; // Matriz de adjacência
    int num_vertices; // Número de vértices no grafo
} Grafo;

// Função para inicializar o grafo
void inicializarGrafo(Grafo *g) {
    g->num_vertices = 0;
    for (int i = 0; i < QTD_VERTICES; i++) {
        for (int j = 0; j < QTD_VERTICES; j++) {
            g->matriz[i][j] = 0; // Inicializa a matriz com 0 (sem arestas)
        }
    }
}

// Função para adicionar vértice
void adicionarVertice(Grafo *g) {
    if (g->num_vertices < QTD_VERTICES) {
        g->num_vertices++;
    } else {
        printf("Número máximo de vértices atingido.\n");
    }
}
```

Este código define uma estrutura que reserva um bloco de memória para uma matriz de $4 \times 4$. A função de inicialização zera essa matriz, e a função para adicionar vértice simplesmente incrementa um contador, sem precisar modificar a matriz já alocada.

Como estamos lidando com matrizes de adjacência, o próximo passo lógico para este código seria implementar uma função para adicionar arestas (conexões) entre os vértices.

**O que você gostaria de fazer a seguir?**
1.  Ver como criar uma função `adicionarAresta(Grafo *g, int v1, int v2)` para este código?
2.  Entender as vantagens e desvantagens de usar uma **Matriz de Adjacência** em comparação com uma **Lista de Adjacência**?
3.  Ver um exemplo de uma função `main()` para testar o código acima?
Vou verificar rapidamente o README.md e o arquivo matrizAdj.c para te passar o comando exato de compilação e execução no Windows (PowerShell).

Read [](file:///c%3A/Repo2026/grafosEmC/matrizAdj.c)

Read [](file:///c%3A/Repo2026/grafosEmC/README.md)

Para rodar no Windows (PowerShell), o fluxo é:

1. Entrar na pasta do projeto  
cd C:\Repo2026\grafosEmC

2. Compilar com GCC (MinGW/MSYS2)  
gcc matrizAdj.c -o .\matrizAdj.exe

3. Executar  
.\matrizAdj.exe

Observação importante: o arquivo matrizAdj.c não tem função main no estado atual. Assim, a compilação deve falhar até você adicionar uma main.

Se quiser, eu já adiciono uma main simples para testar criação de vértices e impressão da matriz.