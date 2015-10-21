#include "Matrix.h"
#include <iostream>

// Constructor: Initialize the matrix to be a rows x cols matrix.
// rows >= 0; cols >= 0
// default is an empty 0 x 0 matrix
// No need to initialize matrix elements
Matrix::Matrix(int rows, int cols) {
  r = rows;
  c = cols;
  elm = new double*[r];
  for (int i = 0; i < r; ++i) {
    elm[i] = new double[c];
  }
}

// Copy constructor
Matrix::Matrix(const Matrix & mt) {
  r = mt.rows();
  c = mt.cols();

  elm = new double*[r];
  for (int i = 0; i < r; ++i) {
    elm[i] = new double[c];
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      elm[i][j] = mt.el(i, j);
    }
  }
}

// Destructor for the matrix
Matrix::~Matrix() {
  for (int i = 0; i < r; ++i) {
    delete [] elm [i];
  }
  delete [] elm;
}

// Return the number of rows of the matrix
int Matrix::rows() const {
  return r;
}

// Return the number of columns of the matrix
int Matrix::cols() const {
  return c;
}

// Return the (i, j)th element of the matrix
// Precondition: i and j are valid ranges
double & Matrix::el(int i, int j) const {
  return elm[i][j];
}

// Assign and copy all the elements of matrix op to the matrix.
// Resize matrix (allocate space) if necessary
void Matrix::assign(const Matrix & op) {
  if (op.rows() > r || op.cols() > c) {
    // TODO: Resize matrix
  }
  for (int i = 0; i < op.rows(); ++i) {
    for (int j = 0; j < op.cols(); ++j) {
      elm[i][j] = op.el(i,j);
    }
  }
}

// Return a new matrix which is the product of
// this matrix and matrix op.
// Precondition: valid multiplication with correct rows and columns
Matrix Matrix::mul(const Matrix & op) const {
  if (c == op.rows()) {
    int mr = r; // Load matrix parameters into easy to understand variables
    int mp = c;
    int mc = op.cols();

    Matrix m(r, op.cols());
    for (int i = 0; i < mr; ++i) {
      for (int j = 0; j < mc; ++j) {
	for (int k = 0; k < mp; ++k) {
	  m.setel(i, j, el(i, k)*op.el(k, j));
	}
      }
    }
    return m;
  }
  else {
    Matrix n(0,0);
    return n;
  }
}

// Return a new matrix which is the transpose of the matrix.
Matrix Matrix::transpose() const {
  Matrix trans(c, r);
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < r; ++j) {
      trans.setel(i, j, el(j, i));
    }
  }
  return trans;
}

// Return a new matrix which is the inverse of the matrix.
// Return a zero matrix if inverse does not exist
Matrix Matrix::inverse() const {
  if (det() != 0) { // Check if inverse
    
  }
  Matrix n(0,0);
  return n;
}

double Matrix::det() const {
  if (r != c) {
    return 0;
  }
  
  if (r == 1) {
    return elm[0][0];
  }

  double det = 0;

  for (int i = 0; i < r; i++) {
    Matrix minor = getMinor(0, i);
    //    minor.print();
    if (i % 2 == 0) {
      det += el(0, i) * minor.det();
    }
    else {
      det -= el(0, i) * minor.det();
    }
    //    std::cout << "Debug: " << det << std::endl;
  }
  return det;
}

Matrix Matrix::getMinor(const int & minor_r, const int & minor_c) const {
  Matrix minor(r-1, c-1);

  int rowCount = 0;
  int colCount = 0;

  for (int i = 0; i < r; i++) {
    if (i != minor_r) {
      colCount = 0;
      for (int j = 0; j < c; j++) {
	if (j != minor_c) {
	  //	  std::cout << "Debug: " << i << "," << j << "," << rowCount << "," << colCount << "," << el(i,j) << std::endl;
	  minor.setel(rowCount, colCount, el(i, j));
	  colCount++;
	}
      }
      rowCount++;
    }
  }
  return minor;
}

void Matrix::setel(int i, int j, const double & val) {
  elm[i][j] = val;
}

void Matrix::print() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << el(i, j) << " ";
    }
    std::cout << std::endl;
  }
}
