// Here is a link to float documentation: https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

#include <iostream> 

// iomanip stands for input output manipulation.
#include <iomanip>
using namespace std;

int main() {

	// float is used if you want a decimal value.
	// float, like any variable, allocates a specific amount of memory.
	// An f suffix is used to denote a literal of type float.
	float f_val = 76.4f;

	cout << fixed << f_val << endl;
	cout << scientific << f_val << endl;

	cout << sizeof(f_val) << endl;

	// double allows for more digits before the decimal point. 
	double d_val = 76.4;
	cout << setprecision(20) << fixed << d_val << endl;

	// long double can store a lot of sig figs.
	long double ld_val = 123.456789098654321;
	cout << setprecision(20) << fixed << ld_val << endl;
	cout << sizeof(long double) << endl;

	// Remember, float values are never what they seem.
	// float is only reliable for a certain amount of sig figs, 6-8.
	float num = 1.1;

	if (num == 1.1) {
		cout << "Equal." << endl;
	}
	else {
		cout << "Not equal." << endl;
	}

	return 0;
}