#include <iostream>
using namespace std;

// Normally, you would declare the class in a header file and define the methods in another .cpp file.
// This is just here for readability.
class Animal {
private:
	string name;

public:
	void setName(string name) { this->name = name; };

	// When defining a cont method, type const after the ().
	// const in a method mean the method cannot change instance data.
	//		This means no =, etc.
	void speak() const { cout << "My name is : " << name << endl; };
};

int main() {

	// const values cannot change.
	// Always declare a value you don't want to change as a const.
	const double PI = 3.14159265;
	cout << PI << endl;

	Animal animal;
	animal.setName("Freddy");
	animal.speak();

	int val = 8;
	// In this case, pVal is a pointer to an integer that is constant. 
	// This means no reassigning the value of the pointer.
	// However, you can reassign what the pointer is pointing to.
	const int* pVal = &val;
	int num = 11;

	pVal = &num;

	// In this case, pointer is a constant pointer to an integer.
	// This means no reassigning the memory address the pointer is pointing to.
	// However, you can reassign the value that the pointer is pointing to.
	int* const pointer = &val;
	*pointer = 10;

	return 0;
}