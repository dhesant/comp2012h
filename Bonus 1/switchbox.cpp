#include "Stack.h"
#include <iostream>
using namespace std;

/// CheckBox: Determine whether the switch box is routable
bool CheckBox(int pins[], int n) {

	// TODO: Returen true if it is routable, false otherwise
	// Hint: Use Stack to implement this part


}

int main() {
	int *pins, n;

	cout << "** Assumption: The number of pins is even and it is greater than or equal to  2 **" << endl ;

	cout << "Type number of pins in switch box: " ;
	cin >> n ;
	

	pins = new int[n];

	cout << "Type numbers for pins 1 through " << n << ": " ;
	for (int i=0;i<n;i++)
		cin >> pins[i] ;

	bool result = CheckBox(pins, n);
	if ( result ) {
		cout << "The switch box is routable" << endl ;
	} else {
		cout << "The switch box is NOT routable" << endl ;
	}

	delete [] pins;

	return 0;
}
