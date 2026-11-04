#include "Prim.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                    ЛАБОРАТОРНА РОБОТА № 6                                 ║\n";
    cout << "║                  Побудова мінімального каркасу                            ║\n";
    cout << "║                       Алгоритм Прима                                      ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n";

    int n = 9;
    Graph graph(n);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 5, 4);
    graph.addEdge(2, 8, 2);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    cout << "\nВхідні дані:\n";
    cout << "Кількість вершин: " << n << "\n";
    cout << "Граф представлено матрицею суміжності\n\n";

    cout << "Ребра графа:\n";
    cout << "┌──────┬─────────────┬──────┐\n";
    cout << "│  №   │    Ребро    │ Вага │\n";
    cout << "├──────┼─────────────┼──────┤\n";

    int edgeNum = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph.adjMatrix[i][j] > 0) {
                cout << "│  " << setw(2) << edgeNum++ << "  │  {v"
                     << (i + 1) << ",v" << (j + 1) << "}    │  "
                     << setw(2) << graph.adjMatrix[i][j] << "  │\n";
            }
        }
    }
    cout << "└──────┴─────────────┴──────┘\n";

    primMST(graph, 0);

    return 0;
}