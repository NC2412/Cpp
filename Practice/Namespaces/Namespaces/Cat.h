#pragma once

#include <iostream>
using namespace std;

namespace cats {
	
	// global variables are all caps.
	const string NAME = "Freddy";

	class Cat
	{
	public:
		Cat();
		virtual ~Cat();
		void speak();
	};
}

