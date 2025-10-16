#include <iostream>
using namespace std;
//Tree is hierarchical data structure which is a collection of nodes connected by edges.
//The topmost node is called root node.
//Each node contains a value and a list of references to its child nodes.
//A node that has no children is called a leaf node.
//A subtree of a node is a tree consisting of that node and its descendants.
//For a particular node, the parent node is called the ancestor node and the child nodes are called descendant nodes.
//There are mainly 5 types of binary trees:
//1. Full Binary Tree: A binary tree in which every node has either 0 or 2 children.
//2. Complete Binary Tree: A binary tree in which all levels are completely filled except possibly the last level, which is filled from left to right.
//3. Perfect Binary Tree: A binary tree in which all internal nodes have two children and all leaf nodes are at the same level.
//4. Balanced Binary Tree: A binary tree in which the height of the tree can maximum be log(n) where n is the number of nodes in the tree.
//5. Degenerate (or pathological) Tree: A binary tree in which each parent node has only one child. This essentially makes it a linked list.
//Binary Tree Representation:
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    cout<<root->left->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->data;
    return 0;
}