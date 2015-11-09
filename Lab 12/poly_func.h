#include "func.h"

#ifndef _POLY_FUNC_H
#define _POLY_FUNC_H

/**
 * A class derived from Func to implement polynomial function.
 */
class PolyFunc: public Func {
public:
	/**
	 * To create a polynomial from an integer array.
	 * P(x) = a[0] x^(s-1) + a[1] x^(s-2) + ... + a[s-2] x + a[s-1]
	 * a is an integer array, s is the size of a.
	 */
	PolyFunc(const double* array, int size);

	/**
	 * It will release all dynamically allocated memory used by this object.
	 */
	virtual ~PolyFunc();


	/**
	 * Evaluate the function at d.
	 * return a function value
	 */
	double EvaluateAt(double d // value in the domain
		) const;
	/**
	 * Calculate the derivative value of a function at d.
	 * return a derivative value
	 */
	double DerivativeAt(double d // value in the domain
		) const;

    /**
	 *  Print the function properties to the output stream os at x.
	 *	name = sin
	 *	is periodic = true
	 *	value at 0 = 0
	 *	is differentiable at 0 = true
	 *	derivative at 0 = 10
	 */
	void Print(ostream& os, // output stream
		double x // value in the domain
		) const;

private:
	double* terms; // An array of integer terms for the coefficients
	int num_of_terms; // Number of coefficients
};

/**
* To create a PolyFunc object dynamically from user input.
* return pointer to the newly created PolyFunc object
*/
PolyFunc* CreatePolyFunc(ostream& os , istream& is);

#endif //_POLY_FUNC_H
