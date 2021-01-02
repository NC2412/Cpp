#include <iostream>
#include "StringVector.h"
using namespace std;

int main()
{
        StringVector list(10);

        char num[] = "index: 0";
        for (int i = 0; i < 20; i++) {
            num[7] = '0' + i;
            list.add(num);

            if (list.indexOf(num) < 0) {
                cout << "ERROR, CANNOT FIND: " << num << endl;
            }
            else {
                cout << "Added: " << num << endl;
            }
        }

        for (int i = 0; i < list.getSize(); i++) {
            cout << list.get(i) << ", " << flush;
        }

        cout << endl << list.remove(0) << endl;

        cout << endl;
        for (int i = 0; i < list.getSize(); i++) {
            cout << list.get(i) << ", " << flush;
        }

        cout << list.remove("index: 1") << endl;

        cout << endl;
        for (int i = 0; i < list.getSize(); i++) {
            cout << list.get(i) << ", " << flush;
        }

        list.add("");
        list.remove("asdf");

    return 0;
}