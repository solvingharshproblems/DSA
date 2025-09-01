#include <iostream>
#include <vector>
using namespace std;
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
Node* ConvertArray2LL(vector<int> arr){
    if(arr.empty()) return nullptr;
    Node* head=new Node(arr[0]);;
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node *n=new Node(arr[i]);
        temp->next=n;
        temp=temp->next;
    }
    return head;
}
//Problem 1: Insert element at the head of the linked list
Node* insertAtHead(Node*& head,int value){
    Node* n=new Node(value);
    n->next=head;
    head=n;
    return head;
}
//Problem 2: Insert element at the tail of the linked list
Node* insertAtTail(Node*& head,int value){
    Node* n=new Node(value);
    if(head==nullptr){
        head=n;
        return head;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=n;
    return head;
}
//Problem 3: Insert kth element of the linked list
Node* insertAtKthPosition(Node*& head,int value,int k) {
    if (k == 1) {
        return insertAtHead(head, value);
    }
    Node* n=new Node(value);
    Node* temp=head;
    int i=1;
    while(i<k-1 && temp!=nullptr){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr) {
        delete n;
        return head;
    }
    n->next=temp->next;
    temp->next=n;
    return head;
}
//Problem 4: Insert element of a specific value into the linked list
Node* insertElement(Node*& head,int value){
    if(head==nullptr){
        return insertAtHead(head,value);
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* n=new Node(value);
    temp->next=n;
    return head;
}
int main(){
    int size;
    cout<<"Enter the size of linked list: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the linked list: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2LL(arr);
    int value1;
    cout<<"Enter the value to insert at head: ";
    cin>>value1;
    cout<<"After inserting at head: ";
    head=insertAtHead(head,value1);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value2;
    cout<<"Enter the value to insert at tail: ";
    cin>>value2;
    cout<<"After inserting at tail: ";
    head=insertAtTail(head,value2);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int k;
    cout<<"Enter the position to insert: ";
    cin>>k;
    head=insertAtKthPosition(head,-1,k);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value;
    cout<<"Enter the value to insert: ";
    cin>>value;
    head=insertElement(head,value);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}