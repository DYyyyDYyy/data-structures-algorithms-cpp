#include <iostream>

#include "Convert.h"
#include "List.h"

int main()
{
    string input = "(1 + 2) * (3 / 4) - 5";
    // std::cout << "Enter your expression: ";
    // std::cin >> input;

    string a = InfixToPrefix("(" + input + ")");
    std::cout << "Prefix: " << a << std::endl;
    a = PrefixToInfix(a);
    std::cout << "Infix: " << a << std::endl;
    a = InfixToPostfix(a);
    std::cout << "Postfix " << a << std::endl;
    a = PostfixToInfix(a);
    std::cout << "Infix : " << a << std::endl;


}
