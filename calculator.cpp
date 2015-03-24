// File Name: calculator.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#include "calculator.hpp"
#include "stack.hpp"
#include <iostream>
#include <sstream>

template<class Element>
void print_stack(Stack<Element> e);

using namespace std;

int main() {
    Stack<double> doubleStack;
    doubleStack.push(20);
    doubleStack.push(40);
    print_stack(doubleStack);

} // End Main

template<class Element>
void print_stack(Stack<Element> e) {
    list_element<Element> * ptr = new list_element<Element>;
    ptr = e.m_first;
    while(ptr != NULL) {
        cout << ptr->value << endl;
        ptr = ptr->next;
    }

}
