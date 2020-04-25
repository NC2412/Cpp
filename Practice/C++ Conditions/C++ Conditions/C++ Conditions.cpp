#include <iostream>
using namespace std;

/* 
	== equality test
	!= not equals
	< less than
	<= less than or equal to
	> greater than
	>= greater than or equal to
	&& and.......The single & represents the bitwise operator
	|| or
*/

int main() {

	int a = 7;
	int b = 4;

	if (a > 8) {
		cout << "Condition 1 is true." << endl;
	}
	else {
		cout << "Condition 1 is false." << endl;
	}

	// The compiler reads left to right.
	// If the first condition is true, it then evaluates the next condition.
	// If the first condition is false, it moves on to the next code to execute.
	if (a == 7 && b == 4) {
		cout << "Condition 2 is true." << endl;
	}
	else {
		cout << "Condition 2 is false." << endl;
	}

	// If the first condition is true, the whole condition is true. No need to check the next condition.
	// Only one of the conditions have to be true for the whole condition to be true.
	if (a == 7 || b == 4) {
		cout << "Condition 3 is true." << endl;
	}
	else {
		cout << "Condition 3 is false." << endl;
	}

	// Remember the compiler reads left to right.
	// b is not 8.
	// a is 7.
	// This makes the && portion of the condition true.
	// Becuase the rest of the condition is part of an || statement, the whole condition is true.	
	if (b != 8 && a == 7 || a < 10) {
		cout << "Condition 4 is true." << endl;
	}
	else {
		cout << "Condition 4 is false." << endl;
	}
	// To make the above statement clearer, add parenthesis around the && portion.
	// Ex: ((b != 8 && a == 7) || a < 10)

	// Isn't this useful. Reminds me of python.
	// You can store the condition in a variable.
	bool condition = (b != 8) && (a == 7);
	cout << condition << endl;

	bool condition_ = (a < 10);

	// Feel free to compare variables like this.
	if (condition && condition_) {
		cout << "Condition 5 is true." << endl;
	}
	else {
		cout << "Condition 5 is false." << endl;
	}

	return 0;
}