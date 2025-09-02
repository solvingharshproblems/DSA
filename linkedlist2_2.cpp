#include <iostream>
#include <vector>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
        Node(int data1,Node* next1,Node* prev1){
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
//Problem 1: Delete the head of DLL
Node* DeleteHead(Node*& head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    delete temp;
    return head;
} //TC=O(1)
//Problem 2: Delete the tail of DLL
Node* DeleteTail(Node*& head){
    Node* temp=head;
    if(head==nullptr){
        return head;
    }
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    if(temp->prev!=nullptr){
        temp->prev->next=nullptr;
    }
    delete temp;
    return head;
} //TC=O(n)
//Problem 3: Delete kth element of DLL
Node* DeleteElement(Node*& head,int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        return head;
    }
    Node* temp=head;
    int i=1;
    while(i<k && temp!=nullptr){
        temp=temp->next;
        i++;
    }
    if(temp==nullptr){
        return head;
    }
    if(temp==head){
        head=head->next;
        if(head){
            head->prev=nullptr;
        }
        delete temp;
        return head;
    }
    if(temp->prev){
        temp->prev->next=temp->next;
    }
    if(temp->next){
        temp->next->prev=temp->prev;
    }
    return head;
} //TC=O(n)
Node* DeleteValue(Node*& head,int value){
    if(head==nullptr){
        return head;
    }
    if(head->data==value){
        return DeleteHead(head);
    }
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==value){
            if(temp->prev!=nullptr){
                temp->prev->next=temp->next;
            }
            if(temp->next!=nullptr){
                temp->next->prev=temp->prev;
            }
            delete temp;
            return head;
        }
        temp=temp->next;
    }
    return head;
} //TC=O(n)
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head=ConvertArray2DLL(arr);
    cout<<"The elements of the linked list are: ";
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=DeleteHead(head);
    cout<<"After deleting head: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=DeleteTail(head);
    cout<<"After deleting tail: ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int k;
    cout<<"Enter the position of the element to delete: ";
    cin>>k;
    head=DeleteElement(head,k);
    cout<<"After deleting element at position "<<k<<": ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    int value;
    cout<<"Enter the value to delete: ";
    cin>>value;
    head=DeleteValue(head,value);
    cout<<"After deleting value "<<value<<": ";
    temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}