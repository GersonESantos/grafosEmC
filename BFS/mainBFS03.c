#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BRANCO 0
#define CINZA  1
#define PRETO  2
#define NULO  -1
#define INF    INT_MAX

typedef struct {
    int cor;
    int d;
    int pi;
} Vertice;

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

// Função para mostrar o estado atual detalhado (Cor, Distância, Pai)
void mostrar_estado_detalhado(int n, Vertice vertices[], const char* acao, int u_atual) {
    char nomes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    printf("\n>>> %s", acao);
    if (u_atual != NULO) printf(" (u = %c)", nomes[u_atual]);
    printf("\n");
    
    printf("Vertice | ");
    for (int i = 0; i < n; i++) printf("  %c  | ", nomes[i]);
    printf("\n--------|");
    for (int i = 0; i < n; i++) printf("-----| ");
    
    // Linha de Cores
    printf("\nCor     | ");
    for (int i = 0; i < n; i++) {
        char c = (vertices[i].cor == BRANCO) ? 'B' : (vertices[i].cor == CINZA) ? 'C' : 'P';
        printf("  %c  | ", c);
    }
    
    // Linha de Distâncias
    printf("\nd       | ");
    for (int i = 0; i < n; i++) {
        if (vertices[i].d == INF) printf(" inf | ");
        else printf("  %d  | ", vertices[i].d);
    }
    
    // Linha de Pais (PI)
    printf("\npi      | ");
    for (int i = 0; i < n; i++) {
        if (vertices[i].pi == NULO) printf(" NIL | ");
        else printf("  %c  | ", nomes[vertices[i].pi]);
    }
    printf("\n");
}

void BFS(int n, int *G, int s, Vertice vertices[]) {
    char nomes[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for (int u = 0; u < n; u++) {
        vertices[u].cor = BRANCO;
        vertices[u].d = INF;
        vertices[u].pi = NULO;
    }

    vertices[s].cor = CINZA;
    vertices[s].d = 0;
    vertices[s].pi = NULO;

    mostrar_estado_detalhado(n, vertices, "Inicializacao", NULO);

    Fila* Q = criar_fila(n);
    enfileirar(Q, s);

    while (!fila_vazia(Q)) {
        int u = desenfileirar(Q);
        mostrar_estado_detalhado(n, vertices, "Desenfileirando", u);

        for (int v = 0; v < n; v++) {
            if (G[u * n + v] == 1) {
                if (vertices[v].cor == BRANCO) {
                    vertices[v].cor = CINZA;
                    vertices[v].d = vertices[u].d + 1;
                    vertices[v].pi = u;
                    enfileirar(Q, v);
                    
                    char msg[50];
                    sprintf(msg, "Descobrindo vizinho %c", nomes[v]);
                    mostrar_estado_detalhado(n, vertices, msg, u);
                }
            }
        }
        vertices[u].cor = PRETO;
        mostrar_estado_detalhado(n, vertices, "Finalizando vertice", u);
    }
    free(Q->itens);
    free(Q);
}

int main() {
    int n = 6;
    // Grafo dos seus estudos na Newton Paiva
    int grafo[6][6] = {
        {0, 1, 1, 1, 0, 0}, // A -> B, C, D
        {1, 0, 0, 0, 1, 0}, // B -> A, E
        {1, 0, 0, 0, 0, 1}, // C -> A, F
        {1, 0, 0, 0, 0, 0}, // D -> A
        {0, 1, 0, 0, 0, 1}, // E -> B, F
        {0, 0, 1, 0, 1, 0}  // F -> C, E
    };

    Vertice *vertices = (Vertice*)malloc(n * sizeof(Vertice));
    int origem = 0; // Iniciando em A

    printf("=== EXECUCAO BFS PASSO A PASSO ===\n");
    
    BFS(n, &grafo[0][0], origem, vertices);

    free(vertices);
    return 0;
}