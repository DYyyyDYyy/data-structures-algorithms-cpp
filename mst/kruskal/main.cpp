#include <iostream>
#include <vector>      // Додано бібліотеку для векторів
#include <algorithm>
#include <iomanip>
#include "DSU.h"

using namespace std;

struct Edge {
    int v1;
    int v2;
    int weight;

    Edge(int vertex1 = 0, int vertex2 = 0, int w = 0)
        : v1(vertex1), v2(vertex2), weight(w) {}
};


void sortEdges(vector<Edge>& edges) {
    int m = edges.size();
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void printPartition(DSU& dsu, int n) {
    cout << "{";
    for (int i = 1; i <= n; i++) {
        cout << "{v" << i << "}";
        if (i < n) cout << ",";
    }
    cout << "}";
}


void kruskalMST(vector<Edge>& edges, int n) {
    cout << "\n╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║           АЛГОРИТМ КРАСКАЛА - ПОБУДОВА МІНІМАЛЬНОГО КАРКАСУ              ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n\n";

    sortEdges(edges);

    DSU dsu(n);


    vector<Edge> mst;
    int totalWeight = 0;
    int m = edges.size();

    cout << "┌─────────────┬──────┬───────────────────────────────────────────┬──────────────┐\n";
    cout << "│    Ребро    │ Вага │        Розбиття множини вершин           │ Добір ребра  │\n";
    cout << "├─────────────┼──────┼───────────────────────────────────────────┼──────────────┤\n";

    cout << "│      —      │  —   │ ";
    for (int i = 1; i <= n; i++) {
        cout << "{v" << i << "}";
        if (i < n) cout << ",";
    }
    cout << " │      —       │\n";
    cout << "├─────────────┼──────┼───────────────────────────────────────────┼──────────────┤\n";

    for (int i = 0; i < m; i++) {
        int v1 = edges[i].v1;
        int v2 = edges[i].v2;
        int weight = edges[i].weight;

        if (dsu.set_find(v1) != dsu.set_find(v2)) {
            mst.push_back(edges[i]);
            totalWeight += weight;

            dsu.set_union(v1, v2);

            cout << "│  {v" << v1 << ",v" << v2 << "}  │  "
                 << setw(2) << weight << "  │ ";
            cout << "Множини об'єднано                         ";
            cout << "│     ТАК      │\n";
        } else {
            cout << "│  {v" << v1 << ",v" << v2 << "}  │  "
                 << setw(2) << weight << "  │ ";
            cout << "Вершини в одній множині                   ";
            cout << "│     НІ       │\n";
        }
    }

    cout << "└─────────────┴──────┴───────────────────────────────────────────┴──────────────┘\n\n";

    cout << "═══════════════════════════════════════════════════════════════════════════\n";
    cout << "                    РЕЗУЛЬТАТИ ПОБУДОВИ КАРКАСУ\n";
    cout << "═══════════════════════════════════════════════════════════════════════════\n\n";

    cout << "Ребра мінімального каркасу:\n";
    cout << "┌──────┬─────────────┬──────┐\n";
    cout << "│  №   │    Ребро    │ Вага │\n";
    cout << "├──────┼─────────────┼──────┤\n";

    for (size_t i = 0; i < mst.size(); i++) {
        cout << "│  " << setw(2) << (i + 1) << "  │  {v"
             << mst[i].v1 << ",v" << mst[i].v2 << "}    │  "
             << setw(2) << mst[i].weight << "  │\n";
    }

    cout << "└──────┴─────────────┴──────┘\n\n";
    cout << "Загальна вага мінімального каркасу: " << totalWeight << "\n";
    cout << "Кількість ребер у каркасі: " << mst.size() << "\n\n";
}

int main() {
    setlocale(LC_ALL, "");

    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "║                    ЛАБОРАТОРНА РОБОТА № 6                                 ║\n";
    cout << "║                  Побудова мінімального каркасу                            ║\n";
    cout << "║                      Алгоритм Краскала                                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════════════════════╝\n\n";

    int choice;
    cout << "Оберіть режим роботи:\n";
    cout << "1. Використати граф за замовчуванням (тестовий варіант)\n";
    cout << "2. Ввести власний граф вручну\n";
    cout << "Ваш вибір (1 або 2): ";
    cin >> choice;

    int n;
    vector<Edge> edges;

    if (choice == 2) {
        int m;
        cout << "\nВведіть кількість вершин: ";
        cin >> n;
        cout << "Введіть кількість ребер: ";
        cin >> m;

        cout << "\nВводьте ребра у форматі (Початкова_вершина Кінцева_вершина Вага):\n";
        for (int i = 0; i < m; i++) {
            int v1, v2, w;
            cout << "Ребро " << i + 1 << ": ";
            cin >> v1 >> v2 >> w;
            edges.push_back(Edge(v1, v2, w));
        }
    } else {
        n = 9;

        edges = {
            Edge(1, 2, 4),
            Edge(1, 8, 8),
            Edge(2, 3, 8),
            Edge(2, 8, 11),
            Edge(3, 4, 7),
            Edge(3, 6, 4),
            Edge(3, 9, 2),
            Edge(4, 5, 9),
            Edge(4, 6, 14),
            Edge(5, 6, 10),
            Edge(6, 7, 2),
            Edge(7, 8, 1),
            Edge(7, 9, 6),
            Edge(8, 9, 7)
        };
    }

    cout << "\nВхідні дані:\n";
    cout << "Кількість вершин: " << n << "\n";
    cout << "Кількість ребер: " << edges.size() << "\n\n";

    cout << "Ребра графа:\n";
    cout << "┌──────┬─────────────┬──────┐\n";
    cout << "│  №   │    Ребро    │ Вага │\n";
    cout << "├──────┼─────────────┼──────┤\n";
    for (size_t i = 0; i < edges.size(); i++) {
        cout << "│  " << setw(2) << (i + 1) << "  │  {v"
             << edges[i].v1 << ",v" << edges[i].v2 << "}    │  "
             << setw(2) << edges[i].weight << "  │\n";
    }
    cout << "└──────┴─────────────┴──────┘\n";


    kruskalMST(edges, n);



    return 0;
}