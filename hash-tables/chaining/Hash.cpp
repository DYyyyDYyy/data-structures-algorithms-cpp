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

void ChainedHashInsert(std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int)) {
    int idx = hashFunc(key, table.size());
    table[idx].push_front(key);
}

bool ChainedHashSearch(const std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int)) {
    int idx = hashFunc(key, table.size());
    int PosInList = 0;
    for (int val : table[idx]) {
        if (val == key)
        {
            std::cout << "List: " << idx << "\n";
            std::cout << "Pos: " << PosInList << std::endl;
            return true;

        }
        PosInList++;



    }
    return false;
}

bool ChainedHashDelete(std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int)) {
    int idx = hashFunc(key, table.size());
    std::list<int>& lst = table[idx];
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (*it == key) {
            lst.erase(it);
            return true;
        }
    }
    return false;
}

void ChainedHashShow(const std::vector<std::list<int>>& table) {
    for (size_t i = 0; i < table.size(); ++i) {
        std::cout << i << ": ";
        for (int val : table[i]) {
            std::cout << val << " -> ";
        }
        std::cout << "NULL" << std::endl;
    }
}