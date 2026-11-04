//
// Created by Didukh Sviatoslav on 03.11.25.
//
/*
 * File: List.cpp
 * Description: Файл реалізації для Лабораторної роботи №4
 * Містить логіку функцій для стеку, черги та двозв'язного списку.
 */

#include "List.h"
#include <iostream>

// Визначення глобальних вказівників
Node* stack_head;
Node* queue_front;
Node* queue_rear;
Node* dll_first;
Node* dll_last;

// Ініціалізація всіх списків як порожніх
void create_empty_lists() {
    stack_head = NULL;
    queue_front = NULL;
    queue_rear = NULL;
    dll_last = NULL;
}




void push(datatype data) {
    // 1. Виділити пам'ять [cite: 70]
    Node *temp = new Node;
    // 2. Заповнити поле [cite: 72]
    temp->key = data;
    // 3. Зв'язати з вершиною [cite: 73]
    temp->next = stack_head;

    // Адаптація для двозв'язної структури (необов'язково для стеку, але коректно)
    temp->previous = NULL;
    if (stack_head != NULL) {
        stack_head->previous = temp;
    }

    // 4. Встановити нову вершину [cite: 74] (помилка у нумерації, 75 є частиною 74)
    stack_head = temp;
}

// Алгоритм видалення елементу зі стеку [cite: 74]
void pop() {
    // 1. Перевірити на порожнечу [cite: 76]
    if (stack_head == NULL) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    // 2. Створити копію вказівника [cite: 77]
    Node *temp = stack_head;
    // 3. Перемістити вершину [cite: 79]
    stack_head = temp->next;

    // Адаптація для двозв'язної структури
    if (stack_head != NULL) {
        stack_head->previous = NULL;
    }

    // 4. Звільнити пам'ять [cite: 81]
    delete temp;
}

// Алгоритм відображення вмісту стеку [cite: 82]
void show_stack() {
    // 1. Створити тимчасовий вказівник [cite: 83]
    Node *temp = stack_head;
    std::cout << "STACK (top->bottom): ";
    // 2. Поки не кінець стеку [cite: 84]
    while (temp != NULL) {
        std::cout << temp->key << " -> ";
        temp = temp->next; // [cite: 84]
    }
    std::cout << "NULL" << std::endl;
}


// --- Частина 2: Реалізація Черги --- [cite: 117]

// Алгоритм додавання елемента у чергу [cite: 103]
void enqueue(datatype data) {
    // 1. Виділити пам'ять [cite: 104]
    Node *temp = new Node;
    // 2. Заповнити поле [cite: 105-106]
    temp->key = data;
    // 3. Встановити останнім [cite: 108]
    temp->next = NULL;

    // Адаптація для двозв'язної структури
    temp->previous = queue_rear;

    // 4. Якщо черга порожня [cite: 108]
    if (queue_front == NULL) {
        queue_front = temp;
    } else {
        // 5. Якщо не порожня [cite: 109]
        queue_rear->next = temp;
    }
    // 6. Встановити кінець черги [cite: 110]
    queue_rear = temp;
}

// Алгоритм видалення елементу з черги [cite: 111-112]
void dequeue() {
    // Аналогічно до pop(), але `head` замінено на `front` [cite: 112]

    // 1. Перевірити на порожнечу [cite: 76]
    if (queue_front == NULL) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    // 2. Створити копію [cite: 77]
    Node *temp = queue_front;
    // 3. Перемістити початок [cite: 79]
    queue_front = temp->next;

    // Якщо черга стала порожньою, оновити і кінець
    if (queue_front == NULL) {
        queue_rear = NULL;
    } else {
        // Адаптація для двозв'язної структури
        queue_front->previous = NULL;
    }

    // 4. Звільнити пам'ять [cite: 81]
    delete temp;
}

// Відображення черги (використовує той же алгоритм, що й show_stack) [cite: 114]
void show_queue() {
    Node *temp = queue_front; // [cite: 83] (адаптовано)
    std::cout << "QUEUE (front->rear): ";
    while (temp != NULL) { // [cite: 84]
        std::cout << temp->key << " -> ";
        temp = temp->next; // [cite: 84]
    }
    std::cout << "NULL" << std::endl;
}


// --- Частина 3: Реалізація Двозв'язного Списку ---

// Алгоритм додавання в початок списку [cite: 142-145]
void add_begin(datatype data) {
    Node *temp = new Node;      // [cite: 146]
    temp->key = data;           // [cite: 148-149]
    temp->next = dll_first;     // [cite: 150-152]
    temp->previous = NULL;      // [cite: 153]

    if (dll_first != NULL) {    // [cite: 154]
        dll_first->previous = temp;
    } else {
        dll_last = temp;        // [cite: 156] (Якщо список був порожній)
    }
    dll_first = temp;           // [cite: 157]
}

// Алгоритм додавання в кінець списку [cite: 159-162]
void add_end(datatype data) {
    Node *temp = new Node;      // [cite: 163]
    temp->key = data;           // [cite: 164]
    temp->next = NULL;          // [cite: 165-166]
    temp->previous = dll_last;  // [cite: 167]

    if (dll_last != NULL) {     // [cite: 168]
        dll_last->next = temp;
    } else {
        dll_first = temp;       // [cite: 169] (Якщо список був порожній)
    }
    dll_last = temp;            // [cite: 170-171]
}

// Алгоритм видалення з початку списку [cite: 172-175]
void del_begin() {
    if (dll_first == NULL) {    // [cite: 176]
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node *temp = dll_first;     // [cite: 177]
    dll_first = temp->next;     // [cite: 178]

    if (dll_first != NULL) {
        dll_first->previous = NULL; // [cite: 180]
    } else {
        dll_last = NULL;        // [cite: 181-182] (Список став порожнім)
    }
    delete temp;                // [cite: 182] (Крок 6)
}

// Алгоритм видалення з кінця списку [cite: 183]
void del_end() {
    if (dll_last == NULL) {     // [cite: 184]
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node *temp = dll_last;      // [cite: 185]
    dll_last = temp->previous;  // [cite: 186]

    if (dll_last != NULL) {
        dll_last->next = NULL;  // [cite: 187]
    } else {
        dll_first = NULL;       // [cite: 188-189] (Список став порожнім)
    }
    delete temp;                // [cite: 189] (Крок 6)
}

// Алгоритм пошуку елементу [cite: 190]
Node* search(datatype key) {
    Node *temp = dll_first;     // [cite: 190] (Крок 1)
    while (temp != NULL) {      // [cite: 191] (Крок 2)
        if (temp->key == key) {
            return temp;        // [cite: 191]
        }
        temp = temp->next;      // [cite: 191]
    }
    std::cout << "Element " << key << " not found." << std::endl; // [cite: 192-194]
    return NULL;
}

// Алгоритм додавання елементу після знайденого [cite: 195]
void add_mid(datatype key, datatype data) {
    // 1. Пошук [cite: 195]
    Node *pkey = search(key);

    // 2. Якщо не знайдено [cite: 196]
    if (pkey == NULL) {
        return;
    }

    // 3. Якщо знайдений в кінці [cite: 196]
    if (pkey == dll_last) {
        add_end(data);
        return;
    }

    // 4. Якщо в середині [cite: 197]
    // 6. Виділити пам'ять [cite: 198]
    Node *temp = new Node;
    // 7. Заповнити поле [cite: 199]
    temp->key = data;

    // 8. Зв'язати з наступним [cite: 199]
    temp->next = pkey->next;
    // 9. Зв'язати з попереднім (знайденим) [cite: 199]
    temp->previous = pkey;
    // 10. Зв'язати знайдений з новим [cite: 200]
    pkey->next = temp;
    // 11. Зв'язати наступний з новим [cite: 200]
    (temp->next)->previous = temp;
}

// Алгоритм видалення знайденого елементу [cite: 201]
void del_mid(datatype key) {
    // 1. Пошук [cite: 201]
    Node *pkey = search(key);

    // 2. Якщо не знайдено [cite: 202]
    if (pkey == NULL) {
        return;
    }
    // 3. Якщо на початку [cite: 202]
    if (pkey == dll_first) {
        del_begin();
        return;
    }
    // 4. Якщо в кінці [cite: 203]
    if (pkey == dll_last) {
        del_end();
        return;
    }

    // 5. Інакше (в середині)
    // 6. Зв'язати попередній з наступним [cite: 204]
    (pkey->previous)->next = pkey->next;
    // 7. Зв'язати наступний з попереднім [cite: 205]
    (pkey->next)->previous = pkey->previous;

    // 8. Звільнити пам'ять [cite: 205]
    delete pkey;
}

// Відображення двозв'язного списку
void show_dll() {
    Node *temp = dll_first; // [cite: 83] (адаптовано)
    std::cout << "DLL (first<->last): ";
    if (temp == NULL) {
        std::cout << "EMPTY";
    }
    while (temp != NULL) { // [cite: 84]
        std::cout << temp->key << " <-> ";
        temp = temp->next; // [cite: 84]
    }
    std::cout << "NULL" << std::endl;
}