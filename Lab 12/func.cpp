#include "func.h"
#include <cfloat>
#include <cmath>
Func::Func(string _name, bool _isPeriodic):
name(_name), isPeriodic(_isPeriodic) { };

string Func::GetName() const {
	return name;
}

bool Func::IsDifferentiable(double d) const {
	// assume all functions are differentiable
	return true;
}

bool Func::IsPeriodic() const {
	return isPeriodic;
}


