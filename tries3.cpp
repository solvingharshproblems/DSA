#include <iostream>
using namespace std;
struct Node{
    Node* links[2];
    bool flag=false;
    bool containsKey(int ch){
        return links[ch]!=nullptr;
    }
    void put(int ch,Node* node){
        links[ch]=node;
    }
    Node* get(int ch){
        return links[ch];
    }
    bool setEnd(){
        flag=true;
        return true;
    }
};
class Trie{
public:
    Node* root;
public: 
    Trie(){
        root=new Node();
    }
    void insert(int word){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(word>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    bool search(int word){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(word>>i)&1;
            if(!node->containsKey(bit)){
                return false;
            }
            node=node->get(bit);
        }
        return node->setEnd();
    }
    bool startsWith(int prefix){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(prefix>>i)&1;
            if(!node->containsKey(bit)){
                return false;
            }
            node=node->get(bit);
        }
        return true;
    }
    int getMaxXOR(int num){
        Node* node=root;
        int maxXOR=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containsKey(1-bit)){
                maxXOR=maxXOR|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxXOR;
    }
};
//Problem 1: Maximum XOR of Two Numbers in an Array
//For Optimal Approach, we will insert all the numbers in the Trie and then we will check for each number 
//if we can find a number in the Trie which can give us maximum XOR value or not.
int findMaximumXOR(vector<int>& nums) {
    Trie trie;
    for(auto num:nums){
        trie.insert(num);
    }
    int maxXOR=0;
    for(auto num:nums){
        maxXOR=max(maxXOR,trie.getMaxXOR(num));
    }
    return maxXOR;
}
int main(){
    vector<int> nums={3,10,5,25,2,8};
    cout<<findMaximumXOR(nums)<<endl;
    return 0;
}