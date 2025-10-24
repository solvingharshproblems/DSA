#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
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
//Problem 1: Boundary traversal of a binary tree (anti-clock wise)
//For Optimal Approach, on the left side of root node we will implement pre-order traversal, on the right side we will implement post-order traversal and for the leaf nodes we will implement in-order traversal.
void LeftBoundary(Node* root,vector<int> &result){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    result.push_back(root->data);
    if(root->left!=nullptr){
        LeftBoundary(root->left,result);
    } 
    else{
        LeftBoundary(root->right,result);
    }
}
void RightBoundary(Node* root,vector<int> &result){
    if(root==nullptr || (root->left==nullptr && root->right==nullptr)){
        return;
    }
    if(root->right!=nullptr){
        RightBoundary(root->right,result);
    } 
    else{
        RightBoundary(root->left,result);
    }
    result.push_back(root->data);
}
void LeafNodes(Node* root,vector<int> &result){
    if(root==nullptr){
        return;
    }
    if(root->left==nullptr && root->right==nullptr){
        result.push_back(root->data);
        return;
    }
    LeafNodes(root->left,result);
    LeafNodes(root->right,result);
}
void BoundaryTraversal(Node* root){
    vector<int> result;
    if(root==nullptr){
        return;
    }
    result.push_back(root->data);
    LeftBoundary(root->left,result);
    LeafNodes(root,result);
    RightBoundary(root->right,result);
    for(int val:result){
        cout<<val<<" ";
    }
} // TC=O(n) SC=O(h) where h is the height of the tree
//Problem 2: Vertical order traversal of a binary tree
//For Optimal Approach, we can use level order traversal while keeping track of horizontal distance of each node from the root node.
void VerticalOrder(Node* root){
    map<int,map<int,multiset<int>>> mp;
    queue<pair<Node*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node* temp=p.first;
        int x=p.second.first;  
        int y=p.second.second; 
        mp[x][y].insert(temp->data);
        if(temp->left){
            q.push({temp->left,{x-1,y+1}});
        }
        if(temp->right){
            q.push({temp->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto p: mp){
        vector<int> col;
        for(auto q:p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    for(const auto& vec:ans){
        for(int val:vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
//Note: We are not considering the TC of map and multiset insertions and output nested loop here.
//Problem 3: Top view of a binary tree
//For Optimal Approach, we can use level order traversal while keeping track of horizontal distance of each node from the root node. We will store only the first node at each horizontal distance.
void TopView(Node* root){
    map<int,int> topNode;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        Node* temp=p.first;
        int hd=p.second;
        if(topNode.find(hd)==topNode.end()){
            topNode[hd]=temp->data;
        }
        if(temp->left){
            q.push({temp->left,hd-1});
        }
        if(temp->right){
            q.push({temp->right,hd+1});
        }
    }
    for(auto p:topNode){
        cout<<p.second<<" ";
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
int main(){
    /*
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->left->right=new Node(4);
    root->left->left->right->left=new Node(5);
    root->left->left->right->right=new Node(6);
    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->left->left=new Node(10);
    root->right->right->left->right=new Node(11);
    BoundaryTraversal(root);
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(10);
    root->left->left->right=new Node(5);
    root->left->left->right->right=new Node(6);
    root->right->left=new Node(9);
    root->right->right=new Node(10);
    VerticalOrder(root);
    */
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->right=new Node(7);
    TopView(root);
    return 0;
}