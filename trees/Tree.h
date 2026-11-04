#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

// Визначення типу для ключа вузла
typedef int datatype;

// Структура вузла бінарного дерева
struct Node
{
    datatype key;      // Інформаційне поле (ключ) вузла
    Node* parent;      // Вказівник на батьківський вузол
    Node* left;        // Вказівник на лівого сина
    Node* right;       // Вказівник на правого сина
};

// ============ Функції для роботи з простим бінарним деревом ============

// Функція для створення бінарного дерева
// pNode - вказівник на вузол (спочатку = NULL)
// n - кількість вузлів у дереві
void CreateTree(Node*& pNode, int n);

// Функція для виведення дерева (графічне представлення)
// pNode - вказівник на поточний вузол
// L - рівень глибини
void ShowTree(Node* pNode, int L);

// Обхід дерева у прямому порядку (преордер): корінь, ліве піддерево, праве піддерево
void PreOrder(Node* pNode);

// Обхід дерева у зворотному порядку (постордер): ліве піддерево, праве піддерево, корінь
void PostOrder(Node* pNode);

// Обхід дерева у внутрішньому порядку (інордер): ліве піддерево, корінь, праве піддерево
void InOrder(Node* pNode);

// Функція для очищення дерева (звільнення пам'яті)
void DeleteTree(Node*& pNode);

// ============ Функції для роботи з бінарним деревом пошуку (BST) ============

// Пошук вузла за ключем у BST
// pNode - корінь дерева
// key - ключ для пошуку
// Повертає вказівник на знайдений вузол або NULL
Node* SearchNodeBST(Node* pNode, datatype key);

// Створення кореня BST
// key - значення ключа кореня
// Повертає вказівник на новостворений корінь
Node* CreateRootBST(datatype key);

// Вставка нового вузла у BST
// pRoot - корінь дерева
// key - ключ для вставки
void InsertNodeBST(Node*& pRoot, datatype key);

// Видалення вузла з BST
// pRoot - корінь дерева
// delNode - вузол для видалення
// Повертає видалений ключ
datatype DeleteNodeBST(Node*& pRoot, Node*& delNode);

// Пошук наступного вузла (Successor) у BST
// pNode - вузол, для якого шукається Successor
// Повертає вказівник на наступний вузол або NULL
Node* SuccessorNodeBST(Node* pNode);

// Пошук попереднього вузла (Predecessor) у BST
// pNode - вузол, для якого шукається Predecessor
// Повертає вказівник на попередній вузол або NULL
Node* PredecessorNodeBST(Node* pNode);

// Пошук вузла з мінімальним ключем у піддереві
// pNode - корінь піддерева
Node* MinimumNodeBST(Node* pNode);

// Пошук вузла з максимальним ключем у піддереві
// pNode - корінь піддерева
Node* MaximumNodeBST(Node* pNode);

#endif // TREE_H
