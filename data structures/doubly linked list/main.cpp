#include <iostream>

using namespace std;

class Node{
public :
    Node *next;
    Node *prev;
    int value;
    Node():next(nullptr),prev(nullptr),value(0){}
    Node(int v):next(nullptr),prev(nullptr),value(v){}
};

void insert_node_at_tail(Node **head,int val){
    Node *new_node = new Node(val);
    if(*head==nullptr){
        *head = new_node;
        return;
    }
    else{
        Node *temp = *head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insert_at_head(Node **head,int val){
    Node *node = new Node(val);
    if(*head == nullptr){
        *head = node;
        return;
    }
    Node *temp = *head;
    *head = node;
    temp->prev = node;
    node->next=temp;
}

void insert_node_at_index(Node **head,int val,int index){
    //1 based indexing
    Node *new_node = new Node(val);
    if(index==1){
        new_node->next = *head;
        if(*head==nullptr){
            return;
        }
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }
    Node *temp = *head;
    int i;
    for(i=0;i<index-2 && temp !=nullptr;i++){
            cout<<"here\n";
    cout<<"temp : "<<temp<<endl;
    cout<<" i : "<<i<<endl;
    cout<<"temp->next " <<temp->next<<endl;
        temp = temp->next;
    }
    if(i==index-2 && temp !=nullptr){
        if(temp->next==nullptr){
        temp->next = new_node;
        new_node->prev = temp;
        }
        else{
        new_node->next = temp->next;
        new_node->prev = temp;
        (temp->next)->prev = new_node;
        temp->next = new_node;
        }
    }
    else{
        cout<<"\n\nError : Index out of range!!\n";
    }
}

void delete_node_at_tail(Node **head){
    if(*head==nullptr){
        cout<<"Error !! Cannot delete from empty list!!\n";
        return;
    }
    else if((*head)->next == nullptr){
            delete (*head)->next;
            (*head) = nullptr;
            return;
    }
    Node *temp = *head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node *node = temp->prev;
    node->next = nullptr;
    delete temp;
}

void delete_node_at_head(Node **head){
    if(*head == nullptr){
        cout<<"Error : Cannot delete from an empty list!!\n";
    }
    else{
        if((*head)->next==nullptr){
            delete *head;
            *head = nullptr;
            return;
        }
        Node *temp = *head;
        *head = temp->next;
        (*head)->prev = nullptr;
        delete temp;
    }
}


void print_node(Node **head){
    Node *temp = *head;
    int i=1;
    while(temp!=nullptr){
        cout<<"\nNode "<<i<<endl;
        cout<<" Prev : "<<temp->prev<<endl;
        cout<<" Current : "<<temp<<endl;
        cout<<" Value : "<<temp->value<<endl;
        cout<<" Next : "<<temp->next<<endl;
        temp=temp->next;
        i++;
    }
}

int main()
{
    Node *head = new Node();
    head = nullptr;
    delete_node_at_head(&head);
    insert_at_head(&head,700);
    delete_node_at_head(&head);
    insert_node_at_tail(&head,5);
    insert_node_at_tail(&head,6);
    insert_node_at_tail(&head,9);
    insert_node_at_tail(&head,8);
    print_node(&head);
    insert_node_at_index(&head,90,1);
    print_node(&head);
    insert_at_head(&head,700);
    print_node(&head);
    delete_node_at_tail(&head);
    print_node(&head);
    delete_node_at_head(&head);
    print_node(&head);
    return 0;
}
