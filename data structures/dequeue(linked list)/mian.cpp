#include <iostream>

using namespace std;
class Node{
    int val;
    Node* prev;
    Node* next;
public:
    Node():val(0),prev(nullptr),next(nullptr){}
    Node(int v):val(v),prev(nullptr),next(nullptr){}
    void setVal(int v){
        this->val=v;
    }
    void setPrev(Node* p){
        this->prev=p;
    }
    void setNext(Node* n){
        this->next=n;
    }
    int getVal(){
        return this->val;
    }
    Node* getPrev(){
        return this->prev;
    }
    Node* getNext(){
        return this->next;
    }
};
class Dequeue{
    Node* head;
    Node* tail;
public:
    Dequeue():head(nullptr),tail(nullptr){}
    void insert_at_head(int v){
        Node* new_node = new Node(v);
        if(head==nullptr){
            head = new_node;
            tail = head;
        }
        else{
            new_node->setNext(head);
            head->setPrev(new_node);
            head= new_node;
        }
    }
    void insert_at_tail(int v){
        Node* new_node = new Node(v);
        if(tail==nullptr){
            head = new_node;
            tail = head;
        }
        else{
            new_node->setPrev(tail);
            tail->setNext(new_node);
            tail = new_node;
        }
    }
    void delete_at_head(){
        if(head==nullptr){
            cout<<"Cannot delete from an empty List\n";
            return;
        }
        Node* n = head;
        head = n->getNext();
        if(head!=nullptr){
            head->setPrev(nullptr);
        }
        delete n;
    }
    void delete_at_tail(){
        if(tail==nullptr){
            cout<<"Cannot delete from an empty List\n";
        }
        else{
            Node* n = tail;
        tail = n->getPrev();
        if(tail!=nullptr){
            tail->setNext(nullptr);
        }
        delete n;
        }

    }
    int get_front(){
        if(head==nullptr){
            cout<<"Error Empty Queue\n";
            return -1;
        }
        else{
            return head->getVal();
        }
    }

    int get_rear(){
        if(tail==nullptr){
            cout<<"Error Empty Queue\n";
            return -1;
        }
        else{
            return tail->getVal();
        }
    }

};
int main()
{
    Dequeue d;
    cout<<d.get_front()<<endl;
    d.insert_at_head(5);
    d.insert_at_tail(8);
    cout<<d.get_front()<<endl;
    cout<<d.get_rear()<<endl;
    d.insert_at_head(10);
    cout<<d.get_front()<<endl;
    d.insert_at_tail(20);
    cout<<d.get_rear()<<endl;
    d.delete_at_head();
    cout<<d.get_front()<<endl;
    d.delete_at_tail();
    cout<<d.get_rear()<<endl;
    d.delete_at_tail();
    cout<<d.get_rear()<<endl;
    cout<<d.get_front()<<endl;
    d.delete_at_tail();
    d.delete_at_tail();

    return 0;
}
