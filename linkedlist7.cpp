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
//Problem 1: Detect a loop in a LL
//For Brute Force Approach we can use a hash map to store the visited nodes
bool DetectLoopBruteForce(Node* head){
    unordered_map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=nullptr){
        if(visited[temp]){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
} //TC=O(n) SC=O(n)
//For Optimal Approach we will use Tortoise and Hare Algorithm
bool DetectLoopOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
} //TC=O(n) 
//Problem 2: Find the length of the loop in a LL
//For Brute Force Approach we can use a hash map to store the visited nodes and when we find a visited node we can count the number of nodes in the loop
int LengthOfLoopBruteForce(Node* head){
    unordered_map<Node*,bool> visited;
    Node* temp=head;
    while(temp!=nullptr){
        if(visited[temp]){
            int count=1;
            Node* loopNode=temp->next;
            while(loopNode!=temp){
                count++;
                loopNode=loopNode->next;
            }
            return count;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return 0;
} //TC=O(n) SC=O(n)
//For Optimal Approach we will use Tortoise and Hare Algorithm to detect the loop and then count the number of nodes in the loop
int LengthOfLoopOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return 0;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int count=1;
            Node* loopNode=slow->next;
            while(loopNode!=slow){
                count++;
                loopNode=loopNode->next;
            }
            return count;
        }
    }
    return 0;
} //TC=O(n) SC=O(1)
int main(){
    int size;
    cout<<"Enter size of linked list: ";
    cin>>size;
    cout<<"Enter elements of linked list: ";
    vector<int> arr(size);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    Node* head1=ConvertArray2LL(arr);
    //Creating a loop for testing
    head1->next->next->next->next=head1->next;
    if(DetectLoopBruteForce(head1)){
        cout<<"Loop detected in the linked list"<<endl;
    }else{
        cout<<"No loop detected in the linked list"<<endl;
    }
    cout<<"Length of the loop in the linked list is: "<<LengthOfLoopBruteForce(head1)<<endl;
    cout<<"Length of the loop in the linked list is: "<<LengthOfLoopOptimal(head1)<<endl;
    return 0;
}