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
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
//Problem 1: Delete the middle node of a linked list
//If there are even nodes, then there would be two middle nodes, we need to delete the second middle node
//For Brute Force Approach we can reach the node just before the middle node and then delete the middle node
Node* DeleteMiddleBruteForce(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    int mid=count/2;
    temp=head;
    for(int i=0;i<mid-1;i++){
        temp=temp->next;
    }
    Node* nodeToDelete=temp->next;
    temp->next=temp->next->next;
    delete nodeToDelete;
    return head;
} //TC=O(2n)
//For Optimal Approach we can use Tortoise and Hare Algorithm to reach the middle node in one traversal
Node* DeleteMiddleOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* slow=head;
    Node* fast=head;
    Node* prev=nullptr;
    while(fast!=nullptr && fast->next!=nullptr){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=slow->next;
    delete slow;
    return head;
} //TC=O(n)
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head1=ConvertArray2LL(arr);
    cout<<"Linked list after deleting middle node: ";
    head1=DeleteMiddleOptimal(head1);
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    delete head1;
    cout<<endl;
    return 0;
}