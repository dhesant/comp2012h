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
  // Resize matrix if necessary.
  if (op.rows() > r || op.cols() > c) {
    // Get new matrix dimensions
    int newr = (op.rows() > r ? op.rows() : r);
    int newc = (op.cols() > c ? op.cols() : c);
  
    // Create new 2D array
    double** newelm = new double*[newr];
    for (int i = 0; i < newr; ++i) {
      newelm[i] = new double[newc];
    }

    // Fill new array with 0 for safety
    for (int i = 0; i < newr; ++i) {
      for (int j = 0; j < newc; ++j) {
	newelm[i][j] = 0;
      }
    }

    // Copy elements from old array to new array
    for (int i = 0; i < r; ++i) { 
      for (int j = 0; j < c; ++j) {
	newelm[i][j] = el(i, j);
      }
    }

    // Delete old array from memory
    for (int i = 0; i < r; ++i) {
      delete [] elm [i];
    }
    delete [] elm;

    // Reassign existing matrix parameters to new parameters
    r = newr; 
    c = newc;
    elm = newelm;
  }    

  // Copy elements to the matrix
  for (int i = 0; i < op.rows(); ++i) {
    for (int j = 0; j < op.cols(); ++j) {
      el(i, j) = op.el(i,j);
    }
  }
}

// Return a new matrix which is the product of
// this matrix and matrix op.
// Precondition: valid multiplication with correct rows and columns

// Incorrect formula
Matrix Matrix::mul(const Matrix & op) const {
  if (c != op.rows()) {
    Matrix n(0,0);
    return n;
  }

  // Define matrix dimensions in variables
  int mr = r;
  int mp = c; // = op.rows();
  int mc = op.cols();

  // Initialize output matrix to all 0
  Matrix m(mr, mc);
  for (int i = 0; i < mr; ++i) {
    for (int j = 0; j < mc; ++j) {
      m.el(i, j) = 0;
    }
  }

  for (int i = 0; i < mr; ++i) {
    for (int j = 0; j < mc; ++j) { // For each cell (i, j)
      for (int k = 0; k < mp; ++k) { // For each col in 1, and row in 2
	m.el(i, j) += el(i, k)*op.el(k, j);
      }
    }
  }
  return m;
}

// Return a new matrix which is the transpose of the matrix.
Matrix Matrix::transpose() const {
  Matrix trans(c, r);
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < r; ++j) {
      trans.el(i, j) = el(j, i);
    }
  }
  return trans;
}

// Return a new matrix which is the inverse of the matrix.
// Return a zero matrix if inverse does not exist
Matrix Matrix::inverse() const {
  double deter = det();

  if (deter == 0) {
    Matrix n(0,0);
    return n;
  }

  Matrix cf = cofactor();
  Matrix inv = cf.transpose();

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      inv.el(i, j) /= deter;
    }
  }
  return inv;
}

// Return a new matrix which is the cofactor matrix of the matrix.
// Return a zero matrix if the matrix is not square.
Matrix Matrix::cofactor() const {
  if (r != c) {
    Matrix n(0,0);
    return n;
  }
  
  Matrix cf(r, c);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int factor = ((j+1) + i*r)%2==0?-1:1;
      Matrix minor = getMinor(i, j);
      cf.el(i, j) = factor*minor.det();
    }
  }
  return cf;
}

// Return the determinant of the matrix.
// Returns 0 if the matrix is not square.
double Matrix::det() const {
  // Ensure matrix is square
  if (r != c) {
    return 0;
  }
  
  // Recursive end condition return (matrix is a 1x1 matrix)
  if (r == 1) {
    return elm[0][0];
  }

  double det = 0;

  for (int i = 0; i < r; i++) {
    Matrix minor = getMinor(0, i);
    if (i % 2 == 0) {
      det += el(0, i) * minor.det();
    }
    else {
      det -= el(0, i) * minor.det();
    }
  }
  return det;
}

// Return a new matrix that excludes the (minor_r)'th row, and the (minor_c)'th column,
Matrix Matrix::getMinor(const int & minor_r, const int & minor_c) const {
  // Return zero matrix if matrix is 1x1
  if (r < 2 && c < 2) {
    Matrix n(0,0);
    return n;
  }

  Matrix min(r-1, c-1);

  int rowCount = 0;
  int colCount = 0;

  for (int i = 0; i < r; i++) {
    if (i != minor_r) {
      colCount = 0;
      for (int j = 0; j < c; j++) {
	if (j != minor_c) {
	  min.el(rowCount, colCount) = el(i, j);
	  colCount++;
	}
      }
      rowCount++;
    }
  }
  return min;
}

// Print the matrix to std::cout
void Matrix::print() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << el(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

// Set the matrix to the identity matrix.
void Matrix::setIdentity() {
  // Ensure matrix is square
  if (r != c) {
    return;
  }

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i == j) {
	el(i, j) = 1;
      }
      else {
	el(i, j) = 0;
      }
    }
  }
}

// Solve matrix equation Ax=B, where A is the current matrix.
// Precondition: A must be a square matrix, and B must be a m x 1 matrix, where A is a m x n matrix.
Matrix Matrix::solveForX(const Matrix & b) const {
  // Ensure B is the correct size
  if (b.rows() != r && b.cols() != 1) {
    Matrix n(0,0);
    return n;
  }

  Matrix inva = inverse();
  Matrix x = inva.mul(b);

  return x;
}

void Matrix::setZero() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      el(i, j) = 0;
    }
  }
}
