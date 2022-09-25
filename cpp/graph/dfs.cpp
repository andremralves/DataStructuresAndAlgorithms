#include <iostream>
#include <vector>

using namespace std;

size_t graph_size = 13;
void addEdge(std::vector<std::vector<size_t>> *adj, size_t u, size_t v) {
    (*adj)[u].push_back(v);
    (*adj)[v].push_back(u);
}

std::vector<bool> visited(graph_size, false);
int count = 0;
void dfs(const std::vector<std::vector<size_t>> adj, size_t start) {
    if(visited[start] == true) return;
    visited[start] = true;
    for (size_t i = 0; i < adj[start].size(); i++) {
        count++;
        dfs(adj, adj[start][i]);
    }
}

int main (int argc, char *argv[])
{
    std::vector<std::vector<size_t>> g(graph_size, std::vector<size_t>()); 
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 8);
    addEdge(&g, 2, 3);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);
    addEdge(&g, 3, 7);
    addEdge(&g, 5, 6);
    addEdge(&g, 6, 7);
    addEdge(&g, 7, 8);
    addEdge(&g, 7, 10);
    addEdge(&g, 7, 11);
    addEdge(&g, 8, 9);
    addEdge(&g, 10, 11);
    for (size_t i = 0; i < graph_size; i++) {
        if(visited[i] == false) {
            cout<<i<<endl;
            dfs(g, i);
        }
    }
    cout<<count<<endl;
        

    return 0;
}
