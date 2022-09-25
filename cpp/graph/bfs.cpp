#include <iostream>
#include <vector>
#include <queue>

using namespace std;

size_t graph_size = 13;
void addEdge(std::vector<std::vector<size_t>> *adj, size_t u, size_t v) {
    (*adj)[u].push_back(v);
    (*adj)[v].push_back(u);
}

std::vector<bool> visited(graph_size, false);
std::vector<int> previous(graph_size, -1);
queue<size_t> v_queue;
void bfs(const std::vector<std::vector<size_t>> adj, size_t start) {
    // init queue
    v_queue.push(start);
    visited[start] = true;
    while (v_queue.size() != 0) {
        // select the front node from queue
        int current = v_queue.front();
        // pop the front node
        v_queue.pop();

        //cout<<current<<endl;
        for (size_t i = 0; i < adj[current].size(); i++) {
            if(visited[adj[current][i]] == false) {
                // add to queue
                v_queue.push(adj[current][i]);
                visited[adj[current][i]] = true;
                previous[adj[current][i]] = current;
            }
        } 
    }
}

int main (int argc, char *argv[])
{
    std::vector<std::vector<size_t>> g(graph_size, std::vector<size_t>()); 
    addEdge(&g, 0, 7);
    addEdge(&g, 0, 9);
    addEdge(&g, 0, 11);
    addEdge(&g, 1, 8);
    addEdge(&g, 1, 10);
    addEdge(&g, 2, 3);
    addEdge(&g, 2, 12);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 7);
    addEdge(&g, 5, 6);
    addEdge(&g, 6, 7);
    addEdge(&g, 7, 11);
    addEdge(&g, 8, 9);
    addEdge(&g, 8, 12);
    addEdge(&g, 9, 10);
    
    for (size_t i = 0; i < graph_size; i++) {
        if(visited[i] == false) {
            bfs(g, 0);
        }
    }
    int p = previous[12];
    cout<<"Shortest path from 0 to 12: "<<12;
    while (p != -1)
    {
        cout<<"<-"<<p;
        p = previous[p];
    }
    cout<<"\n";

    return 0;
}
