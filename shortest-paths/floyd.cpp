#include "graph_solver.h"

// Функція для форматованого виводу матриць (як на скріншоті)
void printFormattedMatrix(const Matrix& m, const std::string& title, bool isPathMatrix) {
    int n = m.size();

    // Заголовок таблиці
    std::cout << "\n" << title << "\n";

    // Верхній рядок індексів
    std::cout << "      ";
    for(int i = 0; i < n; ++i) {
        std::cout << std::setw(5) << i;
    }
    std::cout << "\n\n";

    // Вивід рядків
    for (int i = 0; i < n; ++i) {
        // Індекс рядка зліва (синім кольором в консолі зазвичай не роблять, тому просто число)
        std::cout << std::setw(3) << i << "   ";

        for (int j = 0; j < n; ++j) {
            std::cout << "|"; // Вертикальний роздільник для краси
            if (m[i][j] == INF) {
                std::cout << std::setw(4) << "INF";
            } else {
                std::cout << std::setw(4) << m[i][j];
            }
        }
        std::cout << "|\n"; // Закриваючий роздільник
    }
    std::cout << "\n";
}

void runFloydWithParam(const Matrix& adj, int n) {
    std::cout << "\n--- Результат алгоритму Флойда-Воршелла ---\n";

    Matrix dist = adj;
    Matrix p(n, std::vector<int>(n, -1));

    // Крок 1. Ініціалізація матриць
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j && dist[i][j] != INF) {
                p[i][j] = i;
            } else {
                p[i][j] = -1;
            }
        }
    }

    // Крок 2. Основний цикл алгоритму (без виводу проміжних кроків)
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        p[i][j] = p[k][j]; // Оновлюємо попередника
                    }
                }
            }
        }
    }

    // Перевірка на цикли від'ємної довжини
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            std::cout << "УВАГА: Виявлено цикл від'ємної довжини!\n";
            return;
        }
    }

    // Крок 3. Вивід лише двох фінальних матриць
    printFormattedMatrix(dist, "Cost Table (Матриця вартостей)", false);
    printFormattedMatrix(p, "Path Table (Матриця шляхів)", true);


    // int start, end;
    // std::cout << "Введіть початкову і кінцеву вершину для детального шляху (або -1 -1 для виходу): ";
    // std::cin >> start >> end;
    //
    // if (start != -1 && end != -1) {
    //     if (start < 0 || start >= n || end < 0 || end >= n) {
    //         std::cout << "Невірні вершини.\n";
    //     } else if (dist[start][end] == INF) {
    //         std::cout << "Шляху не існує.\n";
    //     } else {
    //         std::cout << "Найкоротша відстань: " << dist[start][end] << "\n";
    //
    //         // Відновлення шляху
    //         create_empty_lists();
    //         int curr = end;
    //         push(curr);
    //
    //         while (curr != start) {
    //             int prev = p[start][curr];
    //             if (prev == -1) break;
    //             curr = prev;
    //             push(curr);
    //         }
    //
    //         std::cout << "Шлях: ";
    //         bool first = true;
    //         while (stack_head != NULL) {
    //             if (!first) std::cout << " -> ";
    //             std::cout << stack_head->key;
    //             pop();
    //             first = false;
    //         }
    //         std::cout << "\n";
    //     }
    // }
}


/*
1 5 3
3 5 8
3 1 9
2 5 2
5 6 3
6 5 4
7 6 3
4 2 9
-1 -1 -1
*/