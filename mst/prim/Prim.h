#ifndef PRIM_H
#define PRIM_H

#include <limits>

const int INF = std::numeric_limits<int>::max();
const int MAX_V = 100;

struct Graph {
    int adjMatrix[MAX_V][MAX_V];
    int n;
    
    Graph(int vertices);
    void addEdge(int v1, int v2, int weight);
};

struct MSTEdge {
    int v1, v2, weight;
    
    MSTEdge(int vertex1 = 0, int vertex2 = 0, int w = 0);
};

void primMST(Graph& graph, int startVertex);

#endif