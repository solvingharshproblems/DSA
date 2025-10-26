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
//For Optimal Approach, we will use inorder recursive traversal to find the path from root to the given node.
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
//Problem 2: Lowest common ancestor in a binary tree
//A node is the lowest common ancestor of two nodes n1 and n2 if it is the deepest node that has both n1 and n2 as descendants.
//For Optimal Approach, we will use preorder recursive traversal to find the lowest common ancestor of the two given nodes.
Node* LCA(Node* root,int n1,int n2){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLCA=LCA(root->left,n1,n2);
    Node* rightLCA=LCA(root->right,n1,n2);
    if(leftLCA && rightLCA){
        return root;
    }
    return (leftLCA!=nullptr)?leftLCA:rightLCA;
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
    root->right->right=new Node(9);
    root->right->left=new Node(8);
    int n1=4,n2=7;
    Node* lca=LCA(root,n1,n2);
    if(lca!=nullptr){
        cout<<"LCA of "<<n1<<" and "<<n2<<" is: "<<lca->data<<endl;
    }
    else{
        cout<<"LCA does not exist!"<<endl;
    }
    return 0;
}