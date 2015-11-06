/*
 * bigint.cpp
 */

#include "bigint.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

BigInt::BigInt() {
  // Set BigInt using from_string with string "0"
  from_string("0");
}

BigInt::BigInt(const char *str) {
  // Set BigInt using from_string with str
  from_string(str);
}

BigInt::BigInt(int i) {
  // Convert i to string str
  char str[12];
  sprintf(str, "%d", i);
  // Set BigInt using from_string with str
  from_string(str);
}

BigInt::BigInt(const BigInt &bi) {
  // Get BigInt bi as string str
  char* str = new char [bi.getLength()];
  bi.to_string(str);
  // Set BigInto using from_string with str
  from_string(str);
  delete [] str;
}

BigInt::~BigInt(); // Since nothing is dynamically allocated when construction, no need for a destructor

bool BigInt::from_string(const char *str) {
  // Copy str to string s
  std::string s = str;

  // Set the sign according to whether s begins with '-' or not
  if (s[0] == '-') {
    sign = '-';
    s = s.substr(1);
  }
  else {
    sign = '+';
  }
  
  // Pad the remaining string with 0's to ensure it's divisible by 2
  if (s.length() % 2) {
    s.insert(0, "0");
  }

  // Iterativly push back the last 2 digits to the vector
  for (unsigned int i = 0; i < s.length()/2; ++i) {
    std::string substr = s.substr(i * 2, 2);
    abs_value.push_back(atoi(substr.c_str()));
  }

  return true;
}

// const overloaded version of the function to_string
void BigInt::to_string(char *str) const {
  std::string s = "";

  // If number is negative, add '-' to front of string  
  if (sign == '-') {
    s.append("-");
  }

  // Iterativly copy the digits into the string
  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }

  // Copy string to char array
  std::strcpy(str, s.c_str());
}

void BigInt::to_string(char *str) {
  std::string s = "";

  // If number is negative, add '-' to front of string    
  if (sign == '-') {
    s.append("-");
  }

  // Iterativly copy the digits into the string
  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }

  // Copy string to char array
  std::strcpy(str, s.c_str());
}

void BigInt::print(){
  // Get string using to_string
  char* str = new char [getLength()];
  to_string(str);

  std::cout << str << std::endl; // Print to std::cout
  delete [] str; // Cleanup
}


unsigned int BigInt::getSize() const { // Get number of elements in the vector
  return abs_value.size();
}

unsigned int BigInt::getLength() const { // Get length of string of the BigInt
  if (sign == '-') {
    return getSize()*2+2; // +2, 1 for null termination, 1 for sign
  }
  else {
    return getSize()*2+1; // +1, 1 for null termination
  }
}

void BigInt::normalize() { // Normalize the BigInt
  for (uint i = (getSize()-1); i > 0; --i) {
    while(abs_value[i] > 100) { // Normalize i'th element
      abs_value[i] -= 100;
      ++abs_value[i-1];
    }
  }
  
  if (abs_value[0] > 100) {
    abs_value.insert(abs_value.begin(), (unsigned short)0); // Insert element at beginning to receive overflow
    while (abs_value[1] > 100) { // Normalize first element
      abs_value[1] -= 100;
      ++abs_value[0];
    }
  }
}
