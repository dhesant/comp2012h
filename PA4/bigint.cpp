/*
 * bigint.cpp
 */

#include "bigint.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_LENGTH 50

BigInt::BigInt() {
  from_string("0");
}

BigInt::BigInt(const char *str) {
  from_string(str);
}

BigInt::BigInt(int i) {
  char str[12];
  sprintf(str, "%d", i);
  from_string(str);
}

BigInt::BigInt(const BigInt &bi) {
  char str[MAX_LENGTH];
  bi.to_string(str);
  from_string(str);
}

BigInt::~BigInt() {
}

bool BigInt::from_string(const char *str) {
  std::string s = str;
  if (s[0] == '-') {
    sign = '-';
    s = s.substr(1);
  }
  else {
    sign = '+';
  }
  
  if (s.length() % 2) {
    s.insert(0, "0");
  }

  for (uint i = 0; i < s.length()/2; ++i) {
    std::string substr = s.substr(i * 2, 2);
    abs_value.push_back(atoi(substr.c_str()));
  }

  return true;
}

void BigInt::to_string(char *str) const {
  std::string s = "";
  
  if (sign == '-') {
    s.append("-");
  }

  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }

  std::strcpy(str, s.c_str());
}

void BigInt::to_string(char *str) {
  std::string s = "";
  
  if (sign == '-') {
    s.append("-");
  }

  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }

  std::strcpy(str, s.c_str());
}

void BigInt::print() {
  char str[MAX_LENGTH];
  to_string(str);
  std::cout << str << std::endl;
}

