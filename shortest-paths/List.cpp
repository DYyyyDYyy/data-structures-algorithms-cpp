#include "List.h"
#include <iostream>

Node* stack_head;
Node* queue_front;
Node* queue_rear;
Node* dll_first;
Node* dll_last;

void create_empty_lists() {
    stack_head = nullptr;
    queue_front = nullptr;
    queue_rear = nullptr;
    dll_last = nullptr;
    dll_first = nullptr;
}

void push(datatype data) {
    Node *temp = new Node;
    temp->key = data;
    temp->next = stack_head;
    temp->previous = nullptr;
    if (stack_head != nullptr) {
        stack_head->previous = temp;
    }
    stack_head = temp;
}

void pop() {
    if (stack_head == nullptr) {
        return;
    }
    Node *temp = stack_head;
    stack_head = temp->next;
    if (stack_head != nullptr) {
        stack_head->previous = nullptr;
    }
    delete temp;
}

void show_stack(Node *stack_head1) {
    Node *temp = stack_head1;
    std::cout << "STACK (top->bottom): ";
    while (temp != nullptr) {
        std::cout << temp->key << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL";
}

std::string str_stack(Node *stack_head1) {
    Node *temp = stack_head1;
    std::string res;
    res = "(top->bottom): ";
    while (temp != nullptr) {
        res += std::to_string(temp->key) + " -> ";
        temp = temp->next;
    }
    res += "NULL";
    return res;
}

// ... Інші функції (enqueue, dequeue і т.д.) залишаються як у вашому файлі ...
// Я скоротив їх тут для економії місця, але у проекті вони мають бути присутні, 
// щоб не було помилок лінкування. 
// Якщо ви не використовуєте чергу в цій лабі, можна залишити заглушки, 
// але краще просто вставити повний вміст вашого файлу List.cpp сюди.

void enqueue(datatype data) {} 
void dequeue() {}
void show_queue() {}
std::string str_queue() { return ""; }
void add_begin(datatype data) {}
void add_end(datatype data) {}
void del_begin() {}
void del_end() {}
Node* search(datatype key) { return nullptr; }
void add_mid(datatype key, datatype data) {}
void del_mid(datatype key) {}
void show_dll() {}