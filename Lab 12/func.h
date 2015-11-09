#include <iostream>
#include <string>

using namespace std;

#ifndef _FUNC_H
#define _FUNC_H

/**
 * The base class of all function classes.
 */
class Func {
public:
	/**
	 * To create a Func object
	 */
	Func(string _name, // the function name
		bool _isPeriodic // the boolean value to indicate whether the function is periodic
		);

	/**
	 * It will release all dynamically allocated memory used by this object.
	 */
	virtual ~Func() { }

	/**
	 * Get the function name.
	 * return name of the function
	 */
	string GetName() const;

	/**
	 * Check whether the function is differentiable at d.
	 * return if differentiable return TRUE, else return FALSE.
	 */
	bool IsDifferentiable(double d // value in the domain
		) const;

	/**
	 * Check whether the function is periodic.
	 * return if the function is periodic return TRUE, else return FALSE.
	 */
	bool IsPeriodic() const;

	/**
	 * Evaluate the function at d.
	 * return a function value
	 */
	virtual double EvaluateAt(double d // value in the domain
		) const = 0;

	/**
	 * Calculate the derivative value of a function at d.
	 * return a derivative value
	 */
	virtual double DerivativeAt(double d // value in the domain
		) const = 0;

	/**
	 *  Print the function properties to the output stream os at x.
	 *	name = sin
	 *	is periodic = true
	 *	value at 0 = 0
	 *	is differentiable at 0 = true
	 *	derivative at 0 = 10
	 */
	virtual void Print(ostream& os, // output stream
		double x // value in the domain
		) const = 0;

private:
	const string name; // The function name
	const bool isPeriodic; // The boolean value to indicate whether the function is periodic
};

#endif //_FUNC_H
