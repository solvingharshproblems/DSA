#include <iostream>
#include <vector>
using namespace std;
//Creation of a Linked List
class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node *next1){
        data=data1;
        next=next1; 
    }
    Node(int data1){
        data=data1;
        next=nullptr; 
    }
};
int main(){
    vector<int> arr={10,20,30,40,50};
    Node* y=new Node(arr[0],nullptr);
    cout<<y->data<<endl;
    return 0;
}