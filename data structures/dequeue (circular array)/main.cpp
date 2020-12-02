#include <iostream>
#define MAX_SIZE 100000
using namespace std;
class DEQueue{
    int qfront;
    int qrear;
    int queue_array[MAX_SIZE];
public:
    DEQueue():qfront(-1),qrear(-1){}
    bool isEmpty(){
        return qfront==qrear && qfront==-1 ;
    }
    bool IsFull()
	{
		return (qrear+1)%MAX_SIZE == qfront ? true : false;
	}
    void enque_rear(int x){
        if(IsFull()){
                cout<<"Queue Full!!\n";
                return;
        }
        else if(isEmpty()){
            qfront=qrear=0;
        }
        else{
            qrear=(qrear+1)%MAX_SIZE;
        }
        queue_array[qrear]=x;
    }
    void enque_front(int x){
        if(IsFull()){
                cout<<"Queue Full!!\n";
                return;
        }
        else if(isEmpty()){
            qfront=qrear=0;
        }
        else{
            if(qfront==0){
                qfront = MAX_SIZE-1;
            }
            else{
                qfront-=1;
            }
        }
        queue_array[qfront]=x;
    }
    void dequeue_front(){
        if(isEmpty()){
            cout<<"Error!! Cannot dequeue empty queue!!\n";
        }
        else if(qfront==qrear){
            qfront=qrear=-1;
        }
        else{
            qfront=(qfront+1)%MAX_SIZE;
        }
    }
    void dequeue_rear(){
        if(isEmpty()){
            cout<<"Error!! Cannot dequeue empty queue!!\n";
        }
        else if(qfront==qrear){
            qfront=qrear=-1;
        }
        else{
            qrear=(qrear-1)%MAX_SIZE;
        }
    }
    int get_front(){
        if(isEmpty()){
            cout<<"Error!! Cannot return front from empty queue!\n";
            return -1;
        }
        else{
            return queue_array[qfront];
        }
    }
    int get_rear(){
        if(isEmpty()){
            cout<<"Error!! Cannot return front from empty queue!\n";
            return -1;
        }
        else{
            return queue_array[qrear];
        }
    }

};
int main()
{
    DEQueue dequeue;
    while(true){
        cout<<"Menu : 1) Enqueue 2) Dequeue 3) Display 4) Exit\n\n";
        cout<<"Enter option : ";
        int option ;
        cin>>option;
        switch(option){
            case(1):{
                cout<<"Operation End : 1) Front 2) Rear (default)\n\n";
                int opt,e;
                cout<<"Enter option : ";
                cin>>opt;
                cout<<"Enter the Element to be Enqueued : ";
                cin>>e;
                switch(opt){
                    case(1):{
                        dequeue.enque_front(e);
                        break;
                    }
                    default:{
                        dequeue.enque_rear(e);
                    }
                }
                cout<<"Enqueued Successfully!!\n\n";
                break;
            }

            case(2):{
                cout<<"Operation End : 1) Rear 2) Front (default)\n\n";
                int opt;
                cout<<"Enter option : ";
                cin>>opt;
                switch(opt){
                    case(1):{
                        dequeue.dequeue_rear();
                        break;
                    }
                    default:{
                        dequeue.dequeue_front();
                    }
                }
                cout<<"Dequeued Successfully!!\n\n";
                break;
                }
            case(3):{
                cout<<"Operation End : 1) Front 2) Rear (default)\n\n";
                int opt;
                cout<<"Enter option : ";
                cin>>opt;
                switch(opt){
                    case(1):{
                        int val = dequeue.get_front();
                        if(val==-1){
                            continue;
                        }
                        else{
                            cout<<"Queue Front : "<<val<<endl;
                        }
                        break;
                    }
                    default:{
                        int val = dequeue.get_rear();
                        if(val==-1){
                            continue;
                        }
                        else{
                            cout<<"Queue Rear : "<<val<<endl;
                        }
                    }
                }
                break;}
            case(4):{cout<<"Thank You\n\n";return 0;}
            default:{
                cout<<"Invalid Option \n\n";
            }
        }
    }
    return 0;
}
