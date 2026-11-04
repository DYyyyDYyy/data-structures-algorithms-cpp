//
// Created by Didukh Sviatoslav on 03.05.26.
//

#ifndef HASH_H
#define HASH_H

#include <vector>
#include <list>

int DivisionHash(int key, int m);
int MultiplicationHash(int key, int m);

void ChainedHashInsert(std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int));
bool ChainedHashSearch(const std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int));
bool ChainedHashDelete(std::vector<std::list<int>>& table, int key, int (*hashFunc)(int, int));
void ChainedHashShow(const std::vector<std::list<int>>& table);

#endif