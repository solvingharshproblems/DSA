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
//Binary Tree Traversal:
//There are 2 main types of tree traversal:
//1. Depth First Search (DFS): In this traversal, we go as deep as possible along each branch before backtracking.
//There are 3 types of DFS traversal:
//a. Inorder Traversal (Left, Root, Right)
//b. Preorder Traversal (Root, Left, Right)
//c. Postorder Traversal (Left, Right, Root)
//2. Breadth First Search (BFS) or Level Order Traversal: In this traversal, we visit all the nodes at the present depth level before moving on to the nodes at the next depth level.
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