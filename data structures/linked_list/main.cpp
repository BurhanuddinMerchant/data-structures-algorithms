#include <iostream>

using namespace std;

class Node{
    public:
    Node *next;
    int value;
    void insertNodeAtEnd(Node **head,int val){
        Node *new_Node = new Node;
        if(*head==nullptr){
            *head = new_Node;
            new_Node->next=nullptr;
            new_Node->value=val;
            return;
        }
        Node *node = *head;
        while(node->next!=nullptr){
            node=node->next;
        }
        node->next=new_Node;
        new_Node->value=val;
        new_Node->next=nullptr;
        return;
    }

    void insertNodeAtHead(Node **head,int val){
        Node *new_node = new Node;
        if(*head==nullptr){
            *head = new_node;
            new_node->next = nullptr;
            new_node->value = val;
        }
        else{
            Node *temp = *head;
            new_node->next = temp;
            new_node->value = val;
            *head = new_node;
        }
    }
    void insertNodeAtIndex(Node **head,int val,int index){
        Node *new_node = new Node();
        new_node->value = val;
        new_node->next = nullptr;
        if(index==1){
            new_node->next = *head;
            *head = new_node;
            return;
        }
        Node *temp = *head;
        int i;
        for (i = 0; i < index - 2 && temp!=nullptr;i++){
            temp = temp->next;
        }
        if(i==index-2 && temp!=nullptr){
            new_node->next = temp->next;
            temp->next = new_node;
            cout << "here\n";
            cout << "temp : "<<temp->value<<endl;
            cout << "new : "<<new_node->value<<endl;
        }
       else{
           cout << "Error : Index out of range!!\n";
        }

    }
    void deleteNode(Node **head,int index){
        if(*head==nullptr){
            cout << "Error : Cannot delete from an empty list!!\n";
            return;
        }
        else {
            Node *node = *head;
            if(index==1){
                *head = node->next;
                delete node;
                return;
            }
            int i;
            for (i = 0; i < index - 2 && node->next!=nullptr;i++){
                node = node->next;
            }
            if(i==index-2 && node->next!=nullptr){
                Node *temp = node->next;
                node->next = temp->next;
                delete temp;
            }
            else{
                cout << "Error! List index out of range!!\n";
            }
        }
    }
    void deleteNodeAtHead(Node **head){
        if(*head==nullptr){
            cout<<"Cannot Delete From An Empty List !!\n";
            return;
        }
        else{
            Node *temp = *head;
            *head = temp->next;
            delete temp;
        }
    }

    void deleteNodeAtTail(Node **head){
        if(*head==nullptr){
            cout<<"Cannot Delete From An Empty List !!\n";
            return;
        }
        else{
            Node *temp = *head;
            Node *prev = *head;
            while(temp->next!=nullptr){
                prev = temp;
                temp = temp->next;
            }
            if(temp==*head){
                delete *head;
                *head = nullptr;
            }
            else{
            delete temp;
            prev->next = nullptr;
            }
        }
    }
    void printList(Node **head){
        if(*head==nullptr){
            cout<<"Empty Linked List\n";
        }
        else{
            Node *node= *head;
            while(node!=nullptr){
                cout<<"value at : "<<node<<" = " <<node->value<<endl;
                node=node->next;
            }
        }
    }

};

class LinkList{
    Node *head;
public:
    LinkList():head(nullptr){}//default constructor
    void insert_node_at_end(int element){
        head->insertNodeAtEnd(&head,element);
    }
    void insert_node_at_head(int element){
        head->insertNodeAtHead(&head, element);
    }
    void insert_node_at_index(int element,int index){
        //1 based indexing followed
        head->insertNodeAtIndex(&head, element, index);
    }
    void delete_node_at_index(int index){
        //1 based indexing followed
        head->deleteNode(&head,index);
    }
    void delete_node_at_tail(){
        head->deleteNodeAtTail(&head);
    }
    void delete_node_at_head(){
        head->deleteNodeAtHead(&head);
    }
    void print_list(){
        head->printList(&head);
    }
};

int main()
{
    LinkList l;
    cout<<"Singly Linked List : \n";
    while(true){
        cout<<"Operations : \n1)Print List\n2)Add Element At Head\n";
        cout<<"3)Add Element At Tail\n4)Add Element At Index\n";
        cout<<"5)Delete Element At Head\n6)Delete Element At Tail\n";
        cout<<"7)Delete Element At Index\n8)Exit\n";
        int option;
        cout<<"Enter the Option : ";
        cin>>option;
        switch (option){

            case(1):{
                cout<<"\nCurrent state of List : \n";
                l.print_list();
                cout<<"\n";
                break;
            }
            case(2):{
                int e;
                cout<<"\nEnter element to be added at Head: ";
                cin>>e;
                l.insert_node_at_head(e);
                cout<<"\nElement added \n";
                break;
                }
            case(3):{
                int e;
                cout<<"\nEnter element to be added at Tail: ";
                cin>>e;
                l.insert_node_at_end(e);
                cout<<"\nElement added \n";
                break;
                }
            case(4):{
                int i,e;
                cout<<"\nEnter the element : ";
                cin>>e;
                cout<<"\nEnter the index :";
                cin>>i;
                l.insert_node_at_index(e,i);
                cout<<"\n";
                break;
                }
            case(5):{
                cout<<"\nDelete At Head Initiated\n";
                l.delete_node_at_head();
                cout<<"\n";
                break;
                }
            case(6):{
                cout<<"\nDelete At Tail Initiated\n";
                l.delete_node_at_tail();
                cout<<"\n";
                break;
                }
            case(7):{
                int i;
                cout<<"\nEnter the Index to be deleted : ";
                cin>>i;
                cout<<"\nDelete Initiated \n";
                l.delete_node_at_index(i);
                break;
                }
            case(8):{
                break;
                }
            default:{
            cout<<"Invalid Option\n";
            }

        }
        cout<<"\n";
        if(option==8){
            break;
        }

    }
    cout<<"Thank You\n";
    return 0;

}
