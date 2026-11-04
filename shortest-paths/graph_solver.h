#ifndef GRAPH_SOLVER_H
#define GRAPH_SOLVER_H

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>
#include "List.h" // Підключаємо наш стек

const int INF = 1e8;

// Тип даних для матриці
using Matrix = std::vector<std::vector<int>>;

// Функції, що приймають вже введений граф
void runDijkstraWithParam(const Matrix& adj, int n);
void runFloydWithParam(const Matrix& adj, int n);

// Допоміжні
void printMatrix(const Matrix& m, const std::string& title);

#endif // GRAPH_SOLVER_H