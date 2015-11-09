#include <cfloat>
#include "impulse_func.h"

#define EQUALITY_LIMIT 0.001

ImpulseFunc::ImpulseFunc(double _impulseAt, double _magnitude)
: Func("impulse", false), impulseAt(_impulseAt), magnitude(_magnitude)
{
}

bool ImpulseFunc::IsDifferentiable(double d) const {
	// not differentiable at the impulse
	double diff = DiffToImpulse(d);
	return diff >= EQUALITY_LIMIT;
}

double ImpulseFunc::EvaluateAt(double d) const {
	double diff = DiffToImpulse(d);
	return diff < EQUALITY_LIMIT? magnitude: 0.00;
}

double ImpulseFunc::DerivativeAt(double d) const {
	return IsDifferentiable(d)? 0.00: DBL_MAX;
}

double ImpulseFunc::DiffToImpulse(double d) const {
	double diff = d - impulseAt;
	if (diff < 0.00) { diff *= -1.00; }
	return diff;
}

void ImpulseFunc::Print(ostream& os, double x) const {
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

ImpulseFunc* CreateImpulseFunc(ostream& os, istream& is) {
	os << "impulse and magnitude? (separate them with a space)" << endl;
	os << "> ";

	double i, m;
	ImpulseFunc* impulse = NULL;
	if ((is >> i) && (is >> m)) {
		impulse = new ImpulseFunc(i, m);
	}

	return impulse;
}
