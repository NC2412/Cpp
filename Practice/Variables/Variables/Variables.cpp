#include <iostream> 
using namespace std;

int main() {

	// allocates memory to store an integer
	// very important to give variables specific names
	int cats = 2;

	// use underscores to separate names
	int num_dogs = 2;

	// or camelcase
	int totalNum = cats + num_dogs;

	// cannot start a variable name with numbers
	// BE CONSISTENT WITH NAMING SCHEME

	cout << "Number of cats: " << cats << endl;
	cout << "Number of dogs: " << num_dogs << endl;

	cout << "Total number of animals: " << totalNum << endl;

	cout << "New dog acquired." << endl;

	num_dogs++;

	cout << "New number of dogs: " << num_dogs << endl;

	return 0;
}