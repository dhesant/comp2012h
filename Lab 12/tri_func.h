#include "func.h"

#ifndef _TRI_FUNC_H
#define _TRI_FUNC_H

/**
 * A class derived from Func to implement sine function.
 */
class SinFunc: public Func {
public:
	/**
	 * To create a sine function.
	 */
	SinFunc(double _scale = 1.00 // scale of sine function
		);
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
	double scale; // Scale of the sine function
};

/**
* To create a SinFunc object dynamically from user input.
* return pointer to the newly created SinFunc object
*/
SinFunc* CreateSinFunc(ostream& os, istream& is);

/**
 * A class derived from Func to implement cosine function.
 */
class CosFunc: public SinFunc {
public:
	/**
	 * To create a cosine function
	 */
	CosFunc(double _scale = 1.00 //!< scale of cosine function
		);
	/**
	 * Evaluate the function at d.
	 * return a function value
	 */
	virtual double EvaluateAt(double d //!< value in the domain
		) const;
	/**
	 * Calculate the derivative value of a function at d.
	 * return a derivative value
	 */
	virtual double DerivativeAt(double d // value in the domain
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

};
/**
* To create a CosFunc object dynamically from user input.
* return pointer to the newly created CosFunc object
*/
CosFunc* CreateCosFunc(ostream& os, istream& is);

#endif //_TRI_FUNC_H
