//what is a stack?
//stack is a linear data structure which follows a particular order in which the operations are performed.
//The order may be LIFO(Last In First Out) or FILO(First In Last Out).
//The stack data structure has two main operations:
//1. push: which adds an element to the collection
//2. pop: which removes the most recently added element that was not yet removed.
//what is a queue?
//A queue is a linear structure which follows a particular order in which the operations are performed.
//The order is FIFO(First In First Out).
//The queue data structure has the following operations:
//1. enqueue: which adds an element to the end of the collection
//2. dequeue: which removes the first element that was added to the collection.
//Implementing stack using array
#include <iostream>
using namespace std;
class Stack{
    public:
        int top;
        int st[100]; // TC=O(1) SC=O(n)
        void Push(int x){
            if(top==99){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                top++;
                st[top]=x;
            }
            
        } // TC=O(1)
        int Top(){
            if(top==-1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                return st[top];
            }
        } // TC=O(1)
        int Pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else{
                int x=st[top];
                top--;
                return x;
            }
        } // TC=O(1)
        int Size(){
            return top+1;
        } // TC=O(1)
};

int main(){
    Stack s;
    s.top=-1;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout<<"Top element is: "<<s.Top()<<endl;
    cout<<"Stack size is: "<<s.Size()<<endl;
    cout<<"Popped element is: "<<s.Pop()<<endl;
    cout<<"Top element is: "<<s.Top()<<endl;
    cout<<"Stack size is: "<<s.Size()<<endl;
    return 0;
}