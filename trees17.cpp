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
//Problem 1: Kth smallest element in a BST
//For Brute Force Approach, we can perform any traversal (inorder, preorder, postorder) and store the elements in a vector, then return the k-1 index element from the sorted vector
void InorderTraversal(Node* root,vector<int>& elements){
    if(root==nullptr){
        return;
    }
    InorderTraversal(root->left,elements);
    elements.push_back(root->data);
    InorderTraversal(root->right,elements);
}
int KthSmallestBruteForce(Node* root,int k){
    vector<int> elements;
    InorderTraversal(root,elements);
    if(k>0 && k<=elements.size()){
        return elements[k-1];
    }
    return -1; 
} // TC=O(2n) SC=O(n)
//For Optimal Approach, we will perform an inorder traversal and keep a count of nodes visited, when count reaches k, we return the node's value
//Note: To minimize the space complexity, we will use morris traversal for inorder traversal
int KthSmallestOptimal(Node* root,int k){
    Node* current=root;
    int count=0;
    while(current){
        if(current->left==nullptr){
            count++;
            if(count==k){
                return current->data;
            }
            current=current->right;
        }
        else{
            Node* predecessor=current->left;
            while(predecessor->right && predecessor->right!=current){
                predecessor=predecessor->right;
            }
            if(predecessor->right==nullptr){
                predecessor->right=current;
                current=current->left;
            }
            else{
                predecessor->right=nullptr;
                count++;
                if(count==k){
                    return current->data;
                }
                current=current->right;
            }
        }
    }
    return -1;
} // TC=O(n) SC=O(1)
//Problem 2: Validate BST
//For Optimal Approach, we will use inorder traversal to check if the elements are in sorted order
bool ValidateBST(Node* root,Node*& prev){
    if(root==nullptr){
        return true;
    }
    if(!ValidateBST(root->left,prev)){
        return false;
    }
    if(prev!=nullptr && root->data<=prev->data){
        return false;
    }
    prev=root;
    return ValidateBST(root->right,prev);
}
bool IsValid(Node* root){
    Node* prev=nullptr;
    return ValidateBST(root,prev);
} // TC=O(n) SC=O(h), h is the height of the tree
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    /*
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int kthSmallest=KthSmallestBruteForce(root,k);
    if(kthSmallest!=-1){
        cout<<"The "<<k<<"th smallest element in the BST is: "<<kthSmallest<<endl;
    }
    else{
        cout<<"Invalid value of k"<<endl;
    }
    kthSmallest=KthSmallestOptimal(root,k);
    if(kthSmallest!=-1){
        cout<<"The "<<k<<"th smallest element in the BST is: "<<kthSmallest<<endl;
    }
    else{
        cout<<"Invalid value of k"<<endl;
    }
    */
    if(IsValid(root)){
        cout<<"The tree is a valid BST"<<endl;
    }
    else{
        cout<<"The tree is not a valid BST"<<endl;
    }
    return 0;
}