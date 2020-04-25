#pragma once
#include <iostream>
using namespace std;

/*
	Classes are a way to bundle data with subroutines.
	Think of them as defining your own variable types.
	Classes are what you use them for.
*/

// Define the class with the keyword class and it's name.
// No need for ().
class Cat {

// Destructors run once when an object is destroyed.

// Anything within private is not able to be accessed from another file, only from the class.
private:
	// These are instance variables.
	// Every instance of this class will have it's own variable.
	int age;
	bool happy;
	string color;
	string name;

// public makes the functions inside accessible outside of the files associated with this class.
public:

	// Cat() is a default constructor.
	// Notice how it is the same name as the class.
	// Constructors run once when a new instance of the class object is instantiated.
	// Constructors do not have a return type, so no need for a keyword in front.
	// If you declare a method with an initialization list, be sure to include {}.
	Cat(); // : color("brown") {};

	// Cat(string name, int age) is a parameterized constructor.
	// You can have as many contructors as you want, just none with the same amount of parameter.
	// You can also initialize the method here, like this. It does get a bit cluttered though and defeats the organization a header file has.
	// Called "in-line implementation."
	Cat(string name, int age);
	//Cat(string name, int age) { this->name = name; this->age = age; }

	// ~Cat() is a destructor.
	// Same exact properties as a constructor, except instead of running on start it runs on destroy.
	~Cat();

	void speak();
	void jump();
	void make_happy();
	void make_sad();
	void set_age(int desired_age);
	int get_age();
	void set_name(string desired_name);
	string get_name();
	string to_string();

// Notice there is a ; following the }.
};