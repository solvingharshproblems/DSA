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
//Converting Array to Linked List
Node* ConverArray2LL(vector<int> arr){
    Node *head=new Node(arr[0],nullptr);
    Node *temp=head;
    for(int i=1;i<arr.size();i++){
        Node *n=new Node(arr[i],nullptr);
        temp->next=n;
        temp=temp->next;
    }
    return head;
}
//Problem 1: Delete the head of the linked list
Node* deleteHead(Node*& head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
//Problem 2: Delete the tail of the linked list
Node* deleteTail(Node* head){
    if(head==nullptr){
        return head;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
//Problem 3: Delete kth element of the linked list
Node* deleteKthElement(Node* head,int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        return deleteHead(head);
    }
    Node* temp=head;
    for(int i=0;i<k-2;i++){
        if(temp->next==nullptr){
            return head;
        }
        temp=temp->next;
    }
    if(temp->next==nullptr){
        return head;
    }
    Node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    return head;
}
//Problem 4: Delete element of a specific value from the linked list
Node* deleteElement(Node* head, int value) {
    if (head == nullptr) {
        return head;
    }
    if (head->data == value) {
        return deleteHead(head);
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == value) {
            Node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
            return head;
        }
        temp = temp->next;
    }
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
    Node* head=ConverArray2LL(arr);
    cout<<"After deleting head: ";
    head=deleteHead(head);
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"After deleting tail: ";
    head=deleteTail(head);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int k;
    cout<<"Enter the position of the element to delete: ";
    cin>>k;
    head=deleteKthElement(head,k);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value;
    cout<<"Enter the value of the element to delete: ";
    cin>>value;
    head=deleteElement(head,value);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}