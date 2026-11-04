#ifndef SORT_H
#define SORT_H

void Merge(int* A, int p, int q, int r);
void MergeSort(int* A, int p, int r);
void printArray(int* A, int size);

int Partition(int* A, int p, int r);
int RandomizedPartition(int* A, int p, int r);
void QuickSort(int* A, int p, int r);
int RandomizedSelect(int* A, int p, int r, int i);

#endif