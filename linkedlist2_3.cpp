#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
        Node(int data1,Node* next1,Node* prev1){
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
Node* ConvertArray2DLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
//Problem 1: Reverse a DLL
//For brute force approach, we can temporarily store the values in stack and then push them back in DLL
Node* ReverseDLLBruteForce(Node*& head){
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(!st.empty()){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
} //TC=O(2n) SC=O(n)
//For optimal approach, we can reverse the links of pointers
Node* ReverseDLLOptimal(Node*& head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev==nullptr?nullptr:prev->prev;;
} //TC=O(n) 
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2DLL(arr);
    cout<<"The elements of the linked list are: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=ReverseDLLBruteForce(head);
    cout<<"After reversing (brute force): ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=ReverseDLLOptimal(head);
    cout<<"After reversing (optimal): ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}