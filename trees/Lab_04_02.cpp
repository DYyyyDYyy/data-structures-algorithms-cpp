#include "Tree.h"
#include <iostream>
using namespace std;

void PrintMenuBST()
{
    cout << "\n====== МЕНЮ БІНАРНОГО ДЕРЕВА ПОШУКУ ======" << endl;
    cout << "1. Створити корінь дерева" << endl;
    cout << "2. Вставити вузол" << endl;
    cout << "3. Видалити вузол" << endl;
    cout << "4. Пошук вузла" << endl;
    cout << "5. Знайти Successor (наступний вузол)" << endl;
    cout << "6. Знайти Predecessor (попередній вузол)" << endl;
    cout << "7. Показати дерево (графічно)" << endl;
    cout << "8. Обхід у прямому порядку (Preorder)" << endl;
    cout << "9. Обхід у внутрішньому порядку (Inorder)" << endl;
    cout << "10. Обхід у зворотному порядку (Postorder)" << endl;
    cout << "11. Знайти мінімум" << endl;
    cout << "12. Знайти максимум" << endl;
    cout << "13. Видалити дерево" << endl;
    cout << "0. Вихід" << endl;
    cout << "===========================================" << endl;
    cout << "Виберіть операцію: ";
}

int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");

    Node* root = NULL;
    int choice;
    datatype key;
    Node* foundNode = NULL;

    while (true)
    {
        PrintMenuBST();
        cin >> choice;

        switch (choice)
        {
        case 1: // Створити корінь дерева
        {
            cout << "Введіть ключ для кореня дерева: ";
            cin >> key;

            if (root != NULL)
            {
                cout << "Помилка: дерево вже існує! Спочатку видаліть його." << endl;
                break;
            }

            root = CreateRootBST(key);
            cout << "Корінь дерева успішно створено з ключем " << key << endl;
            break;
        }

        case 2: // Вставити вузол
        {
            if (root == NULL)
            {
                cout << "Помилка: спочатку створіть корінь дерева!" << endl;
                break;
            }

            cout << "Введіть ключ для вставки: ";
            cin >> key;

            InsertNodeBST(root, key);

            cout << "\nТекуче дерево:" << endl;
            ShowTree(root, 0);
            break;
        }

        case 3: // Видалити вузол
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "Введіть ключ вузла для видалення: ";
            cin >> key;

            foundNode = SearchNodeBST(root, key);
            if (foundNode == NULL)
            {
                cout << "Помилка: вузол з ключем " << key << " не знайдено!" << endl;
                break;
            }

            DeleteNodeBST(root, foundNode);
            cout << "Вузол з ключем " << key << " успішно видалено." << endl;

            cout << "\nТекуче дерево:" << endl;
            if (root != NULL)
                ShowTree(root, 0);
            else
                cout << "Дерево порожнє!" << endl;
            break;
        }

        case 4: // Пошук вузла
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "Введіть ключ для пошуку: ";
            cin >> key;

            foundNode = SearchNodeBST(root, key);
            if (foundNode != NULL)
                cout << "Вузол з ключем " << key << " знайдено!" << endl;
            else
                cout << "Вузол з ключем " << key << " не знайдено." << endl;
            break;
        }

        case 5: // Знайти Successor
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "Введіть ключ вузла для знаходження Successor: ";
            cin >> key;

            foundNode = SearchNodeBST(root, key);
            if (foundNode == NULL)
            {
                cout << "Помилка: вузол з ключем " << key << " не знайдено!" << endl;
                break;
            }

            Node* successor = SuccessorNodeBST(foundNode);
            if (successor != NULL)
                cout << "Successor для вузла " << key << " є: " << successor->key << endl;
            else
                cout << "Successor для вузла " << key << " не існує (це максимум)." << endl;
            break;
        }

        case 6: // Знайти Predecessor
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "Введіть ключ вузла для знаходження Predecessor: ";
            cin >> key;

            foundNode = SearchNodeBST(root, key);
            if (foundNode == NULL)
            {
                cout << "Помилка: вузол з ключем " << key << " не знайдено!" << endl;
                break;
            }

            Node* predecessor = PredecessorNodeBST(foundNode);
            if (predecessor != NULL)
                cout << "Predecessor для вузла " << key << " є: " << predecessor->key << endl;
            else
                cout << "Predecessor для вузла " << key << " не існує (це мінімум)." << endl;
            break;
        }

        case 7: // Показати дерево
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "\n========== ГРАФІЧНЕ ПРЕДСТАВЛЕННЯ ДЕРЕВА ПОШУКУ ==========" << endl;
            ShowTree(root, 0);
            cout << "============================================================" << endl;
            break;
        }

        case 8: // Обхід у прямому порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "\nОбхід у прямому порядку (Preorder): ";
            PreOrder(root);
            cout << endl;
            break;
        }

        case 9: // Обхід у внутрішньому порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "\nОбхід у внутрішньому порядку (Inorder): ";
            InOrder(root);
            cout << endl;
            break;
        }

        case 10: // Обхід у зворотному порядку
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            cout << "\nОбхід у зворотному порядку (Postorder): ";
            PostOrder(root);
            cout << endl;
            break;
        }

        case 11: // Знайти мінімум
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            Node* minNode = MinimumNodeBST(root);
            if (minNode != NULL)
                cout << "Мінімальний ключ у дереві: " << minNode->key << endl;
            break;
        }

        case 12: // Знайти максимум
        {
            if (root == NULL)
            {
                cout << "Помилка: дерево порожнє!" << endl;
                break;
            }

            Node* maxNode = MaximumNodeBST(root);
            if (maxNode != NULL)
                cout << "Максимальний ключ у дереві: " << maxNode->key << endl;
            break;
        }

        case 13: // Видалити дерево
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
