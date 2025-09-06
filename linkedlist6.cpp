#include <iostream>
#include <vector>
#include <unordered_map>
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
// SC=O(n) due to recursion stack
//Problem 2: Find the intersection point Y of two linked lists
//For Brute Force we can use two nested loops to check for each node of the first linked list if it is present in the second linked list using hash map
Node* FindIntersectionBruteForce(Node* head1, Node* head2){
    unordered_map<Node*,int> mp;
    Node* temp=head2;
    while(temp!=nullptr){
        mp[temp]=1;
        temp=temp->next;
    }
    temp=head1;
    while(temp!=nullptr){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
} //TC=O(n+m) SC=O(m) where n and m are the sizes of the two linked lists
//For Better Approach we can first find the lengths of the two linked lists and then move the pointer of the longer linked list by the difference in lengths,
// and then move both pointers one step at a time until they meet
Node* FindIntersectionBetter(Node* head1, Node* head2){
    int len1=0,len2=0;
    Node* temp=head1;
    while(temp!=nullptr){
        len1++;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        len2++;
        temp=temp->next;
    }
    int diff=abs(len1-len2);
    Node* ptr1=head1;
    Node* ptr2=head2;
    if(len1>len2){
        for(int i=0;i<diff;i++){
            ptr1=ptr1->next;
        }
    }else{
        for(int i=0;i<diff;i++){
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=nullptr && ptr2!=nullptr){
        if(ptr1==ptr2){
            return ptr1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return nullptr;
} //TC=O(n+2m)
//For Optimal Approach we can use two pointers to traverse the two linked lists and when they reach the end of their respective linked lists,
//we can point them to the head of the other linked list. This way they will traverse the same distance when they meet at the intersection point.
Node* FindIntersectionOptimal(Node* head1, Node* head2){
    if(head1==nullptr || head2==nullptr){
        return nullptr;
    }
    Node* ptr1=head1;
    Node* ptr2=head2;
    while(ptr1!=ptr2){
        if(ptr1==nullptr){
            ptr1=head2;
        }else{
            ptr1=ptr1->next;
        }
        if(ptr2==nullptr){
            ptr2=head1;
        }else{
            ptr2=ptr2->next;
        }
    }
    return ptr1;
} //TC=O(n+m) 
int main(){
    /*
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
    */
   int size1, size2;
    cout<<"Enter size of first linked list: ";
    cin>>size1;
    cout<<"Enter elements of first linked list: ";
    vector<int> arr1(size1);
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter size of second linked list: ";
    cin>>size2;
    cout<<"Enter elements of second linked list: ";
    vector<int> arr2(size2);
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    Node* head1=ConvertArray2LL(arr1);
    Node* head2=ConvertArray2LL(arr2);
    Node* intersection=FindIntersectionBruteForce(head1,head2);
    if(intersection!=nullptr){
        cout<<"The intersection point is: "<<intersection->data<<endl;
    }else{
        cout<<"The linked lists do not intersect"<<endl;
    }
    intersection=FindIntersectionBetter(head1,head2);
    if(intersection!=nullptr){
        cout<<"The intersection point is: "<<intersection->data<<endl;
    }else{
        cout<<"The linked lists do not intersect"<<endl;
    }
    intersection=FindIntersectionOptimal(head1,head2);
    if(intersection!=nullptr){
        cout<<"The intersection point is: "<<intersection->data<<endl;
    }else{
        cout<<"The linked lists do not intersect"<<endl;
    }
    return 0;
}