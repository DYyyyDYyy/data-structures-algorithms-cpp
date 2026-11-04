#include <iostream>
#include "Sort.h"

int main() {
    // --- Частина 1: Counting Sort ---
    std::cout << "--- Частина 1: Counting Sort ---" << std::endl;
    int n1;
    std::cout << "Введіть кількість елементів: ";
    std::cin >> n1;

    int* A = new int[n1];
    int* B = new int[n1];
    int max_val = 0;

    std::cout << "Введіть елементи масиву (цілі числа >= 0): " << std::endl;
    for (int i = 0; i < n1; i++) {
        std::cin >> A[i];
        if (A[i] > max_val) max_val = A[i];
    }

    CountingSort(A, B, n1, max_val);

    std::cout << "Результат Counting Sort: ";
    printArray(B, n1);
    std::cout << std::endl;

    // --- Частина 2: Radix Sort ---
    std::cout << "--- Частина 2: Radix Sort ---" << std::endl;
    int n2, d;
    std::cout << "Введіть кількість елементів: ";
    std::cin >> n2;
    std::cout << "Введіть кількість розрядів (d): ";
    std::cin >> d;

    int* D = new int[n2];
    std::cout << "Введіть " << d << "-розрядні числа: " << std::endl;
    for (int i = 0; i < n2; i++) {
        std::cin >> D[i];
    }

    RadixSort(D, n2, d);

    std::cout << "Результат Radix Sort: ";
    printArray(D, n2);

    delete[] A;
    delete[] B;
    delete[] D;

    return 0;
}