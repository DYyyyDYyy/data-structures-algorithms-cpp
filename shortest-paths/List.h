#ifndef LIST_H
#define LIST_H

#include <string>

typedef int datatype;

struct Node {
    datatype key;
    Node* next;
    Node* previous;
};

// Глобальні змінні (як у вашому коді)
extern Node* stack_head;
extern Node* queue_front;
extern Node* queue_rear;
extern Node* dll_first;
extern Node* dll_last;

// Функції стеку
void push(datatype data);
void pop();
void show_stack(Node *stack_head1);
std::string str_stack(Node *stack_head1);

// Інші функції (черга, список) - залишаємо для сумісності
std::string str_queue();
void enqueue(datatype data);
void dequeue();
void show_queue();
void add_begin(datatype data);
void add_end(datatype data);
void del_begin();
void del_end();
Node* search(datatype key);
void add_mid(datatype key, datatype data);
void del_mid(datatype key);
void show_dll();

// Допоміжна функція
void create_empty_lists();

#endif // LIST_H