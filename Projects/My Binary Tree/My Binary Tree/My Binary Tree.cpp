#include <iostream>
#include "BinaryTree.h"
#include "Util.h"
using namespace std;

int main() {
	BinaryTree tree;

	int addArray[] = { 10, 3, 11, 23, 1 };
	for (int v : addArray) {
 		if (ErrorCodes::FAILURE == tree.insertNode(v)) {
			return 1;
		}
	}

	// tree.printTree();

	return 0;
}