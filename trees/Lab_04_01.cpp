#include "Tree.h"
#include <iostream>
using namespace std;

void PrintMenu()
{
    cout << "\n====== МЕНЮ ======" << endl;
    cout << "1. Створити дерево" << endl;
    cout << "2. Показати дерево (графічно)" << endl;
    cout << "3. Обхід у прямому порядку (Preorder)" << endl;
    cout << "4. Обхід у внутрішньому порядку (Inorder)" << endl;
    cout << "5. Обхід у зворотному порядку (Postorder)" << endl;
    cout << "6. Очистити дерево" << endl;
    cout << "0. Вихід" << endl;
    cout << "==================" << endl;
    cout << "Виберіть операцію: ";
}

int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");

    Node* root = NULL;
    int choice, n;

    while (true)
    {
        PrintMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: // Створити дерево
        {
            cout << "Введіть кількість вузлів у дереві: ";
            cin >> n;

            if (n <= 0)
            {
                cout << "Помилка: кількість вузлів повинна бути > 0!" << endl;
                break;
            }

            if (root != NULL)
            {
                cout << "Попередня дерево буде видалено." << endl;
                DeleteTree(root);
            }

            cout << "\nСтворення дерева (введіть " << n << " ключів):" << endl;
            CreateTree(root, n);
            cout << "\nДерево успішно створено!" << endl;
            break;
        }

        case 2: // Показати дерево
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево не створено!" << endl;
                break;
            }

            cout << "\n========== ГРАФІЧНЕ ПРЕДСТАВЛЕННЯ ДЕРЕВА ==========" << endl;
            ShowTree(root, 0);
            cout << "===================================================" << endl;
            break;
        }

        case 3: // Обхід у прямому порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево не створено!" << endl;
                break;
            }

            cout << "\nОбхід у прямому порядку (Preorder): ";
            PreOrder(root);
            cout << endl;
            break;
        }

        case 4: // Обхід у внутрішньому порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево не створено!" << endl;
                break;
            }

            cout << "\nОбхід у внутрішньому порядку (Inorder): ";
            InOrder(root);
            cout << endl;
            break;
        }

        case 5: // Обхід у зворотному порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево не створено!" << endl;
                break;
            }

            cout << "\nОбхід у зворотному порядку (Postorder): ";
            PostOrder(root);
            cout << endl;
            break;
        }

        case 6: // Очистити дерево
        {
            if (root == NULL)
            {
                cout << "Дерево вже порожнє!" << endl;
                break;
            }

            DeleteTree(root);
            cout << "Дерево успішно видалено!" << endl;
            break;
        }

        case 0: // Вихід
        {
            cout << "\nЗавершення програми..." << endl;
            if (root != NULL)
                DeleteTree(root);
            return 0;
        }

        default:
        {
            cout << "Помилка: невірна операція!" << endl;
            break;
        }
        }
    }

    return 0;
}
