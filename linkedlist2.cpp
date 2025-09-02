#include <iostream>
#include <vector>
using namespace std;
// Doubly linked list node
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1,Node *next1,Node *prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* ConvertArray2LL(vector<int> arr){
    Node *head=new Node(arr[0]);
    Node *prev=head;
    for(int i=1;i<arr.size();i++){
        Node *temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp; 
    }
    return head;

}
//Problem 1: Insert value at head of the DLL
Node* InsertatHead(Node*& head,int value){
    Node* temp=new Node(value);
    temp->next=head;
    if(head!=nullptr){
        head->prev=temp;
    }
    head=temp;
    return head;
} //TC=O(1)
//Problem 2: Insert value at tail of DLL
Node* InsertatTail(Node*& head,int value){
    Node* temp=head;
    if(head==nullptr){
        return InsertatHead(head,value);
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* n=new Node(value,nullptr,temp);
    temp->next=n;
    return head;
} //TC=O(n)
//Problem 3: Insert value at kth element of DLL
Node* InsertatKthPosition(Node*& head,int value,int k){
    if(k==1){
        return InsertatHead(head,value);
    }
    Node* temp=head;
    int i=1;
    while(i<k-1 && temp!=nullptr){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr){
        delete temp;
        return head;
    }
    Node* n=new Node(value);
    n->next=temp->next;
    temp->next=n;
    return head;
} //TC=O(n)
//Problem 4: Insert a specific value in DLL
Node* InsertValue(Node*& head,int value){
    if(head==nullptr){
        return InsertatHead(head,value);
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* n=new Node(value,nullptr,temp);
    temp->next=n;
    return head;
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2LL(arr);
    cout<<"The elements of the linked list are: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value1;
    cout<<"Enter the value to enter at the head: ";
    cin>>value1;
    head=InsertatHead(head,value1);
    cout<<"The elements of the linked list are: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value2;
    cout<<"Enter the value to enter at the tail: ";
    cin>>value2;
    head=InsertatTail(head,value2);
    cout<<"The elements of the linked list are: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value3;
    cout<<"Enter the value to enter at the kth position: ";
    cin>>value3;
    int k;
    cout<<"Enter the position: ";
    cin>>k;
    head=InsertatKthPosition(head,value3,k);
    cout<<"The elements of the linked list are: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value4;
    cout<<"Enter the value to enter in the DLL: ";
    cin>>value4;
    head=InsertValue(head,value4);
    cout<<"The elements of the linked list are: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}