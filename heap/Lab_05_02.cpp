#include "Heap.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputArray(Element arr[], int& heapSize) {
    cout << "\nВведіть кількість елементів (не більше " << MAX_SIZE << "): ";
    while (!(cin >> heapSize) || heapSize <= 0 || heapSize > MAX_SIZE) {
        cout << "Помилка! Введіть правильне число (1-" << MAX_SIZE << "): ";
        clearInput();
    }

    for (int i = 0; i < heapSize; i++) {
        cout << "Елемент [" << i + 1 << "] - Назва завдання: ";
        cin >> arr[i].taskName;
        cout << "Елемент [" << i + 1 << "] - Пріоритет: ";
        while (!(cin >> arr[i].priority)) {
            cout << "Помилка! Введіть ціле число: ";
            clearInput();
        }
    }

    cout << "\nМасив введено успішно!\n";
}

void displayMenu() {
    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║       ЛАБОРАТОРНА РОБОТА №5 - ЧАСТИНА 2               ║\n";
    cout << "║              Черга з пріоритетами                      ║\n";
    cout << "╠════════════════════════════════════════════════════════╣\n";
    cout << "║  ЗАГАЛЬНІ ОПЕРАЦІЇ:                                    ║\n";
    cout << "║  1. Ввести новий масив                                 ║\n";
    cout << "║  2. Показати поточну чергу                             ║\n";
    cout << "║  3. Побудувати Max-Heap (черга з макс. пріоритетом)    ║\n";
    cout << "║  4. Побудувати Min-Heap (черга з мін. пріоритетом)     ║\n";
    cout << "║                                                        ║\n";
    cout << "║  ОПЕРАЦІЇ MAX-HEAP:                                    ║\n";
    cout << "║  5. Показати максимум                                  ║\n";
    cout << "║  6. Видалити максимум                                  ║\n";
    cout << "║  7. Збільшити ключ елемента                            ║\n";
    cout << "║  8. Додати елемент у Max-Heap                          ║\n";
    cout << "║                                                        ║\n";
    cout << "║  ОПЕРАЦІЇ MIN-HEAP:                                    ║\n";
    cout << "║  9. Показати мінімум                                   ║\n";
    cout << "║ 10. Видалити мінімум                                   ║\n";
    cout << "║ 11. Зменшити ключ елемента                             ║\n";
    cout << "║ 12. Додати елемент у Min-Heap                          ║\n";
    cout << "║                                                        ║\n";
    cout << "║  0. Вихід                                              ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
    cout << "Виберіть опцію: ";
}

int main() {
    Element arr[MAX_SIZE];
    int heapSize = 0;
    bool arrayEntered = false;
    bool isMaxHeap = false;
    bool isMinHeap = false;
    int choice, index, newKey, priorityValue;
    string taskName;
    Element extValue;

    cout << "═══════════════════════════════════════════════════════\n";
    cout << "  ЛАБОРАТОРНА РОБОТА №5 - ЧЕРГА З ПРІОРИТЕТАМИ        \n";
    cout << "═══════════════════════════════════════════════════════\n";

    while (true) {
        displayMenu();

        while (!(cin >> choice)) {
            cout << "Помилка! Введіть число: ";
            clearInput();
        }

        try {
            switch (choice) {
                case 1:
                    inputArray(arr, heapSize);
                    arrayEntered = true;
                    isMaxHeap = false;
                    isMinHeap = false;
                    break;

                case 2:
                    if (!arrayEntered) {
                        cout << "\nПомилка: спочатку введіть масив!\n";
                        break;
                    }
                    cout << "\nПоточна черга (розмір: " << heapSize << "):\n";
                    PrintArray(arr, heapSize);
                    if (isMaxHeap) {
                        cout << "Тип: Max-Heap (незростаюча піраміда)\n";
                    } else if (isMinHeap) {
                        cout << "Тип: Min-Heap (неспадна піраміда)\n";
                    } else {
                        cout << "Тип: звичайний масив (не організовано як піраміду)\n";
                    }
                    PrintHeap(arr, heapSize);
                    break;

                case 3:
                    if (!arrayEntered) {
                        cout << "\nПомилка: спочатку введіть масив!\n";
                        break;
                    }
                    BuildMaxHeap(arr, heapSize);
                    isMaxHeap = true;
                    isMinHeap = false;
                    cout << "\nMax-Heap побудовано успішно:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 4:
                    if (!arrayEntered) {
                        cout << "\nПомилка: спочатку введіть масив!\n";
                        break;
                    }
                    BuildMinHeap(arr, heapSize);
                    isMaxHeap = false;
                    isMinHeap = true;
                    cout << "\nMin-Heap побудовано успішно:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 5:
                    if (!isMaxHeap) {
                        cout << "\nПомилка: спочатку побудуйте Max-Heap!\n";
                        break;
                    }
                    extValue = HeapMax(arr, heapSize);
                    cout << "\nМаксимальний елемент: {" << extValue.taskName << ": " << extValue.priority << "}\n";
                    break;

                case 6:
                    if (!isMaxHeap) {
                        cout << "\nПомилка: спочатку побудуйте Max-Heap!\n";
                        break;
                    }
                    cout << "\nЧерга до видалення максимуму:\n";
                    PrintArray(arr, heapSize);
                    extValue = HeapExtractMax(arr, heapSize);
                    cout << "Видалено максимальний елемент: {" << extValue.taskName << ": " << extValue.priority << "}\n";
                    cout << "Черга після видалення:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 7:
                    if (!isMaxHeap) {
                        cout << "\nПомилка: спочатку побудуйте Max-Heap!\n";
                        break;
                    }
                    cout << "\nПоточна черга:\n";
                    PrintArray(arr, heapSize);
                    cout << "Введіть індекс елемента (0-" << heapSize - 1 << "): ";
                    while (!(cin >> index) || index < 0 || index >= heapSize) {
                        cout << "Помилка! Введіть правильний індекс: ";
                        clearInput();
                    }
                    cout << "Поточне значення: {" << arr[index].taskName << ": " << arr[index].priority << "}\n";
                    cout << "Введіть нове значення пріоритету (більше за поточне): ";
                    while (!(cin >> newKey)) {
                        cout << "Помилка! Введіть ціле число: ";
                        clearInput();
                    }
                    HeapIncreaseKey(arr, index, newKey);
                    cout << "Ключ збільшено успішно!\n";
                    cout << "Черга після збільшення ключа:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 8:
                    if (!isMaxHeap) {
                        cout << "\nПомилка: спочатку побудуйте Max-Heap!\n";
                        break;
                    }
                    cout << "\nПоточна черга:\n";
                    PrintArray(arr, heapSize);
                    cout << "Введіть назву нового завдання: ";
                    cin >> taskName;
                    cout << "Введіть пріоритет нового завдання: ";
                    while (!(cin >> priorityValue)) {
                        cout << "Помилка! Введіть ціле число: ";
                        clearInput();
                    }
                    MaxHeapInsert(arr, heapSize, priorityValue, taskName, MAX_SIZE);
                    cout << "Елемент додано успішно!\n";
                    cout << "Черга після додавання:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 9:
                    if (!isMinHeap) {
                        cout << "\nПомилка: спочатку побудуйте Min-Heap!\n";
                        break;
                    }
                    extValue = HeapMin(arr, heapSize);
                    cout << "\nМінімальний елемент: {" << extValue.taskName << ": " << extValue.priority << "}\n";
                    break;

                case 10:
                    if (!isMinHeap) {
                        cout << "\nПомилка: спочатку побудуйте Min-Heap!\n";
                        break;
                    }
                    cout << "\nЧерга до видалення мінімуму:\n";
                    PrintArray(arr, heapSize);
                    extValue = HeapExtractMin(arr, heapSize);
                    cout << "Видалено мінімальний елемент: {" << extValue.taskName << ": " << extValue.priority << "}\n";
                    cout << "Черга після видалення:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 11:
                    if (!isMinHeap) {
                        cout << "\nПомилка: спочатку побудуйте Min-Heap!\n";
                        break;
                    }
                    cout << "\nПоточна черга:\n";
                    PrintArray(arr, heapSize);
                    cout << "Введіть індекс елемента (0-" << heapSize - 1 << "): ";
                    while (!(cin >> index) || index < 0 || index >= heapSize) {
                        cout << "Помилка! Введіть правильний індекс: ";
                        clearInput();
                    }
                    cout << "Поточне значення: {" << arr[index].taskName << ": " << arr[index].priority << "}\n";
                    cout << "Введіть нове значення пріоритету (менше за поточне): ";
                    while (!(cin >> newKey)) {
                        cout << "Помилка! Введіть ціле число: ";
                        clearInput();
                    }
                    HeapDecreaseKey(arr, index, newKey);
                    cout << "Ключ зменшено успішно!\n";
                    cout << "Черга після зменшення ключа:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 12:
                    if (!isMinHeap) {
                        cout << "\nПомилка: спочатку побудуйте Min-Heap!\n";
                        break;
                    }
                    cout << "\nПоточна черга:\n";
                    PrintArray(arr, heapSize);
                    cout << "Введіть назву нового завдання: ";
                    cin >> taskName;
                    cout << "Введіть пріоритет нового завдання: ";
                    while (!(cin >> priorityValue)) {
                        cout << "Помилка! Введіть ціле число: ";
                        clearInput();
                    }
                    MinHeapInsert(arr, heapSize, priorityValue, taskName, MAX_SIZE);
                    cout << "Елемент додано успішно!\n";
                    cout << "Черга після додавання:\n";
                    PrintArray(arr, heapSize);
                    PrintHeap(arr, heapSize);
                    break;

                case 0:
                    cout << "\nДякуємо за використання програми!\n";
                    cout << "═══════════════════════════════════════════════════════\n";
                    return 0;

                default:
                    cout << "\nНевірний вибір! Спробуйте ще раз.\n";
            }
        } catch (const exception& e) {
            cout << "\n⚠️  " << e.what() << "\n";
        }

        cout << "\nНатисніть Enter для продовження...";
        clearInput();
        cin.get();
    }

    return 0;
}