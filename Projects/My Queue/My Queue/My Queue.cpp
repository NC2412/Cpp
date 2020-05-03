#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue <int>queue;

    int addArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    for (auto val : addArr) {
        queue.enqueue(val);
    }

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << ", " << flush;
    }
}