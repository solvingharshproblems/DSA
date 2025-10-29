#include <iostream>
#include <vector>
#include <unordered_map>
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
//Problem 2: Construct a binary tree from the given inorder and preorder traversals
//For Optimal Approach, we will use a hash map to store the indices of inorder elements for O(1) access and recursively build the tree
Node* BuildTreeHelper(vector<int>& preorder,vector<int>& inorder,int& preIndex,int inStart,int inEnd,unordered_map<int,int>& inorderMap){
    if(preIndex>=preorder.size() || inStart>inEnd){
        return nullptr;
    }
    int rootValue=preorder[preIndex++];
    Node* root=new Node(rootValue);
    int midIndex=inorderMap[rootValue];
    root->left=BuildTreeHelper(preorder,inorder,preIndex,inStart,midIndex-1,inorderMap);
    root->right=BuildTreeHelper(preorder,inorder,preIndex,midIndex+1,inEnd,inorderMap);
    return root;
}
Node* BuildTree(vector<int>& preorder,vector<int>& inorder){
    if(preorder.size()==0 || inorder.size()==0){
        return nullptr;
    }
    unordered_map<int,int> inorderMap;
    for(int i=0;i<inorder.size();i++){
        inorderMap[inorder[i]]=i;
    }
    int preIndex=0;
    Node* root=BuildTreeHelper(preorder,inorder,preIndex,0,inorder.size()-1,inorderMap);
    return root;
} // TC=O(n) SC=O(2n) due to hash map and recursive stack space
//Problem 3: Construct a binary tree from the given inorder and postorder traversals
//Similar to Problem 2, we can use a hash map and recursively build the tree using postorder traversal
Node* BuildTreeHelper2(vector<int>& inorder,vector<int>& postorder,int& postIndex,int inStart,int inEnd,unordered_map<int,int>& inorderMap){
    if(postIndex<0 || inStart>inEnd){
        return nullptr;
    }
    int rootValue=postorder[postIndex--];
    Node* root=new Node(rootValue);
    int midIndex=inorderMap[rootValue];
    root->right=BuildTreeHelper2(inorder,postorder,postIndex,midIndex+1,inEnd,inorderMap);
    root->left=BuildTreeHelper2(inorder,postorder,postIndex,inStart,midIndex-1,inorderMap);
    return root;
}
Node* BuildTree2(vector<int>& inorder,vector<int>& postorder){
    if(inorder.size()==0 || postorder.size()==0){
        return nullptr;
    }
    unordered_map<int,int> inorderMap;
    for(int i=0;i<inorder.size();i++){
        inorderMap[inorder[i]]=i;
    }
    int postIndex=postorder.size()-1;
    Node* root=BuildTreeHelper2(inorder,postorder,postIndex,0,inorder.size()-1,inorderMap);
    return root;
} // TC=O(n) SC=O(2n) due to hash map and recursive stack space
void Inorder(Node* root) {
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
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
    cout<<endl;
    vector<int> preorder={10,20,40,50,30,60};
    vector<int> inorder={40,20,50,10,60,30};
    Node* root1=BuildTree(preorder,inorder);
    cout<<"New tree: "<<root1->data<<" "<<root1->left->data<<" "<<root1->right->data<<" "<<root1->left->left->data<<" "<<root1->left->right->data<<" "<<root1->right->left->data;
    cout<<endl;
    vector<int> inorder2={40,20,50,10,60,30};
    vector<int> postorder={40,50,20,60,30,10};
    Node* root2=BuildTree2(inorder2,postorder);
    cout<<"New tree: ";
    Inorder(root2);
    cout<<endl;
    return 0;
}