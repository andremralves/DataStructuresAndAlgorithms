#include <iostream>
#include <map>
#include <list>
#include <limits>
#include <set>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();

set<char> visited;
set<char> unvisited = {'A', 'B', 'C', 'D', 'E'};
map<char, map<char, int>> graph = {
    {'A', {{'B', 6}, {'D', 1}}},
    {'B', {{'A', 6}, {'C', 5}, {'D', 2}, {'E', 2}}},
    {'C', {{'B', 5}, {'E', 5}}},
    {'D', {{'A', 1}, {'B', 2}, {'E', 1}}},
    {'E', {{'B', 2}, {'C', 5}, {'D', 1}}},
};

char getSmallestDistance(map<char, int> distances) {
    map<char, int>::iterator it;
    int min = MAX_INT;
    map<char, int>::iterator smallest;
    for (it = distances.begin(); it != distances.end(); it++) {
        if(visited.find(it->first) == visited.end()) {
            if(it->second <= min) {
                min = it->second;
                smallest = it;
            }
        }
    }
    return smallest->first;
}

int main (int argc, char *argv[])
{
        
    // Shortest distance from start vertex
    map<char, int> shortest_distance = {{'A', 0}, {'B',MAX_INT}, {'C', MAX_INT}, {'D',MAX_INT}, {'E', MAX_INT}};
    map<char, char> previous_vertex = {{'A', NULL}, {'B', NULL}, {'C', NULL}, {'D', NULL}, {'E', NULL}};

    // Dijkstra algorithm
    while (unvisited.size())
    {
        char currentVertex = getSmallestDistance(shortest_distance);
        //cout<<"current v: "<<currentVertex<<endl;
        //cout<<"shortest d: "<<shortest_distance[currentVertex]<<endl;
        for(auto vertex : graph[currentVertex])
        {
            if(!visited.count(vertex.first)) {
                int distance = graph[currentVertex][vertex.first] + shortest_distance[currentVertex];
                //cout<<currentVertex<<"->"<<vertex.first<<": "<<distance<<endl;
                if(distance < shortest_distance[vertex.first]) {
                    shortest_distance[vertex.first] = distance;
                    previous_vertex[vertex.first] = currentVertex;
                }
            }
        }
        visited.insert(currentVertex);
        unvisited.erase(currentVertex);
    } 

    cout<<"\nShortest path from A to C: "<<shortest_distance['C']<<endl;
    // Print path
    cout<<"Path: ";
    char prev = 'C';
    while (previous_vertex[prev])
    {
        cout<<prev<<"<-";
        prev = previous_vertex[prev];
    }
    cout<<prev<<endl;
    return 0;
}
