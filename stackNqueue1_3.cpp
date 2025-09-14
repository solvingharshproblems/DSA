#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
};
//Implementing stack using queue
class Stack{
    public:
        queue<int> q1;
        queue<int> q2;
        int size=0;
        void Push(int x){
            q2.push(x);
            size++;
            while(q1.size()!=0){
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp=q1;
            q1=q2;
            q2=temp;
        } // TC=O(n) SC=O(1)
        int Pop(){
            if(q1.size()==0){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else{
                size--;
                return q1.front();
            }
        } // TC=O(1) SC=O(1)
        int Top(){
            if(q1.size()==0){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                return q1.front();
            }
        } // TC=O(1) SC=O(1)
        int Size(){
            return size;
        } // TC=O(1) SC=O(1)
};
int main(){
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout<<"The top element is: "<<s.Top()<<endl;
    cout<<"The size of the stack is: "<<s.Size()<<endl; 
    cout<<"Popped element is: "<<s.Pop()<<endl; 
    cout<<"The size of the stack is: "<<s.Size()<<endl;
    return 0;
}