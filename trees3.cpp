#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data=val;
        right=nullptr;
        left=nullptr;
    }
}Node;
//1. Level Order Traversal
//We will use a queue to perform level order traversal by enqueueing child nodes.
void LevelOrder(Node* root){
    vector<vector<int>> result;
    if(root==nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> currentLevel;
        for(int i=0;i<size;i++){
            Node* currentNode=q.front();
            q.pop();
            if(currentNode->left!=nullptr){
                q.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                q.push(currentNode->right);
            }
            currentLevel.push_back(currentNode->data);
        }
        result.push_back(currentLevel);
    }
    for(const auto& level:result){
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    LevelOrder(root);
    return 0;
}