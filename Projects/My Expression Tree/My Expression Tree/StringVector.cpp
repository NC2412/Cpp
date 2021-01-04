#include "StringVector.h"
#include <iostream>

bool StringVector::add(int index, string item)
{
    if (item == "") {
        return 0;
    }

    if (size == capacity) {
        resize();
    }

    if (items[index] != "") {
        pushItemsBack(index);
    }
    
    *(items + index) = item;
    size++;

    return 1;
}

StringVector::~StringVector()
{
    for (int i = 0; i < capacity; i++)
        cout << items[i] << ", " << flush;
    delete[] items;
}

string StringVector::remove(string item)
{
    int index = indexOf(item);

    if (index == -1) {
        return "";
    }
    else {
        return remove(index);
    }
}

string StringVector::remove(int index)
{
    string retItem = "";

    if (index < 0 || index >= size) {
        return "";
    }

    retItem = items[index];
    items[index] = "";

    pushItemsForward(index);

    return retItem;
}

string StringVector::get(int index)
{
    return items[index];
}

int StringVector::indexOf(string item) {
    for (int i = 0; i < size; i++) {
        if (item == items[i]) {
            return i;
        }
    }

    return -1;
}

bool StringVector::resize() {
    string* temp = new string[capacity * 2];

    for (int i = 0; i < size; i++) {
        temp[i] = items[i];
    }

    capacity *= 2;
    items = temp;
    return 1;
}

bool StringVector::pushItemsBack(int start) {
    for (int i = size; i > start; i--) {
        items[i] = items[i - 1];
    }

    return 1;
}

bool StringVector::pushItemsForward(int start) {

    string temp;
    for (int i = start; i < size - 1; i++) {
        temp = items[i];
        items[i] = items[i + 1];
        items[i + 1] = temp;
    }

    return 1;
}