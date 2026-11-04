
#ifndef LAB_2_SORT_H
#define LAB_2_SORT_H
#include <iostream>

const int size = 5;
typedef int given;
given datatype[size] = {-1, 8, -2, 0, 5};
given test_array[size];

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void test_wipe(given testarr[], int size) {
    for (int i = 0; i < size; i++) {
        testarr[i] = datatype[i];
    }
}


void selectionSort(int array[], int start, int end) {
    for (int step = start; step < end - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < end; i++) {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
        printArray(array, end);
    }
}


void insertionSort(given arr[size], int start, int end)
{
    int i, key, j;
    for (i = start; i < end; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printArray(arr, end);

    }
}



void bubbleSort(given v[size], int start, int end) {
    int n = size;

    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = start; j < end - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                flag = true;

                printArray(v, end);
            }


        }


        if (!flag)
            break;
    }
}

void menu() {
    int choice, start, stop, loop, dummy;
    loop = 1;
    while (loop == 1) {
        system("clear");
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Here's your starting array: " <<std::endl;


        printArray(datatype, size);
        std::cout << "Choose the sorting algorythm" << std::endl;
        std::cout << "Type:" << std::endl;
        std::cout << "1 - to use bubble sort" << std::endl;
        std::cout << "2 - to use insert sort" << std::endl;
        std::cout << "3 - to use selection sort" << std::endl;
        std::cout << "0 - to end the program" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;

        switch (choice) {
            case 0:
                loop = 0;

                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "Thanks for using our program!" << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                break;
            case 1:
                system("clear");

                test_wipe(test_array, size);
                std::cout << "Enter start and stop, separated by spaces: ";
                std::cin >> start >> stop;
                bubbleSort(test_array, start, stop);
                std::cout << std::endl;
                std::cout << std::endl;


                std::cout << std::endl;
                std::cout << "The array is sorted using Bubble sort in range from " << start << " to " << stop << std::endl;

                std::cout << "Here's your starting array: " <<std::endl;
                printArray(datatype, size);
                std::cout << "Here's your result" << std::endl;
                printArray(test_array, size);
                std::cout << std::endl;
                std::cout << std::endl;

                std::cout << "Enter 1 to continue" << std::endl;
                std::cout << std::endl;

                std::cin >> dummy;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;

                break;
            case 2:
                system("clear");

                test_wipe(test_array, size);
                std::cout << "Enter start and stop, separated by spaces: ";

                std::cin >> start >> stop;
                insertionSort(test_array, start, stop);
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "The array is sorted using Insertion sort in range from " << start << " to " << stop << std::endl;

                std::cout << "Here's your starting array: " <<std::endl;
                printArray(datatype, size);
                std::cout << "Here's your result" << std::endl;
                printArray(test_array, size);
                std::cout << std::endl;
                std::cout << "Enter 1 to continue" << std::endl;
                std::cin >> dummy;
                break;
            case 3:
                system("clear");

                test_wipe(test_array, size);
                std::cout << "Enter start and stop, separated by spaces: ";
                std::cin >> start >> stop;

                printArray(test_array, size);
                selectionSort(test_array, start, stop);
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "The array is sorted using Selection sort in range from " << start << " to " << stop << std::endl;

                std::cout << "Here's your starting array: " <<std::endl;
                printArray(datatype, size);
                std::cout << "Here's your result" << std::endl;
                printArray(test_array, size);
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;

                std::cout << "Enter 1 to continue" << std::endl;
                std::cin >> dummy;
                break;

        }
    }

}
#endif //LAB_2_SORT_H

// -1, -2, -4, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -1, -4, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 9, 7, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 9, 6, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 9, 5, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 9, 4, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 4, 9, 3, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 4, 3, 9, 2, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 4, 3, 2, 9, 1, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 4, 3, 2, 1, 9, 0, 12
// -2, -4, -1, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 8, 6, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 8, 5, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 8, 4, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 4, 8, 3, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 4, 3, 8, 2, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 4, 3, 2, 8, 1, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 4, 3, 2, 1, 8, 0, 9, 12
// -4, -2, -1, 7, 6, 5, 4, 3, 2, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 7, 5, 4, 3, 2, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 7, 4, 3, 2, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 7, 3, 2, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 7, 2, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 7, 1, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 1, 7, 0, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 6, 5, 4, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 5, 6, 4, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 5, 4, 6, 3, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 5, 4, 3, 6, 2, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 5, 4, 3, 2, 6, 1, 0, 7, 8, 9, 12
// -4, -2, -1, 5, 4, 3, 2, 6, 1, 0, 7, 8, 9, 12

