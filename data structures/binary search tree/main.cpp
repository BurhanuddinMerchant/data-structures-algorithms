#include "bst.h"
int main()
{
    BST<int> bst;
    bst.insertNode(10);
    bst.insertNode(20);
    bst.insertNode(5);
    bst.insertNode(1);
    bst.insertNode(2);
    cout << "\n\n";
    bst.printTree();
    return 1;
}