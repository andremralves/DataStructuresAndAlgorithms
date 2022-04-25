#include <stdio.h>
#include <stdlib.h>

// init Graph
// Insert Edge
// Remove Edge
// Copy Graph
// Destroy Graph

typedef struct graph *Graph;

typedef struct {
    int v;
    int w;
} Edge;

struct graph {
    int vertices;
    int edges;
    int **adj;
};

void printMatrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(j==col-1)
                printf("%d\n", matrix[i][j]);
            else
                printf("%d ", matrix[i][j]);
        }
    } 
}

int **initMatrix(int rows, int cols) {
    // allocate matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // initialize with 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0; 
        }
    }

    return matrix;
}

//Initialize the graph with v vertices
Graph initGraph(int v) {
    Graph g = malloc(sizeof(*g));
    g->vertices = v;
    g->edges = 0;
    g->adj = initMatrix(v, v);
    return g;
}

void insetEdge(Graph g, Edge e) {
    int v = e.v, w = e.w;
    if(g->adj[v][w] == 0)
        g->edges++;
    g->adj[v][w]=1;
    g->adj[w][v]=1;
}

void removeEdge(Graph g, Edge e) {
    int v = e.v, w = e.w;
    if(g->adj[v][w] == 1)
        g->edges--;
    g->adj[v][w]=0;
    g->adj[w][v]=0;
}

void showEdges(Graph g, Edge es[]) {
    int v, w, e = 0;
    if(g->adj[v][w] == 1)
        g->edges--;
    g->adj[v][w]=0;
    g->adj[w][v]=0;
}

int main ()
{
    Graph g = initGraph(10);
    Edge e;
    e.v = 5;
    e.w = 3;
    insetEdge(g, e);
    e.v = 2;
    e.w = 7;
    insetEdge(g, e);
    printf("Vertices:\n");
    printf("%d\n", g->vertices);
    printf("Edges:\n");
    printf("%d\n", g->edges);
    printf("Adj Matrix:\n");
    printMatrix(g->adj, 10, 10);
    return 0;
}
