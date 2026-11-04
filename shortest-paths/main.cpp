#include <iostream>
#include "graph_solver.h"


void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Включення кирилиці
#ifdef _WIN32
    system("chcp 65001");
#endif


    create_empty_lists();

    while (true) {
        std::cout << "\n=========================================\n";
        std::cout << "       НОВИЙ ГРАФ (ВВЕДЕННЯ ДАНИХ)\n";
        std::cout << "=========================================\n";

        int n;
        std::cout << "Введіть кількість вершин (або 0 для виходу): ";
        if (!(std::cin >> n)) { clearInput(); continue; }
        if (n == 0) break;

        Matrix adj(n, std::vector<int>(n, INF));
        for(int i = 0; i < n; ++i) adj[i][i] = 0;

        std::cout << "Введіть ребра (звідки куди вага). \n";
        std::cout << "Для завершення введіть: -1 -1 -1\n";

        while (true) {
            int u, v, w;
            std::cin >> u >> v >> w;
            if (u == -1) break;
            if (u >= 0 && u < n && v >= 0 && v < n) {
                adj[u][v] = w;

                // adj[v][u] = w;
            } else {
                std::cout << "Помилка: невірний номер вершини.\n";
            }
        }

        // Внутрішній цикл роботи з введеним графом
        int subChoice;
        bool backToInput = false;

        while (!backToInput) {
            std::cout << "\n--- РОБОТА З ПОТОЧНИМ ГРАФОМ ---\n";
            std::cout << "1. Алгоритм Дейкстри\n";
            std::cout << "2. Алгоритм Флойда-Воршелла\n";
            std::cout << "3. Ввести новий граф\n";
            std::cout << "0. Вихід з програми\n";
            std::cout << "Ваш вибір: ";
            std::cin >> subChoice;

            switch (subChoice) {
                case 1:
                    runDijkstraWithParam(adj, n);
                    break;
                case 2:
                    runFloydWithParam(adj, n);
                    break;
                case 3:
                    backToInput = true;
                    break;
                case 0:
                    std::cout << "Завершення роботи.\n";
                    return 0;
                default:
                    std::cout << "Невірний вибір.\n";
            }
        }
    }

    return 0;
}