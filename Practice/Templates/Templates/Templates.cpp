#include <iostream>
using namespace std;

/*
	Templates allow you to create objects with the type defined by the user.
	With templates, C++ needs to see the definition and implementation together.
	Templates will assume the type has the correct implementation to use it's assumed methods.
*/

// To define a class as a template, follow the syntax below.
// You may have multiple types defined.
template<class T, class K>
class Test {
private:
	T obj;
	K val;

public:
	Test(T obj, K val) {
		this->obj = obj;
		this->val = val;
	}

	void print() {
		cout << obj << endl;
	}

	void multiply() {
		cout << obj * val << endl;
	}
};

// You can also have template functions.
// You can implement them with classes.
// You can use typename to define your variable.
//		- typename and class do the same thing.
template<typename T>
void print(T n) {
	cout << "Template version" << endl;
}

// You can overload functions, allowing c++ to infer which function to call.
void print(int value) {
	cout << "Non-template version." << endl;
}

template<class T>
void show() {
	cout << T() << endl;
}

int main() {

	// You must define the object with the type you want to use.
	Test<string, int> test1("Hello", 10);
	test1.print();
	test1.multiply();

	print<string>("This is a function.");
	print<int>(5);
	// To guarantee the template function is called, include empty <>.
	print<>(5);
	// Type inference happens here, no need to include <>.
	print("Hello");
	print(22);

	// This will not compile becuase nothing is passed in the argument list ( () ).
	// You must pass a parameter into the argument list so c++ can infer the type.
//	show<>();

	return 0;
}