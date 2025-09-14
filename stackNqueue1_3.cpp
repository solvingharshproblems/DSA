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
//Implementing queue using stack
class Queue{
    public:
        stack<int> s1;
        stack<int> s2;
        int size=0;
        int Enqueue(int x){
            s1.push(x);
            size++;
            return x;
        } // TC=O(1) SC=O(1)
        int Dequeue(){
            if(s1.size()==0 && s2.size()==0){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            else{
                if(s2.size()==0){
                    while(s1.size()!=0){
                        s2.push(s1.top());
                        s1.pop();
                    }
                }
                int x=s2.top();
                s2.pop();
                size--;
                return x;
            }
        } // TC=O(n) SC=O(1)
        int Front(){
            if(s1.size()==0 && s2.size()==0){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            else{
                if(s2.size()==0){
                    while(s1.size()!=0){
                        s2.push(s1.top());
                        s1.pop();
                    }           
                }
                return s2.top();
            }
        } // TC=O(n) SC=O(1)
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
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    cout<<"The front element is: "<<q.Front()<<endl;
    cout<<"The size of the queue is: "<<q.Size()<<endl; 
    cout<<"Dequeued element is: "<<q.Dequeue()<<endl; 
    cout<<"The size of the queue is: "<<q.Size()<<endl;
    return 0;
}