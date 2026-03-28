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
// TC=O(N*32) SC=O(N*32)
//Problem 2: Maximum ZOR with an Element from an Array
//For Optimal Approach, we will insert all the numbers in the Trie and then we will check for each number.
//If we can find a number in the Trie which can give us maximum XOR value or not. 
//We will also check if the number is less than or equal to the given limit or not. 
//If it is less than or equal to the given limit then we will update our answer. 
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    sort(nums.begin(),nums.end());
    Trie trie;
    vector<int> ans(queries.size());
    vector<pair<int,pair<int,int>>> offlineQueries;
    int index=0,i=0,n=nums.size();
    for(int j=0;j<queries.size();j++){
        int x=queries[j][0];
        int m=queries[j][1];
        offlineQueries.push_back({m,{x,j}});
    }
    sort(offlineQueries.begin(),offlineQueries.end());
    for(auto &q:offlineQueries){
        int m=q.first;
        int x=q.second.first;
        int idx=q.second.second;
        while(i<n && nums[i]<=m){
            trie.insert(nums[i]);
            i++;
        }
        if(i==0){
            ans[idx]=-1;
        }
        else{
            ans[idx]=trie.getMaxXOR(x);
        }
    }
    return ans;
}
int main(){
    vector<int> nums={3,10,5,25,2,8};
    cout<<findMaximumXOR(nums)<<endl;
    vector<vector<int>> queries={{3,1},{1,3},{5,6}};
    vector<int> nums2={0,1,2,3,4};
    vector<int> ans=maximizeXor(nums2,queries);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}