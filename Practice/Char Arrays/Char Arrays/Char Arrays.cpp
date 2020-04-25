#include <iostream>
using namespace std;

int main() {
	
	// Declaring a char array is the same as any other array. 
	// However, you are able to write all the characters in "" and the compiler will convert that into an array for you.
	// This is much easier than the standard way of { 'h', 'e', 'l', 'l', 'o' }.
	// Be ware of the null terminator.
	char word[] = "hello";
	char noNullTerminator[] = { 'h', 'e', 'l', 'l', 'o' };

	for (int i = 0; i < sizeof(word); i++) {

		// This returns a 6th index, because the sizeof(word) is really 6.
		// This is becuase of the NULL TERMINATOR.
		// This lets the program know where the string actually ends.
		// word has it because when declaring word, I used "".
		cout << i << ": " << word[i] << endl;
	}

	for (int i = 0; i < sizeof(noNullTerminator); i++) {

		// See, no null terminator! 
		cout << i << ": " << noNullTerminator[i] << endl;
	}

	int k = 0;
	// We can say k cannot be 0 because the null terminator value is 0.
	while (word[k] != 0) {

		cout << k << ": " << word[k] << endl;;
		k++;
	}

	return 0;
}