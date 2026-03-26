//Trie is a tree data structure used for efficient retrieval of a key in a large dataset of strings.
//It is also known as a prefix tree because it stores the common prefix of the strings.
//It mainly consists of nodes where each node represents a character of the string and has a boolean flag to indicate if it is the end of a word.
//We can perform various operations on a trie such as insertion, search, and deletion of words.
#include <iostream>
#include <unordered_map>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
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
private:
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
        return node->flag;
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
    int countWords(Node* node){
        int count=0;
        if(node->flag){
            count++;
        }
        for(int i=0;i<26;i++){
            if(node->links[i]!=NULL){
                count+=countWords(node->links[i]);
            }
        }
        return count;
    }
    int countWordsEqualTo(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->flag?1:0;
    }
    int countWordsStartingWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node=node->get(prefix[i]);
        }
        return countWords(node);
    }
    void erase(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node=node->get(word[i]);
        }
        node->flag=false;
    }
}; //TC=O(N) SC=O(N) where N is the length of the word being inserted/searched.
//Problem 2: Implement countWordsEqualTo and countWordsStartingWith and erase functions in Trie
int main(void){
    Trie* trie=new Trie();
    trie->insert("apple");
    cout<<trie->search("apple")<<endl;   // returns true
    cout<<trie->search("app")<<endl;     // returns false
    cout<<trie->startsWith("app")<<endl; // returns true
    trie->insert("app");
    cout<<trie->search("app")<<endl;     // returns true
    cout<<trie->countWordsEqualTo("app")<<endl; // returns 1
    cout<<trie->countWordsStartingWith("app")<<endl; // returns 2
    trie->erase("app");
    cout<<trie->search("app")<<endl;     // returns false
    cout<<trie->countWordsEqualTo("app")<<endl; // returns 0
    cout<<trie->countWordsStartingWith("app")<<endl; // returns 1
    return 0;
}