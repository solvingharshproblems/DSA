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
//Problem 2: Merge two sorted LL
//For Brute Force Approach we can store elements of both LLs in an array,sort it and then convert it to LL
Node* MergeLLsBruteForce(Node* head1,Node* head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    vector<int> arr;
    Node* temp=head1;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    return ConvertArray2LL(arr);
} //TC=O((n+m)log(n+m)) SC=O(n+m)
//For Optimal Approach we can use the concept of dummy node denoted by mergedHead
Node* MergeLLsOptimal(Node* head1,Node* head2){
    if(head1==nullptr){
        return head2;
    }
    if(head2==nullptr){
        return head1;
    }
    Node* mergedHead=nullptr;
    if(head1->data<head2->data){
        mergedHead=head1;
        head1=head1->next;
    }
    else{
        mergedHead=head2;
        head2=head2->next;
    }
    Node* temp=mergedHead;
    while(head1!=nullptr && head2!=nullptr){
        if(head1->data<head2->data){
            temp->next=head1;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            head2=head2->next;
        }
        temp=temp->next;
    }
    if(head1!=nullptr){
        temp->next=head1;
    }
    if(head2!=nullptr){
        temp->next=head2;
    }
    return mergedHead;
} //TC=O(n+m)
int main(){
    /*
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
    */
    int size1,size2;
    cout<<"Enter size of first linked list: ";
    cin>>size1;
    vector<int> arr1(size1);
    cout<<"Enter elements of first linked list: ";
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    Node* head1=ConvertArray2LL(arr1);
    cout<<"Enter size of second linked list: ";
    cin>>size2;
    vector<int> arr2(size2);
    cout<<"Enter elements of second linked list: ";
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    Node* head2=ConvertArray2LL(arr2);
    cout<<"Merged Linked List: ";
    Node* temp=MergeLLsOptimal(head1,head2);
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}