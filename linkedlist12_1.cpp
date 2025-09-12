#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child; // For multilevel linked list
    Node(int data1,Node *next1,Node* child1=nullptr){
        data=data1;
        next=next1;
        child=child1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
};
Node* ConvertArray2LL(vector<int> arr){
    if(arr.size()==0){
        return nullptr;
    }
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->child=newNode;
        temp=temp->child;
    }
    return head;
}
//Problem 1: Flatten a multilevel linked list
//Each node has two pointers: next and child. The child pointer may or may not point to a separate list, also containing these special nodes. 
//These child lists may have one or more children of their own, and so on, to produce a multilevel data structure.
//For Brute Force Approach we can store elements of the multilevel LL in an array and then convert it to LL
Node* FlattenLLBruteForce(Node* head){
    if(head==nullptr){
        return head;
    }
    vector<int> arr;
    Node* temp=head;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        Node* child=temp->child;
        while(child!=nullptr){
            arr.push_back(child->data);
            child=child->next;
        }
        temp=temp->next;
    }
    return ConvertArray2LL(arr);
} //TC=O(n+m) SC=O(n+m)
//For Better Approach we can use the concept of dummy node denoted by dummyNode
Node* FlattenLLBetter(Node* list1, Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            temp->child=list1;
            temp=list1;
            list1=list1->child;
        }
        else{
            temp->child=list2;
            temp=list2;
            list2=list2->child;
        }
        temp->child=nullptr;
    }
    return dummyNode->child;
} //TC=O(n+m)
//For Optimal Approach we will use recursion
//Note: For 2 lists only we can use the better approach for k lists we will use this optimal approach
Node* FlattenLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* MergedHead=FlattenLLOptimal(head->next);
    return FlattenLLBetter(head,MergedHead);
} //TC=O(n*2m) SC=O(n) for recursion stack
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
    Node* temp=head;
    cout<<"Flattened Linked List: ";
    temp=FlattenLLOptimal(head);
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->child;
    }
    cout<<endl;
    return 0;
}