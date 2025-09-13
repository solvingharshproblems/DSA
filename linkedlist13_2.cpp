#include <iostream>
#include <unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int data1,Node *next1,Node *random1){
        data=data1;
        next=next1;
        random=random1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        random=nullptr;
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
//Problem 2: Clone a linked list with next and random pointer
//For Brute Force Approach we can use hashing to store the mapping of original node to cloned node and then update the random pointers of cloned nodes
Node* CloneLLBruteForce(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    unordered_map<Node*,Node*> mapping;
    Node* temp=head;
    while(temp!=nullptr){
        mapping[temp]=new Node(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        mapping[temp]->next=mapping[temp->next];
        mapping[temp]->random=mapping[temp->random];
        temp=temp->next;
    }
    return mapping[head];
} //TC=O(2n) SC=O(2n) where n is number of nodes in linked list
//For Optimal Approach we can insert cloned nodes in between original nodes and then update the random pointers of cloned nodes and finally separate the original and cloned linked lists
Node* CloneLLOptimal(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp!=nullptr){
        Node* newNode=new Node(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=newNode->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->random!=nullptr){
            temp->next->random=temp->random->next;
        }
        temp=temp->next->next;
    }
    Node* clonedHead=head->next;
    Node* cloneTemp=clonedHead;
    temp=head;
    while(temp!=nullptr){
        temp->next=temp->next->next;
        if(cloneTemp->next!=nullptr){   
            cloneTemp->next=cloneTemp->next->next;
        }
        temp=temp->next;
        cloneTemp=cloneTemp->next;
    }
    return clonedHead;
} //TC=O(3n) SC=O(n) where n is the cloned linked list size
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
    Node* temp=CloneLLBruteForce(head);
    cout<<"Cloned linked list: ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}