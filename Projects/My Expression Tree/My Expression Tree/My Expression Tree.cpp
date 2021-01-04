#include <iostream>
#include "ExpressionTree.h"
#include "StringVector.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    ExpressionTree tree;
    string input;

    cout << "Enter an expression: " << flush;
    getline(cin, input);

    tree.buildTree(2, input);

    return 0;
}