#include <iostream>
#include <queue>
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

int get_max(Node **root){
    if(*root==nullptr){
        cout<<"Error : Empty tree!!\n";
        return -1;
    }
    else if((*root)->right==nullptr){
        return (*root)->value;
    }
    return get_max(&((*root)->right));
}
int get_min(Node **root){
    if(*root==nullptr){
        cout<<"Error : Empty tree!!\n";
        return -1;
    }
    else if((*root)->left==nullptr){
        return (*root)->value;
    }
    return get_min(&((*root)->left));
}
//BFS algorithm
void level_order_traversal(Node **root){
    if(*root==nullptr){
        cout<<"Error : Empty Tree!!\n";
        return;
    }
    queue <Node*> nodeq;
    nodeq.push(*root);
    while(!nodeq.empty()){
        cout<<nodeq.front()->value<<" ";
        if(nodeq.front()->left!=nullptr){
            nodeq.push(nodeq.front()->left);
        }
        if(nodeq.front()->right!=nullptr){
            nodeq.push(nodeq.front()->right);
        }
        nodeq.pop();
    }
    cout<<endl;
}
//DFS algorithms
void preorder_traversal(Node **root){
    // value - left - right
    if(*root==nullptr) {
        return ;
    }
    cout<<(*root)->value<<" ";
    preorder_traversal(&((*root)->left));
    preorder_traversal(&((*root)->right));
}
void inorder_traversal(Node **root){
    // left - value - right
    if(*root==nullptr){
        return ;
    }
    inorder_traversal(&((*root)->left));
    cout<<(*root)->value<<" ";
    inorder_traversal(&((*root)->right));
}
void postorder_traversal(Node **root){
    // left - right - value
    if(*root==nullptr){
        return ;
    }
    postorder_traversal(&((*root)->left));
    postorder_traversal(&((*root)->right));
    cout<<(*root)->value<<" ";
}
int main()
{
    Node *root;
    root = nullptr;
    cout<<get_min(&root)<<endl;
    insert_node(&root,15);
    insert_node(&root,10);
    insert_node(&root,20);
    insert_node(&root,0);
    insert_node(&root,300);
    insert_node(&root,50);
    insert_node(&root,5);
    insert_node(&root,1);
    cout<<get_max(&root)<<endl;
    cout<<get_min(&root)<<endl;
    cout<<"Level order : ";
    level_order_traversal(&root);
    cout<<"Preorder : ";
    preorder_traversal(&root);
    cout<<endl;
    cout<<"Inorder : ";
    inorder_traversal(&root);
    cout<<endl;
    cout<<"Postorder : ";
    postorder_traversal(&root);
    cout<<endl;
    return 0;
}
