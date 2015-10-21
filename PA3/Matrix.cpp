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
    int newr = (op.rows() > r ? op.rows() : r);
    int newc = (op.cols() > c ? op.cols() : c);
  
    double** newelm = new double*[newr]; // Create new double array
    for (int i = 0; i < newr; ++i) {
      newelm[i] = new double[newc];
    }

    for (int i = 0; i < r; ++i) { // Populate new pointer array with old values
      for (int j = 0; j < c; ++j) {
	newelm[i][j] = el(i, j);
      }
    }

    r = newr; // Reassign existing values
    c = newc;
    delete [] elm;
    elm = newelm;
  }    

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

  int mr = r; // Load matrix parameters into easy to understand variables
  int mp = c;
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
  if ( r != c) {
    Matrix n(0,0);
    return n;
  }
  
  Matrix cf(r, r);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int factor = (((j+1) + i*r)%2==0?-1:1);
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

void Matrix::print() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cout << el(i, j) << " ";
    }
    std::cout << std::endl;
  }
}

void Matrix::setIdentity() {
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

void Matrix::setel(int i, int j, const double & val) {
  elm[i][j] = val;
}
