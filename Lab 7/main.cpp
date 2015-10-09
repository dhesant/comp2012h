// COMP152 Lab

#include <iostream>
#include "date.h"
using namespace std;

int main() {
  int day, month, year;
  cout << "Enter today's date (day month year): ";
  cin >> day >> month >> year;
  Date today(day, month, year);

  cout << "Today is ";
  today.print();

  Date deadline;
  deadline.set(15, 10, 2015);

  cout << "The deadline of this assessment is ";
  deadline.print();

  return 0;
};
