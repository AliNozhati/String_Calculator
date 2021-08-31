// Made by Ali Nozhati on 2021/8/31

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>

std::string sumstri(const char*, const char*);   // n digits + n digits
std::string minstri(const char*, const char*);   // n digits - n digits
std::string multistri(const char*, const char*); // n digits * n digits
std::string divitstri(const char*, const char*); // n digits / 9 digits
std::string modestri(const char* , const char*); // n digits % 9 digits
std::string operator+(const std::string, const std::string);
std::string operator-(const std::string, const std::string);
std::string operator*(const std::string, const std::string);
std::string operator/(const std::string, const std::string);
std::string operator%(const std::string, const std::string);

#endif
