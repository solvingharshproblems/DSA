#include <iostream>
#include <vector>
using namespace std;
//Creation of a Linked List
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
//Converting Array to Linked List
Node* ConverArray2LL(vector<int> arr){
    Node *head=new Node(arr[0],nullptr);
    Node *temp=head;
    for(int i=1;i<arr.size();i++){
        Node *n=new Node(arr[i],nullptr);
        temp->next=n;
        temp=temp->next;
    }
    return head;
}
//Search an element in a Linked List
Node* SearchinginLL(Node* head,int key){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            return temp;
        }
        temp=temp->next;
    }
    return nullptr;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node* y=ConverArray2LL(arr);
    Node* temp=y;
    cout<<"The elements of the linked list are: ";
    //Finding length of a Linked List
    int count=0;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;
    }
    cout<<endl<<"The length of the linked list is: "<<count<<endl;
    int key;
    cout<<"Enter the element to be searched: ";
    cin>>key;
    Node* result=SearchinginLL(y,key);
    if(result!=nullptr){
        cout<<"Element found: "<<result->data<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}