// File Name: calculator.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#include "calculator.hpp"
#include "stack.hpp"
#include <iostream>
#include <sstream>
#include <bits/algorithmfwd.h>
#include <string>
template<class Element>
void print_stack(Stack<Element> e);

using namespace std;

int main() {
    Stack<double> doubleStack;

    string infix = "(( 3-(8   /    5 ))*    2)";


//    Start: infix contains an expression
//    postfix is empty
//    stack is empty
    string postfix = getString(infix);

    cout << "infix: " << infix << endl;
    cout << "postfix: " << postfix << endl;

}

string getString(string &infix) {
    string postfix = "";
    Stack<char> charStack;
    char symbol;
    char stack_sym;
    for (int i = 0; i < infix.length(); ++i) {
        symbol = infix[i];
        if (symbol == ' ') continue;
        if (symbol == '(') charStack.push(symbol);
        else if (symbol == ')') {
            stack_sym = charStack.pop();
            while (stack_sym != '(') {
                append_postfix(stack_sym, postfix);
                stack_sym = charStack.pop();
            }
        }
//        ...

        else if (!isalpha(symbol) && !isdigit(symbol)) {
            if (charStack.is_empty()) charStack.push(symbol);
            else if (charStack.top() == '(') charStack.push(symbol);
            else {
                stack_sym = charStack.pop();
                while (stack_sym != '(') {
                    append_postfix(stack_sym, postfix);
                    stack_sym = charStack.pop();
                }
                charStack.push(stack_sym);
            }
        }

        else //* symbol is letter/number */
        {
            append_postfix(symbol, postfix);
        }
    } /* end for each symbol */

    while (!charStack.is_empty()) {
        stack_sym = charStack.pop();
        append_postfix(stack_sym, postfix);
    }
    return postfix;
}

template<class Element>
void print_stack(Stack<Element> e) {
    list_element<Element> *ptr = new list_element<Element>;
    ptr = e.m_first;
    while (ptr != NULL) {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }
}

void append_postfix(char c, string &postfix) {
    postfix += c;
    postfix += " ";
}



