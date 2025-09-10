#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1,Node *next1,Node *prev1){
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
        Node* newNode=new Node(arr[i],nullptr,prev);
        prev->next=newNode;
        prev=newNode;
    }
    return head;
}
//Problem 1: Remove duplicated from a sorted DLL
//For Brute Force Approach we can use 2 nested loops to find duplicates and remove them
Node* RemoveDuplicatesBruteForce(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp1=head;
    while(temp1!=nullptr){
        Node* temp2=temp1->next;
        int count=0;
        while(temp2!=nullptr){
            if(temp1->data==temp2->data){
                Node* todelete=temp2;
                temp2=temp2->next;
                if(todelete->next!=nullptr){
                    todelete->next->prev=todelete->prev;
                }
                todelete->prev->next=todelete->next;
                delete todelete;
                count++;
            }
            else{
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }
    return head;
} //TC=O(n^2)
//For Optimal Approach we can use a single loop to traverse the list and remove duplicates
Node* RemoveDuplicatesOptimal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        Node* nextNode=temp->next;
        while(nextNode!=nullptr && nextNode->data==temp->data){
            Node* todelete=nextNode;
            nextNode=nextNode->next;
            delete todelete;
        }
        temp->next=nextNode;
        if(nextNode!=nullptr){
            nextNode->prev=temp;
        }
        temp=temp->next;
    }
    return head;
} //TC=O(n ) its not O(n^2) because 2nd while loop is not executed for every node of traversal done by 1st while loop
int main(){
    int size;
    cout<<"Enter the size of linked list: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the linked list: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2DLL(arr);
    Node* temp=RemoveDuplicatesOptimal(head);
    cout<<"The linked list after removing duplicates is: ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}