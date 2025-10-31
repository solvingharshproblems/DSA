#include <iostream>
using namespace std;
//Binary Search Tree
//In a binary search tree (BST), for each node, all elements in its left subtree are less than the node's value, and all elements in its right subtree are greater than the node's value.
//Mostly height of a BST is log n, so the time complexity for search, insert and delete operations is O(log n) on average. However, in the worst case (when the tree becomes unbalanced and resembles a linked list), these operations can take O(n) time.
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
//Problem 1: Search in a BST
//For Optimal Approach, we will use the property of BST to search for the key and traverse left or right accordingly
Node* SearchInBST(Node* root,int key){
    while(root!=nullptr && root->data!=key){
        if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return root;
} // TC=O(h) SC=O(1), h is the height of the tree
//Problem 2: Ceil in a BST
//Ceil of a key in BST is the smallest element in the BST which is greater than or equal to the key.
//For Optimal Approach, we will use the property of BST to find the ceil value and return the minimum candidate found
int CeilInBST(Node* root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
            return ceil;
        }
        if(key>root->data){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
} // TC=O(h) SC=O(1), h is the height of the tree
int main(){
    Node* root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(1);
    root->left->right=new Node(6);
    root->right->right=new Node(14);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);
    root->right->right->left=new Node(13);
    int key=7;
    Node* result=SearchInBST(root,key);
    if(result){
        cout<<"Key "<<key<<" found in BST."<<endl;
    }
    else{
        cout<<"Key "<<key<<" not found in BST."<<endl;
    }
    int ceil;
    cout<<"Enter key to find ceil in BST: ";
    cin>>ceil;
    int ceilValue=CeilInBST(root,ceil);
    if(ceilValue!=-1){
        cout<<"Ceil of "<<ceil<<" in BST is: "<<ceilValue<<endl;
    }
    else{
        cout<<"Ceil of "<<ceil<<" does not exist in BST."<<endl;
    }
    return 0;
}