#include <iostream>
using namespace std;

// A common way to get the elements of an array that is passed into a function is to include the elements as a parameter.
void show1(const int elements, string words[]) {

	// sizeof(words) here returns 4 bytes.
	// This is because we only have the pointer to words.
	cout << sizeof(words) << endl;

	for (int i = 0; i < elements; i++) {
		cout << words[i] << endl;
	}
}

// Notice how this function is the exact same as show1, except words is a pointer.
// Array syntax and pointer syntax are synonymous in this case.
// We still do not have the number of elements in the array.
void show2(const int elements, string *words) {
	for (int i = 0; i < elements; i++) {
		cout << words[i] << endl;
	}
}

// This works because it is a reference to an array of strings.
// If I were to just type '&words[3]' words would then be an array of references to strings. This has to do with precenence.
void show3(string(&words)[3]) {

	// Because we now have a reference to the array, we can use the sizeof(array)/sizeof(type) method.
	for (int i = 0; i < sizeof(words) / sizeof(string); i++) {
		cout << words[i] << endl;
	}
}

char* getMemory(int size) {
	char* pMem = new char[size];

	return pMem;
}

void freeMemory(char* pMem) {
	delete [] pMem;
}

int main() {

	string words[] = { "Apple", "orange", "banana" };

	// sizeof(words) here returns 84 bytes.
	cout << sizeof(words) << endl;

	show1(3, words);
	show2(3, words);
	show3(words);

	char* pMemory = getMemory(100);
	freeMemory(pMemory);

	return 0;
}