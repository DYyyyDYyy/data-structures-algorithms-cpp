#include "Prim.h"
#include <iostream>
#include <iomanip>

using namespace std;

Graph::Graph(int vertices) : n(vertices) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void Graph::addEdge(int v1, int v2, int weight) {
    adjMatrix[v1][v2] = weight;
    adjMatrix[v2][v1] = weight;
}

MSTEdge::MSTEdge(int vertex1, int vertex2, int w) : v1(vertex1), v2(vertex2), weight(w) {}

void primMST(Graph& graph, int startVertex) {
    int n = graph.n;
    
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║             АЛГОРИТМ ПРИМА - ПОБУДОВА МІНІМАЛЬНОГО КАРКАСУ               ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n\n";
    
    cout << "Початкова вершина: v" << (startVertex + 1) << "\n\n";
    
    bool visited[MAX_V];   
    int min_e[MAX_V];       
    int sel_e[MAX_V];    
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        min_e[i] = INF;
        sel_e[i] = -1;
    }
    
    visited[startVertex] = true;
    
    for (int i = 0; i < n; i++) {
        if (i != startVertex && graph.adjMatrix[startVertex][i] > 0) {
            min_e[i] = graph.adjMatrix[startVertex][i];
            sel_e[i] = startVertex;
        }
    }
    
    MSTEdge mst[MAX_V];
    int mstCount = 0;
    int totalWeight = 0;
    
    cout << "┌───────────────────┬──────────────────────┬──────┐\n";
    cout << "│   Множина U       │  Добір ребра в каркас│ Вага │\n";
    cout << "├───────────────────┼──────────────────────┼──────┤\n";
    
    cout << "│ {v" << (startVertex + 1) << "}              │          —           │  —   │\n";
    cout << "├───────────────────┼──────────────────────┼──────┤\n";
    
    for (int count = 0; count < n - 1; count++) {
        int minWeight = INF;
        int minVertex = -1;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && min_e[i] < minWeight) {
                minWeight = min_e[i];
                minVertex = i;
            }
        }
        
        if (minVertex == -1) break;
        
        visited[minVertex] = true;
        
        if (sel_e[minVertex] != -1) {
            mst[mstCount++] = MSTEdge(sel_e[minVertex], minVertex, minWeight);
            totalWeight += minWeight;
        }
        
        cout << "│ {";
        bool first = true;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                if (!first) cout << ",";
                cout << "v" << (i + 1);
                first = false;
            }
        }
        
        int printed = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) printed++;
        }
        for (int i = printed * 3; i < 15; i++) {
            cout << " ";
        }
        cout << "} │  {v" << (sel_e[minVertex] + 1) << ",v" << (minVertex + 1) << "}";
        cout << "             │  " << setw(2) << minWeight << "  │\n";
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph.adjMatrix[minVertex][i] > 0) {
                if (graph.adjMatrix[minVertex][i] < min_e[i]) {
                    min_e[i] = graph.adjMatrix[minVertex][i];
                    sel_e[i] = minVertex;
                }
            }
        }
    }
    
    cout << "└───────────────────┴──────────────────────┴──────┘\n\n";
    
    cout << "═══════════════════════════════════════════════════════════════════════════\n";
    cout << "                    РЕЗУЛЬТАТИ ПОБУДОВИ КАРКАСУ\n";
    cout << "═══════════════════════════════════════════════════════════════════════════\n\n";
    
    cout << "Ребра мінімального каркасу:\n";
    cout << "┌──────┬─────────────┬──────┐\n";
    cout << "│  №   │    Ребро    │ Вага │\n";
    cout << "├──────┼─────────────┼──────┤\n";
    
    for (int i = 0; i < mstCount; i++) {
        cout << "│  " << setw(2) << (i + 1) << "  │  {v" 
             << (mst[i].v1 + 1) << ",v" << (mst[i].v2 + 1) << "}    │  "
             << setw(2) << mst[i].weight << "  │\n";
    }
    
    cout << "└──────┴─────────────┴──────┘\n\n";
    cout << "Загальна вага мінімального каркасу: " << totalWeight << "\n";
    cout << "Кількість ребер у каркасі: " << mstCount << "\n\n";
}