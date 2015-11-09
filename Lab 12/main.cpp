#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "func.h"
#include "tri_func.h"
#include "poly_func.h"
#include "impulse_func.h"
#include "exp_func.h"

void printLine(ostream& os) {
	os << "-----------------------------------------------" << endl;
}

int main() {

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	while (true) {
		// get the function name from user input
		fout << "Enter your function name (sin/cos/poly/impulse/exp): " << endl << "> ";
		string fname;
		fin >> fname;

		Func* func = NULL;

		////////////////////////////////////////////////////
		// block A:
		//
		// create an Func object dynamically
		// the actual type of the object depends on the user input
		if (fname == "sin") {
			func = CreateSinFunc(fout, fin);
		} else if (fname == "cos") {
			func = CreateCosFunc(fout, fin);
		} else if (fname == "poly") {
			func = CreatePolyFunc(fout, fin);
		} else if (fname == "impulse") {
			func = CreateImpulseFunc(fout, fin);
		} else if (fname == "exp") {
			func = CreateExpFunc(fout, fin);
		}
/*		else if (fname=="tan") {
		    func = CreateTanFunc(fout, fin);
		}
*/		 else {
			break;
		}
		// end-of block A
		////////////////////////////////////////////////////

		////////////////////////////////////////////////////
		// block B:
		//
		// this block of code is independent
		// to the actual type of func points to,
		// what we know is the type of that object
		// must be derived from Func
		if (func != NULL) {
			// print
			fout << "calculate at? ";
			
			//complete it here. 
			
			// release the func object
			delete func;
		}
		// end-of block B
		////////////////////////////////////////////////////
	};

	fout.close();
	fin.close();

	return 0;
};
