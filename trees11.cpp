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
//Problem 1: Maximum width of a binary tree
//We need to return the maximum number of nodes present or should be at any level of tree
//For Optimal Approach, we will subtract the right most index - left most index + 1 of every level to check the maximum one
void MaxWidth(Node* root){
    if(root==nullptr){
        return;
    }
    int ans=0;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int minn=q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int currentID=q.front().second-minn;
            Node* node=q.front().first;
            q.pop();
            if(i==0){
                first=currentID;
            }
            if(i==size-1){
                last=currentID;
            }
            if(node->left){
                q.push({node->left,currentID*2+1});
            }
            if(node->right){
                q.push({node->right,currentID*2+2});
            }
        }
        ans=max(ans,last-first+1);
    }
    cout<<ans;
} // TC=O(n) SC=O(n) where n is the number of nodes
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(8);
    root->right->right->left=new Node(6);
    root->right->right->right=new Node(7);
    cout<<"Maximum width of the binary tree is: ";
    MaxWidth(root);
    return 0;
}