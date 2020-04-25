#include <iostream>
using namespace std;

int main() {

	// String literals are always put in double quotes.
	// string is not the same as int
	// text is an object, string is a class.
	// int is a primitive type
	string text = "This is a string variable's contents.";

	cout << text << endl;

	string first_name = "Nicolo";
	string last_name = "Cammarano";

	cout << first_name << ' ' << last_name << endl;

	// concatenation
	string full_name = first_name + ' ' + last_name;

	cout << full_name << endl;

	// You can also create a string like this:
	char c = 'b';
	// This instantiates name as the value of c, 10 times.
	string name(10, c);

	return 0;
}