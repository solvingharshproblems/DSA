#include <iostream>
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
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
//Problem 2: Reverse nodes in K groups in a singly linked list
//For Optimal Approach we will use 3 helper functions 
Node* GetKthNode(Node* head,int k){ //This function returns the k-th node from the head
    Node* temp=head;
    while(temp!=nullptr && k>1){
        temp=temp->next;
        k--;
    }
    return temp;
}
Node* reverseDLL(Node* head){ //This function reverses the singly linked list and returns the new head
    Node* prev=nullptr;
    Node* curr=head;
    while(curr!=nullptr){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
Node* ReverseKGroupOptimal(Node* head,int k){ 
    if(head==nullptr || k<=1){
        return head;
    }
    Node* temp=head;
    Node* prevLast=nullptr;
    while(temp!=nullptr){
        Node* KthNode=GetKthNode(temp,k);
        if(KthNode==nullptr){
            break;
        }
        Node* nextGroupHead=KthNode->next;
        KthNode->next=nullptr;
        Node* revHead=reverseDLL(temp);
        if(temp==head){
            head=KthNode;
        }
        else{
            prevLast->next=KthNode;
        }
        prevLast=temp;
        temp=nextGroupHead;
    }
    return head;
} //TC=O(n)
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
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    Node* temp=ReverseKGroupOptimal(head,k);
    cout<<"The linked list after reversing in k groups is: ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}