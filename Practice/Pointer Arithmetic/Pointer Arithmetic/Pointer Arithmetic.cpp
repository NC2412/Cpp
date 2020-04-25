#include <iostream>
using namespace std;

int main() {

	const int elements = 5;

	// If you put a variable in the [], it must be a const.
	// This is because the compiler allocates a certain amount of memeory for this object.
	//		The value in the [] cannot change.
	string words[elements] = { "one", "two", "three", "four", "five" };

	string* pWords = words;

	// Before this statement, pWords is on the 0th index.
	// When incrementing a pointer like this, it moves the pointer x amount of units.
	// In this case, it moves the pointer forward sizeof(string) bytes * 3 forward, ending up on the 3st index.
	pWords += 3;

	cout << *pWords << endl;

	// Subtracting sizeof(string) bytes from the current amount of bytes.
	pWords--;

	cout << *pWords << endl;

	string* pLast = &pWords[elements];
	while (pWords <= pLast) {

		cout << *pWords << endl;;
		pWords++;
	}

	return 0;
}