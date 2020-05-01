#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue queue;

    int addArr[] = { 1, 2 };
    for (auto val : addArr) {
        queue.enqueue<int>(val);
    }

    for (auto i : addArr) {
        cout << queue.dequeue<int>() << ", " << flush;
    }
}