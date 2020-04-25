#include <iostream>
using namespace std;

class Animal {
private:
	string name;

public:
	Animal() { cout << "Animal created." << endl; }
	Animal(const Animal& other) : name(other.name) { cout << "Animal created by copying." << endl; }
	~Animal() { cout << name << " destroyed" << endl; }

	inline void setName(string name) { this->name = name; }
	inline void speak() const { cout << "My name is: " << name << endl; }
};

int main() {

	// This instantiates and allocates an object in memory.
	// The [] allocate enough memory for x amount of objects, in this case: 10.
	// It also creates an array of animals.
	Animal *pAnimal = new Animal[10];

	// This works with the 5th animal in the array.
	pAnimal[5].setName("George");
	pAnimal[5].speak();

	// To deallocate all the memory, use [] between delete and the object.
	delete [] pAnimal;

	char* pMem = new char[1000];
	delete[] pMem;

	return 0;
}