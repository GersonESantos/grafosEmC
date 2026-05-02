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

// Função para mostrar o estado atual dos vértices
void mostrar_estado(int n, Vertice vertices[], const char* acao, int u) {
    char nomes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    printf("%-25s | ", acao);
    if (u != NULO) printf("u=%c | ", nomes[u]);
    else printf("    | ");

    for (int i = 0; i < n; i++) {
        char c;
        if (vertices[i].cor == BRANCO) c = 'B';
        else if (vertices[i].cor == CINZA) c = 'C';
        else c = 'P';
        printf("%c:%c  ", nomes[i], c);
    }
    printf("\n");
}

void BFS(int n, int *G, int s, Vertice vertices[]) {
    for (int u = 0; u < n; u++) {
        vertices[u].cor = BRANCO;
        vertices[u].d = INF;
        vertices[u].pi = NULO;
    }

    vertices[s].cor = CINZA;
    vertices[s].d = 0;
    vertices[s].pi = NULO;

    mostrar_estado(n, vertices, "Inicializacao", NULO);

    Fila* Q = criar_fila(n);
    enfileirar(Q, s);

    while (!fila_vazia(Q)) {
        int u = desenfileirar(Q);
        mostrar_estado(n, vertices, "Desenfileirando", u);

        for (int v = 0; v < n; v++) {
            if (G[u * n + v] == 1) {
                if (vertices[v].cor == BRANCO) {
                    vertices[v].cor = CINZA;
                    vertices[v].d = vertices[u].d + 1;
                    vertices[v].pi = u;
                    enfileirar(Q, v);
                    mostrar_estado(n, vertices, "Descobrindo vizinho", v);
                }
            }
        }
        vertices[u].cor = PRETO;
        mostrar_estado(n, vertices, "Finalizando vertice", u);
    }
    free(Q->itens);
    free(Q);
}

int main() {
    int n = 6;
    int grafo[6][6] = {
        {0, 1, 1, 1, 0, 0}, // A -> B, C, D
        {1, 0, 0, 0, 1, 0}, // B -> A, E
        {1, 0, 0, 0, 0, 1}, // C -> A, F
        {1, 0, 0, 0, 0, 0}, // D -> A
        {0, 1, 0, 0, 0, 1}, // E -> B, F
        {0, 0, 1, 0, 1, 0}  // F -> C, E
    };

    Vertice *vertices = (Vertice*)malloc(n * sizeof(Vertice));
    int origem = 0; 

    printf("%-25s | u   | Estados (Vertice:Cor)\n", "Passo");
    printf("--------------------------------------------------------------------------\n");
    
    BFS(n, &grafo[0][0], origem, vertices);

    printf("\nResultados finais:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertice %c | Distancia: %d | Predecessor: %d\n", 'A'+i, vertices[i].d, vertices[i].pi);
    }

    free(vertices);
    return 0;
}