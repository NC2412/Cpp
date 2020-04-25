#include <iostream>
using namespace std;

class Frog {

// Encapsulation is hiding instance variables or functions from outside code.
// This can be used so variables cannot be changed or methods cannot be accessed.
// A good practice is to encapsulate as much as you can.
private:
	string name;

// Another good practice is to separate your private variables with your private methods.
private:
	string getName() { return name; }

public:
	Frog(string name) : name(name) {}
	void info() { cout << "My name is: " << getName() << endl; }
};

int main() {

	Frog frog("Freddy");
	frog.info();

	return 0;
}