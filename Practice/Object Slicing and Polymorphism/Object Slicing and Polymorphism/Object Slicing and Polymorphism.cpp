#include <iostream>
using namespace std;

class Parent {
public:
	Parent() : one(0) { }

	Parent(const Parent& other) : one(0) {
		cout << "Copy parent" << endl;
	}

	virtual void print() {
		cout << "Parent" << endl;
	}

	virtual ~Parent() {}

private:
	int one;
};

class Child : public Parent {
public:
	Child() : two(0) {}
	void print() {
		cout << "Child" << endl;
	}

private:
	int two;
};

int main() {

	Child c1;
	// If you have a reference of a parent class, you can assign an object of the subclass type to it.
	Parent& p1 = c1;

	// To print 'child' we need to make the parent function virtual.
	p1.print();

	// This is implicit copy initialization.
	// This also 'slices' away the variables in Child, called object slicing.
	// Because the copy constructor is called in Parent, it makes no use of the variables in the Child subclass, hence slicing them away.
	//
	// This is also 'upcasting' the Child objext to the parent type, self explanatory. 
	//		- Going up the hierarchy.
	Parent p2 = Child();

	p2.print();

	return 0;
}