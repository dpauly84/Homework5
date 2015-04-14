// File Name: calculator.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#include "calculator.hpp"
#include "stack.hpp"

using namespace std;

template<class Element>
void print_stack(Stack <Element> e);

int main() {

    string infix, postfix;
    infix = "(4 - 2 + 6)";

    cout << "Enter an expression in infix notation: ";
//    getline(cin, infix);

    postfix = infix_to_postfix(infix);
    cout << "Your expression converted to postfix is: " << postfix << endl;
    cout << endl;

    cout << "the result of evaluating your expression is: "
    << compute_postfix(postfix);

    return 0;
} // End main

string infix_to_postfix(string & infix) {
    string postfix = "";
    Stack<char> charStack;
    char symbol; // character from string infix
    char stack_sym; // character from top of stack
    for (int i = 0; i < infix.length(); ++i) { // iterate through characters in infix string
        symbol = infix[i];
        if (symbol == ' ') continue; // ignore spaces
        if (symbol == '(') charStack.push(symbol);
        else if (symbol == ')') {
            stack_sym = charStack.pop();
            while (stack_sym != '(') {
                append_postfix(stack_sym, postfix);
                if (charStack.is_empty()) break;
                stack_sym = charStack.pop();
            }
        }

        else if (!isalpha(symbol) && !isdigit(symbol)) { // symbol is an operator
            if (charStack.is_empty()) {
                charStack.push(symbol);
            }
            else if (charStack.top() == '(') {
                charStack.push(symbol);
            }
            else {
                stack_sym = charStack.pop();
                while (stack_sym != '(' ) {
                    append_postfix(stack_sym, postfix);
                    if (charStack.is_empty()) break;
                    stack_sym = charStack.pop();
                }
                charStack.push(symbol);
            }
        }

        else // symbol is letter/number
        {
            append_postfix(symbol, postfix);
        }
    } // end for each symbol

    while (!charStack.is_empty()) {
        stack_sym = charStack.pop();
        append_postfix(stack_sym, postfix);
    }
    return postfix;
}

template<class Element>
void print_stack(Stack <Element> e) {
    list_element <Element> *ptr = new list_element <Element>;
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

double compute_postfix(string & postfix) {
    Stack<double> doubleStack; // Initialize a stack of doubles
    double num1, num2;
    char symbol;
    int i = 0;
    do {
        symbol = postfix[i];
        if (symbol == ' ') {
            ++i;
            continue;
        }
        else if (isdigit(symbol)) {
            doubleStack.push(char_to_double(symbol));
        }
        else {
            num2 = doubleStack.pop();
            num1 = doubleStack.pop();

            switch (symbol) {
                case '+':
                    doubleStack.push(num1 + num2);
                    break;
                case '-':
                    doubleStack.push(num1 - num2);
                    break;
                case '*':
                    doubleStack.push(num1 * num2);
                    break;
                case '/':
                    doubleStack.push(num1 / num2);
                    break;
            }
        }
        ++i;
    } while (i < postfix.length());

    return doubleStack.pop();

}

double char_to_double(char c) {
    return static_cast<double>(c - '0');
}

