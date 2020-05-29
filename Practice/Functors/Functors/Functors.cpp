#include <iostream>
using namespace std;

/*
	Functors are another way of passing blocks of code to something.
	Functors are an alternative to function pointers.
*/

struct Test {
	virtual bool operator()(string& text) = 0;

	virtual ~Test() {}
};

// THIS IS A FUNCTOR!!
// By default, everything in a struct is public. This is the opposite for classes.
struct MatchTest : public Test{
	// () are operators in c++. In this case, we overload the () operator and also define what we want to do with them.
	// The first () specifies what operator we are dealing with.
	// The second () is the argument list. 
	virtual bool operator()(string &text) {
		return text == "lion";
	}
};

void check(string text, Test& test) {
	if (test(text))
		cout << "Text matchdes!" << endl;
	else
		cout << "No match!" << endl;
}

int main() {
	
	// When passing 'pred' we are essentially passing around the code within MatchTest.
	MatchTest pred;

	string value = "lion";

	// This looks like a function call, but it's not.
	// This is a case of the () operator being overloaded our way.
	cout << pred(value) << endl;

	check(value, pred);

	return 0;
}