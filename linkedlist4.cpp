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
//Problem 1: Sort a linked list of 0s,1s and 2s
//For brute force we can count and store the counts of 0s,1s and 2s and then modify the linked list
Node* Sort012BruteForce(Node* head){
    int count0=0;
    int count1=0;
    int count2=0;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            count0++;
        }
        else if(temp->data==1){
            count1++;
        }
        else{
            count2++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(count0>0){
            temp->data=0;
            count0--;
        }
        else if(count1>0){
            temp->data=1;
            count1--;
        }
        else{
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }
    return head;
} //TC=O(2n) 
//For optimal approach we can use 3 pointers to maintain the 3 lists of 0s,1s and 2s and then connect them
//But here we will use the Dutch National Flag Algorithm using 3 dummy nodes
Node* Sort012Optimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* zeroDummy=new Node(-1);
    Node* oneDummy=new Node(-1);
    Node* twoDummy=new Node(-1);
    Node* zeroTail=zeroDummy;
    Node* oneTail=oneDummy;
    Node* twoTail=twoDummy;
    Node* curr=head;
    while(curr!=nullptr){
        if(curr->data==0){
            zeroTail->next=curr;
            zeroTail=curr;
        }
        else if(curr->data==1){
            oneTail->next=curr;
            oneTail=curr;
        }
        else{
            twoTail->next=curr;
            twoTail=curr;
        }
        curr=curr->next;
    }
    zeroTail->next=oneDummy->next;
    oneTail->next=twoDummy->next;
    twoTail->next=nullptr;
    head=zeroDummy->next;
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;
    return head;
}
//TC=O(n)
//Problem 2: Remove nth node from the end of the linked list
//For brute force approach we can keep a count of the number of nodes and join result=count-nth node from start to the node next to nth node from end
Node* RemoveNthFromEndBruteForce(Node* head,int n){
    if(head==nullptr){
        return head;
    }
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    if(n==count){
        Node* newHead=head->next;
        delete head;
        return newHead;
    }
    int pos=count-n;
    temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    Node* nodeToDelete=temp->next;
    temp->next=temp->next->next;
    delete nodeToDelete;
    return head;
} //TC=O(2n) 
//For optimal approach we can use 2 pointers slow and fast and move fast pointer 2 steps ahead and then move both pointers one step at a time until fast pointer reaches the end
//Now slow pointer will be at the node previous to the nth node from the end
Node* RemoveNthFromEndOptimal(Node* head,int n){
    if(head==nullptr){
        return head;
    }
    Node* dummy=new Node(-1);
    dummy->next=head;
    Node* slow=dummy;
    Node* fast=dummy;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    Node* nodeToDelete=slow->next;
    slow->next=slow->next->next;
    delete nodeToDelete;
    return dummy->next;
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
    /*
    Node* head1=Sort012BruteForce(ConvertArray2LL(arr));
    cout<<"The elements of the sorted linked list are: ";
    Node* temp=head1;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head2=Sort012Optimal(ConvertArray2LL(arr));
    cout<<"The elements of the sorted linked list are: ";
    temp=head2;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    */
   int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    Node* head3=RemoveNthFromEndBruteForce(ConvertArray2LL(arr),n);
    cout<<"The elements of the modified linked list are: ";
    Node* temp=head3;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    Node* head4=RemoveNthFromEndOptimal(ConvertArray2LL(arr),n);
    cout<<"The elements of the modified linked list are: ";
    temp=head4;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}