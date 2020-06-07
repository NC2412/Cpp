#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print(const string text) {
	mtx.lock();
	cout << text << endl;
	mtx.unlock();
}

// Keep count unsigned and const so it cannot change and it is never less that 0 (so the for loop doesn't break).
void threadFunc1(const unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		print((char)i + ": Hello from thread function 1!");
	}
}

void threadFunc2(const unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		print((char)i + ": Hello from thread function 2!");
	}
}

class personFunctor {
public:
	personFunctor(const int age, const string name) : age(age), name(name) {}

	string operator()() {
		return "Name: " + name + ", Age: " + (char)age + ", ";
	}

private:
	int age;
	string name;
};


int main() {

	personFunctor pfunc(17, "Nicolo Cammarano");

	thread t1(threadFunc1, 10);
	thread t2(threadFunc2, 10);
	//thread t3(pfunc());
	thread t4([](const unsigned int count) {
		for (unsigned int i = 0; i < count; i++) {
			print((char)i + ": Hello from lambda thread!");
		}
		}, 10);
	
	t1.join();
	t2.join();
	//t3.join();
	t4.join();

	return 0;
}