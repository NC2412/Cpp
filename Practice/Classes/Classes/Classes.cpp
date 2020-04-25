#include <iostream>
// Must include the class header file in all files where the class is being referenced.
#include "Cat.h"
using namespace std;

int main() {

	// Instantiates cat as a Cat object.
	// Scope is the region in which the object exists.
	// When the end } is reached, the destructor will be called.
	Cat cat("Cee Cee", 10);

	// To acess the variables or methods of a class, use the . operator.
	cat.make_happy();
	cat.speak();
	cat.jump();

	// Naked {} can be used if you want to be able to deallocate memory at a certain point in your code.
	// Cat test will only exist between the following {}.
	{
		Cat test;

		test.set_name("Test subject 001");
		test.set_age(9);
		test.make_happy();
		test.speak();
		test.jump();
		
		cout << test.get_name() << ", " << test.get_age() << endl;
	}

	cout << cat.to_string() << endl;

	// To print the memory address, you can also use an & prefixing the name.
	cout << cat.to_string() << ", memory location: " << &cat << endl;
	return 0;
}