#include <iostream>
using namespace std;

int main() {

	// If statements are the exact same as any other language
	// The syntax needs () surrounding the condition.
	bool fun = true;

	// Remember, 1 is true, 0 is false.
	if (fun == 1) {
		cout << "Yay! It's fun!" << endl;
	}
	else {
		cout << "Sorry!" << endl;
	}

	// If else if else statements are the same as any other language
	int num = 10;
	
	// The compiler will keep checking if conditions are true until it finds one.
	// When the true statement is found, the code within it will be executed.
	if (num < 5) {
		cout << "More than that." << endl;
	}
	else if (num == 5) {
		cout << "Correct." << endl;
	}
	else {
		cout << "Less than that." << endl;
	}

	return 0;
}