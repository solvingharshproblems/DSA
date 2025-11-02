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
//Problem 1: Insert in a BST
//For Optimal Approach, we will use the property of BST to find the correct position to insert the new node
Node* InsertInBST(Node* root,int key){
    Node* newNode=new Node(key);
    if(root==nullptr){
        return newNode;
    }
    Node* parent=nullptr;
    Node* curr=root;
    while(curr){
        parent=curr;
        if(key<curr->data){
            curr=curr->left;
        }
        else{
            curr=curr->right;;
        }
    }
    if(key<parent->data){
        parent->left=newNode;
    }
    else{
        parent->right=newNode;
    }
    return root;
} // TC=O(h) SC=O(1), h is the height of the tree
//Problem 2: Delete in a BST
//For Optimal Approach, there will be 2 cases 
//1. Node to be deleted has one child or no child
//2. Node to be deleted has two children
Node* DeleteInBST(Node* root,int key){
    if(root==nullptr){
        return root;
    }
    if(key<root->data){
        root->left=DeleteInBST(root->left,key);
    }
    else if(key>root->data){
        root->right=DeleteInBST(root->right,key);
    }
    else{
        if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        Node* temp=root->right;
        while(temp->left){
            temp=temp->left;
        }
        root->data=temp->data;
        root->right=DeleteInBST(root->right,temp->data);
    }
    return root;
} // TC=O(h) SC=O(h), h is the height of the tree
void Inorder(Node* root) {
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root=InsertInBST(root,7);
    cout<<"Inorder Traversal after Insertion: ";
    Inorder(root);
    cout<<endl;
    root=DeleteInBST(root,5);
    cout<<"Inorder Traversal after Deletion: ";
    Inorder(root);
    cout<<endl;
    return 0;
}