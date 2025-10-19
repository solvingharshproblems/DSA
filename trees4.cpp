#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data=val;
        right=nullptr;
        left=nullptr;
    }
}Node;
//1. Post-order Traversal (Left, Right, Root) (Iterative using 2 stacks) 
void PostOrder1(Node* root){
    if(root==nullptr){
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        Node* currentNode=s1.top();
        s1.pop();
        s2.push(currentNode);
        if(currentNode->left!=nullptr){
            s1.push(currentNode->left);
        }
        if(currentNode->right!=nullptr){
            s1.push(currentNode->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->left=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);
    PostOrder1(root);
    return 0;
}