#include <iostream>
#include <vector>
#include <queue>
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
Node* CovertArray2LL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}
//Problem 2: Merge K sorted linked lists
//For Brute Force Approach we can store elements of all the k linked lists in an array
Node* MergeKSortedLLBruteForce(vector<Node*> lists){
    if(lists.size()==0){
        return nullptr;
    }
    vector<int> arr;
    for(int i=0;i<lists.size();i++){
        Node* temp=lists[i];
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp=temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    return CovertArray2LL(arr);
} //TC=O(n log n) SC=O(n) where n is total number of nodes in all k linked lists
//For Better Approach we can first merge 2 linked lists together and then repeat it for k linked lists
Node* Merge2LLs(Node* head1,Node* head2){
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
}
Node* MergeKSortedLLBetter(vector<Node*> lists){
    if(lists.size()==0){
        return nullptr;
    }
    Node* head=lists[0];
    for(int i=1;i<lists.size();i++){
        head=Merge2LLs(head,lists[i]);
    }
    return head;
} //TC=O(n*k) where n is average number of nodes in each linked list and k is number of linked lists
//For Optimal Approach we will use min heap to store the first node of each linked list
Node* MergeKSortedLLOptimal(vector<Node*> lists){
    if(lists.size()==0){
        return nullptr;
    }
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i=0;i<lists.size();i++){
        if(lists[i]!=nullptr){
            pq.push({lists[i]->data,lists[i]});
        }
    }
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
} //TC=O(n log k) SC=O(k) where n is total number of nodes in all k linked lists
int main(){
    int k;
    cout<<"Enter number of linked lists: ";
    cin>>k;
    vector<Node*> lists(k);
    for(int i=0;i<k;i++){
        int size;
        cout<<"Enter size of linked list "<<i+1<<": ";
        cin>>size;
        vector<int> arr(size);
        cout<<"Enter elements of linked list "<<i+1<<": ";
        for(int j=0;j<size;j++){
            cin>>arr[j];
        }
        lists[i]=CovertArray2LL(arr);
    }
    Node* mergedHeadOptimal=MergeKSortedLLOptimal(lists);
    cout<<"Merged linked list using optimal approach: ";
    Node* temp=mergedHeadOptimal;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return 0;
}