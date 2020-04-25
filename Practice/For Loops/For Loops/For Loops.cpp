#include <iostream>
using namespace std;

int main() {

	// for loops are the most used and very useful, obviously.
	// (loop counter variable; condition; incrementation) {}
	for (int i = 0; i < 10; i++) {
		cout << "Trail " << i << endl;
	 }

	int j = 0;
	// On the incrementation portion of a for loop, you can increment multiple variables at once.
	for (int i = 0; i < 10; i++, j++) {
		cout << i << " " << j << endl;
	}

	return 0;
}