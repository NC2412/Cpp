#include "Animals.h"

namespace nac {

	Cat::Cat() {
		cout << "Cat created." << endl;
	}

	Cat::~Cat() {
		cout << "Cat destroyed." << endl;
	}

	void Cat::speak() {
		cout << "Meow from namespace." << endl;
	}

}