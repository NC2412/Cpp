#include <iostream>
using namespace std;

int main() {

	// MY SOLUTION

	char word[] = "I am loving c++!";
	// No need to divide by the type because a char is 1 byte.
	int size = sizeof(word);

	// This for loop only needs to run about half the size of the word.
	for (int i = 0; i < size / 2; i++) {
		// switchIndex is used so I don't have to keep typing its contents. This may not be memory efficient.
		char switchIndex = size - 1 - i;
		char holder = word[switchIndex];

		word[switchIndex] = word[i];
		word[i] = holder;
	}

	for (int i = 0; i < size; i++) {
		cout << word[i] << flush;
	}

	// TUTORIAL SOLUTION 

	char text[] = "hello";
	int len = sizeof(text) - 1;
	char* pStart = text;
	char* pEnd = text + len - 1;

	while (pStart < pEnd) {

		char save = *pStart;
		*pStart = *pEnd;
		*pEnd = save;

		pStart++;
		pEnd--;
	}

	cout << endl << text << endl;

	return 0;
}