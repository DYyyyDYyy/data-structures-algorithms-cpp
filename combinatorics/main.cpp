#include <iostream>
#include "Comb.h"

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n, k;

    while (true) {
        std::cout << "Введіть значення n (або 0 для виходу): ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Програма завершена." << std::endl;
            break;
        }

        std::cout << "Введіть значення k: ";
        std::cin >> k;

        if (k < 0) {
            std::cout << "Помилка: k не може бути від'ємним. Спробуйте ще раз.\n" << std::endl;
            continue;
        }

        std::cout << "\n--- РЕЗУЛЬТАТИ ОБЧИСЛЕНЬ для n = " << n << ", k = " << k << " ---\n" << std::endl;

        try {
            std::cout << "1. Перестановки P(" << n << "): " << factorial(n) << std::endl;

            std::cout << "2. Розміщення без повторень A(" << n << ", " << k << "): " << A(n, k) << std::endl;

            std::cout << "3. Розміщення з повтореннями _A(" << n << ", " << k << "): " << _A(n, k) << std::endl;

            std::cout << "4. Сполучення без повторень C(" << n << ", " << k << "): " << C(n, k) << std::endl;

            std::cout << "5. Сполучення з повтореннями _C(" << n << ", " << k << "): " << _C(n, k) << std::endl;

        } catch (const std::invalid_argument& e) {
            std::cerr << "Помилка обчислення: " << e.what() << std::endl;
        }

        std::cout << "\n---------------------------------------------\n" << std::endl;
    }

    return 0;
}