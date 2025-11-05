#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
}Node;
//Problem 1: Recover BST
//Youre given a BST in which two nodes are swapped by mistake. Recover the tree without changing its structure.
//For Brute Force Approach, we can do inorder traversal and store the values in an array. 
//Then sort the array and again do inorder traversal to update the values of nodes from sorted array.
void inorder(Node* root,vector<int>& vals){
    if(root==nullptr){ 
        return;
    }
    inorder(root->left, vals);
    vals.push_back(root->data);
    inorder(root->right, vals);
}
void InorderUpdate(Node* root,vector<int>& vals,int& index){
    if(root==nullptr){ 
        return;
    }
    InorderUpdate(root->left,vals,index);
    root->data=vals[index++];
    InorderUpdate(root->right,vals,index);
}
void RecoverBSTBruteForce(Node* root){
    vector<int> vals;
    inorder(root,vals);
    sort(vals.begin(),vals.end());
    int index=0;
    InorderUpdate(root,vals,index);
    cout<<"BST Recovered"<<endl;
} // TC=O(2n+nlogn) SC=O(n)
//For Optimal Approach, we will use Morris Inorder Traversal to find the two swapped nodes and swap their values. 
void InorderOptimal(Node* root){
    static Node *first=nullptr,*middle=nullptr,*last=nullptr;
    static Node* prev=new Node(INT_MIN);
    if(root==nullptr){
        return;
    }
    InorderOptimal(root->left);
    if(prev!=nullptr && root->data < prev->data){
        if(!first){
            first=prev;
            middle=root;
        }
        else{
            last=root;
        }
    }
    prev=root;
    InorderOptimal(root->right);
}
void RecoverBSTOptimal(Node* root){
    Node *first=nullptr,*middle=nullptr,*last=nullptr;
    Node* prev=new Node(INT_MIN);
    InorderOptimal(root);
    if(first && last){
        swap(first->data,last->data);
    }
    else if(first && middle){
        swap(first->data,middle->data);
    }
    cout<<"BST Recovered"<<endl;
} // TC=O(n) SC=O(1)
int main(){
    Node* root=new Node(1);
    root->left=new Node(3);
    root->right=new Node(2);
    RecoverBSTBruteForce(root);
    RecoverBSTOptimal(root);
    return 0;
}