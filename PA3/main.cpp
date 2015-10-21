#include <cstdlib>
#include <iostream>
#include "Matrix.h"

int main() {
  Matrix matrix(3,3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix.setel(i, j, (i+1)*(j+1));
    }
  }

  std::cout << "Matrix: " << std::endl;

  matrix.print();
  
  Matrix trans = matrix.transpose();
  
  std::cout << "Transpose: " << std::endl;

  trans.print();
}
