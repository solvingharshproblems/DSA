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
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
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
    return 0;
}