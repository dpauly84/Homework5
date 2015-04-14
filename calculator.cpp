// File Name: calculator.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 5
// Last Changed: April 14, 2015

// Description: This program implements uses stacks to convert infix notation to
// postfix notation and calculates the result.

#include "calculator.hpp"
#include "stack.hpp"
#include <cstdlib> // Provides EXIT_SUCCESS

using namespace std;

int main() {

    string infix, postfix;

    cout << "Enter an expression in infix notation: ";
    getline(cin, infix);

    postfix = infix_to_postfix(infix);
    cout << "Your expression converted to postfix is: " << postfix << endl;
    cout << endl;

    cout << "The result of evaluating your expression is: "
    << compute_postfix(postfix) << endl;

    return EXIT_SUCCESS;

} // End main

// Converts and infix  notation string to postfix
// Infix string must be fully parenthesized
// All operands in infix string must be single digit numbers
string infix_to_postfix(string & infix) {
    string postfix = "";
    Stack<char> charStack;
    char symbol; // character from string infix
    char stack_sym; // character from top of stack
    for (unsigned int i = 0; i < infix.length(); ++i) { // iterate through characters in infix string
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

// Appends char c to string postfix and adds a space between characters
void append_postfix(char c, string &postfix) {
    postfix += c;
    postfix += " ";
}

// computes postfix notation and returns the value as type double
double compute_postfix(string & postfix) {
    Stack<double> doubleStack; // Initialize a stack of doubles
    double num1, num2;
    char symbol;
    unsigned int i = 0;
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

// converts a char to a double and returns it
double char_to_double(char c) {
    return static_cast<double>(c - '0');
}

