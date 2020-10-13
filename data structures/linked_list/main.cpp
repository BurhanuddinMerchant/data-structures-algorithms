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
    void print_list(){
        head->printList(&head);
    }
};

int main()
{
    LinkList l;
    l.insert_node_at_end(5);
    l.insert_node_at_head(6);
    l.insert_node_at_index(3, 1);
    l.insert_node_at_index(4, 2);
    l.insert_node_at_index(9, 5);
    l.insert_node_at_index(10, 7);
    l.insert_node_at_index(9, 0);
    l.insert_node_at_index(9, -1);
    l.print_list();
    cout << "here\n";
    l.delete_node_at_index(9);
    l.delete_node_at_index(2);
    l.print_list();
    //l.print_list();
    return 0;

}
