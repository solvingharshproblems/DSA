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
//Problem 1: Root to node path in a binary tree
//For Optimal Approach, we can use inorder recursive traversal to find the path from root to the given node.
void RootToNodePath(Node* root,int key){
    if(root==nullptr){
        return;
    }
    static vector<int> path;
    path.push_back(root->data);
    if(root->data==key){
        for(int val:path){
            cout<<val<<" ";
        }
        return;
    }
    RootToNodePath(root->left,key);
    RootToNodePath(root->right,key);
    path.pop_back();
} // TC=O(n) SC=O(h)
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(7);
    int key=7;
    cout<<"Root to node path for "<<key<<": ";
    RootToNodePath(root,key);
    cout<<endl;
    return 0;
}