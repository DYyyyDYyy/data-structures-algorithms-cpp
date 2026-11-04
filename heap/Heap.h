#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>
#include <string>

struct Element {
    int priority;
    std::string taskName;
};

int Parent(int i);
int Left(int i);
int Right(int i);

void MaxHeapify(Element arr[], int heapSize, int i);
void BuildMaxHeap(Element arr[], int n);

void MinHeapify(Element arr[], int heapSize, int i);
void BuildMinHeap(Element arr[], int n);

void HeapSort(Element arr[], int n, bool ascending = true);

Element HeapMax(Element arr[], int heapSize);
Element HeapExtractMax(Element arr[], int& heapSize);
void HeapIncreaseKey(Element arr[], int i, int key);
void MaxHeapInsert(Element arr[], int& heapSize, int key, std::string taskName, int maxSize);

Element HeapMin(Element arr[], int heapSize);
Element HeapExtractMin(Element arr[], int& heapSize);
void HeapDecreaseKey(Element arr[], int i, int key);
void MinHeapInsert(Element arr[], int& heapSize, int key, std::string taskName, int maxSize);

void PrintArray(Element arr[], int n);
void PrintHeap(Element arr[], int n);

#endif