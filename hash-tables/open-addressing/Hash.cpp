//
// Created by Didukh Sviatoslav on 03.05.26.
//


#include "Hash.h"
#include <cmath>
#include <iostream>

int DivisionHash(int key, int m) {
    return key % m;
}

int MultiplicationHash(int key, int m) {
    const double A = 0.6180339887;
    double frac = key * A - std::floor(key * A);
    return static_cast<int>(std::floor(m * frac));
}


int LinearProbe(int key, int i, int m) {
    return (DivisionHash(key, m) + i) % m;
}

int QuadraticProbe(int key, int i, int m, int c1, int c2) {
    int h = DivisionHash(key, m);
    return (h + c1 * i + c2 * i * i) % m;
}

int DoubleProbe(int key, int i, int m) {
    int h1 = DivisionHash(key, m);
    int h2 = 1 + (key % (m - 1));
    return (h1 + i * h2) % m;
}


void LinearHashInsert(std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = LinearProbe(key, i, m);
        if (table[j] == EMPTY || table[j] == DELETED) {
            table[j] = key;
            std::cout << "Inserted at index " << j << std::endl;
            return;
        }
    }
    std::cout << "Error: hash table overflow" << std::endl;
}

bool LinearHashSearch(const std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = LinearProbe(key, i, m);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) return true;
    }
    return false;
}

bool LinearHashDelete(std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = LinearProbe(key, i, m);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) {
            table[j] = DELETED;
            return true;
        }
    }
    return false;
}

void LinearHashShow(const std::vector<int>& table) {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << i << ": ";
        if (table[i] == EMPTY) std::cout << "EMPTY";
        else if (table[i] == DELETED) std::cout << "DELETED";
        else std::cout << table[i];
        std::cout << std::endl;
    }
}


void QuadraticHashInsert(std::vector<int>& table, int key, int m, int c1, int c2) {
    for (int i = 0; i < m; ++i) {
        int j = QuadraticProbe(key, i, m, c1, c2);
        if (table[j] == EMPTY || table[j] == DELETED) {
            table[j] = key;
            std::cout << "Inserted at index " << j << std::endl;
            return;
        }
    }
    std::cout << "Error: hash table overflow" << std::endl;
}

bool QuadraticHashSearch(const std::vector<int>& table, int key, int m, int c1, int c2) {
    for (int i = 0; i < m; ++i) {
        int j = QuadraticProbe(key, i, m, c1, c2);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) return true;
    }
    return false;
}

bool QuadraticHashDelete(std::vector<int>& table, int key, int m, int c1, int c2) {
    for (int i = 0; i < m; ++i) {
        int j = QuadraticProbe(key, i, m, c1, c2);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) {
            table[j] = DELETED;
            return true;
        }
    }
    return false;
}

void QuadraticHashShow(const std::vector<int>& table) {
    LinearHashShow(table);
}


void DoubleHashInsert(std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = DoubleProbe(key, i, m);
        if (table[j] == EMPTY || table[j] == DELETED) {
            table[j] = key;
            std::cout << "Inserted at index " << j << std::endl;
            return;
        }
    }
    std::cout << "Error: hash table overflow" << std::endl;
}

bool DoubleHashSearch(const std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = DoubleProbe(key, i, m);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) return true;
    }
    return false;
}

bool DoubleHashDelete(std::vector<int>& table, int key, int m) {
    for (int i = 0; i < m; ++i) {
        int j = DoubleProbe(key, i, m);
        if (table[j] == EMPTY) return false;
        if (table[j] == key) {
            table[j] = DELETED;
            return true;
        }
    }
    return false;
}

void DoubleHashShow(const std::vector<int>& table) {
    LinearHashShow(table);
}