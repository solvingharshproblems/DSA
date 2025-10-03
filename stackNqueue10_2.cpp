#include <iostream>
#include <unordered_map>
using namespace std;
//Problem 2: Implement LRU Cache
//Declare a class LRUCache with a constructor that takes the capacity of the cache as an argument.
//Declare a get function that takes a key as an argument and returns the value of the key if it exists in the cache, otherwise returns -1.
//Declare a put function that takes a key and value as arguments and adds the key-value pair. Only if the key is not already present. If the cache is full, remove the least recently used item.
//put and get functions should be in O(1) time complexity.
//For Optimal Approach, we can use a doubly linked list to keep track of the order of usage of the keys. We can also use a hash map to store the key-value pairs.
class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache{
    private:
    int capacity;
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;
    public:
    LRUCache(int cap){
        capacity=cap;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key){
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Node* node=cache[key];
        remove(node);
        insertAtFront(node);
        return node->value;
    }
    void put(int key,int value){
        if(cache.find(key)!=cache.end()){
            Node* node=cache[key];
            remove(node);
            node->value=value;
            insertAtFront(node);
        }
        else{
            if(cache.size()==capacity){
                Node* node=tail->prev;
                remove(node);
                cache.erase(node->key);
                delete node;
            }
            Node* newNode=new Node(key,value);
            insertAtFront(newNode);
            cache[key]=newNode;
        }
    }
    void remove(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertAtFront(Node* node){
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }
}; //TC=O(1) SC=O(capacity)
int main(){
    LRUCache x(4);
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