#include <cstdlib>
#include <iostream>
#include "Matrix.h"

double lookup[10] = { 0, 1, 2, 3, 0, 4, 5, 1, 0, 6};
double lookup2x3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
double lookup2x2[5] = {0, 9, 8, 7, 6};

int main() {
  Matrix m3x3(3,3);
  Matrix m2x3(2,3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      m3x3.el(i, j) = lookup[(j+1)+(3*i)];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      m2x3.el(i, j) = lookup2x3[(j+1)+(2*i)];
    }
  }

  std::cout << "Matrix 1: " << std::endl;
  m3x3.print();
  
  std::cout << "Matrix 2: " << std::endl;
  m2x3.print();
 
  m3x3.assign(m2x3);

  std::cout << "Matrix: " << std::endl;
  m3x3.print();
  

  std::cout << "Det: " << m3x3.det() << std::endl;

  Matrix trans = m3x3.transpose();
  std::cout << "Transpose: " << std::endl;
  trans.print();

  Matrix cofactor = m3x3.cofactor();
  std::cout << "Cofactor: " << std::endl;
  cofactor.print();

  Matrix inverse = m3x3.inverse();
  std::cout << "Inverse: " << std::endl;;
  inverse.print();

  Matrix i = m3x3.mul(inverse);
  std::cout << "I: " << std::endl;
  i.print();

  i.setIdentity();
  std::cout << "I (generated): " << std::endl;
  i.print();

  Matrix m2x2(2,2);
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m2x2.el(i, j) = lookup2x2[(j+1)+(2*i)];
    }
  }

  std::cout << "M(2x2): " << std::endl;
  m2x2.print();
  
  m2x2.assign(m3x3);
  std::cout << "M(2x2): " << std::endl;
  m2x2.print();
  
}
