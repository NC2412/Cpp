#include <iostream>
using namespace std;

/*
	An abstract class is a class containing methods with no implementation.
		- This means they are 'pure virtual methods.'
	A class with any amount of pure virtual functions is an abstract class.
*/

class Animal {

	// This is a pure virtual funciton.
	// Pure virtual functions are initialized as 0 as a placeholder.
	virtual void speak() = 0;

	virtual void run() = 0;
};

class Dog : public Animal {

public:
	virtual void speak() {
		cout << "Wood!" << endl;
	}
};

class Labrador : public Dog {
public:
	virtual void run() {
		cout << "Labrador running" << endl;
	}
};


int main() {

	// To instantiate an instance of an abstract class, ALL pure virtual methods MUST be implemented.
	//Dog dog;
	//dog.speak();

	Labrador lab;
	lab.run();
	lab.speak();

	return 0;
}