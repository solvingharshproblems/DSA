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
//Problem 2: Flatten a binary tree to a linked list in-place
//For Brute Force Approach, we can perform a reverse preorder traversal (root, right, left) and keep track of the previously visited node
void FlattenBruteForce(Node* root){
    static Node* prev=nullptr;
    if(root==nullptr){
        return;
    }
    FlattenBruteForce(root->right);
    FlattenBruteForce(root->left);
    root->right=prev;
    root->left=nullptr;
    prev=root;
} // TC=O(n) SC=O(log n) due to recursive stack space
//For Better Approach, we can use a stack to perform an iterative preorder traversal of brute force
void FlattenBetter(Node* root){
    if(root==nullptr){
        return;
    }
    stack<Node*> st;
    st.push(root);
    Node* prev=nullptr;
    while(!st.empty()){
        Node* currentNode=st.top();
        st.pop();
        if(prev){
            prev->right=currentNode;
            prev->left=nullptr;
        }
        if(currentNode->right){
            st.push(currentNode->right);
        }
        if(currentNode->left){
            st.push(currentNode->left);
        }
        prev=currentNode;
    }
} // TC=O(n) SC=O(log n) due to stack space
//For Optimal Approach, we can use Morris Traversal technique to flatten the tree in-place without extra space
void FlattenOptimal(Node* root){
    Node* current=root;
    while(current){
        if(current->left){
            Node* predecessor=current->left;
            while(predecessor->right){
                predecessor=predecessor->right;
            }
            predecessor->right=current->right;
            current->right=current->left;
            current->left=nullptr;
        }
        current=current->right;
    }
} // TC=O(n) SC=O(1)
void Inorder(Node* root) {
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void PreOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PrintFlattenedTree(Node* root){
    Node* current=root;
    while(current){
        cout<<current->data<<" ";
        current=current->right;
    }
    cout<<endl;
}
int main(){
    /*
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
    */
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    cout<<"Original Tree Inorder: ";
    Inorder(root);
    cout<<endl;
    FlattenBruteForce(root);
    PrintFlattenedTree(root);
    FlattenBetter(root);
    PrintFlattenedTree(root);
    FlattenOptimal(root);
    PrintFlattenedTree(root);
    return 0;
}