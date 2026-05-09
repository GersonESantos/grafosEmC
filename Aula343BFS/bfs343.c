//Procedimento busca em largura (BFS-Breadth First Search) para grafos representados com matrizes de adjacência
#include <stdio.h>
#include <stdlib.h>
#define QTD_VERTICES 4 // Definir o número de vértices

// Estrutura de grafo
typedef struct {
    int matriz[QTD_VERTICES][QTD_VERTICES]; // Matriz de adjacência
    int num_vertices; // Número de vértices no grafo
} Grafo;

// Procedimento para inicializar o grafo
void inicializarGrafo(Grafo *g) {
    g->num_vertices = 0;
    for (int i = 0; i < QTD_VERTICES; i++) {
        for (int j = 0; j < QTD_VERTICES; j++) {
            g->matriz[i][j] = 0; // Inicializa a matriz com 0 (sem arestas)
        }
    }
}
// Procedimento para adicionar vértice
void adicionarVertice(Grafo *g) {
    if (g->num_vertices < QTD_VERTICES) {
        printf("Vertice %d adicionado com sucesso!\n", g->num_vertices);
        g->num_vertices++;
    } else {
        printf("Nao e possivel adicionar mais vertices. O limite foi atingido.\n");
    }
}

// Função para verificar se o vértice existe
int verticeExiste(int v, int numV) {
    if (v >= 0 && v < numV)
        return 1;
    else
        return 0;
}

// Procedimento para adicionar aresta entre dois vértices
void adicionarAresta(Grafo *g, int v1, int v2) {
    if (verticeExiste(v1, g->num_vertices) && verticeExiste(v2, g->num_vertices)) {
        g->matriz[v1][v2] = 1; // Adiciona aresta de v1 para v2
        g->matriz[v2][v1] = 1; // Como o grafo é não direcionado, adiciona também a aresta de v2 para v1
        printf("Aresta entre %d e %d adicionada com sucesso.\n", v1, v2);
    } else {
        printf("Vertices invalidos! Aresta nao adicionada.\n");
    }
}
// Procedimento para remover aresta entre dois vértices
void removerAresta(Grafo *g, int v1, int v2) {
    if (verticeExiste(v1, g->num_vertices) && verticeExiste(v2, g->num_vertices)) {
        g->matriz[v1][v2] = 0; // Remove a aresta de v1 para v2
        g->matriz[v2][v1] = 0; // Remove a aresta de v2 para v1
        printf("Aresta entre %d e %d removida com sucesso.\n", v1, v2);
    } else {
        printf("Vertices invalidos! Aresta nao removida.\n");
    }
}
// Procedimento para exibir a matriz de adjacência
void exibirMatriz(Grafo *g) {
    printf("\nMatriz de Adjacencia do Grafo:\nVertices----");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertice %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Procedimento Busca em Largura (BFS - Breadth-First Search)
void bfs(Grafo *g, int verticeInicial) {
    int visitados[QTD_VERTICES] = {0};
    int fila[QTD_VERTICES];
    int indiceRemover = 0, indiceEnfileirar = 0;

    visitados[verticeInicial] = 1; // Marca o vértice inicial como visitado
    fila[indiceEnfileirar++] = verticeInicial; // Coloca o vértice inicial na fila

    printf("Busca em Largura (BFS) a partir do vertice %d: ", verticeInicial);

    while (indiceRemover < indiceEnfileirar) {
        int VerticeAtual = fila[indiceRemover++]; // Retira um vértice da fila
        printf("%d ", VerticeAtual);

        // Enfileira os vizinhos não visitados
        for (int i = 0; i < g->num_vertices; i++) {
            if (g->matriz[VerticeAtual][i] == 1 && !visitados[i]) {
                visitados[i] = 1;
                fila[indiceEnfileirar++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    Grafo g;
    inicializarGrafo(&g); // Inicializa o grafo

    // Adicionando vértices
    adicionarVertice(&g); // Vértice 0
    adicionarVertice(&g); // Vértice 1
    adicionarVertice(&g); // Vértice 2
    adicionarVertice(&g); // Vértice 3

    // Adicionando arestas
    adicionarAresta(&g, 0, 1);
    adicionarAresta(&g, 1, 2);
    adicionarAresta(&g, 2, 3);
    adicionarAresta(&g, 0, 3);

    // Executando busca em largura
    bfs(&g, 0);

    // Exibindo a matriz de adjacência
    exibirMatriz(&g);  
    removerAresta(&g, 0, 3);// Removendo uma aresta e exibindo novamente
    exibirMatriz(&g);
    
    // Executando busca em largura novamente após a remoção
    bfs(&g, 0);

    return 0;
}