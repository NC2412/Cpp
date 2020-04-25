
/*
	Note to self:
		When confused, just write out the process like shown below.
		It helps to make it crystal clear.
*/

#include <iostream>
using namespace std;

int main() {

	// Same initialization/declaration as 1D arrays.
	// A 2D array is just an array where the elements themselves are also arrays.
	//		This pattern continues for as many dimensions you want.
	// When declaring a 2D array, you are able to leave the first [] blank, but not the second [].
	//		This is because C++ sees the first [] as just a bunch of values, but sees the second []
	//			as the organization. 
	//		You cannot have a differing amount of second [] values.
	string animals[2][3] = {
		// 2 rows, with 3 values
		{"Fox", "Dog", "Cat"},
		{"Mouse", "Squirrel", "Parrot"}
	};

	// Must be very careful to only iterate as many times as there are values.
	//		Remember what happens when you try to access/manipulate values that aren't meant to be changed.
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			
			// This just prints each element of the row with a space in between.
			cout << animals[i][j] << " " << flush;
		}

		// This just prints a new line. Cleaner than cout << "\n" << flush;
		cout << endl;
	}

	// Multiplication table practice.
	for (int i = 0; i <= 12; i++) {
		for (int j = 0; j <= 12; j++) {
			cout << (i * j) << "\t" << flush;
		}
		cout << endl;
	}

	// Just like sizeof for an int, you will need to divide the bytes of the string array by the bytes of a string.
	cout << "Size of string: " << sizeof(string) << endl;
	cout << "Size of animals: " << sizeof(animals) << endl;
	cout << "Size of animals[0]: " << sizeof(animals[0]) << endl;

	// Just need to divide sizeof( array ) by the sizeof( array[0] ).
	//		This return the number of rows.
	//		To clear up confusion: sizeof(animals[0]) returns the sum of the bytes of each individual string in that row.
	//			3 (the amount of elements) * 28 (the bytes of a string) = 84.
	//			168 (the total bytes of the 2D array) / 84 (the bytes each row contains) = 2 (the number of rows)/
	for (int i = 0; i < (sizeof(animals) / sizeof(animals[0])); i++) {

		// This loop divides the sizeof( row ) by te sizeof( variable ).
		// To clear up confusion: sizeof(animals[0]) returns the sum of the bytes of each individual string in that row.
		//		84 (the total bytes of the row) / 28 (the bytes of a string) = 3 (the number of elements in each row).
		for (int j = 0; j < (sizeof(animals[0]) / sizeof(string)); j++) {
			cout << animals[i][j] << " " << flush;
		}
		cout << endl;
	}

	return 0;
}