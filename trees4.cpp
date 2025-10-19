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
//1. Post-order Traversal (Left, Right, Root) (Iterative using 2 stacks) 
void PostOrder1(Node* root){
    if(root==nullptr){
        return;
    }
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        Node* currentNode=s1.top();
        s1.pop();
        s2.push(currentNode);
        if(currentNode->left!=nullptr){
            s1.push(currentNode->left);
        }
        if(currentNode->right!=nullptr){
            s1.push(currentNode->right);
        }
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
//2. Post-order Traversal (Left, Right, Root) (Iterative using 1 stack)
void PostOrder2(Node* root){
    if(root==nullptr){
        return;
    }
    stack<Node*> s;
    Node* currentNode=root;
    Node* lastVisitedNode=nullptr;
    while(!s.empty() || currentNode!=nullptr){
        if(currentNode!=nullptr){   
            s.push(currentNode);
            currentNode=currentNode->left;
        }
        else{
            Node* peekNode=s.top();
            if(peekNode->right!=nullptr && lastVisitedNode!=peekNode->right){
                currentNode=peekNode->right;
            }
            else{
                cout<<peekNode->data<<" ";
                lastVisitedNode=peekNode;
                s.pop();
            }
        }
    }
} // TC=O(n) SC=O(h) where h is the height of the tree
//3. Preorder, Inorder and Postorder Traversals (Morris Traversal)
void MorrisTraversal(Node* root){
    stack<pair<Node*,int>> s;
    s.push({root,1});
    vector<int> pre,in,post;
    if(root==nullptr){
        return;
    }
    while(!s.empty()){
        auto it=s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left!=nullptr){
                s.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right!=nullptr){
                s.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    cout<<"Preorder Traversal: ";
    for(int val:pre){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal: ";
    for(int val:in){
        cout<<val<<" "; 
    }
    cout<<endl;
    cout<<"Postorder Traversal: ";
    for(int val:post){
        cout<<val<<" ";
    }
} // TC=O(3n) SC=O(4h) where h is the height of the tree
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(6);
    root->right->left=new Node(7);
    root->right->right=new Node(8);
    root->right->right->left=new Node(9);
    root->right->right->right=new Node(10);
    PostOrder1(root);
    cout<<endl;
    PostOrder2(root);
    cout<<endl;
    MorrisTraversal(root);
    return 0;
}