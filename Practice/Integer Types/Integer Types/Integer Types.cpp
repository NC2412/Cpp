#include <iostream>

// limits allows you to get the max or min value you can store.
// Here is the limits documentation: https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=vs-2019
#include <limits>

using namespace std;

int main() {

	// Only allocates a certain amount of memory to store the variable.
	// this is too large.
	int value = 123;
	cout << value << endl;
	
	cout << "Max int value: " << INT_MAX << endl;
	cout << "Min int value: " << INT_MIN << endl;

	// You can change the int storage by adding long.
	long int l_num = 12341234123421341234;
	cout << l_num << endl;

	short int s_num = 3241;
	cout << s_num << endl;

	// Use sizeof() to see the memory the object has.
	// sizeof() returns the byte value, remember the value of a byte is 8 bits.
	cout << "Size of int: " << sizeof(int) << endl;
	cout << "Size of short int: " << sizeof(short int) << endl;
	cout << "Size of long int: " << sizeof(long int) << endl;

	// unsigned int can only have positive values.
	// signeed ints can be positive or negative.
	// This allows you to have a bigger value, because there is no need to use a bit to represent + or -.
	unsigned int u_num = 12341234;

	cout << u_num << endl;

	return 0;
}