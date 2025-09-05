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
        Node* n=new Node(arr[i]);
        temp->next=n;
        temp=n;
    }
    return head;
}
//Problem 1: Reverse a LL
//For Brute Force we can store the elements of the linked list in a stack and then pop the elements from the stack and modify the linked list
Node* ReverseBruteForce(Node* head){
    stack<int> s;
    Node* temp=head;
    while(temp!=nullptr){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=s.top();
        s.pop();
        temp=temp->next;
    }
    return head;
} //TC=O(2n) SC=O(n)
//Optimal Approach: We can reverse the linked list by changing the next pointers of each node
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
} //TC=O(n)
//We can also do it using recursion
Node* ReverseRecursive(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead=ReverseRecursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newHead;
} //TC=O(n) SC=O(n) due to recursion stack
//Problem 2: Check if a linked list is a palindrome
//For Brute Force we can store the elements of the linked list in a stack and then pop the elements from the stack and compare with the linked list
bool CheckPalindromeBruteForce(Node* head){
    stack<int> s;
    Node* temp=head;
    while(temp!=nullptr){
        s.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=s.top()){
            return false;
        }
        s.pop();
        temp=temp->next;
    }
    return true;
} //TC=O(2n) SC=O(n)
//For Optimal Approach we can find the middle of the linked list and reverse the second half of the linked list and then compare the first half and the reversed second half
bool CheckPalindromeOptimal(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=ReverseOptimal(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=nullptr){
        if(first->data!=second->data){
            ReverseOptimal(newHead); //Reversing back the second half to restore the original linked list
            return false;
        }
        first=first->next;
        second=second->next;
    }
    ReverseOptimal(newHead); //Reversing back the second half to restore the original linked list
    return true;
} //TC=O(2n)
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head1=ReverseBruteForce(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head2=ReverseOptimal(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    temp=head2;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head3=ReverseRecursive(ConvertArray2LL(arr));
    cout<<"The elements of the reversed linked list are: ";
    temp=head3;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    bool isPalindrome1=CheckPalindromeBruteForce(ConvertArray2LL(arr));
    if(isPalindrome1){
        cout<<"The linked list is a palindrome"<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome"<<endl;
    }
    bool isPalindrome2=CheckPalindromeOptimal(ConvertArray2LL(arr));
    if(isPalindrome2){
        cout<<"The linked list is a palindrome"<<endl;
    }
    else{
        cout<<"The linked list is not a palindrome"<<endl;
    }
    return 0;
}