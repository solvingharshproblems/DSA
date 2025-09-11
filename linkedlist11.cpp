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
//Problem 1: Rotate a LL by K nodes
//For Optimal Approach we can use the concept of making a circular LL
Node* RotateLL(Node* head,int k){
    if(head==nullptr || head->next==nullptr || k==0){
        return head;
    }
    Node* temp=head;
    int len=1;
    while(temp->next!=nullptr){
        temp=temp->next;
        len++;
    }
    temp->next=head;//converting to circular LL
    k=k%len;//when k>len
    int stepsToNewHead=len-k;
    while(stepsToNewHead--){
        temp=temp->next;
    }
    head=temp->next;
    temp->next=nullptr;//breaking the circular LL
    return head;
} //TC=O(2n)
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter elements of linked list: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2LL(arr);
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Linked List after rotation: ";
    Node* temp=RotateLL(head,k);
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}