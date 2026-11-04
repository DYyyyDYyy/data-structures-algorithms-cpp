//
// Created by Didukh Sviatoslav on 22.02.26.
//

#include "Sort.h"
#include <iostream>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cmath>


void CountingSort(int* A, int* B, int n, int k) {
    // Масив С для підрахунку, розміром k+1 (від 0 до k)
    int* C = new int[k + 1];

    for (int i = 0; i <= k; i++) {
        C[i] = 0; // Ініціалізація нулями
    }

    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1; // Підрахунок кількості кожного елемента
    }

    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1]; // Обчислення позицій (кількість елементів <= i)
    }



    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j]; // -1 бо в C++ індексація з 0
        C[A[j]] = C[A[j]] - 1;
    }

    delete[] C;
}

// Спеціальна версія Counting Sort для Radix Sort, що сортує за розрядом
void CountingSortForRadix(int* A, int n, int exp) {
    int* B = new int[n];
    int C[10] = {0}; // Для десяткової системи k=9

    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % 10; // Отримання потрібного розряду
        C[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
    delete[] B;
}


void RadixSort(int* A, int n, int d) {
    int exp = 1;
    // Цикл від молодшого розряду до старшого
    for (int i = 1; i <= d; i++) {
        CountingSortForRadix(A, n, exp);
        exp *= 10;
    }
}
void Merge(int* A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = new int[n1 + 1];
    int* R = new int[n2 + 1];

    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    std::cout << "Злиття [" << p << "..." << r << "]: ";
    for (int x = p; x <= r; x++) {
        std::cout << A[x] << " ";
    }
    std::cout << std::endl;

    delete[] L;
    delete[] R;
}

void MergeSort(int* A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

void printArray(int* A, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int Partition(int* A, int p, int r) {
    int x = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

int RandomizedPartition(int* A, int p, int r) {
    int i = p + std::rand() % (r - p + 1);
    std::swap(A[r], A[i]);
    return Partition(A, p, r);
}

void QuickSort(int* A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int RandomizedSelect(int* A, int p, int r, int i) {
    if (p == r) {
        return A[p];
    }

    int q = RandomizedPartition(A, p, r);
    int k = q - p + 1;

    if (i == k) {
        return A[q];
    } else if (i < k) {
        return RandomizedSelect(A, p, q - 1, i);
    } else {
        return RandomizedSelect(A, q + 1, r, i - k);
    }
}