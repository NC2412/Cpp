#include <iostream>
using namespace std;

int main() {
	int value = 5;

	// switch statements are often faster than if-else if-else statements
	// The condition is the value you want to switch on.
	switch (value) {
		// case is the value you want to check for.
		// You cannot have a variable as part of the case, it is not constant.
		//		Keeping this in mind, you can use const variables.
	case 4:
		cout << "Value is 4." << endl;
		// Need the break statement to get out of the switch.
		break;
	case 5:
		cout << "Value is 5." << endl;
		break;
	case 6:
		cout << "Value is 6." << endl;
		break;
	// default is equvalent to else in an if statement. 
	// If all else fails.
	default:
		cout << "Unrecognized value." << endl;
		// No need for a break here. There are no other cases after this one, so the switch will be exited.
	}

	return 0;
}