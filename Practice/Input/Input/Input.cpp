#include <iostream>
using namespace std;

int main() {

	cout << "Enter your name: " << flush;

	// Declares string variable without assigning a value.
	string name;

	// cin gets the input, uses extraction operators rather than cout's insertion operators (<<, >>)
	cin >> name;
	cout << "You entered: " << name << endl;

	cout << "Enter a number: " << flush;

	int num;
	cin >> num;
	cout << "You entered: " << num << endl;

	return 0;
}