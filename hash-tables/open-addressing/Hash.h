//
// Created by Didukh Sviatoslav on 03.05.26.
//

#ifndef HASH_H
#define HASH_H

#include <vector>

const int EMPTY = -1;
const int DELETED = -2;

int DivisionHash(int key, int m);
int MultiplicationHash(int key, int m);


int LinearProbe(int key, int i, int m);
int QuadraticProbe(int key, int i, int m, int c1, int c2);
int DoubleProbe(int key, int i, int m);

void LinearHashInsert(std::vector<int>& table, int key, int m);
bool LinearHashSearch(const std::vector<int>& table, int key, int m);
bool LinearHashDelete(std::vector<int>& table, int key, int m);
void LinearHashShow(const std::vector<int>& table);


void QuadraticHashInsert(std::vector<int>& table, int key, int m, int c1, int c2);
bool QuadraticHashSearch(const std::vector<int>& table, int key, int m, int c1, int c2);
bool QuadraticHashDelete(std::vector<int>& table, int key, int m, int c1, int c2);
void QuadraticHashShow(const std::vector<int>& table);


void DoubleHashInsert(std::vector<int>& table, int key, int m);
bool DoubleHashSearch(const std::vector<int>& table, int key, int m);
bool DoubleHashDelete(std::vector<int>& table, int key, int m);
void DoubleHashShow(const std::vector<int>& table);

#endif