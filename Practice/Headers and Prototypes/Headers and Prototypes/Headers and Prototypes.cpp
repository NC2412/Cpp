#include <iostream>

// When calling your header file, you must use "" instead of <>.
//		<> refer to a file in a standard location.
//		"" refer to files included in the project.
// #include tell compiler to paste the file in the " " at this spot.
// In this case, the next line is really: void do_something();
#include "utils.h"
using namespace std;

// Below is a prototype.
// This makes the compiler initialize the function before main, allowing you to define the function after main().
/*
void do_something();
*/ 

int main() {

	do_something();
	do_something();

	return 0;
}

void do_something() {
	cout << "Hello" << endl;
}