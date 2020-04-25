#include <iostream>
#include "Cat.h"
#include "Animals.h"

using namespace cats;
using namespace nac;
using namespace std;

/*

	Namespaces are a way to avoid conflicts between classes and/or global variables with the same name.
	The compiler will automatically use the class from the namespace you specify.
	To use multiple classes of the same name, you must specify which namespace you derive the class from.

*/

int main() {

	// To use the namespace nac cat, you must use the syntax: namespace::object.
	nac::Cat cat;
	cat.speak();

	cout << nac::NAME << endl;
	cout << cats::NAME << endl;

	return 0;
}