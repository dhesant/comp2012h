// Constructor: Initialize the matrix to be a rows x cols matrix.
// rows >= 0; cols >= 0
// default is an empty 0 x 0 matrix
// No need to initialize matrix elements
Matrix::Matrix(int rows, int cols) {
  r = rows;
  c = cols;
  elm == new double*[r];
  for (int i = 0, i < r, ++i) {
    elm[i] = new double[c];
  }
}

// Copy constructor
Matrix::Matrix(const Matrix & mt) {
}

// Destructor for the matrix
Matrix::˜Matrix() {
  for (int i = 0, i < r, ++i) {
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
}

// Return a new matrix which is the product of
// this matrix and matrix op.
// Precondition: valid multiplication with correct rows and columns
Matrix Matrix::mul(const Matrix & op) const {
}

// Return a new matrix which is the transpose of the matrix.
Matrix Matrix::transpose() const {
}

// Return a new matrix which is the inverse of the matrix.
// Return a zero matrix if inverse does not exist
Matrix Matrix::inverse() const {
}
