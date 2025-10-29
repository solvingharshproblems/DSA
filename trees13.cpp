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
//Problem 1: Count total nodes in a complete binary tree
//For Brute Force, we can use recursive or iterative inorder traversal and return the count variable after the whole traversal
void CountNodesBruteForce(Node* root,int &count){
    if(root==nullptr){
        return;
    }
    count++;
    CountNodesBruteForce(root->left,count);
    CountNodesBruteForce(root->right,count);
} // TC=O(n) SC=O(h) where h is the height of the tree due to recursive stack space
//For Optimal Approach, we will take height of left and right subtrees and calculate nodes using 2^h-1 formula if heights are equal else we will recursively call for left and right subtrees
int calculateHeight(Node* root,bool left){
    int height=0;
    while(root){
        height++;
        if(left){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return height;
}
int CountNodesOptimal(Node* root){
    if(root==nullptr){
        return 0;
    }
    int leftHeight=calculateHeight(root,true);
    int rightHeight=calculateHeight(root,false);
    if(leftHeight==rightHeight){
        return (1<<leftHeight)-1; 
    }
    else{
        return CountNodesOptimal(root->left)+CountNodesOptimal(root->right)+1;
    }
} // TC=O(log n*log n) SC=O(log n) due to recursive stack space
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int count=0;
    CountNodesBruteForce(root,count);
    cout<<count;
    cout<<endl;
    cout<<CountNodesOptimal(root);
    return 0;
}