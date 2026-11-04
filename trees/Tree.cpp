#include "Tree.h"


void CreateTree(Node*& pNode, int n)
{

    if (n == 0)
    {
        pNode = NULL;
        return;
    }


    pNode = new Node;
    pNode->parent = NULL;
    pNode->left = NULL;
    pNode->right = NULL;

    // Ввести ключ для вузла
    cout << "Введіть ключ для вузла: ";
    cin >> pNode->key;

    // Розподіл вузлів між лівим та правим піддеревом
    int n_left = n / 2;
    int n_right = n - n_left - 1;

    // Рекурсивно створити ліве піддерево
    if (n_left > 0)
    {
        CreateTree(pNode->left, n_left);
        if (pNode->left != NULL)
            pNode->left->parent = pNode;
    }


    if (n_right > 0)
    {
        CreateTree(pNode->right, n_right);
        if (pNode->right != NULL)
            pNode->right->parent = pNode;
    }
}


void ShowTree(Node* pNode, int L)
{
    if (pNode == NULL)
        return;

    ShowTree(pNode->left, L + 1);


    for (int i = 0; i < L; i++)
        cout << "   ";
    cout << pNode->key << "\n";


    ShowTree(pNode->right, L + 1);
}


void PreOrder(Node* pNode)
{
    if (pNode == NULL)
        return;

    cout << pNode->key << " ";
    PreOrder(pNode->left);
    PreOrder(pNode->right);
}

// Обхід у зворотному порядку (Postorder): ліве піддерево, праве піддерево, корінь
void PostOrder(Node* pNode)
{
    if (pNode == NULL)
        return;

    PostOrder(pNode->left);
    PostOrder(pNode->right);
    cout << pNode->key << " ";
}


void InOrder(Node* pNode)
{
    if (pNode == NULL)
        return;

    InOrder(pNode->left);
    cout << pNode->key << " ";
    InOrder(pNode->right);
}

void DeleteTree(Node*& pNode)
{
    if (pNode == NULL)
        return;


    DeleteTree(pNode->left);
    DeleteTree(pNode->right);


    delete pNode;
    pNode = NULL;
}

Node* SearchNodeBST(Node* pNode, datatype key)
{
    if (pNode == NULL)
        return NULL;

    if (pNode->key == key)
        return pNode;
    else if (key < pNode->key)
        return SearchNodeBST(pNode->left, key);
    else
        return SearchNodeBST(pNode->right, key);
}


Node* CreateRootBST(datatype key)
{
    Node* pRoot = new Node;
    pRoot->key = key;
    pRoot->parent = NULL;
    pRoot->left = NULL;
    pRoot->right = NULL;
    return pRoot;
}


void InsertNodeBST(Node*& pRoot, datatype key)
{

    if (pRoot == NULL)
    {
        pRoot = CreateRootBST(key);
        cout << "Вузол з ключем " << key << " вставлено як корінь." << endl;
        return;
    }


    if (SearchNodeBST(pRoot, key) != NULL)
    {
        cout << "Помилка: вузол з ключем " << key << " вже існує!" << endl;
        return;
    }


    Node* pNew = new Node;
    pNew->key = key;
    pNew->parent = NULL;
    pNew->left = NULL;
    pNew->right = NULL;


    Node* pNode = pRoot;
    Node* previous = NULL;

    while (pNode != NULL)
    {
        previous = pNode;
        if (key < pNode->key)
            pNode = pNode->left;
        else
            pNode = pNode->right;
    }


    pNew->parent = previous;

    if (key < previous->key)
        previous->left = pNew;
    else
        previous->right = pNew;

    cout << "Вузол з ключем " << key << " успішно вставлено." << endl;
}


Node* MinimumNodeBST(Node* pNode)
{
    if (pNode == NULL)
        return NULL;

    while (pNode->left != NULL)
        pNode = pNode->left;

    return pNode;
}


Node* MaximumNodeBST(Node* pNode)
{
    if (pNode == NULL)
        return NULL;

    while (pNode->right != NULL)
        pNode = pNode->right;

    return pNode;
}

Node* SuccessorNodeBST(Node* pNode)
{
    if (pNode == NULL)
        return NULL;


    if (pNode->right != NULL)
        return MinimumNodeBST(pNode->right);


    Node* previous = pNode->parent;
    while (previous != NULL && pNode == previous->right)
    {
        pNode = previous;
        previous = previous->parent;
    }

    return previous;
}


Node* PredecessorNodeBST(Node* pNode)
{
    if (pNode == NULL)
        return NULL;

    if (pNode->left != NULL)
        return MaximumNodeBST(pNode->left);


    Node* previous = pNode->parent;
    while (previous != NULL && pNode == previous->left)
    {
        pNode = previous;
        previous = previous->parent;
    }

    return previous;
}


datatype DeleteNodeBST(Node*& pRoot, Node*& delNode)
{
    if (delNode == NULL)
    {
        cout << "Помилка: вузол не знайдено!" << endl;
        return -1;
    }

    datatype deletedKey = delNode->key;
    Node* term = NULL;

    // ВИПАДОК 1: Вузол не має нащадків (листок)
    if (delNode->left == NULL && delNode->right == NULL)
    {
        if (delNode == pRoot)
        {
            pRoot = NULL;
            delete delNode;
        }
        else
        {
            if (delNode->parent->left == delNode)
                delNode->parent->left = NULL;
            else
                delNode->parent->right = NULL;
            delete delNode;
        }
    }

    else if (delNode->left == NULL || delNode->right == NULL)
    {
        Node* next = (delNode->left != NULL) ? delNode->left : delNode->right;

        if (delNode == pRoot)
        {
            pRoot = next;
            next->parent = NULL;
            delete delNode;
        }
        else
        {
            if (delNode->parent->left == delNode)
                delNode->parent->left = next;
            else
                delNode->parent->right = next;
            next->parent = delNode->parent;
            delete delNode;
        }
    }

    else
    {
        term = SuccessorNodeBST(delNode);

        if (term != NULL)
        {
            delNode->key = term->key;
            DeleteNodeBST(pRoot, term);
        }
    }

    return deletedKey;
}
