#include <iostream>
// Not necessarily needed.
#include <exception>
using namespace std;

/*
	Exceptions are an error handling mechanism.
	Usually exceptions are used to address an error your program cannot recover from.
*/

void mightGoWrong() {
	bool error1 = true;
	bool error2 = true;

	if (error1) {
		// The throw keyword will throw an error to the compiler.
		// As soon as you throw, you go straight out of the function.
		//		- The exception will 'throw right out of main.'
		throw "Something went wrong."; // This will throw an exception of type char const*
	}

	if (error2) {
		// To throw an object, you must initialize an instance of the object.
		throw string("Something else went wrong.");
	}
}

void useMightGoWrong() {
	mightGoWrong();
}

void couldGoWrong() {
	bool error1Detected = true;
	bool error2Detected = false;

	if (error1Detected) {
		throw bad_alloc();
	}

	if (error2Detected) {
		throw exception();
	}
}

//
//	CLASS: CanGoWrong
//
class CanGoWrong {
public:
	CanGoWrong() {
		char* pMemory = new char[999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999];
		delete[] pMemory;
	}
};

//
//	CLASS: CanGoWrong
//
class MyException : public exception {
public:
	// Overriding super what() method.
	// By putting parameters in throw(), it implies the method can only throw those parameters.
	virtual const char* what() const throw() {
		return "Something bad happened!";
	}
};

//
//	CLASS: Test
//
class Test {
public:
	void goesWrong() {
		throw MyException();
	}
};

int main() {

	// To handle errors, use the try-catch syntax.
	// try-catch will work within it's scope.
	// try signifies the code you intend to run.
	try {
		useMightGoWrong();
	}
	// catch will 'catch', or handle the errors thrown.
	// Within the (), input parameters for the errors you want to catch.
	catch (int e) {
		cout << "Error code: " << e << endl;
	}
	// To catch multiple types of exceptions, you must implement multiple catch blocks.
	catch (char const* e) {
		cout << "Error message: " << e << endl;
	}
	// To catch an object, you must catch it with a & (reference).
	catch (string& e) {
		cout << "string error message: " << e << endl;
	}

	try {
		CanGoWrong wrong;
	}
	catch (bad_alloc &e) {
		cout << "Caught exception: " << e.what() << endl;
	}

	Test test;

	try {
		test.goesWrong();
	}
	catch (MyException& e) {
		cout << e.what() << endl;
	}

	try {
		couldGoWrong();
	}
	// Be sure to catch subclasses before their parent class.
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
	// If exception is caught first, it will still "work."
	//  - Because bad_alloc is a method of the exception class, polymorphism allows for bad_alloc() to be caught by exception.
	//		- what() is a virtual method, so exception and bad_alloc have it.
	catch (exception& e) {
		cout << e.what() << endl;
	}
	

	cout << "Still running." << endl;

	return 0;
}