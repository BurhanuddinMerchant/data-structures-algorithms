#include <iostream>

using namespace std;

class Node{
    public:
    int value;
    Node *left;
    Node *right;
};
Node* getNewNode(int val){
    Node *node = new Node;
    node->value = val;
    node->left=nullptr;
    node->right=nullptr;
    return node;
}

bool search_node(Node *root,int val){
    if(root==nullptr){
        return false;
    }
    else if(root->value<=val){
        return search_node(root->left,val);
    }
    else {
        return search_node(root->right,val);
    }
}

void insert_node(Node **root,int val){
    if(*root==nullptr){
        *root = getNewNode(val);
    }
    else if(val<=((*root)->value)){
        insert_node(&((*root)->left),val);

    }
    else{
        insert_node(&((*root)->right),val);
    }
    return;
}

int main()
{
    Node *root;
    root = nullptr;
    insert_node(&root,15);
    insert_node(&root,10);
    insert_node(&root,20);
    return 0;
}
