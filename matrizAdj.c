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