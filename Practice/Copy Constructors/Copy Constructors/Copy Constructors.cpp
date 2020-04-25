#include <iostream>
using namespace std;

class Animal {

private:
	string name;

public :
	Animal() { cout << "Animal created." << endl; };

	// A copy constructor takes the reference of another instance of this class and copies it.
	//		The other class MUST be a const. You do not want to be able to change the other class.
	//		It also means you cannot call any non-const methods in the other class.
	// The copy constructor does not copy the fields of the other class, you will have to manually do that.
	// We can access other.name because it is still part of this class.
	Animal(const Animal& other) : name(other.name) { other.speak();  cout << "Animal created by copying." << endl; };
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is: " << name << endl; }

};

int main() {

	Animal animal1;
	animal1.setName("Freddy");

	// While animal 2 is a different instance of the class, it is not technically instantiated, so the constructor is not being called.
	// A different constructor is called: the copy constructor.
	Animal animal2 = animal1;
	animal2.setName("Bob");

	animal1.speak();
	animal2.speak();

	// You can also call the copy constructor like this, a more convential way to instantiate objects, in my opinion.
	Animal animal3(animal1);
	animal3.setName("Jonathan");
	animal3.speak();

	return 0;
}