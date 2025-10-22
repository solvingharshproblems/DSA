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
int main(){
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
    return 0;
}