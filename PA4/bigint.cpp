/**************/
/* bigint.cpp */
/**************/

#include "bigint.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

/*****************************/
/* Constructor & Destructors */
/****************************/

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
  sign = bi.sign;
  abs_value = bi.abs_value;
}

BigInt::~BigInt() { // Since nothing is dynamically allocated when construction, no need for a destructor
}

/*************/
/* Functions */
/************/

bool BigInt::from_string(const char *str) {
  // Copy str to string s
  std::string s = str;

  char oldsign = sign; // save old sign value to restore in case of invalid input

  // Set the sign according to whether s begins with '-', '+' or none
  if (s[0] == '-') {
    sign = '-';
    s = s.substr(1);
  }
  else if (s[0] == '+') {
    sign = '+';
    s = s.substr(1);
  }
  else {
    sign = '+';
  }

  // Ensure input is valid
  if (s.find_first_not_of("0123456789+-") != std::string::npos) {
    sign = oldsign; // restore original sign value on error
    return false;
  }

  // Pad the remaining string with 0's to ensure it has an even length
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

  // Iterativly copy the digits into the string
  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }

  // Remove leading zeros if one exists
  if (s[0] == '0') {
    s.erase(0, 1);
  }

  // If number is negative, add '-' to front of string    
  if (sign == '-') {
    s.insert(0, "-");
  }


  // Copy string to char array
  std::strcpy(str, s.c_str());
}

void BigInt::to_string(char *str) {
  std::string s = "";

  // Iterativly copy the digits into the string
  for (std::vector<unsigned short>::const_iterator it = abs_value.begin(); it != abs_value.end(); ++it) {
    char str[2];
    sprintf(str, "%02d", *it);
    s.append(str);
  }
  
  // Remove leading zeros if one exists
  if (s[0] == '0') {
    s.erase(0, 1);
  }

  // If number is negative, add '-' to front of string    
  if (sign == '-') {
    s.insert(0, "-");
  }

  // Copy string to char array
  std::strcpy(str, s.c_str());
}

void BigInt::print() const {
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

// Fix: normalize for negative values as well (careful, unsigned short)
void BigInt::normalize() { // Normalize the BigInt
  for (uint i = (getSize()-1); i > 0; --i) {
    while(abs_value[i] > 32768) { // Check for negative overflow (uint overflow)
      abs_value[i] += 100;
      abs_value[i-1]--;
    }
    while(abs_value[i] >= 100) { // Check for positive overflow
      abs_value[i] -= 100;
      abs_value[i-1]++;
    }
  }

  while (abs_value[0] == 0 && getSize() > 1) {
    abs_value.erase(abs_value.begin());
  }

  if (abs_value[0] == 65535) {
    flipSign();
    abs_value[0] = 1;
  }      

  if (abs_value[0] >= 100) {
    abs_value.insert(abs_value.begin(), (unsigned short)0); // Insert element at beginning to receive overflow
    while (abs_value[1] >= 100) { // Normalize first element
      abs_value[1] -= 100;
      abs_value[0]++;
    }
  }
}

void BigInt::flipSign() {
  if (sign == '+') {
    sign = '-';
  }
  else {
    sign = '+';
  }
}

bool BigInt::isNegative() const {
  return (sign == '-');
}

bool BigInt::isZero() const {
  return (abs_value[0] == 0 && getSize() == 1);
}

void BigInt::increment() {
  if (isNegative()) {
    abs_value[getSize()-1]--;
  }
  else { 
    abs_value[getSize()-1]++;
  }
  normalize();
}

void BigInt::decrement() {
  if (isNegative()) {
    abs_value[getSize()-1]++;
  }
  else { 
    abs_value[getSize()-1]--;
  }
  normalize();

}

const BigInt& BigInt::operator=(const BigInt &in) {
  if (this == &in) {
    return *this;
  }
  sign = in.sign;
  abs_value = in.abs_value;
  return *this;
}

const BigInt BigInt::operator++(int) {
  BigInt temp(*this);
  increment();
  return temp;
}

const BigInt& BigInt::operator++() {
  increment();
  return *this;
}


const BigInt BigInt::operator--(int) {
  BigInt temp(*this);
  decrement();
  return temp;
}

const BigInt& BigInt::operator--() {
  decrement();
  return *this;
}

const BigInt& BigInt::operator+=(const BigInt &in) {
  BigInt temp(in);
  while (!temp.isZero()) {
    if (temp.isNegative()) {
      decrement();
      temp++;
    }
    else {
      increment();
      temp--;
    }
  }
  return *this;
}

const BigInt& BigInt::operator-=(const BigInt &in) {
  BigInt temp(in);
  while (!temp.isZero()) {
    if (temp.isNegative()) {
      increment();
      temp++;
    }
    else {
      decrement();
      temp--;
    }
  }
  return *this;
}

const BigInt& BigInt::operator*=(const BigInt &in) {
  BigInt counter;
  BigInt result;
  if (in.isNegative()) {
    while (counter > in) {
      result -= (*this);
      counter--;
    }
  }
  else {
    while (counter < in) {
      result += (*this);
      counter++;
    }
  }
  (*this) = result;
  return *this;
}

const BigInt& BigInt::operator/=(const BigInt &in) {
  BigInt counter;
  if (isNegative()) {
    while ((*this) < in) {
      (*this) -= in;
      counter--;
    }
  }
  else {
    while ((*this) > in) {
      (*this) += in;
      counter++;
    }
  }
  (*this) = counter;
  return *this;
}

const BigInt& BigInt::operator%=(const BigInt &in) {
  BigInt divisor = (*this) / in;
  divisor.print();
  BigInt quotient = divisor * in;
  quotient.print();
  (*this) -= quotient;
  this->print();
  return *this;
}

const BigInt operator+(const BigInt &in1, const BigInt &in2) {
  BigInt out(in1);
  out += in2;
  return out;
}

const BigInt operator-(const BigInt &in1, const BigInt &in2) {
  BigInt out(in1);
  out -= in2;
  return out;
}

const BigInt operator*(const BigInt &in1, const BigInt &in2) {
  BigInt out(in1);
  out *= in2;
  return out;
}

const BigInt operator/(const BigInt &in1, const BigInt &in2) {
  BigInt out(in1);
  out /= in2;
  return out;
}

const BigInt operator%(const BigInt &in1, const BigInt &in2) {
  BigInt out(in1);
  out %= in2;
  return out;
}

const bool operator==(const BigInt &in1, const BigInt &in2) {
  BigInt temp(in1);
  temp -= in2;
  return (temp.isZero());
}

const bool operator!=(const BigInt &in1, const BigInt &in2) {
  return (!(in1 == in2));
}

const bool operator>(const BigInt &in1, const BigInt &in2) {
  BigInt temp(in1);
  temp -= in2;
  return (!(temp.isNegative()));
}

const bool operator>=(const BigInt &in1, const BigInt &in2) {
  return (in1 > in2 || in1 == in2);
}

const bool operator<(const BigInt &in1, const BigInt &in2) {
  BigInt temp(in1);
  temp -= in2;
  return (temp.isNegative());
}

const bool operator<=(const BigInt &in1, const BigInt &in2) {
  return (in1 < in2 || in1 == in2);
}
