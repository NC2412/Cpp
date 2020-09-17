#include <iostream>
using namespace std;

// Memoization is a bit like memorization.
// It uses a global list to store recursive values. 
//  - This is much more space and memory efficient. 
int fibNumbers[10];

// Here is the fibonacci recursive method that uses memoization.
int fibMemoization(int n) {
	if (fibNumbers[n] != 0)
		return fibNumbers[n];
	else if (n < 2) {
		fibNumbers[n] = n;
		return n;
	}
	else {
		fibNumbers[n] = fibMemoization(n - 1) + fibMemoization(n - 2);
		return fibNumbers[n];
	}
}

// Here is the fibonacci recursive method without memoization.
//  - You can see how it is less code, yet it is more taxing on space and time.
int fib(int n) {
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main() {
	int n = 5;

	cout << "Fibonacci of " << n << " with memoization: " << fibMemoization(n) << endl;
	cout << "The values of fibNumbers: " << flush;

	for (int i : fibNumbers)
		cout << i << ", " << flush;
	cout << endl;

	cout << "Fibonacci of " << n << " without memoization: " << fib(n) << endl;

	return 0;
}