#include <iostream>
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
//Problem 1: Boundary traversal of a binary tree (anti-clock wise)
//For Optimal Approach, on the left side of root node we will implement pre-order traversal, on the right side we will implement post-order traversal and for the leaf nodes we will implement in-order traversal.
void LeftBoundary(Node* root,vector<int> &result){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    result.push_back(root->data);
    if(root->left!=nullptr){
        LeftBoundary(root->left,result);
    } 
    else{
        LeftBoundary(root->right,result);
    }
}
void RightBoundary(Node* root,vector<int> &result){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    if(root->right!=nullptr){
        RightBoundary(root->right,result);
    } 
    else{
        RightBoundary(root->left,result);
    }
    result.push_back(root->data);
}
void LeafNodes(Node* root,vector<int> &result){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        result.push_back(root->data);
        return;
    }
    LeafNodes(root->left,result);
    LeafNodes(root->right,result);
}
void BoundaryTraversal(Node* root){
    vector<int> result;
    if(root==nullptr){
        return;
    }
    result.push_back(root->data);
    LeftBoundary(root->left,result);
    LeafNodes(root,result);
    RightBoundary(root->right,result);
    for(int val:result){
        cout<<val<<" ";
    }
} // TC=O(n) SC=O(h) where h is the height of the tree
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->left->right=new Node(4);
    root->left->left->right->left=new Node(5);
    root->left->left->right->right=new Node(6);
    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right=new Node(11);
    BoundaryTraversal(root);
    return 0;
}