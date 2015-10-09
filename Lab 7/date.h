// COMP152 Lab
class Date {
public:
  Date(int day, int month, int year);
  Date();

  void set(int d, int m, int y);
  void print();

private:
  int day;
  int month;
  int year;
};
