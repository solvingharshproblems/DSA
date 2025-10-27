#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
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
//Problem 2: Children sum property in a binary tree
//Check if the parent node has value as sum of left and right children node, if not then add +1, n number of times of any of the node 
//For Optimal Approach, we will use recursive approach to check and add value to nodes
void IncrementChild(Node* root,int diff){
    if(root->left){
        root->left->data+=(-diff);
        IncrementChild(root->left,-diff);
    }
    else if(root->right){
        root->right->data+=(-diff);
        IncrementChild(root->right,-diff);
    }
}
void ChildrenSumProperty(Node* root){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        return;
    }
    ChildrenSumProperty(root->left);
    ChildrenSumProperty(root->right);
    int leftData=root->left ? root->left->data:0;
    int rightData=root->right ? root->right->data:0;
    int diff=(leftData+rightData)-root->data;
    if(diff>0){
        root->data+=diff;
    }
    else if(diff<0){
        IncrementChild(root,diff);
    } 
}
void Inorder(Node* root){
    if(root==nullptr){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
} // TC=O(n) SC=O(h)
int main(){
    /*
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
    */
    Node* root=new Node(2);
    root->left=new Node(35);
    root->right=new Node(10);
    root->left->left=new Node(2);
    root->left->right=new Node(3);
    root->right->right=new Node(2);
    root->right->left=new Node(5);
    ChildrenSumProperty(root);
    Inorder(root);
    return 0;
}