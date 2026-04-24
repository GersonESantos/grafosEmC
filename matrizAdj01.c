#include <stdio.h>
#include <stdlib.h>

#define QTD_VERTICES 4 // Definir o número de vértices

// Estrutura de grafo
typedef struct 
{
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
        printf("Vertice %d adicionado com sucesso!\n", g->num_vertices);
        g->num_vertices++;
    } else {
        printf("Nao e possivel adicionar mais vertices. O limite foi atingido.\n");
    }
}

// Função para verificar se o vértice existe
int verticeExiste(int v, int numV) {
    if (v >= 0 && v < numV) {
        return 1;
    } else {
        return 0;
    }
}

// Função para adicionar aresta entre dois vértices
void adicionarAresta(Grafo *g, int v1, int v2) {
    if (verticeExiste(v1, g->num_vertices) && verticeExiste(v2, g->num_vertices)) {
        g->matriz[v1][v2] = 1; // Adiciona aresta de v1 para v2
        g->matriz[v2][v1] = 1; // Como o grafo é não direcionado, adiciona também a aresta de v2 para v1
        printf("Aresta entre %d e %d adicionada com sucesso.\n", v1, v2);
    } else {
        printf("Erro: Um ou ambos os vertices (%d, %d) nao existem.\n", v1, v2);
    }
}

// Função para remover aresta entre dois vértices
void removerAresta(Grafo *g, int v1, int v2) {
    if (verticeExiste(v1, g->num_vertices) && verticeExiste(v2, g->num_vertices)) {
        g->matriz[v1][v2] = 0;
        g->matriz[v2][v1] = 0;
        printf("Aresta entre %d e %d removida com sucesso.\n", v1, v2);
    } else {
        printf("Erro: Um ou ambos os vertices (%d, %d) nao existem.\n", v1, v2);
    }
}

// --- FUNÇÃO ADICIONADA DA IMAGEM ---
void exibirMatriz(Grafo *g) {
    printf("\nMatriz de Adjacencia do Grafo:\nVertices---");
    
    // Cabeçalho com os índices das colunas
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Linhas da matriz
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Vertice %d: ", i);
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// -----------------------------------

int main(void) {
    Grafo g;
    inicializarGrafo(&g);

    printf("--- Adicionando Vertices ---\n");
    adicionarVertice(&g); // Vértice 0
    adicionarVertice(&g); // Vértice 1
    adicionarVertice(&g); // Vértice 2
    adicionarVertice(&g); // Vértice 3

    printf("\n--- Adicionando Arestas ---\n");
    adicionarAresta(&g, 0, 1); // Conecta 0 e 1
    adicionarAresta(&g, 1, 2); // Conecta 1 e 2
    adicionarAresta(&g, 2, 3); // Conecta 2 e 3
    adicionarAresta(&g, 0, 3); // O vértice 3 já foi adicionado, então a aresta é válida

    printf("\nNumero total de vertices: %d\n", g.num_vertices);

    // Chama a função que foi adicionada
    exibirMatriz(&g);
    removerAresta(&g, 0, 3); // Remove a aresta entre 0 e 3
    exibirMatriz(&g);
    return 0;
}