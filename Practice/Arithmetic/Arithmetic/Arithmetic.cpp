#include <iostream>
using namespace std;

/*
	+
	-
	*
	/
	+=
	-=
	*=
	/=
	%
	%+
	Order of operations
*/

int main() {

	// Remember, an int/int will truncate the remaining value.
	double val1 = 7 / 2;
	cout << val1 << endl;

	// Casting the values to a different type is an easy way to divide integers.
	double val2 = (double)7 / 2;
	cout << val2 << endl;

	int val3 = 8;
	val3++; // val3 = val3 + 1 or val3 += 1.
	cout << val3 << endl;

	int val4 = 10; 
	val4 /= 5;
	cout << val4 << endl;

	// Modulus performs integer division and returns the remainder.
	int val5 = 11;
	val5 %= 3;
	cout << val5 << endl;

	// Obviously never actually write an equation like this, it's impossible to read.
	double equation = 5 / 4 % 2 + 2 * 6;
	cout << equation << endl;

	return 0;
}