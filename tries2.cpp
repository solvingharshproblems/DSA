#include <iostream>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
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
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->setEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
//Problem 1: Longest Word with All Prefixes
//We are given an array of strings words. Return the longest string in words such that every prefix of it is also in words.
//For Optimal Approach, we will use Trie Data Structure. We will insert all the words in the Trie and then we will check for each word if all the prefixes of it are present in the Trie or not. 
//If they are present then we will check if it is the longest word or not. If it is the longest word then we will update our answer. Finally, we will return our answer.
string completeString(int n,vector<string> &words){
    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(words[i]);
    }
    string ans="";
    for(int i=0;i<n;i++){
        string word=words[i];
        if(trie.search(word)){
            if(word.size()>ans.size()){
                ans=word;
            }
            else if(word.size()==ans.size() && word<ans){
                ans=word;
            }
        }
    }
    if(ans==""){
        return "None";
    }
    return ans;
} //TC=O(N*L) SC=O(N*L) where L is the average length of the words in the array
//Problem 2: Number of Distinct Substrings in a String
//For Optimal Approach, we will use Trie Data Structure. We will insert all the substrings of the string in the Trie and then we will count the number of nodes in the Trie.
// The number of nodes in the Trie will be equal to the number of distinct substrings in the string.
int countDistinctSubstrings(string s){
    Trie trie;
    int count=0;
    for(int i=0;i<s.size();i++){
        Node* node=trie.root;
        for(int j=i;j<s.size();j++){
            if(!node->containsKey(s[j])){
                node->put(s[j],new Node());
                count++;
            }
            node=node->get(s[j]);
        }
    }
    return count;
} //TC=O(N^2) SC=O(N^2) 
int main(){
    vector<string> words={"n","ni","nin","ninj","ninja","ninga"};
    cout<<completeString(words.size(),words)<<endl;
    string s="ababa";
    cout<<countDistinctSubstrings(s)<<endl;
    return 0;
}