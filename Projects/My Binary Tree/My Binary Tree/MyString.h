#pragma once
#include <iostream>
using namespace std;

class MyString {
public:
	MyString() {};
	MyString(const string text) : text(text) {};
	~MyString() {};

	int operator<(const string text) {
		return text.length();
	}
	int operator<=(const string text) {
		return text.length();
	}
	int operator==(const string text) {
		return text.length();
	}
	int operator>(const string text) {
		return text.length();
	}
	int operator>=(const string text) {
		return text.length();
	}

	string getString() { return text; }
private:
	string text;
};