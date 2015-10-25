#include <cstdlib>
#include <iostream>
#include "Matrix.h"

double lookup1[3][3] = {{1, 2, 3}, {0, 4, 5}, {1, 0, 6}};
double lookup2x4[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
double lookup4x2[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

double lookupa[3][4] = {{3, 2, -5},{1,-3,2},{5,-1,4}};
double lookupb[3] = {12,-13,10};

int main() {
  Matrix m2x4(2, 4);
  Matrix m4x2(4, 2);
  Matrix m4x4(4, 4);

  m4x4.setZero();
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      m2x4.el(i, j) = lookup2x4[i][j];
    }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      m4x2.el(i, j) = lookup4x2[i][j];
    }
  }

  // Test matrix assignment w/o resizing
  std::cout << "Matrix:\n";
  m4x4.print();
  
  std::cout << "Matrix 1:\n";
  m4x2.print();

  m4x4.assign(m4x2);
  std::cout << "Matrix:\n";
  m4x4.print();
  
  std::cout << "Matrix 2:\n";
  m2x4.print();
 
  m4x4.assign(m2x4);
  std::cout << "Matrix:\n";
  m4x4.print();

  std::cout << std::endl;  

  // Test matrix copy constructor
  Matrix mCopy(m4x4);
  
  std::cout << "Copy Matrix:\n";
  mCopy.print();

  std::cout << std::endl;

  // Test matrix transpose, cofactor, inverse.
  Matrix m(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      m.el(i, j) = lookup1[i][j];
    }
  }
  
  std::cout << "Matrix:\n";
  m.print();
  
  std::cout << "Det: " << m.det() << std::endl;

  Matrix trans = m.transpose();
  std::cout << "Transpose:\n";
  trans.print();

  Matrix cofactor = m.cofactor();
  std::cout << "Cofactor:\n";
  cofactor.print();

  Matrix inverse = m.inverse();
  std::cout << "Inverse:\n";;
  inverse.print();

  // Verify inverse is valid by the equation A^-1 A = I
  Matrix i = m.mul(inverse);
  std::cout << "I:\n";
  i.print();

  // Set I to identity with function setIdentity()
  i.setIdentity();
  std::cout << "I (generated):\n";
  i.print();

  std::cout << std::endl;

  // Test assignment with resizing
  Matrix m2x2(2,2);
  
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      m2x2.el(i, j) = lookup4x2[i][j];
    }
  }

  std::cout << "M(2x2):\n";
  m2x2.print();
  
  m2x2.assign(m);
  std::cout << "M(2x2):\n";
  m2x2.print();

  std::cout << std::endl;

  // Test solveForX
  Matrix a(3, 3);
  Matrix b(3, 1);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a.el(i, j) = lookupa[i][j];
    }
  }

  for (int i = 0; i < 3; ++i) {
      b.el(i, 0) = lookupb[i];
  }

  Matrix x = a.solveForX(b);

  std::cout << "A:\n";
  a.print();
  std::cout << "B:\n";
  b.print();
  std::cout << "X:\n";
  x.print();
}
