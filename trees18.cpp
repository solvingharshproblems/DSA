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
//Problem 1: LCA of two nodes in a BST
//For Optimal Approach, we will perform a DFS traversal, at each node we will check if both n1 and n2 are smaller than the node's value,
// if yes we will go to left subtree, if both are greater we will go to right subtree, else we have found our LCA
Node* findLCA(Node* root,Node* p,Node* q){
    if(root==nullptr){
        return nullptr;
    }
    if(p->data<root->data && q->data<root->data){
        return findLCA(root->left,p,q);
    }
    else if(p->data>root->data && q->data>root->data){
        return findLCA(root->right,p,q);
    }
    else{
        return root;
    }
} // TC=O(h) SC=O(h) where h is the height of the tree
 //Problem 2: Construct BST from preorder traversal
//For Brute Force Approach, we can compare the element to root, if the element is smaller we go to left subtree else we go to right subtree
//We keep doing this until we find a NULL position to insert the new node
void insertBST(Node*& root,int val){
    if(root==nullptr){
        root=new Node(val);
        return;
    }
    if(val<root->data){
        insertBST(root->left,val);
    }
    else{
        insertBST(root->right,val);
    }
}
Node* constructBSTBruteForce(vector<int>& preorder){
    Node* root=nullptr;
    for(int val:preorder){
        insertBST(root,val);
    }
    return root;
} // TC=O(n^2) SC=O(n)
//For Optimal Approach, we will use a recursive function with bounds to construct the BST
Node* constructBSTHelper(vector<int>& preorder,int& index,int bound){
    if(index==preorder.size() || preorder[index]>bound){
        return nullptr;
    }
    Node* root=new Node(preorder[index++]);
    root->left=constructBSTHelper(preorder,index,root->data);
    root->right=constructBSTHelper(preorder,index,bound);
    return root;
}
Node* constructBSTOptimal(vector<int>& preorder){
    int index=0;
    return constructBSTHelper(preorder,index,INT_MAX);
} // TC=O(n) SC=O(1)
void Inorder(Node* root) {
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main(){
    /*
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    Node* p=root->left;
    Node* q=root->right;
    Node* lca=findLCA(root,p,q);
    if(lca){
        cout<<"LCA of "<<p->data<<" and "<<q->data<<" is "<<lca->data<<endl;
    } 
    else{
        cout<<"LCA not found"<<endl;
    }
    */
    vector<int> preorder={8,5,1,7,10,12};
    Node* bstRoot=constructBSTOptimal(preorder);
    cout<<"BST constructed from preorder traversal."<<endl;
    Inorder(bstRoot);
    return 0;
}