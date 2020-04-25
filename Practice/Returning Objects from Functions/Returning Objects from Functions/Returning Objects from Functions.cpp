#include <iostream>
using namespace std;

class Animal {
private:
	string name;

public:
	Animal() { cout << "Animal created." << endl; }
	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying. " << endl; }
	~Animal() { cout << name << " destroyed" << endl; }

	void setName(string name) { this->name = name; }
	void speak() const { cout << "My name is: " << name << endl; }
};

Animal *createAnimal() {
	Animal *pAnimal = new Animal();
	pAnimal->setName("Bertie");

	// C++ will create a temporary object just to return the object.
	return pAnimal;
}

int main() {

	// Another copy of the object occurs when you assign the temporary return object to the new object.
	// This calls the copy constructor.
	// pFrog is just copying over the 8 bytes allocated for an object.
	Animal *pFrog = createAnimal();

	// Do not forget to delete pFrog because when instantiating, the new keyword was used in createAnimal().
	delete pFrog;

	return 0;
}