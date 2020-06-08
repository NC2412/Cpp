#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void print(const char text[]) {
	mtx.lock();
	for (int i = 0; i < sizeof(text); i++) {
		cout << text[i] << flush;
	}
	cout << endl;
	mtx.unlock();
}

// Keep count unsigned and const so it cannot change and it is never less that 0 (so the for loop doesn't break).
void threadFunc1(const unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		print(i + ": Hello from thread function 1!");
	}
}

void threadFunc2(const unsigned int count) {
	for (unsigned int i = 0; i < count; i++) {
		print(i + ": Hello from thread function 2!");
	}
}

class Functor {
	void operator()(const char text[]) {
		print(text);
	}
};

int main() {

	Functor functor();
	//functor("Hello from () overload from main. NOT A THREAD.");

	thread t1(threadFunc1, 10);
	thread t2(threadFunc2, 10);
	thread t3(functor, "Hello from functor thread!");
	thread t4([](const unsigned int count) {
		for (unsigned int i = 0; i < count; i++) {
			print((char)i + ": Hello from lambda thread!");
		}
		}, 10);
	
	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}