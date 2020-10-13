#include <iostream>
using namespace std;
#define MAX_SIZE 1000
class Stack{
    long long top;
    long long stack_array[MAX_SIZE];
public:
    Stack():top(-1){}
    bool isEmpty(){return top==-1;}
    void pop(){
        if(this->isEmpty()){
            cout<<"Cannot POP from Empty Stack!!\n";
        }
        else{
            this->top-=1;
        }
    }
    void push(long long element){
        if(top==MAX_SIZE-1){
            cout<<"Stack overflow!!\n";
        }
        else{
            top+=1;
            stack_array[top]=element;
        }
    }
    long long peak(){
        if(isEmpty()){return -1;}
        else{
            return stack_array[top];
        }
    }
};
int main()
{
    Stack s;
    //s.push(value)
    //s.pop()
    //s.peak()
    //s.isEmpty()
    return 0;
}
