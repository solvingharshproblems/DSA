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
//Problem 1: Find the diameter of binary tree
//We need to return the maximum distance between the 2 nodes of a binary tree
//For Brute Force Approach, we will take sum of the nodes on the depth of right side and of the left side for every node and return the maximum sum obtained.
int maxDepth(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    return max(leftDepth,rightDepth)+1;
}
int DiameterBruteForce(Node* root){
    if(root==nullptr){
        return 0;
    }
    int maxSum=0;
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);
    int currentDiameter=leftDepth+rightDepth;
    int leftDiameter=DiameterBruteForce(root->left);
    int rightDiameter=DiameterBruteForce(root->right);
    maxSum=max(currentDiameter,max(leftDiameter,rightDiameter));
    return maxSum;
} // TC=O(n^2) SC=O(h) where h is the height of the tree
//For Optimal Approach, we can calculate the diameter while calculating the height of the tree in a single traversal.
int height(Node* root,int &diameter){
    if(root==nullptr){
        return 0;
    }
    int leftHeight=height(root->left,diameter);
    int rightHeight=height(root->right,diameter);
    diameter=max(diameter,leftHeight+rightHeight);
    return max(leftHeight,rightHeight)+1;
}
void DiameterOptimal(Node* root){
    int diameter=0;
    height(root,diameter);
    cout<<diameter<<endl;
} // TC=O(n) SC=O(h) where h is the height of the tree
//Problem 2: Maximum Path Sum in Binary Tree
//A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
//For Optimal Approach, we can use the max depth function with slight modification to calculate the maximum path sum.
int maxDepthPath(Node* root,int &maxSum){
    if(root==nullptr){
        return 0;
    }
    int leftSum=max(0,maxDepthPath(root->left,maxSum));
    int rightSum=max(0,maxDepthPath(root->right,maxSum));
    maxSum=max(maxSum,root->data+leftSum+rightSum);
    return root->data+max(leftSum,rightSum);
}
void MaxPathSumOptimal(Node* root){
    if(root==nullptr){
        return;
    }
    int maxSum=INT_MIN;
    maxDepthPath(root,maxSum);
    cout<<maxSum<<endl;
} // TC=O(n) SC=O(h) where h is the height of the tree
int main(){
    /*
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(4);
    root->right->left->left=new Node(5);
    root->right->right=new Node(6);
    root->right->right->right=new Node(7);
    root->right->right->right->right=new Node(8);
    root->right->left->left->left=new Node(9);
    int diameter1=DiameterBruteForce(root);
    cout<<diameter1<<endl;
    DiameterOptimal(root);
    */
    Node* root=new Node(-10);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    MaxPathSumOptimal(root);
    return 0;
}