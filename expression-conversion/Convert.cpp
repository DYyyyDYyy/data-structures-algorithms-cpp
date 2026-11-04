//
// Created by SviatArch on 11/13/25.
//
// Convert.cpp
#include <bits/stdc++.h>
#include "List.h"
using namespace std;



int getPriority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string InfixToPrefix(string in)
{
    Node *stackHead = nullptr;
    string result = "";


    reverse(in.begin(), in.end());


    for (int i = 0; i < in.length(); i++)
    {
        char c = in[i];


        if (c == ' ') continue;


        if (isalnum(c))
        {
            result += c;
        }

        else if (c == ')')
        {
            string temp(1, c);
            push(stackHead, temp);
        }

        else if (c == '(')
        {
            while (stackHead != nullptr && stackHead->key != ")")
            {
                result += stackHead->key;
                pop(stackHead);
            }

            if (stackHead != nullptr) {
                pop(stackHead);
            }
        }

        else
        {

            while (stackHead != nullptr &&
                   getPriority(c) < getPriority(stackHead->key[0]))
            {
                result += stackHead->key;
                pop(stackHead);
            }
            string temp(1, c);
            push(stackHead, temp);
        }
    }


    while (stackHead != nullptr)
    {
        result += stackHead->key;
        pop(stackHead);
    }


    reverse(result.begin(), result.end());

    return result;
}

string InfixToPostfix(string in)
{
    Node *stackHead = nullptr;
    string temp;
    string result;
    for (int i = 0; i < in.length(); i++)
    {

        if (isdigit(in[i]) or isalpha(in[i]))
        {
            result += in[i];
        } else if (in[i] == '*' or in[i] == '/' or in[i] == '^' or in[i] == '-' or in[i] == '+')
        {
            temp = in[i];
            push(stackHead, temp);

        }
        if (in[i] == ')')
        {
            Node* temp1 = stackHead;
            result += temp1->key;
            pop(stackHead);

        }
    }
    return result;



}
string PostfixToInfix(string post)
{
    Node *stackHead = nullptr;


    for (int i = 0; i < post.length(); i++)
    {
        char c = post[i];
        if (c == ' ') continue;


        if (isalnum(c))
        {
            string temp(1, c);
            push(stackHead, temp);
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (stackHead == nullptr) return "Error";


            string op2 = stackHead->key;
            pop(stackHead);

            if (stackHead == nullptr) return "Error";

            string op1 = stackHead->key;
            pop(stackHead);


            string temp = "(" + op1 + c + op2 + ")";


            push(stackHead, temp);
        }
    }


    if (stackHead != nullptr) {
        string result = stackHead->key;
        pop(stackHead);
        return result;
    }
    return "";
}

string PrefixToInfix(string pref)
{
    Node *stackHead = nullptr;


    for (int i = pref.length() - 1; i >= 0; i--)
    {
        char c = pref[i];
        if (c == ' ') continue;


        if (isalnum(c))
        {
            string temp(1, c);
            push(stackHead, temp);
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            if (stackHead == nullptr) return "Error";


            string op1 = stackHead->key;
            pop(stackHead);

            if (stackHead == nullptr) return "Error";

            string op2 = stackHead->key;
            pop(stackHead);


            string temp = "(" + op1 + c + op2 + ")";


            push(stackHead, temp);
        }
    }

    if (stackHead != nullptr) {
        string result = stackHead->key;
        pop(stackHead);
        return result;
    }
    return "";
}