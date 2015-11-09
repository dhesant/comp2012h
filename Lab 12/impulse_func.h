#include "func.h"
#include <cmath>
#ifndef _IMPULSE_FUNC_H
#define _IMPULSE_FUNC_H

/**
 * A class derived from Func to implement impulse function.
 */
class ImpulseFunc: public Func {
public:
	/**
	 * To create an impulse function.
	 */
	ImpulseFunc(double _impulseAt, // x-coordinate of the impulse
		double _magnitude // y-coordinate of the impulse
		);

	/**
	 * Check whether the function is differentiable at d.
	 * Impulse function is differentiable except at the impulse
	 * return If differentiable return TRUE, else return FALSE.
	 */
	bool IsDifferentiable(double d // value in the domain
		) const;

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
	/**
	 * Calculate the difference between the impulse and d.
	 * return  the absolute value of the difference
	 */
	double DiffToImpulse(double d // value in the domain
		) const;

	const double impulseAt; // x-coordinate of the impulse
	const double magnitude; // y-coordinate of the impulse
};

/**
* To create an ImpulseFunc object dynamically from user input.
* return pointer to the newly created ImpulseFunc object
*/
ImpulseFunc* CreateImpulseFunc(ostream& os, istream& is);

#endif //_IMPULSE_FUNC_H
