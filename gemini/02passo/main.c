#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 5

// 1. Array global para marcar os visitados (como o 'marked' da imagem)
bool marked[MAX_VERTICES];

// 2. A matriz de adjacência (o nosso Grafo G)
int matrizAdjacencia[MAX_VERTICES][MAX_VERTICES];

// --- ALGORITMO DFS INTEGRADO COM A MATRIZ ---
void dfs(int v) {
    // Visita o vértice (imprime no console)
    printf("Visitando vertice: %d\n", v);
    
    // Marca como visitado
    marked[v] = true;

    // Procura vizinhos na matriz (percorre a linha v)
    // Isso substitui o "for w in G.neighbors(v)" do Python
    for (int w = 0; w < MAX_VERTICES; w++) {
        // Se existe conexão (matriz[v][w] == 1) E o vizinho não foi visitado
        if (matrizAdjacencia[v][w] == 1 && !marked[w]) {
            dfs(w); // Chamada recursiva
        }
    }
}

int main() {
    // 3. Inicializar visitados com false
    for (int i = 0; i < MAX_VERTICES; i++) {
        marked[i] = false;
    }

    // 4. Montar o Grafo (igual fizemos na parte anterior)
    // Conexões do vértice 0 (baseado na sua imagem)
    matrizAdjacencia[0][1] = 1; matrizAdjacencia[1][0] = 1;
    matrizAdjacencia[0][2] = 1; matrizAdjacencia[2][0] = 1;
    matrizAdjacencia[0][3] = 1; matrizAdjacencia[3][0] = 1;
    matrizAdjacencia[1][3] = 1; matrizAdjacencia[3][1] = 1;
    matrizAdjacencia[3][4] = 1; matrizAdjacencia[4][3] = 1;

    // 5. Iniciar a busca a partir do vértice 0
    printf("--- Iniciando Busca em Profundidade (DFS) ---\n");
    dfs(0);

    return 0;
}