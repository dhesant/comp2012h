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
  //TO DO: display the date of today

  Date deadline;
  //TO DO: set the date of assignment's deadline
  cout << "The deadline of this assessment is ";
  //TO DO: display the date of assignment's deadline

  return 0;
};
