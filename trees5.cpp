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
//Problem 1: Maximum Depth of Binary Tree
//For Optimal Approach, we can use any of the recursive or level-order traversal methods to find the maximum depth of the binary tree.
//Note: For the worst case, the space complexity for both approaches will be O(n) where n is the number of nodes in the binary tree.
//Here, we will use a recursive approach.
int maxDepth(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return max(leftDepth,rightDepth)+1;
} // TC=O(n) SC=O(h) where h is the height of the tree
//Problem 2: Check if a Binary Tree is Height-Balanced
//A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.
//For Optimal Approach, we can use a recursive function that returns the height of the tree if it is balanced, and -1 if it is not balanced.
int checkBalance(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftHeight=checkBalance(root->left);
    if(leftHeight==-1){
        return -1;
    }
    int rightHeight=checkBalance(root->right);
    if(rightHeight==-1){
        return -1;
    }
    if(abs(leftHeight-rightHeight)>1){
        return -1;
    }
    return max(leftHeight,rightHeight)+1;
}
bool isBalanced(Node* root){
    return checkBalance(root)!=-1;  
} // TC=O(n) SC=O(h) where h is the height of the tree
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
    cout<<"Maximum Depth of Binary Tree: "<<maxDepth(root)<<endl;
    if(isBalanced(root)){
        cout<<"The Binary Tree is Height-Balanced"<<endl;
    }
    else{
        cout<<"The Binary Tree is not Height-Balanced"<<endl;
    }
    return 0;
}