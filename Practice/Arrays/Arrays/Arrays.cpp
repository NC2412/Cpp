#include <iostream>
using namespace std;

int main() {
	// An array is a list of values stored in one variable
	// Must declare how many elements you will have in the list using [] after the variable names.
	// This is so the compiler can create memory for the variable.
	// Remember, this is only declaring a variable.
	int values[4];

	// To add values or change them, this is the syntax.
	values[0] = 10;
	values[1] = 20;
	values[2] = 30;
	// If you do not give every spot a value, you will recieve garbage in that spot.
	// This is because by default, the different elements of the array (int, string, double, etc.) are not initialized.
	//		This means you recieve whatever else was initially in that spot of the computer's memory.
	//values[3] = 40;

	for (int i = 0; i < 4; i++) {
		cout << i << ": " << values[i] << endl;
	}

	// C++ does not stop you from accessing elements that don't exist.
	// This accesses memory not allocated for the array. 
	// cout << "Bad idea: " << values[10] << endl;
	// An even worse idea would be to write to memory not allocated for this, you can really mess things up.
	// Java, for example, would stop you from doing this.

	// You can also initialize the variable.
	// This means giving it all the values it needs on declaration.
	double numbers[4] = { 4.5, 3.2, 54.4, 3.0 };

	for (int i = 0; i < 4; i++) {
		cout << i << ": " << numbers[i] << endl;
	}

	// An easy way to initialize values in a declared array is a loop.
	int nums[10];

	for (int i = 0; i < 10; i++) {
		nums[i] = i + 1;
		cout << i << ": " << nums[i] << endl;
	}

	// Use sizeof() to determine the byte size of the array
	// The sizeof(nums) will be 40, because there are 10 int values. Remember an int is 4 bytes.
	cout << sizeof(nums) << endl;
	// To find the number of elements in the array, you will have to divide the sizeof(array) by the sizeof(variable type)
	cout << sizeof(nums) / sizeof(int) << endl;
	
	// i must be an unsigned int because:
	//		sizeof() returns and unsigned int, remember unsigned int cannot be negative.
	// You cannot compare int with unsigned int.
	for (unsigned int i = 0; i < (sizeof(nums) / sizeof(int)); i++) {
		cout << nums[i] << endl;
	}

	return 0;
}