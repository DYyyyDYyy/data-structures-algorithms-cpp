#include "graph_solver.h"

// Допоміжна функція для виводу одного рядка результату
void printPathResult(int startNode, int endNode, int dist, const std::vector<int>& parent) {
    std::cout << "Шлях " << startNode << " -> " << endNode << ": ";
    if (dist == INF) {
        std::cout << "не існує (INF)\n";
    } else {
        std::cout << "Довжина = " << dist << ", Маршрут: ";

        // Використання стеку з Lab 4 для відновлення шляху
        create_empty_lists();

        int curr = endNode;
        while (curr != -1) {
            push(curr);
            if (curr == startNode) break;
            curr = parent[curr];
        }

        bool first = true;
        while (stack_head != NULL) {
            if (!first) std::cout << " -> ";
            std::cout << stack_head->key;
            pop();
            first = false;
        }
        std::cout << "\n";
    }
}

void runDijkstraWithParam(const Matrix& adj, int n) {
    int startNode;
    std::cout << "\n--- Алгоритм Дейкстри (Частина 1) ---\n";
    std::cout << "Введіть початкову вершину (0 - " << n - 1 << "): ";
    std::cin >> startNode;

    if (startNode < 0 || startNode >= n) {
        std::cout << "Невірний номер вершини!\n";
        return;
    }

    // Крок 1. Ініціалізація
    std::vector<int> length(n, INF);
    std::vector<bool> label(n, false);
    std::vector<int> parent(n, -1);

    length[startNode] = 0;

    // Основний цикл алгоритму
    for (int i = 0; i < n; ++i) {

        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!label[j] && (v == -1 || length[j] < length[v])) {
                v = j;
            }
        }

        if (length[v] == INF) break;
        label[v] = true;

        // Оновлення міток
        for (int to = 0; to < n; ++to) {
            if (adj[v][to] != INF && adj[v][to] != 0) {
                if (length[v] + adj[v][to] < length[to]) {
                    length[to] = length[v] + adj[v][to];
                    parent[to] = v;
                }
            }
        }
    }


    int outChoice;
    std::cout << "\nВиберіть формат виводу:\n";
    std::cout << "1. Знайти шлях до конкретної вершини\n";
    std::cout << "2. Знайти шляхи до всіх вершин\n";
    std::cout << "Ваш вибір: ";
    std::cin >> outChoice;

    if (outChoice == 1) {
        int endNode;
        std::cout << "Введіть кінцеву вершину: ";
        std::cin >> endNode;
        if (endNode >= 0 && endNode < n) {
            printPathResult(startNode, endNode, length[endNode], parent);
        } else {
            std::cout << "Невірна вершина.\n";
        }
    } else {
        std::cout << "\nРезультати для всіх вершин:\n";
        for (int i = 0; i < n; ++i) {
            if (i == startNode) continue;
            printPathResult(startNode, i, length[i], parent);
        }
    }
}

//
// 0 2 8
// 2 0 9
// 0 1 7
// 1 0 9
// 1 3 5
// 3 7 5
// 5 1 9
// 1 6 6
// 2 1 6
// 2 4 6
// 2 5 7
// -1 -1 -1