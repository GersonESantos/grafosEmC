#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define NULO  -1
#define INF    INT_MAX

// Estrutura para os vértices do grafo
typedef struct {
    int cor;
    int d;  // distância
    int pi; // predecessor (π)
} Vertice;

// Estrutura simples de Fila (Queue) para o BFS
typedef struct {
    int *itens;
    int frente;
    int tras;
    int tamanho;
} Fila;

Fila* criar_fila(int n) {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->itens = (int*)malloc(n * sizeof(int));
    q->frente = 0;
    q->tras = 0;
    q->tamanho = n;
    return q;
}

void enfileirar(Fila* q, int v) {
    q->itens[q->tras++] = v;
}

int desenfileirar(Fila* q) {
    return q->itens[q->frente++];
}

int fila_vazia(Fila* q) {
    return q->frente == q->tras;
}

// Algoritmo BFS conforme o pseudocódigo fornecido
// Use um array plano para evitar parâmetros VLA em compiladores que não suportam VLA
void BFS(int n, int *G, int s, Vertice vertices[]) {
    // 1-4: Inicialização de todos os vértices u em V - {s}
    for (int u = 0; u < n; u++) {
        if (u != s) {
            vertices[u].cor = BRANCO;
            vertices[u].d = INF;
            vertices[u].pi = NULO;
        }
    }

    // 5-7: Inicialização do vértice de origem s
    vertices[s].cor = CINZA;
    vertices[s].d = 0;
    vertices[s].pi = NULO;

    // 8-9: Inicialização da fila Q com s
    Fila* Q = criar_fila(n);
    enfileirar(Q, s);

    // 10: Enquanto Q não estiver vazia
    while (!fila_vazia(Q)) {
        // 11: Remove u da fila
        int u = desenfileirar(Q);

        // 12: Para cada v adjacente a u
        for (int v = 0; v < n; v++) {
            if (G[u * n + v] == 1) { // Se existe aresta (u, v)
                // 13: Se v for BRANCO
                if (vertices[v].cor == BRANCO) {
                    // 14-17: Atualiza e enfileira v
                    vertices[v].cor = CINZA;
                    vertices[v].d = vertices[u].d + 1;
                    vertices[v].pi = u;
                    enfileirar(Q, v);
                }
            }
        }
        // 18: u é finalizado como PRETO
        vertices[u].cor = PRETO;
    }
    // libera a fila usada
    free(Q->itens);
    free(Q);
}

int main() {
    int n = 6; // Exemplo com 6 vértices (A=0, B=1, C=2, D=3, E=4, F=5)
    
    // Matriz de adjacência baseada nos seus estudos anteriores (A-F)
    int grafo[6][6] = {
        {0, 1, 1, 1, 0, 0}, // A conecta com B, C, D
        {1, 0, 0, 0, 1, 0}, // B conecta com A, E
        {1, 0, 0, 0, 0, 1}, // C conecta com A, F
        {1, 0, 0, 0, 0, 0}, // D conecta com A
        {0, 1, 0, 0, 0, 1}, // E conecta com B, F
        {0, 0, 1, 0, 1, 0}  // F conecta com C, E
    };

    Vertice *vertices = (Vertice*)malloc(n * sizeof(Vertice));
    int origem = 0; // Iniciando no vértice A

    // Passa o ponteiro para o primeiro elemento da matriz
    BFS(n, &grafo[0][0], origem, vertices);

    printf("Resultados do BFS partindo de A:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertice %d | Distancia: %d | Predecessor: %d\n", i, vertices[i].d, vertices[i].pi);
    }

    free(vertices);

    return 0;
}