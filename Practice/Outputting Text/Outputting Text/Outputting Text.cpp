#include <iostream>
using namespace std;

int main() {

	// flush tells the operating system to clean memory and output text from it.
	// Does not create a line feed or 'carriage' return.
	cout << "Starting program." << flush;

	// endl outputs a new line after the text. Like println in java.
	cout << "This is some text." << endl;
	cout << "Here is some more text." << endl;

	// multiple lines in one statement
	cout << "Banana. " << "Apple. " << "Orange. " << endl;

	// endl or flush force the os to print, rather than waiting until there is more to print.
	cout << "Even more text." << endl;

	return 0;
}