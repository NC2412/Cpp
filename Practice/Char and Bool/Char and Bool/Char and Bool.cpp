// Here is the link to an ASCII table: http://www.asciitable.com/.
// American Standard Code for Information Interchange (ASCII).

#include <iostream>
using namespace std;

int main() {

	// bool is used for true or false values.
	// 0 = false. 1 = true.
	bool b_val = false;
	cout << b_val << endl;

	b_val = 1;
	cout << b_val << endl;

	// char is for a single character.
	// char takes up exactly 1 byte.
	// char uses 's'ingle 'q'outes as a value.
	// char can also take a number up to 255, which represents an ASCII value.
	// char can only take an ASCII value from -128 to +127, 256 different values including 0.
	char c_val = 'n';
	char n_val = '7';
	char a_val = 126;
	cout << c_val << endl;
	cout << n_val << endl;
	cout << a_val << endl;

	// By typecasting a char, you will get the ASCII value.
	cout << (int)n_val << endl;
	cout << (int)c_val << endl;

	//The size of char is important because it can be used to allocate a specific number of bytes in memory.
	cout << sizeof(char) << endl;

	// wchar_t is used to represent a broader range of characters than char does.
	wchar_t w_val = 'i';
	cout << (char)w_val << endl;
	cout << sizeof(wchar_t) << endl;


	return 0;
}