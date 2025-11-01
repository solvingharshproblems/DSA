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
//Problem 4: Insert in a BST
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
    return 0;
}