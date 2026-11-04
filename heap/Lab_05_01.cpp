#include "Heap.h"
#include <iostream>
#include <limits>

using namespace std;

const int MAX_SIZE = 100;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputArray(Element arr[], int& n) {
    cout << "\nВведіть кількість елементів (не більше " << MAX_SIZE << "): ";
    while (!(cin >> n) || n <= 0 || n > MAX_SIZE) {
        cout << "Помилка! Введіть правильне число (1-" << MAX_SIZE << "): ";
        clearInput();
    }
    
    cout << "Введіть " << n << " елементів:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Елемент [" << i + 1 << "]: ";
        while (!(cin >> arr[i].priority)) {
            cout << "Помилка! Введіть ціле число: ";
            clearInput();
        }
    }
    
    cout << "\nМасив введено успішно!" << endl;
}

void displayMenu() {
    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║       ЛАБОРАТОРНА РОБОТА №5 - ЧАСТИНА 1               ║" << endl;
    cout << "║       Побудова піраміди. Пірамідальне сортування      ║" << endl;
    cout << "╠════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. Ввести новий масив                                 ║" << endl;
    cout << "║  2. Показати поточний масив                            ║" << endl;
    cout << "║  3. Побудувати незростаючу піраміду (Max-Heap)         ║" << endl;
    cout << "║  4. Побудувати неспадну піраміду (Min-Heap)            ║" << endl;
    cout << "║  5. Сортувати за зростанням (Heap Sort)                ║" << endl;
    cout << "║  6. Сортувати за спаданням (Heap Sort)                 ║" << endl;
    cout << "║  7. Показати піраміду (візуалізація)                   ║" << endl;
    cout << "║  0. Вихід                                              ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "Виберіть опцію: ";
}

void copyArray(Element source[], Element dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

int main() {
    Element arr[MAX_SIZE];
    Element tempArr[MAX_SIZE];
    int n = 0;
    bool arrayEntered = false;
    int choice;
    
    cout << "═══════════════════════════════════════════════════════" << endl;
    cout << "  ЛАБОРАТОРНА РОБОТА №5 - СТРУКТУРИ ДАНИХ: ПІРАМІДИ  " << endl;
    cout << "═══════════════════════════════════════════════════════" << endl;
    
    while (true) {
        displayMenu();
        
        while (!(cin >> choice)) {
            cout << "Помилка! Введіть число: ";
            clearInput();
        }
        
        switch (choice) {
            case 1:
                inputArray(arr, n);
                arrayEntered = true;
                break;
                
            case 2:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                cout << "\nПоточний масив:" << endl;
                PrintArray(arr, n);
                break;
                
            case 3:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                copyArray(arr, tempArr, n);
                BuildMaxHeap(tempArr, n);
                cout << "\nНезростаюча піраміда (Max-Heap) побудована:" << endl;
                PrintArray(tempArr, n);
                cout << "\nВихідний масив залишився незмінним:" << endl;
                PrintArray(arr, n);
                break;
                
            case 4:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                copyArray(arr, tempArr, n);
                BuildMinHeap(tempArr, n);
                cout << "\nНеспадна піраміда (Min-Heap) побудована:" << endl;
                PrintArray(tempArr, n);
                cout << "\nВихідний масив залишився незмінним:" << endl;
                PrintArray(arr, n);
                break;
                
            case 5:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                cout << "\nМасив до сортування:" << endl;
                PrintArray(arr, n);
                HeapSort(arr, n, true);
                cout << "\nМасив після сортування за зростанням:" << endl;
                PrintArray(arr, n);
                break;
                
            case 6:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                cout << "\nМасив до сортування:" << endl;
                PrintArray(arr, n);
                HeapSort(arr, n, false);
                cout << "\nМасив після сортування за спаданням:" << endl;
                PrintArray(arr, n);
                break;
                
            case 7:
                if (!arrayEntered) {
                    cout << "\nПомилка: спочатку введіть масив!" << endl;
                    break;
                }
                cout << "\nВізуалізація поточного масиву як піраміди:" << endl;
                PrintHeap(arr, n);
                break;
                
            case 0:
                cout << "\nДякуємо за використання програми!" << endl;
                cout << "═══════════════════════════════════════════════════════" << endl;
                return 0;
                
            default:
                cout << "\nНевірний вибір! Спробуйте ще раз." << endl;
        }
        
        cout << "\nНатисніть Enter для продовження...";
        clearInput();
        cin.get();
    }
    
    return 0;
}
