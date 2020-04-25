#include <iostream>
using namespace std;

class Animal {
private:
	string name;

public:
	Animal() { cout << "Animal created." << endl; }
	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying." << endl; }
	~Animal() { cout << name << " destroyed" << endl; }
	
	void setName(string name) { this->name = name; }
	void speak() const { cout << "My name is: " << name << endl; }
};

int main() {

	// This allocates memory for a single object.
	// By instantiating an object like this, you manage the memory yourself.
	Animal *pCat1 = new Animal();

	// The . operator has a higher precedence than the * operator, so the object will always be dereferenced first.
	// The following syntax is NOT recommended.
	(*pCat1).setName("Freddy");
	// To access something in a pointer, use the -> operator.
	pCat1->speak();

	// If you instantiate the new keyword, you must call delete to deallocate the memory.
	delete pCat1;

	// You cannot delete a NULL pointer, be careful not to do that.
	Animal* pCat2 = NULL; // NULL is synonymous to 0.

	// 8 bytes, the same size as a long variable.
	cout << sizeof(pCat1) << endl;

	return 0;
}