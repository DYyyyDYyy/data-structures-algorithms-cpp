/*
 * File: main.cpp
 * Description: Головний файл (драйвер) для Лабораторної роботи №4
 * Реалізує меню для тестування стеку, черги та двозв'язного списку.
 */

#include "List.h"
#include <iostream>
#include <limits>


void show_all_lists() {
    std::cout << "--- CURRENT STATE ---" << std::endl;
    show_stack();
    show_queue();
    show_dll();
    std::cout << "---------------------" << std::endl;
}

int main() {

    create_empty_lists();

    int choice;
    datatype data, key;

    while (true) {

        std::cout << "\n========= C++ LAB 4: LINEAR LISTS =========" << std::endl;
        std::cout << "--- STACK (Part 1) ---" << std::endl;
        std::cout << "1. Push to Stack" << std::endl;
        std::cout << "2. Pop from Stack" << std::endl;
        std::cout << "--- QUEUE (Part 2) ---" << std::endl;
        std::cout << "3. Enqueue to Queue" << std::endl;
        std::cout << "4. Dequeue from Queue" << std::endl;
        std::cout << "--- DOUBLY LINKED LIST (Part 3) ---" << std::endl;
        std::cout << "5. Add to DLL Begin" << std::endl;
        std::cout << "6. Add to DLL End" << std::endl;
        std::cout << "7. Add to DLL Middle (after key)" << std::endl;
        std::cout << "8. Delete from DLL Begin" << std::endl;
        std::cout << "9. Delete from DLL End" << std::endl;
        std::cout << "10. Delete from DLL Middle (by key)" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";


        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {

            case 1:
                std::cout << "Enter data for stack: ";
                std::cin >> data;
                push(data);
                break;
            case 2:
                pop();
                break;


            case 3:
                std::cout << "Enter data for queue: ";
                std::cin >> data;
                enqueue(data);
                break;
            case 4:
                dequeue();
                break;


            case 5:
                std::cout << "Enter data for DLL: ";
                std::cin >> data;
                add_begin(data);
                break;
            case 6:
                std::cout << "Enter data for DLL: ";
                std::cin >> data;
                add_end(data);
                break;
            case 7:
                std::cout << "Enter KEY to add after: ";
                std::cin >> key;
                std::cout << "Enter NEW data: ";
                std::cin >> data;
                add_mid(key, data);
                break;
            case 8:
                del_begin();
                break;
            case 9:
                del_end();
                break;
            case 10:
                std::cout << "Enter KEY to delete: ";
                std::cin >> key;
                del_mid(key);
                break;

            case 0:
                std::cout << "Exiting program..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }


        if (choice != 0) {
            show_all_lists();
        }
    }

    return 0;
}