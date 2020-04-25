#include <iostream>
using namespace std;

int main() {
	
	// Remember arrays store the string object in a differnet memory location which allocates a consistent number of bytes.
	// An array technically has a bunch of pointers pointing to the string objects that are "in the array."
	string words[] = { "one", "two", "three" };

	// Array variables and pointers are very similar.
	// One of the only differences is an array variable knows the amount of data it is pointing at, a pointer variable doesn't.
	// Because of this, you can assign an array directly to a pointer.
	string* pWords = words;

	// By adding 1 to the pointer, the compiler knows you want to look at the next address the object is pointing at.
	for (int i = 0; i < sizeof(words) / sizeof(string); i++, pWords++) {
		
		// Dereferencing pWords returns the current address value it is pointing at.
		cout << *pWords << endl;
	}

	// Setting a pointer to the object will return the first object it points to.
	string* pElement = words;
	// Setting a pointer to any other index of an object will need the & operator to store the address rather than the value.
	// The [] operator has a higher precedence than &, so the compiler will first retrive the value at [], then the address.
	string* pLast = &words[2];

	while (pElement <= pLast) {

		cout << *pElement << " " << flush;

		pElement++;
	}

	return 0;
}