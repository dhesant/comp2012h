#include <cmath>
#include <cfloat>
#include "poly_func.h"

#define MAX_NUM_OF_TERMS 1024

PolyFunc::PolyFunc(const double* array, int size)
: Func("poly", false) {
	num_of_terms = size;
	terms = new double[size];

	// copy from array to terms
	for (int i = 0; i < size; i++) {
		terms[i] = array[i];
	}
}

PolyFunc::~PolyFunc() {
	delete[] terms;
}

double PolyFunc::EvaluateAt(double x) const {
	// P(x) = a[0] x^(s-1) + a[1] x^(s-2) + ... + a[s-2] x + a[s-1]
	double d = 0.00;
	for (int i = 0; i < num_of_terms; i++) {
		// use pow() from math library
		d += (terms[i] * pow(x, (num_of_terms - 1 - i)));
	}
	return d;
}

double PolyFunc::DerivativeAt(double x) const {
	double d = 0.00;
	for (int i = 0; i < num_of_terms - 1; i++) {
		int deg = num_of_terms - 1 - i;
		d += (terms[i] * deg * pow(x, (deg - 1)));
	}
	return d;
}

void PolyFunc::Print(ostream& os, double x) const {
	const char* const T = "true";
	const char* const F = "false";

	os << "name = " << GetName() << endl
		<< "is periodic = " << (IsPeriodic()? T: F) << endl
		<< "value at " << x << " = ";
		if(fabs(EvaluateAt(x)-DBL_MAX)<0.000001)
            os << F<<endl;
        else
            os << EvaluateAt(x) << endl;
	os << "is differentiable at " << x << " = "
		<< (IsDifferentiable(x)? T: F) << endl;

	if (IsDifferentiable(x)) {
		os << "derivative at " << x << " = " << DerivativeAt(x) << endl;
	}
}

PolyFunc* CreatePolyFunc(ostream& os, istream& is) {
	os << "number of terms: " << endl << "> ";
	int n = 0;
	is >> n;
	if (n < 0) { return NULL; }

	double terms[MAX_NUM_OF_TERMS];
	os << "terms? (separate each term with a space)" << endl;
	for (int i = 0; i < n; ++i) {
		is >> terms[i];
	}

	return new PolyFunc(terms, n);
}
