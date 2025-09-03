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
Node* CovertArray2LL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
//Problem 1: Add 2 numbers represented by linked lists 
//we will use a dummy node to simplify the addition process
Node* AddTwoNumbers(Node* head1,Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    Node* DummyNode=new Node(-1);
    Node* curr=DummyNode;
    int carry=0;
    while(t1!=nullptr || t2!=nullptr){
        int sum=carry;
        if(t1){
            sum+=t1->data;
        }
        if(t2){
            sum+=t2->data;
        }
        carry=sum/10;
        Node* newNode=new Node(sum%10);
        curr->next=newNode;
        curr=newNode;
        if(t1){
        t1=t1->next;
        }
        if(t2){
            t2=t2->next;
        }
    }
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
        curr=newNode;
    }
    return DummyNode->next;
} //TC=O(max(m,n)) SC=O(max(m,n)) for storing the result
int main(){
    int size1;
    cout<<"Enter the size of first linked list: ";
    cin>>size1;
    vector<int> arr1(size1);
    cout<<"Enter the elements of first linked list: ";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    Node* head1=CovertArray2LL(arr1);
    int size2;
    cout<<"Enter the size of second linked list: ";
    cin>>size2;
    vector<int> arr2(size2);
    cout<<"Enter the elements of second linked list: ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    Node* head2=CovertArray2LL(arr2);
    Node* head=AddTwoNumbers(head1,head2);
    cout<<"The elements of the resulting linked list are: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}