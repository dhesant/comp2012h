#include "bigint.h"

#include <iostream>


int main() {
  BigInt bi1("1234");
  BigInt bi2(5678);
  BigInt bi3("-9123");
  BigInt bi4(-4567);
  BigInt bi5(bi1);

  bi1.print();
  bi2.print();
  bi3.print();
  bi4.print();
  bi5.print();

  return 0;
}
