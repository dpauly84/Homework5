// File Name: stack.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 5
// Last Changed: April 14, 2015

#ifndef _HOMEWORK5_STACK_HPP_
#define _HOMEWORK5_STACK_HPP_

#include <stddef.h> // Provides NULL
#include <iostream> // TODO delete for debugging
#include <cstdlib> // Provides EXIT_FAILURE

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
    list_element<Element> *m_last;
};

// Content that would normally go in the source file: Class implementation
// (Needs to be here because it is a template class.)

// constructor
template<class Element>
Stack<Element>::Stack() {
    m_last = NULL;
}

// destructor
template<class Element>
Stack<Element>::~Stack() {
    list_element<Element> *tmp;
    while(m_last != NULL) {
        tmp = m_last;
        m_last = m_last->next;
        delete tmp;
    }
}

// returns the top element of the stack, but does not change the stack
template<class Element>
Element Stack<Element>::top() {
    if(is_empty()){ // Ensure stack is not empty
        std::cout << "Cannot retrieve item off empty stack! Goodbye" << std::endl;
        exit(EXIT_FAILURE);
    }
    return m_last->value;
}

// returns what was the top element of the stack, and also removes this element from the stack
template<class Element>
Element Stack<Element>::pop() {
    if(is_empty()){ // Ensure stack is not empty
        std::cout << "Cannot pop item off empty stack! Goodbye" << std::endl;
        exit(EXIT_FAILURE);
    }
    Element value = m_last->value;
    list_element<Element> *tmp = m_last;
    m_last = m_last->next;
    delete tmp;
    return value;
}

// adds element to top of stack
template<class Element>
void Stack<Element>::push(Element e) {
    list_element<Element>* newElement = new list_element<Element>;
    newElement->value = e;
    if(m_last == NULL) {
        m_last = newElement;
        newElement->next = NULL;
    } else {
        newElement->next = m_last;
        m_last = newElement;
    }
}

// returns true if stack is empty, or false otherwise
template<class Element>
bool Stack<Element>::is_empty() {
    return m_last == NULL;
}

#endif //_HOMEWORK5_STACK_H_
