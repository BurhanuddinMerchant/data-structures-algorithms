#include "treeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BST
{
    TreeNode<T> *root;

public:
    BST() : root(nullptr) {}
    void insertNodeRecursive(TreeNode<T> *r, T v)
    {
        if (v > r->getVal())
        {
            if (r->getRightChild() == nullptr)
            {
                r->setRightChild(new TreeNode<T>(v));
                return;
            }
            else
                insertNodeRecursive(r->getRightChild(), v);
        }
        else
        {
            if (r->getLeftChild() == nullptr)
            {
                r->setLeftChild(new TreeNode<T>(v));
                return;
            }
            else
                insertNodeRecursive(r->getLeftChild(), v);
        }
    }
    void insertNode(T v)
    {
        if (this->root == nullptr)
            this->root = new TreeNode<T>(v);
        else
            insertNodeRecursive(this->root, v);
    }
    void printTreeRecursive(TreeNode<T> *r)
    {
        if (r == nullptr)
            return;
        else
        {
            printTreeRecursive(r->getLeftChild());
            cout << r->getVal() << " ";
            printTreeRecursive(r->getRightChild());
        }
    }
    void printTree()
    {
        printTreeRecursive(this->root);
    }
};
