#include <iostream>
using namespace std;

int main() {

	// break loop.
	for (int i = 0; i < 5; i++) {
		cout << "i is: " << i << endl;

		if (i == 3) {
			// Immediately breaks out of the loop.
			// Key word loop, not the enclosing brackets. Just the enclosing loop.
			break;
		}
	}
	cout << "Complete." << endl;

	// continue loop.
	for (int i = 0; i < 5; i++) {
		if (i == 3) {
			// continue breaks out of the current iteration of the loop.
			// Keyword iteration. This means it restarts the loop without finishing the rest of the code.
			continue;
		}

		cout << "i is: " << i << endl;
	}
	cout << "Complete." << endl;


	return 0;
}