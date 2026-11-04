//
// Created by SviatArch on 11/6/25.
//
#include "List.h"
#include <iostream>
using namespace std;

void push(Node*& head, string key) {
    Node* temp = new Node;
    temp->key = key;
    temp->next = head;
    temp->previous = nullptr;
    head = temp;
}

void pop(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void enqueue(Node*& front, Node*& rear, string data) {
    Node* temp = new Node;
    temp->key = data;
    temp->next = nullptr;
    temp->previous = nullptr;
    if (!front) front = temp;
    else rear->next = temp;
    rear = temp;
}


void show_stack(Node* head) {
    Node* temp = head;
    if (!temp) {
        cout << "[empty]" << endl;
        return;
    }
    cout << "Top -> ";
    while (temp) {
        cout << "[" << temp->key << "]";
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void show_queue(Node* front) {
    Node* temp = front;
    if (!temp) {
        cout << "[empty]" << endl;
        return;
    }
    cout << "Front -> ";
    while (temp) {
        cout << "[" << temp->key << "]";
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

void show_list(Node* first) {
    Node* temp = first;
    if (!temp) {
        cout << "[empty]" << endl;
        return;
    }
    cout << "NULL ";
    while (temp) {
        cout << "<-[" << temp->key << "]->";
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

void dequeue(Node*& front, Node*& rear) {
    if (!front) return;
    Node* temp = front;
    front = temp->next;
    if (!front) rear = nullptr;
    delete temp;
}

void show(Node* first) {
    Node* temp = first;
    while (temp) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

void add_begin(Node*& first, Node*& last, string data) {
    Node* temp = new Node;
    temp->key = data;
    temp->next = first;
    temp->previous = nullptr;
    if (first) first->previous = temp;
    else last = temp;
    first = temp;
}

void add_end(Node*& first, Node*& last, string data) {
    Node* temp = new Node;
    temp->key = data;
    temp->next = nullptr;
    temp->previous = last;
    if (last) last->next = temp;
    else first = temp;
    last = temp;
}

void del_begin(Node*& first, Node*& last) {
    if (!first) return;
    Node* temp = first;
    first = temp->next;
    if (first) first->previous = nullptr;
    else last = nullptr;
    delete temp;
}

void del_end(Node*& first, Node*& last) {
    if (!last) return;
    Node* temp = last;
    last = temp->previous;
    if (last) last->next = nullptr;
    else first = nullptr;
    delete temp;
}

Node* search(Node* first, string key) {
    Node* temp = first;
    while (temp) {
        if (temp->key == key) return temp;
        temp = temp->next;
    }
    return nullptr;
}

void add_mid(Node*& first, Node*& last, string key, string data) {
    Node* pkey = search(first, key);
    if (!pkey) return;
    if (pkey == last) {
        add_end(first, last, data);
        return;
    }
    Node* temp = new Node;
    temp->key = data;
    temp->next = pkey->next;
    temp->previous = pkey;
    pkey->next->previous = temp;
    pkey->next = temp;
}

void del_mid(Node*& first, Node*& last, string key) {
    Node* pkey = search(first, key);
    if (!pkey) return;
    if (pkey == first) {
        del_begin(first, last);
        return;
    }
    if (pkey == last) {
        del_end(first, last);
        return;
    }
    pkey->previous->next = pkey->next;
    pkey->next->previous = pkey->previous;
    delete pkey;
}
