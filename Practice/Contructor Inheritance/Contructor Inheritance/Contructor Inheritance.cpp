#include <iostream>
using namespace std;

/*
	Constructors are NOT inherited in c++.
	However, they ARE called.
	c++ calls all of the default constructors of all the superclasses when it creates an object from the subclass.
*/

class Machine {
private:
	int id;

public: 
	Machine(): id(0) { cout << "Machine no-argument constructor called." << endl; }
	Machine(int id) : id(id) { cout << "Machine parameterized constructor called." << endl; }
	void info() { cout << "ID: " << id << endl; }
};

class Vehicle : public Machine {
public:
	Vehicle() { cout << "Vehicle no-argument constructor called." << endl; }

	// By including the superclass constructor in the initialization list, you can call the superclass' constructor. 
	Vehicle(int id): Machine(id) { cout << "Vehicle parameterized constructor called." << endl; }
};

class Car : public Vehicle {
public:
	// Calling Vehicle constructor, be sure to include parameters.
	// You cannot call indirect superclass constructors.
	Car(): Vehicle(125) { cout << "Car no-argument constructor called." << endl; }
};

int main() {

	Machine machine(123);
	machine.info();

	// The machine contructor will be called first, then the vehicle constructor.
	Vehicle vehicle(124);
	vehicle.info();

	Car car;
	car.info();

	return 0;
}