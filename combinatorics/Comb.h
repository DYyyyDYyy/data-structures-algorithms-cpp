

#ifndef LAB_3_COMB_H
#define LAB_3_COMB_H
#include <cmath>
#include "Sort.h"

long factorial(int a) {
    long num = 1;
    for (int i = 1; i <= a; i++) {
        num *= i;
    }

    return num;
}

int A(int n, int k) {
    if (k < 0 || n < 0 || k > n) {
        return 0;
    }
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
    }
    return res;
}

int _A(int n, int k) {
    if (n < 0 || k < 0) {
        return 0;
    }
    return static_cast<int>(pow(n, k));
}

int C(int n, int k) {
    if (k < 0 || n < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int _C(int n, int k) {
    if (n <= 0 && k > 0) return 0;
    if (k < 0 || n < 0) return 0;
    if (k == 0) return 1;
    return C(n + k - 1, k);


}

void GenPerm(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] < A[i + 1]) {

            bool is_biggest = true;
            for (int j = i + 1; j < n; j++) {
                if (A[i+1] < A[j]) {
                    is_biggest = false;
                }
            }

            if (is_biggest) {
                selectionSort(A, i+1, n);
                for (int j = i + 1; j < n; j++) {
                    if (A[i] < A[j]) {
                        swap(&A[i], &A[j]);
                    }
                }
            }

        }
    }
}
// void FullGenPerm() {
//
// }

#endif //LAB_3_COMB_H