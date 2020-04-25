#include <iostream> 
using namespace std;

// Animal is the superclass to cat.
class Animal {
public:
	void speak() { cout << "Animal speaking." << endl; }
};
// The Animal doesn't know anything about Cat or Tiger.

// Inheritance is used when there is a class similar to another, but not quite the same.
// Cat is the subclass to Animal, but a superclass to Tiger.
// The syntax is subclass : superclass. Keep the superclass public, otherwise you cannot access it's methods.
class Cat : public Animal {
public:
	void jump() { cout << "Cat jumping." << endl; }
};
// Cat knows things about Animal, but nothing about tiger.

//Tiger is the subclass to Cat and an indirect subclass to Animal.
class Tiger : public Cat {
public:
	void roar() { cout << "Tiger roaring." << endl; }
};
// Tiger knows things about Cat and Animal.

int main() {

	Animal a;
	a.speak();

	Cat cat;
	cat.speak();
	cat.jump();

	Tiger tiger;
	tiger.speak();
	tiger.jump();
	tiger.roar();

	return 0;
}