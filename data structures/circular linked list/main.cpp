#include <iostream>

using namespace std;

class Node{
public:
    Node *next;
    int data;
    Node():next(nullptr),data(0){}
    Node(int val):next(nullptr),data(val){}
};
void insert_node(Node **head,int value){
    if(*head==nullptr){
        Node *node = new Node(value);
        *head = node;
        (*head)->next = node;
        return ;
    }
    Node *temp = *head;
    while(temp->next!=*head){
        temp = temp->next;
    }
    Node *new_node = new Node(value);
    temp->next = new_node;
    new_node->next = *head;

}

void print_list(Node **head){
    if(*head==nullptr){
        cout<<"Error : Empty List!!";
        return;
    }
    Node *temp = *head;
    while(temp->next!=*head){
        cout<<"Data : "<<temp->data<<endl;
        cout<<"Next : "<<temp->next<<endl;
        temp=temp->next;
    }
    cout<<"Data : "<<temp->data<<endl;
    cout<<"Next : "<<temp->next<<endl;
}

int main()
{
    Node *head = new Node;
    head = nullptr;
    insert_node(&head,6);
    insert_node(&head,7);
    insert_node(&head,8);
    print_list(&head);
    return 0;
}
