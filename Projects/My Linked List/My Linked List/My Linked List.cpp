#include <iostream>
#include "LinkedList.h"
#include "Util.h"
using namespace std;

int main()
{
	ErrorCodes iRetCode = ErrorCodes::SUCCESS;
	LinkedList list(false);

	int addArray[] = { 4, 7, 100, -20, 0, 350, 350, -100, -100, 8, 10, 10 };
	int delArray[] = { -100, 10, 350 };

	for (int i : addArray) {
		if (ErrorCodes::FAILURE == list.insertNode(i))
			goto Exit;
	}
	/*
	for (int i : delArray) {
		if (ErrorCodes::FAILURE == list.deleteNode(i))
			goto Exit;
	}
	*/
	//if (ErrorCodes::FAILURE == list.deleteIndex(3))
	//	goto Exit;

	if (ErrorCodes::FAILURE == list.printList())
		goto Exit;

	//if (ErrorCodes::FAILURE == list.removeDuplicates())
	//	goto Exit;

	//if (ErrorCodes::FAILURE == list.reverseList())
	//	goto Exit;

	if (ErrorCodes::FAILURE == list.sortList())
		goto Exit;

	if (ErrorCodes::FAILURE == list.printList())
		goto Exit;

	//if (ErrorCodes::FAILURE == list.nFromTail(5))
	//	goto Exit;

	//cout << list.isSorted() << endl;
	//cout << list.hasCycle() << endl;
	cout << list.nFromTail(30) << endl;

 	return 0;

Exit:
	return 1;
}