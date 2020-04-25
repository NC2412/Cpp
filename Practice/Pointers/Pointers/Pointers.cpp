#include <iostream>
using namespace std;

/*
	Pointers are a language feature in c++, not found in many other languages.
	Pointers store the memory address to a variable.
*/

// By passing a function a pointer, you are passing the memory address to the function.
// Becuase it is technically passing by reference, the function has access to the address, thus is able to to manipulate the value.
void manipulate(double* val) {

	cout << "2. Value of double in manipulate: " << *val << endl;

	// When manipulating a pointer value, be sure to include the *.
	// Otherwise you would be trying to change the address.
	*val = 10.0;

	cout << "3. Value of double in manipulate: " << *val << endl;

}

int main() {

	int n_val = 8;

	// * is a pointer. 
	// Remember to use & to get address.
	// pn_val is a pointer to an int.
	int* pn_val = &n_val;

	cout << "Pointer to int address: " << pn_val << endl;

	// By putting an * in front of the pointer variable, it returns the value at that memory address.
	// This is called 'dereferencing' the pointer.
	cout << "Int value via pointer: " << *pn_val << endl;

	// Pointer to an int still is 4 bytes.
	cout << sizeof(pn_val) << endl;
	cout << endl << endl;

	double d_val = 123.4;
	double* pd_val = &d_val;

	cout << "1. Double value: " << *pd_val << endl;
	manipulate(pd_val);
	cout << "4. Double value: " << *pd_val << endl;
	
	// By dereferencing the pointer, you can change the value the pointer points to.
	*pd_val = 17.0;

	cout << "5. Double value: " << *pd_val << endl;

	return 0;
}