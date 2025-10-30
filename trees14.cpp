#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        right=nullptr;
        left=nullptr;
    }
}Node;
//Problem 1: Serialize and Deserialize a binary tree
//For Optimal Approach:
//For Serialize, we will use level order traversal and represent null nodes with a special character '#'
string serialize(Node* root) {
    if(!root){
        return "";
    }
    string s="";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* currentNode=q.front();
        q.pop();
        if(currentNode==nullptr){
            s+="#,";
        }
        else{
            s+=to_string(currentNode->data)+",";
            q.push(currentNode->left);
            q.push(currentNode->right);
        }
    }
    if(!s.empty()){
        s.pop_back(); 
    }
    return s;
} // TC=O(n) SC=O(n) due to queue space
//For Deserialize, we will use a queue to keep track of nodes and build the tree level by level
Node* Deserialize(string data){
    if(data.empty()){
        return nullptr;
    }
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(getline(s,str,',') && str!="#"){
            Node* left=new Node(stoi(str));
            node->left=left;
            q.push(left);
        }
        if(getline(s,str,',') && str!="#"){
            Node* right=new Node(stoi(str));
            node->right=right;
            q.push(right);
        }
    }
    return root;
} // TC=O(n) SC=O(n) due to queue space
void Inorder(Node* root) {
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->right=new Node(5);
    string serializedTree=serialize(root);
    cout<<"Serialized Tree: "<<serializedTree<<endl;
    Node* deserializedTree=Deserialize(serializedTree);
    cout<<"Deserialized Tree: ";
    Inorder(deserializedTree);
    return 0;
}