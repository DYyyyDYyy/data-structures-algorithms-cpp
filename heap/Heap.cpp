#include "Heap.h"
#include <algorithm>
#include <climits>
#include <iomanip>

int Parent(int i) {
    return (i - 1) / 2;
}

int Left(int i) {
    return 2 * i + 1;
}

int Right(int i) {
    return 2 * i + 2;
}

void MaxHeapify(Element arr[], int heapSize, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;

    if (l < heapSize && arr[l].priority > arr[largest].priority) {
        largest = l;
    }

    if (r < heapSize && arr[r].priority > arr[largest].priority) {
        largest = r;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(arr, heapSize, largest);
    }
}

void BuildMaxHeap(Element arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MaxHeapify(arr, n, i);
    }
}

void MinHeapify(Element arr[], int heapSize, int i) {
    int l = Left(i);
    int r = Right(i);
    int smallest = i;

    if (l < heapSize && arr[l].priority < arr[smallest].priority) {
        smallest = l;
    }

    if (r < heapSize && arr[r].priority < arr[smallest].priority) {
        smallest = r;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        MinHeapify(arr, heapSize, smallest);
    }
}

void BuildMinHeap(Element arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        MinHeapify(arr, n, i);
    }
}

void HeapSort(Element arr[], int n, bool ascending) {
    if (ascending) {
        BuildMaxHeap(arr, n);
    } else {
        BuildMinHeap(arr, n);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        if (ascending) {
            MaxHeapify(arr, i, 0);
        } else {
            MinHeapify(arr, i, 0);
        }
    }
}

Element HeapMax(Element arr[], int heapSize) {
    if (heapSize < 1) {
        throw std::underflow_error("Помилка: черга порожня");
    }
    return arr[0];
}

Element HeapExtractMax(Element arr[], int& heapSize) {
    if (heapSize < 1) {
        throw std::underflow_error("Помилка: черга порожня");
    }

    Element max = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;
    MaxHeapify(arr, heapSize, 0);

    return max;
}

void HeapIncreaseKey(Element arr[], int i, int key) {
    if (key < arr[i].priority) {
        throw std::invalid_argument("Помилка: новий ключ менший за поточний");
    }

    arr[i].priority = key;

    while (i > 0 && arr[Parent(i)].priority < arr[i].priority) {
        std::swap(arr[i], arr[Parent(i)]);
        i = Parent(i);
    }
}

void MaxHeapInsert(Element arr[], int& heapSize, int key, std::string taskName, int maxSize) {
    if (heapSize >= maxSize) {
        throw std::overflow_error("Помилка: черга переповнена");
    }

    heapSize++;
    arr[heapSize - 1].priority = INT_MIN;
    arr[heapSize - 1].taskName = taskName;
    HeapIncreaseKey(arr, heapSize - 1, key);
}

Element HeapMin(Element arr[], int heapSize) {
    if (heapSize < 1) {
        throw std::underflow_error("Помилка: черга порожня");
    }
    return arr[0];
}

Element HeapExtractMin(Element arr[], int& heapSize) {
    if (heapSize < 1) {
        throw std::underflow_error("Помилка: черга порожня");
    }

    Element min = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;
    MinHeapify(arr, heapSize, 0);

    return min;
}

void HeapDecreaseKey(Element arr[], int i, int key) {
    if (key > arr[i].priority) {
        throw std::invalid_argument("Помилка: новий ключ більший за поточний");
    }

    arr[i].priority = key;

    while (i > 0 && arr[Parent(i)].priority > arr[i].priority) {
        std::swap(arr[i], arr[Parent(i)]);
        i = Parent(i);
    }
}

void MinHeapInsert(Element arr[], int& heapSize, int key, std::string taskName, int maxSize) {
    if (heapSize >= maxSize) {
        throw std::overflow_error("Помилка: черга переповнена");
    }

    heapSize++;
    arr[heapSize - 1].priority = INT_MAX;
    arr[heapSize - 1].taskName = taskName;
    HeapDecreaseKey(arr, heapSize - 1, key);
}

void PrintArray(Element arr[], int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << "{" << arr[i].taskName << ": " << arr[i].priority << "}";
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void PrintHeap(Element arr[], int n) {
    if (n == 0) {
        std::cout << "Піраміда порожня" << std::endl;
        return;
    }

    std::cout << "Піраміда (рівні):" << std::endl;
    int level = 0;
    int levelSize = 1;
    int printed = 0;

    while (printed < n) {
        std::cout << "Рівень " << level << ": ";
        for (int i = 0; i < levelSize && printed < n; i++, printed++) {
            std::cout << "[" << arr[printed].taskName << ":" << arr[printed].priority << "]";
            if (i < levelSize - 1 && printed < n - 1) std::cout << ", ";
        }
        std::cout << std::endl;
        level++;
        levelSize *= 2;
    }
}