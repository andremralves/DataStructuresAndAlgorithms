#include <stdio.h>
#include <stdlib.h>

// init Graph
// Insert Edge
// Remove Edge
// Copy Graph
// Destroy Graph

typedef struct graph *Graph;
typedef struct node *link;

struct node {
    int v;
    link next;
};

typedef struct {
    int v;
    int w;
} Edge;

struct graph {
    int vertices;
    int edges;
    link *adj;
};

link newNode(int v, link next) {
    link node = malloc(sizeof(*node)); 
    node->v = v;
    node->next = next;
    return node;
}

//Initialize the graph with v vertices
Graph initGraph(int v) {
    Graph g = malloc(sizeof(*g));
    g->vertices = v;
    g->edges = 0;
    g->adj = malloc(sizeof(link) * v);
    for (int i = 0; i < v; i++) {
        g->adj[v] = NULL;
    }
    return g;
}

void insetEdge(Graph g, Edge e) {
    int v = e.v, w = e.w;
    g->adj[v] = newNode(w, g->adj[v]); 
    g->adj[w] = newNode(v, g->adj[w]); 
    g->edges++;
}

void removeEdge(Graph g, Edge e) {
    int v = e.v, w = e.w;
    //TODO
}

void printGraph(Graph g) {
    for (int i = 0; i < g->vertices; i++) {
        link tmp = g->adj[i];
        printf("Vertice:%d Adj:", i);
        while (tmp != NULL) {
            printf("->%d", tmp->v); 
            tmp = tmp->next;
        } 
        printf("\n");
    } 
}


int main ()
{
    Graph g = initGraph(10);
    Edge e;
    e.v = 5; e.w = 3;
    insetEdge(g, e);
    e.v = 2; e.w = 7;
    insetEdge(g, e);
    e.v = 2; e.w = 5;
    insetEdge(g, e);
    e.v = 1; e.w = 8;
    insetEdge(g, e);
    e.v = 1; e.w = 9;
    insetEdge(g, e);
    e.v = 1; e.w = 2;
    insetEdge(g, e);
    printf("Vertices:\n");
    printf("%d\n", g->vertices);
    printf("Edges:\n");
    printf("%d\n", g->edges);
    printf("Adj Matrix:\n");
    printGraph(g);
    return 0;
}
