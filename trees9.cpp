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
//Problem 1: i) Right view of a binary tree
//Here both level order and recursive traversals can be used with both having some disadvantages.
//For Optimal Approach, here we will use recursive pre-order traversal while keeping track of the level of each node. 
//We will print the first node we encounter at each level starting from level 0.
int RightViewTraversal(Node* root,int level,vector<int> &result){
    if(root==nullptr){
        return 0;
    }
    if(level==result.size()){
        result.push_back(root->data);
    }
    RightViewTraversal(root->right,level+1,result);
    RightViewTraversal(root->left,level+1,result);
    return 0;
}
void RightView(Node* root){
    vector<int> result;
    RightViewTraversal(root,0,result);
    for(int val:result){
        cout<<val<<" ";
    }
} // TC=O(n) SC=O(h) 
//ii) Left view of a binary tree
int LeftViewTraversal(Node* root,int level,vector<int> &result){
    if(root==nullptr){
        return 0;
    }
    if(level==result.size()){
        result.push_back(root->data);
    }
    LeftViewTraversal(root->left,level+1,result);
    LeftViewTraversal(root->right,level+1,result);
    return 0;
}
void LeftView(Node* root){
    vector<int> result;
    LeftViewTraversal(root,0,result);
    for(int val:result){
        cout<<val<<" ";
    }
} // TC=O(n) SC=O(h)
//Problem 2: Symmetric binary tree
//If a binary tree is mirror image of itself, then it is a symmetric binary tree.
//For Optimal Approach, we can use recursion to check if left subtree is mirror image of right subtree.
bool isMirror(Node* left,Node* right){
    if(left==nullptr && right==nullptr){    
        return true;
    }
    if(left==nullptr || right==nullptr){
        return false;
    }
    if(left->data!=right->data){
        return false;
    }
    return isMirror(left->left,right->right) && isMirror(left->right,right->left);
}
bool isSymmetric(Node* root){
    if(root==nullptr){
        return true;
    }
    return isMirror(root->left,root->right);
} // TC=O(n) SC=O(h)
int main(){
    /*
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(7);
    root->left->right->left=new Node(6);
    cout<<"Right View: ";
    RightView(root);
    cout<<"\nLeft View: ";
    LeftView(root);
    */
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->right=new Node(3);
    root->right->left=new Node(4);
    if(isSymmetric(root)){
        cout<<"It is a symmetric binary tree!"<<endl;
    }
    else{
        cout<<"It is not a symmetric binary tree!"<<endl;
    }
    return 0;
}