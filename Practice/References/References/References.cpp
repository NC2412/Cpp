#include <iostream>
using namespace std;

/*
	References act as an alias to another variable.
	In other words, if variable x is a reference to variable y, if x changes, y will too, and vice versa.
	References are quite like pointers, just the syntax with referneces are much simpler to pointers.
	References are necessary because they do things pointers can't.
*/

// &val is a reference to whatever variable is passed to this function.
void changeSomething(double &val) {
	val = 123.4;
}

int main() {

	int val1 = 8;

	// The & defines val2 as a reference to val1.
	// The reference does not hold a new integer.
	int &val2 = val1;
	val1 = 10;

	cout << "Value 1: " << val1 << endl;
	cout << "Value 2: " << val2 << endl;

	double value = 4.321;
	changeSomething(value);

	cout << value << endl;

	return 0;
}