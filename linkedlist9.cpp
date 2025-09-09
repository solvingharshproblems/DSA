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
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
//Problem 1: Delete all the occurences of a given key in a doubly linked list
//For Optimal Approach we will declare 3 pointers temp,next and prev
Node* DeleteAllOccurences(Node* head,int value){
    Node* temp=head;
    Node* next;
    Node* prev;
    while(temp!=nullptr){
        if(temp->data==value){
            if(temp==head){
                head=head->next;
            }
            next=temp->next;
            prev=temp->prev;
            if(next!=nullptr){
                next->prev=prev;
            }
            if(prev!=nullptr){
                prev->next=next;
            }
            delete temp;
            temp=next;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
} //TC=O(n) 
//Problem 2: Find all pairs with a given sum in a doubly linked list
//For Brute Force Approach we can use 2 nested loops to find all pairs with a given sum with the help of 2 pointers
Node* FindPairsBruteForce(Node* head,int sum){
    Node* temp1=head;
    while(temp1!=nullptr){
        Node* temp2=temp1->next;
        while(temp2!=nullptr){
            if(temp1->data+temp2->data==sum){
                cout<<"("<<temp1->data<<","<<temp2->data<<") ";
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    cout<<endl;
    return head;
} //TC=O(n^2)
//For Optimal Approach we can use 2 pointers left and right to find all pairs with a given sum
Node* FindPairsOptimal(Node* head,int sum){
    Node* left=head;
    Node* right=head;
    while(right->next!=nullptr){
        right=right->next;
    }
    while(left!=right && right->next!=left){
        if(left->data+right->data==sum){
            cout<<"("<<left->data<<","<<right->data<<") ";
            left=left->next;
            right=right->prev;
        }
        else if(left->data+right->data<sum){
            left=left->next;
        }
        else{
            right=right->prev;
        }
    }
    cout<<endl;
    return head;
} //TC=O(2n)
int main(){
    int size;
    cout<<"Enter the size of the linked list: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the linked list: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2DLL(arr);
    /*
    int value;
    cout<<"Enter the value to be deleted: ";
    cin>>value;
    head=DeleteAllOccurences(head,value);
    cout<<"The elements of the linked list are: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;  
    */
    int sum;
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"The pairs are: ";
    Node* temp1=FindPairsBruteForce(head,sum);
    cout<<"The pairs are: ";
    Node* temp2=FindPairsOptimal(head,sum);
    return 0;
}