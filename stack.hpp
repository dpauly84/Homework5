// File Name: stack.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 4
// Last Changed: March 24, 2015

#ifndef _HOMEWORK5_STACK_HPP_
#define _HOMEWORK5_STACK_HPP_

// Type definitions
template<class Element>
struct list_element {
    Element value;
    list_element<Element> *next;
};

template<class Element>
class Stack {
public:
    Stack();
    ~Stack();
    Element top();
    Element pop();
    void push(Element e);
    bool is_empty();

private:
    list_element<Element> *m_first;
};

// Content that would normally go in the source file: Class implementation
// (Needs to be here because it is a template class.)

// constructor
template<class Element>
Stack<Element>::Stack() {
}

// destructor
template<class Element>
Stack<Element>::~Stack() {
}

// returns the top element of the stack, but doesn’t change the stack
template<class Element>
Element Stack<Element>::top() {
}

// returns what was the top element of the stack, and also removes this element from the stack
template<class Element>
Element Stack<Element>::pop() {
}

// adds element to top of stack
template<class Element>
void Stack<Element>::push(Element e) {
}

// returns true if stack is empty, or false otherwise
template<class Element>
bool Stack<Element>::is_empty() {
}

#endif //_HOMEWORK5_STACK_H_
