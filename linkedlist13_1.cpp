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
//Problem 1: Sort the linked list 
//For Brute Force Approach we can store elements of linked list in an array and then sort the array and again convert it to linked list
Node* SortLLBruteForce(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    vector<int> arr;
    Node* temp=head;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    return ConvertArray2LL(arr);
} //TC=O(n log n) SC=O(n) where n is number of nodes in linked list
//For Optimal Approach we will use Merge Sort
Node* FindMid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
Node* Merge(Node* left,Node* right){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(left!=nullptr && right!=nullptr){
        if(left->data<right->data){
            temp->next=left;
            left=left->next;
        }
        else{
            temp->next=right;
            right=right->next;
        }
        temp=temp->next;
    }
    if(left!=nullptr){
        temp->next=left;
    }
    if(right!=nullptr){
        temp->next=right;
    }
    return dummyNode->next;
}
Node* SortLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* mid=FindMid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=nullptr;
    left=SortLLOptimal(left);
    right=SortLLOptimal(right);
    Node* mergedHead=Merge(left,right);
    return mergedHead;
} //TC=O(n log n) SC=O(log n) where n is number of nodes in linked list
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2LL(arr);
    cout<<"Sorted linked list: ";
    Node* temp=SortLLBruteForce(head);
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Sorted linked list: ";
    temp=SortLLOptimal(head);
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}