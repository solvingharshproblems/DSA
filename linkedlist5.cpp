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
        Node* n=new Node(arr[i]);
        temp->next=n;
        temp=n;
    }
    return head;
}
//Problem 1: Reverse a LL
//For Brute Force we can store the elements of the linked list in a stack and then pop the elements from the stack and modify the linked list
Node* ReverseBruteForce(Node* head){
    stack<int> s;
    Node* temp=head;
    while(temp!=nullptr){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=s.top();
        s.pop();
        temp=temp->next;
    }
    return head;
} //TC=O(2n) SC=O(n)
//Optimal Approach: We can reverse the linked list by changing the next pointers of each node
Node* ReverseOptimal(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
} //TC=O(n)
//We can also do it using recursion
Node* ReverseRecursive(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead=ReverseRecursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
} //TC=O(n) SC=O(n) due to recursion stack
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head1=ReverseBruteForce(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head2=ReverseOptimal(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    temp=head2;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head3=ReverseRecursive(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    temp=head3;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}