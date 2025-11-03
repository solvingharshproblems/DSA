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
//Problem 1: LCA of two nodes in a BST
//For Optimal Approach, we will perform a DFS traversal, at each node we will check if both n1 and n2 are smaller than the node's value,
// if yes we will go to left subtree, if both are greater we will go to right subtree, else we have found our LCA
Node* findLCA(Node* root,Node* p,Node* q){
    if(root==nullptr){
        return nullptr;
    }
    if(p->data<root->data && q->data<root->data){
        return findLCA(root->left,p,q);
    }
    else if(p->data>root->data && q->data>root->data){
        return findLCA(root->right,p,q);
    }
    else{
        return root;
    }
} // TC=O(h) SC=O(h) where h is the height of the tree
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    Node* p=root->left;
    Node* q=root->right;
    Node* lca=findLCA(root,p,q);
    if(lca){
        cout<<"LCA of "<<p->data<<" and "<<q->data<<" is "<<lca->data<<endl;
    } 
    else{
        cout<<"LCA not found"<<endl;
    }
    return 0;
}