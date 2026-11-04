//
// Created by SviatArch on 11/6/25.
//

#ifndef LIST_H
#define LIST_H
#include <string>
typedef int datatype;
using namespace std;
struct Node {
    string key;
    Node* next;
    Node* previous;
};

void push(Node*& head, std::string key);
void pop(Node*& head);
void enqueue(Node*& front, Node*& rear, datatype data);
void dequeue(Node*& front, Node*& rear);
void show(Node* first);
void show_stack(Node* head);
void show_queue(Node* front);
void show_list(Node* first);

void add_begin(Node*& first, Node*& last, datatype data);
void add_end(Node*& first, Node*& last, datatype data);
void del_begin(Node*& first, Node*& last);
void del_end(Node*& first, Node*& last);
Node* search(Node* first, datatype key);
void add_mid(Node*& first, Node*& last, datatype key, datatype data);
void del_mid(Node*& first, Node*& last, datatype key);

#endif
