// COMP152 Lab

#include <iostream>
#include "date.h"
using namespace std;

Date::Date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
};

Date::Date() {
};

void Date::set(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

void Date::print() {
  cout << day << "/" << month << "/" << year << endl;
}
