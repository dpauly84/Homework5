// File Name: utils.hpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 1
// Last Changed: March 21, 2015

#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#include <string> // Provides std::string

// All functions prompt user for input
// Input is read as string and converted to return type
// If conversion is not successful the process repeats
double get_double(std::string prompt);
int get_int(std::string prompt);
long get_long(std::string prompt);
float get_float(std::string prompt);

#endif