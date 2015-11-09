#include <cmath>
#include <cfloat>
#include "tri_func.h"

#define ANGLE90  90.00 * M_PI / 180.00

using namespace std;


/////////
// sine
/////////

SinFunc::SinFunc(double _scale):
Func("sin", true), scale(_scale) { }

double SinFunc::EvaluateAt(double d) const {
	return scale * sin(d);
}

double SinFunc::DerivativeAt(double d) const {
	return scale * cos(d);
}

void SinFunc::Print(ostream& os, double x) const {
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

SinFunc* CreateSinFunc(ostream& os, istream& is) {
	os << "scale? ";
	double scale;
	is >> scale;
	return new SinFunc(scale);
}

///////////
// cosine
///////////

CosFunc::CosFunc(double _scale):
SinFunc(_scale) { }

double CosFunc::EvaluateAt(double d) const {
	//implement it
}

double CosFunc::DerivativeAt(double d) const {
	//implement it
}

void CosFunc::Print(ostream& os, double x) const {
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

CosFunc* CreateCosFunc(ostream& os, istream& is) {
	os << "scale? ";
	double scale;
	is >> scale;
	return new CosFunc(scale);
}

