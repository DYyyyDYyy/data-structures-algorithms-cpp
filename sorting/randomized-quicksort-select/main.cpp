#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
int main() {
    std::srand(std::time(0));
    int n;
    std::string size_tmp;

    bool is_correct = false;
    std::cout << "Введіть кількість елементів масиву: ";
    std::cin >> size_tmp;
    while (!is_correct)
    {

        if (is_number(size_tmp))
        {
            if (floor(std::stof(size_tmp)) == std::stof(size_tmp))
            {
                if (std::stoi(size_tmp) > 0) {
                    n = std::stoi(size_tmp);
                    is_correct = true;}

            }
        } else
        {
            std::cout << "Розмір масиву маж бути цілим числом > 0." << std::endl;
            std::cout << "Будь ласка, введіть число: ";

            std::cin >> size_tmp;
        }
    }

    int* A = new int[n];

    std::cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    QuickSort(A, 0, n - 1);

    std::cout << "Відсортований масив: ";
    printArray(A, n);

    delete[] A;
    return 0;
}