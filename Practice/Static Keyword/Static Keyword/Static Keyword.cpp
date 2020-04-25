#include <iostream>
using namespace std;

// .h header file
class Test {
public:
	// Often const variables are made public, because they are made to be accessed individually.
	static int const MAX = 99;

private:
	int id;
	// static ensures there is only one variable with the name.
	// This means the variable is associated with the class, not with each object.
	// Because the variable is static, it must be initialized somewhere.s
	//		However, if the variable is a const, it can be initialized on declaration.
//	static int const MAX = 99;
	static int count;

public:
	Test() { id = ++count; }
	int getId() { return id; }
	// Static methods are also associated with the class.
	// To access static variables, use a static method.
	//		This means that there is no need to have an instance of the class to access it's methods/variables.
	static void showInfo() {
		cout << count << endl;
	}
};

// .cpp source
int Test::count = 0;

int main() {

	cout << Test::MAX << endl;

	Test test1;
	cout << "Object 1 ID: " << test1.getId() << endl;

	Test test2;
	cout << "Object 2 ID: " << test1.getId() << endl;

	Test::showInfo();

	return 0; 
}