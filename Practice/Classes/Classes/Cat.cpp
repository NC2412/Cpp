#include <iostream>
#include <sstream>
// Essentially pastes the file here behind the scenes.
#include "Cat.h"

using namespace std;

// :: are the equivalent of the . operator in other languages.
// They just specify the method derives from the class.
// Only need :: when defining it's method.
// Class::method makes the methon a member of the class.
Cat::Cat() {
	happy = true;
	age = 2;
	cout << "Cat created." << endl;
}

// This is a constructor initialization list.
// By adding : after the method, you can initialize variables as shown below.
// variable(parameter) replaces this->variable = parameter.
// variable() is the class variable, parameter is the variable passed to the method.
// You can also initialize a variable that has not been passed to the method.
Cat::Cat(string name, int age): age(age), color("Black") {
	// this refers to the class level variable.
	// -> is a pointer!
	this->name = name;

	// By printing 'this' the memory address of the object will print.
	// 0x is the prefix of the number. In this case, the address is in hexadecimal.
	// 16 digits to choose from in each position. 0-9, a-f.
	// Even though hexadecimal has letters, it is still a number.
	cout << "Memory location: "<< this << endl;

}

Cat::~Cat() {
	cout << "Cat destroyed." << endl;
}

void Cat::speak() {

	if (happy) {
		cout << "Meow." << endl;
	}
	else {
		cout << "Hissss..." << endl;
	}
}

void Cat::jump() {
	cout << "Jumping to the top of a table." << endl;
}

// The following methods are setter/mutator methods.
// These methods are used to change something about the object, usually a variable.
void Cat::make_happy() {
	happy - true;
}
void Cat::make_sad() {
	happy = false;
}

void Cat::set_age(int desired_age) {
	age = desired_age;
}

void Cat::set_name(string desired_name) {
	name = desired_name;
}

// The following methods are getter methods.
// These methods return the value of a variable for viewing purposes.
int Cat::get_age()
{
	return age;
}

string Cat::get_name()
{
	return name;
}

string Cat::to_string() {
	stringstream ss;
	ss << name << ", " << age << ", " << color;

	return ss.str();
}