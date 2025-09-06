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
//Problem 1: Adding 1 to a number represented as a linked list
//For brute force approach we can reverse the linked list, add 1 to the first node and then reverse the linked list again
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
} 
Node* AddOneBruteForce(Node* head){
    head=ReverseOptimal(head);
    Node* temp=head;
    int carry=1;
    while(temp!=nullptr && carry>0){
        int sum=temp->data+carry;
        temp->data=sum%10;
        carry=sum/10;
        if(temp->next==nullptr && carry>0){
            Node* newNode=new Node(carry);
            temp->next=newNode;
            carry=0;
        }
        temp=temp->next;
    }
    head=ReverseOptimal(head);
    return head;
} //TC=O(3n) 
//For Optimal Approach we can use recursion to add 1 to the last node and propagate the carry to the previous nodes
int AddOneOptimal(Node* head){
    if(head==nullptr){
        return 1;
    }
    int carry=AddOneOptimal(head->next);
    if(carry==0){
        return 0;
    }
    int sum=head->data+carry;
    head->data=sum%10;
    return sum/10;
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
    Node* head1=AddOneBruteForce(ConvertArray2LL(arr));
    cout<<"The elements of the linked list after adding one are: ";
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
    Node* head2=ConvertArray2LL(arr);
    int carry=AddOneOptimal(head2);
    if(carry>0){
        Node* newNode=new Node(carry);
        newNode->next=head2;
        head2=newNode;
    }
    cout<<"The elements of the linked list after adding one are: ";
    temp=head2;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next; 
    }
    cout<<endl;
    return 0;
}