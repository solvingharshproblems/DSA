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
//Problem 1: Print all the nodes at distance k from given node
//For Optimal Approach, we will first map all the parent nodes using DFS traversal and then use BFS to traverse k levels from target node
void markParents(Node* root,unordered_map<Node*,Node*>& parent_track){
    if(root==nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        if(current->left){
            parent_track[current->left]=current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right]=current;
            q.push(current->right);
        }
    }
}
void printKDistance(Node* root,Node* target,int k){
    unordered_map<Node*,Node*> parent_track;
    markParents(root,parent_track);
    unordered_map<Node*,bool> visited;
    queue<Node*> q;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!q.empty()){
        int size=q.size();
        if(curr_level==k){
            break;
        }
        curr_level++;
        for(int i=0;i<size;i++){
            Node* current=q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left]=true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right]=true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]]=true;
            }
        }
    }
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        q.pop();
    }
} // TC=O(n) SC=O(n) here we can consider hash map space too which is O(log n) in balanced tree
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    Node* target=root->left;
    int k=2;
    printKDistance(root,target,k);
    return 0;
}