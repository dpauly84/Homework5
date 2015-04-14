// File Name: calculator.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 5
// Last Changed: April 14, 2015

#ifndef _HOMEWORK5_CALCULATOR_HPP_
#define _HOMEWORK5_CALCULATOR_HPP_

#include <string>

// Converts and infix  notation string to postfix
// Infix string must be fully parenthesized
// All operands in infix string must be single digit numbers
std::string infix_to_postfix(std::string &infix);

// Appends char c to string postfix and adds a space between characters
void append_postfix(char c, std::string &postfix);

// computes postfix notation and returns the value as type double
double compute_postfix(std::string &postfix);

// converts a char to a double and returns it
double char_to_double(char c);

#endif //_HOMEWORK5_CALCULATOR_HPP_
