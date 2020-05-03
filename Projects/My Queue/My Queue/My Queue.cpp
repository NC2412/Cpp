#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue <int>queue;

    int addArr[] = { 1, 2 };
    for (auto val : addArr) {
        queue.enqueue(val);
    }

    for (auto i : addArr) {
        cout << queue.dequeue() << ", " << flush;
    }
}