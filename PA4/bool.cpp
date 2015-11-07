#include <iostream>
#include "bigint.h"

// Test boolean operations
int main() {
  BigInt b20(20);
  BigInt b202(20);
  BigInt b25(25);
  BigInt b15(15);

  std::cout << (b20 == b202) << std::endl;
  std::cout << (b20 != b202) << std::endl;
  std::cout << (b20 <= b202) << std::endl;
  std::cout << (b20 >= b202) << std::endl;
  std::cout << (b20 < b202) << std::endl;
  std::cout << (b20 > b202) << std::endl;
  std::cout << std::endl;

  std::cout << (b20 == b25) << std::endl;
  std::cout << (b20 != b25) << std::endl;
  std::cout << (b20 <= b25) << std::endl;
  std::cout << (b20 >= b25) << std::endl;
  std::cout << (b20 < b25) << std::endl;
  std::cout << (b20 > b25) << std::endl;
  std::cout << std::endl;

  std::cout << (b20 == b15) << std::endl;
  std::cout << (b20 != b15) << std::endl;
  std::cout << (b20 <= b15) << std::endl;
  std::cout << (b20 >= b15) << std::endl;
  std::cout << (b20 < b15) << std::endl;
  std::cout << (b20 > b15) << std::endl;
  std::cout << std::endl;

  BigInt bn20(-20);
  BigInt bn202(-20);
  BigInt bn25(-25);
  BigInt bn15(-15);

  std::cout << (bn20 == bn202) << std::endl;
  std::cout << (bn20 != bn202) << std::endl;
  std::cout << (bn20 <= bn202) << std::endl;
  std::cout << (bn20 >= bn202) << std::endl;
  std::cout << (bn20 < bn202) << std::endl;
  std::cout << (bn20 > bn202) << std::endl;
  std::cout << std::endl;

  std::cout << (bn20 == bn25) << std::endl;
  std::cout << (bn20 != bn25) << std::endl;
  std::cout << (bn20 <= bn25) << std::endl;
  std::cout << (bn20 >= bn25) << std::endl;
  std::cout << (bn20 < bn25) << std::endl;
  std::cout << (bn20 > bn25) << std::endl;
  std::cout << std::endl;

  std::cout << (bn20 == bn15) << std::endl;
  std::cout << (bn20 != bn15) << std::endl;
  std::cout << (bn20 <= bn15) << std::endl;
  std::cout << (bn20 >= bn15) << std::endl;
  std::cout << (bn20 < bn15) << std::endl;
  std::cout << (bn20 > bn15) << std::endl;
  std::cout << std::endl;
}
