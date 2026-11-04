//
// Created by Didukh Sviatoslav on 07.03.26.
//

#ifndef SORT_H
#define SORT_H


void MergeSort(int* A, int p, int r);
void QuickSort(int* A, int p, int r);
void printArray(int* A, int size);

void CountingSort(int* A, int* B, int n, int k);
void RadixSort(int* A, int n, int d);

#endif