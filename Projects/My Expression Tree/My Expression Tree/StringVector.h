#pragma once
#include <string>
using namespace std;

class StringVector
{
public:
	StringVector() { size = 0; capacity = 10; items = new string[capacity]; }
	StringVector(int size) : capacity(size), size(0) { items = new string[capacity]; }
	~StringVector() { delete[] items; }

	bool add(string item) { return add(this->size, item); }
	bool add(int, string);

	string remove(string);
	string remove(int);

	string get(int);
	int indexOf(string);
	int getSize() { return size; }
	
private:
	int size;
	int capacity;
	string* items;

	bool resize();
	bool pushItemsBack(int);
	bool pushItemsForward(int);
};

