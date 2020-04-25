#include "Cat.h"

Cat::Cat() {
	cout << "Cat created!" << endl;
}

Cat::~Cat() {
	cout << "Cat destroyed." << endl;
}

void Cat::speak() {
	cout << "Meow." << endl;
}