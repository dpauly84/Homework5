// File Name: calculator.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 5
// Last Changed: April 14, 2015

#ifndef _HOMEWORK5_CALCULATOR_HPP_
#define _HOMEWORK5_CALCULATOR_HPP_

#include <string>

std::string infix_to_postfix(std::string &infix);
void append_postfix(char c, std::string &postfix);
double compute_postfix(std::string & postfix);
double char_to_double(char c);

#endif //_HOMEWORK5_CALCULATOR_HPP_
