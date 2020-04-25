#include <iostream>
using namespace std;

// Functions are like a separate piece of code that you can invoke from wherever you like.
//		This means you can reuse the code and split your program into different sections.
// use keyword that you will return. In this case: void.
// show_menu() defines a block of code to be invoked from somewhere else.
void  show_menu() {

	cout << "1) Search" << endl;
	cout << "2) View Record" << endl;
	cout << "3) Quit" << endl;

}
// Be sure to define functions before main.
// This has to do with the scope of the compiler.
//		The compiler reads from top to bottom. 
//		If you try to call show_menu() from main with show_menu() defined after the main function,
//			then an error would occur.

// This function return an integer, so the int keyword is needed before the name.
int get_input() {
	int input;
	cin >> input;

	return input;
}

// To pass a function parameters, just define variables within the (), separated by commas (,).
// Always keep in mind the scope of the same name variables. 
void process_selection(int input) {

	switch (input) {
	case 1:
		cout << "Searching ..." << endl;
		break;
	case 2:
		cout << "Viewing ..." << endl;
		break;
	case 3:
		cout << "Quitting ..." << endl;
		break;
	default:
		cout << "Unrecognized input." << endl;
	}
}

// Aim for a simple main() function.
// This will allow you to quickly figure out what the program does.
int main() {

	// When invoking a function, be sure to type the exact name with () at the end.
	show_menu();
	
	// Feel free to store the function in a variable.
	// This just assigns the return value as the variable value.
	int input = get_input();

	// When calling a function with a paramter; include the variable within the ()
	process_selection(input);

	return 0;
}

