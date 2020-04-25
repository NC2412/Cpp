#include <iostream>
using namespace std;

int main() {

	int i = 0;

	// while loops run until the condition is false.
	// Be careful of infinite loops.
	while (i < 10) {
		cout << "Hello." << endl;
		i++;
	}

	// The const keyword makes sure the variable cannot be changed at all in the program.
	// const variables are names at the beginning of the program or subroutine.
	const string password = "wordpass";
	
	// If this were defined both here and inside the do-while loop, the scope of variables would come into effect;
	// The variable within the do-while loop would mask this one, however the variable inside the do-while would not
	//		be used anywhere else.
	string input;

	// do-while loops begin with do, and and with while(*condition*)
	// The point of a do-while loop is all the code in the brackets are run at least once.
	// This is because the loop runs before it checks the condition.
	do {
		cout << "Enter your password: " << flush;

		cin >> input;

	} while (input != password);

	cout << "Password accepted." << endl;

	return 0;
}