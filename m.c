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

// Função para adicionar vértice (Versão da segunda imagem)
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

int main(void) {
    Grafo g;
    inicializarGrafo(&g);

    printf("--- Adicionando Vertices ---\n");
    adicionarVertice(&g); // Vértice 0
    adicionarVertice(&g); // Vértice 1
    adicionarVertice(&g); // Vértice 2

    printf("\n--- Adicionando Arestas ---\n");
    adicionarAresta(&g, 0, 1); // Conecta 0 e 1
    adicionarAresta(&g, 1, 2); // Conecta 1 e 2
    adicionarAresta(&g, 0, 3); // Deve dar erro, pois o vértice 3 ainda não foi "adicionado"

    printf("\nNumero total de vertices: %d\n", g.num_vertices);

    return 0;
}