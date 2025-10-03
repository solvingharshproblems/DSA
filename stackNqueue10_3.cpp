#include <iostream>
#include <unordered_map>
using namespace std;
//Problem 3: Implementing LFU Cache
//Declare a class LFUCache with a constructor that takes the capacity of the cache as an argument.
//Declare a get function that takes a key as an argument and returns the value of the key if it exists in the cache, otherwise returns -1.
//Declare a put function that takes a key and value as arguments and adds the key-value pair. Only if the key is not already present. If the cache is full, remove the least frequently used item.
//For Optimal Approach, we will declare a doubly linkedlist and 2 unordered maps for hashing elements and their frequencies. 
class Node{
    public:
    int key;
    int value;
    int cnt;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        value=v;
        cnt=1;
        prev=NULL;
        next=NULL;
    }
};
class List{
    public:
    int size;
    Node* head; 
    Node* tail;
    List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addFront(Node* node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }

    void removeNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        size--;
    }
};
class LFUCache{
    private:
    unordered_map<int,Node*> keyNode;              
    unordered_map<int,List*> freqListMap;         
    int maxSizeCache;
    int minFreq;                              
    int curSize;
    public:
    LFUCache(int capacity){
        maxSizeCache=capacity;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }
    int get(int key){
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            int val=node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    void put(int key,int value){
        if(maxSizeCache==0){
            return;
        } 
        if(keyNode.find(key)!=keyNode.end()){
            Node* node=keyNode[key];
            node->value=value;
            updateFreqListMap(node);
        } 
        else{
            if(curSize==maxSizeCache){
                List* list=freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq=1;
            List* listFreq=new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            Node* node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
}; //TC=O(1) SC=O(n)
int main(){
    LFUCache x(4);
    x.put(2,6);
    x.put(4,7);
    x.put(8,11);
    x.put(7,10);
    cout<<x.get(2)<<endl;
    cout<<x.get(8)<<endl;
    x.put(5,6);
    cout<<x.get(7)<<endl;
    x.put(5,7);
    return 0;
}