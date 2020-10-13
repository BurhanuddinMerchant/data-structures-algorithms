#include <iostream>
#define MAX_SIZE 100000
using namespace std;
class Queue{
    long long qfront;
    long long qrear;
    long long queue_array[MAX_SIZE];
public:
    Queue():qfront(-1),qrear(-1){}
    bool isEmpty(){
        return qfront==qrear && qfront==-1 ;
    }
    bool IsFull()
	{
		return (qrear+1)%MAX_SIZE == qfront ? true : false;
	}
    void enque(long long x){
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
    void deque_element(){
        if(isEmpty()){
            cout<<"Error!! Cannot deque empty queue!!\n";
        }
        else if(qfront==qrear){
            qfront=qrear=-1;
        }
        else{
            qfront=(qfront+1)%MAX_SIZE;
        }
    }
    long long get_front(){
        if(isEmpty()){
            cout<<"Error!! Cannot return front from empty queue!\n";
            return -1;
        }
        else{
            return queue_array[qfront];
        }
    }

};
int main()
{
    Queue q;
    //q.enque(x);
    //q.deque();
    //q.get_front();
    return 0;
}
