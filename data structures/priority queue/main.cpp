#include <iostream>

using namespace std;

template <typename T>
class Node{
    T val;
    int priority;
    Node* next;
public:
    Node():next(nullptr),priority(0){}
    Node(T v):val(v),next(nullptr),priority(0){}
    Node(T v,int p):val(v),priority(p),next(nullptr){}
    T get_val(){
    return this->val;
    }
    int get_priority(){
        return this->priority;
    }
    Node* get_next(){
        return this->next;
    }
    void set_val(T v){
        this->val = v;
    }
    void set_next(Node* n){
        this->next = n;
    }
    void set_priority(int p){
        this->priority = p;
    }
    bool operator >=(Node<T>* n){
        return this->priority>=n->get_priority();
    }
};

template <typename T>
class PriorityQueue{
    Node<T>* head;
public:
    PriorityQueue():head(nullptr){}
    void qdeque(){
        if(head==nullptr){
            cout<<"Cannot Delete From An Empty Queue !!\n";
            return;
        }
        else{
            Node<T> *temp = head;
            head = temp->get_next();
            delete temp;
        }
    }
    void qenque(T v,int p){
        Node<T> *n = new Node<T>(v,p);
        if(head==nullptr){
            head = n;
            return;
        }
        else{
            Node<T> *temp = head;
            Node<T> *prev = nullptr;
            while(temp->get_next()!=nullptr&&*temp>=n){

                prev = temp;
                temp = temp->get_next();
            }
            if(*temp>=n){
                temp->set_next(n);
            }
            else{
                    if(prev==nullptr){
                        head = n;
                        n->set_next(temp);
                    }
                    else{
                        n->set_next(prev->get_next());
                        prev->set_next(n);
                    }
            }
            return;

        }
    }
    T get_top(){
        if(head==nullptr){
            cout<<"Empty Queue!!\n";
            return -1;
        }
        else{
            return head->get_val();
        }
    }

};

int main()
{
    PriorityQueue<int> priority_q;
    while(true){
        cout<<"Options : 1) Enque 2) Deque 3) Get Top 4) Exit\n\n";
        int opt;
        cout<<"Enter option : ";
        cin>>opt;
        switch(opt){
            case(1):{
                int val,pri;
                cout<<"Enter Value : ";
                cin>>val;
                cout<<"Enter Priority : ";
                cin>>pri;
                priority_q.qenque(val,pri);
                cout<<"Enqueued Successfully!!\n";
                break;}
            case(2):{
                priority_q.qdeque();
                break;}
            case(3):{
                int val = priority_q.get_top();
                if(val==-1){
                    continue;
                }
                else{
                    cout<<"Value at top : "<<val<<endl;
                }
                break;}
            case(4):{
                cout<<"Thank You\n";
                return 0;}
            default:{cout<<"Invalid Option!!\n";}
        }
    }
    return 0;
}
