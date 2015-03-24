// File Name: calculator.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#include "calculator.hpp"
#include "stack.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    Stack<char> charStack;
    Stack<double> doubleStack;
    string infix = "((3-(8/5))*2)";
    string postfix = "                                  ";
    const char LEFT_PARAN = '(';
    const char RIGHT_PARAN = ')';
    stringstream ss;

//    Stage 1: Convert infix expression to postfix. To stay focused on the use of stacks in this program, and
//    avoid complex parsing details, the following simplifying assumptions can be made:
//    – You may assume that the expression entered by the user is a fully parenthesized infix expression (so do
//        not need to consider precedence of operators).
//    – You may assume that all operands are numbers (not variables) which are single digits, so each character
//    is either a space (to be ignored), or a symbol. The symbols are: left- and right-parenthesis, operators (+,
//    −, ∗, /), and operands (digits).
//    – Use a stack of type Stack<char> to do this conversion.

    cout << "Enter an expression in infix notation:  ";
//    getline(cin, infix);

    cout << infix << endl;


    int i = 0;
    int n = 0;
    do {
        if (infix[i] == LEFT_PARAN) {
            charStack.push(infix[i]);
            cout << "found left paran at " << i << endl;
        }
        else if (isdigit(infix[i])){
            postfix[n++] = infix[i];
            ss <<  infix[i];
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            cout << "operator: " << infix[i] << endl;
            charStack.push(infix[i]);
        }
        else if (infix[i] == RIGHT_PARAN) {
            cout << "found right paran" << endl;
            ss << charStack.pop();
            charStack.pop(); // left paranthesis
        }
        cout << "i is: " << i << endl;
        ++i;
    } while (i != infix.length());

    cout << "Postfix: " << postfix << endl;

    string mystring = ss.str();
    cout << "ss: " << mystring << endl;

} // End Main
