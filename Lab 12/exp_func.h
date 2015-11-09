#include "func.h"

#ifndef _EXP_FUNC_H
#define _EXP_FUNC_H

/**
 * A class derived from Func to implement exponential function.
 */
class ExpFunc: public Func {
public:
	/**
	 * To create an exponential function.
	 * f(x) = scale * exp ^ (exp_scale * x)
	 */
	ExpFunc(double _scale = 1.00,  // scale of exponential function
		double _exp_scale = 1.00 // scale of the exponent
		);

	/**
	 * to override ... from Func
	 */
	bool IsDifferentiable(double d // value in the domain
		) const;

	double EvaluateAt(double d // value in the domain
		) const;

	double DerivativeAt(double d // value in the domain
		) const;

    void Print(ostream& os, // output stream
		double x // value in the domain
		) const;


private:
	double scale;  // scale of exponential function
	double exp_scale; // scale of the exponent
};

/**
* To create an ExpFunc object dynamically from user input.
* return pointer to the newly created ExpFunc object
* complete this function
*/
ExpFunc* CreateExpFunc(ostream& os, istream& is);

#endif //_EXP_FUNC_H
