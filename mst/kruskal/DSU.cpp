#include "DSU.h"
#include <iostream>

DSU::DSU(int n) {
    size = n;
    previous = new int[n + 1];
    rank = new int[n + 1];
    initialize(n);
}

DSU::~DSU() {
    delete[] previous;
    delete[] rank;
}

void DSU::initialize(int n) {
    for (int i = 1; i <= n; i++) {
        previous[i] = i;
        rank[i] = 0;
    }
}

void DSU::set_make(int v) {
    previous[v] = v;
    rank[v] = 0;
}

int DSU::set_find(int v) {

    if (previous[v] == v) {
        return v;
    }

    previous[v] = set_find(previous[v]);
    return previous[v];
}

bool DSU::set_union(int v1, int v2) {

    int root1 = set_find(v1);
    int root2 = set_find(v2);
    

    if (root1 == root2) {
        return false;
    }
    

    if (rank[root1] < rank[root2]) {
        previous[root1] = root2;
    } else if (rank[root1] > rank[root2]) {
        previous[root2] = root1;
    } else {
        previous[root2] = root1;
        rank[root1]++;
    }
    
    return true;
}
