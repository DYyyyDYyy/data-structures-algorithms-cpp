
#include <iostream>
#include <vector>
#include <list>
#include "Hash.h"

int main() {
    int m;
    std::cout << "Enter hash table size m: ";
    std::cin >> m;
    std::vector<std::list<int>> table(m);

    int choice;
    std::cout << "Select hash function:\n1. Division\n2. Multiplication\n";
    std::cin >> choice;
    int (*hashFunc)(int, int) = nullptr;
    if (choice == 1) hashFunc = DivisionHash;
    else if (choice == 2) hashFunc = MultiplicationHash;
    else {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    while (true) {
        std::cout << "\nMenu:\n1. Insert\n2. Search\n3. Delete\n4. Show\n5. Exit\nChoose: ";
        std::cin >> choice;
        if (choice == 5) break;
        int key;
        switch (choice) {
            case 1:
                std::cout << "Enter key: ";
                std::cin >> key;
                ChainedHashInsert(table, key, hashFunc);
                break;
            case 2:
                std::cout << "Enter key: ";
                std::cin >> key;
                if (ChainedHashSearch(table, key, hashFunc))
                    std::cout << "Key found.\n";
                else
                    std::cout << "Key not found.\n";
                break;
            case 3:
                std::cout << "Enter key: ";
                std::cin >> key;
                if (ChainedHashDelete(table, key, hashFunc))
                    std::cout << "Key deleted.\n";
                else
                    std::cout << "Key not found.\n";
                break;
            case 4:
                ChainedHashShow(table);
                break;
            default:
                std::cout << "Invalid.\n";
        }
    }
    return 0;
}