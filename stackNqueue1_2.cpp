#include <iostream>
using namespace std;
//Implementing stack using linked list
class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
};
class Stack{
    public:
        Node* top;
        int size=0;
        int Push(int x){
            Node* newNode=new Node(x);
            if(!newNode){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                newNode->next=top;
                top=newNode;
                size++;
            }
            return x;
        } // TC=O(1) SC=O(1)
        int Pop(){
            if(top==NULL){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            else{
                int x=top->data;
                Node* temp=top;
                top=top->next;
                delete temp;
                size--;
                return x;
            }
        } // TC=O(1) SC=O(1)
        int Top(){
            if(top==NULL){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            else{
                return top->data;
            }
        } // TC=O(1) SC=O(1)
        int Size(){
            return size;
        } // TC=O(1) SC=O(1)    
};
int main(){
    Stack s;
    s.top=NULL;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout<<"The top element is: "<<s.Top()<<endl;
    cout<<"The size of the stack is: "<<s.Size()<<endl; 
    cout<<"Popped element is: "<<s.Pop()<<endl; 
    cout<<"The size of the stack is: "<<s.Size()<<endl; 
    return 0;
}