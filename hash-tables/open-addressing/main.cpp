
#include <iostream>
#include <vector>
#include "Hash.h"

int main() {
    int m;
    std::cout << "Enter hash table size m: ";
    std::cin >> m;

    std::vector<int> table(m, EMPTY);
    int mainChoice;

    while (true) {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Linear probing\n2. Quadratic probing\n3. Double hashing\n4. Exit\nChoice: ";
        std::cin >> mainChoice;

        if (mainChoice == 4) break;


        std::fill(table.begin(), table.end(), EMPTY);

        int c1 = 0, c2 = 0;
        if (mainChoice == 2) {
            std::cout << "Enter constants c1 and c2 for quadratic probing: ";
            std::cin >> c1 >> c2;
        }

        int op;
        while (true) {
            std::cout << "\n--- Operation Menu ---\n";
            std::cout << "1. Insert\n2. Search\n3. Delete\n4. Show table\n5. Back to main menu\nChoice: ";
            std::cin >> op;

            if (op == 5) break;

            int key;
            switch (op) {
            case 1:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                if (mainChoice == 1) LinearHashInsert(table, key, m);
                else if (mainChoice == 2) QuadraticHashInsert(table, key, m, c1, c2);
                else DoubleHashInsert(table, key, m);
                break;
            case 2:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                {
                    bool found = false;
                    if (mainChoice == 1) found = LinearHashSearch(table, key, m);
                    else if (mainChoice == 2) found = QuadraticHashSearch(table, key, m, c1, c2);
                    else found = DoubleHashSearch(table, key, m);
                    std::cout << (found ? "Key found." : "Key not found.") << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                {
                    bool deleted = false;
                    if (mainChoice == 1) deleted = LinearHashDelete(table, key, m);
                    else if (mainChoice == 2) deleted = QuadraticHashDelete(table, key, m, c1, c2);
                    else deleted = DoubleHashDelete(table, key, m);
                    std::cout << (deleted ? "Key deleted." : "Key not found or could not delete.") << std::endl;
                }
                break;
            case 4:
                if (mainChoice == 1) LinearHashShow(table);
                else if (mainChoice == 2) QuadraticHashShow(table);
                else DoubleHashShow(table);
                break;
            default:
                std::cout << "Invalid option." << std::endl;
            }
        }
    }

    return 0;
}