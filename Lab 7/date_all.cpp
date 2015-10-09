// COMP152 Lab

#include <iostream>
using namespace std;

class Date {
public:
  Date(int day, int month, int year);
  Date();

private:
  int day;
  int month;
  int year;
};

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
