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
//Problem 1: Identical trees or not
//For Optimal Approach, we can do any of the traversals (preorder, inorder, postorder) of both trees simultaneously and compare the nodes.
bool isIdentical(Node* root1,Node* root2){
    if(root1==nullptr && root2==nullptr){
        return true;
    }
    if(root1==nullptr || root2==nullptr){
        return false;
    }
    return (root1->data==root2->data) && isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
} // TC=O(min(n1,n2)) SC=O(h) where h is the height of the tree
int main(){
    Node* root1=new Node(1);
    root1->left=new Node(2);
    root1->right=new Node(3);
    root1->right->left=new Node(4);
    root1->right->right=new Node(5);
    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->right->left=new Node(4);
    root2->right->right=new Node(5);
    if(isIdentical(root1,root2)){
        cout<<"The trees are identical"<<endl;
    }
    else{
        cout<<"The trees are not identical"<<endl;
    }
    return 0;
}