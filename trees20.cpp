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
//Problem 2: Largest BST in a Binary Tree
//For Brute Force Approach, we can use the validate function to check if it a BST and then find the size of the largest BST by checking each node.
bool IsBST(Node* root,int minVal,int maxVal){
    if(root==nullptr){
        return true;
    }
    if(root->data<minVal || root->data>maxVal){
        return false;
    }
    return IsBST(root->left,minVal,root->data) && IsBST(root->right,root->data,maxVal);
}
int size(Node* root){
    if(root==nullptr){
        return 0;
    }
    return size(root->left)+1+size(root->right);
}
int LargestBSTBruteForce(Node* root){
    if(root==nullptr){
        return 0;
    }
    if(IsBST(root,INT_MIN,INT_MAX)){
        return size(root);
    }
    int leftSize=LargestBSTBruteForce(root->left);
    int rightSize=LargestBSTBruteForce(root->right);
    return max(leftSize,rightSize);
} // TC=O(n^2) SC=O(h)
//For Optimal Approach, we can use a postorder traversal to get the size of largest BST in a binary tree by declaring a class Info to store size, min, max, ans and isBST for each subtree.
//We will use a helper function which will return Info for each subtree and finally return the ans for the whole tree.
class Info{
    public:
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
    Info(){
        size=0;
        min=INT_MAX;
        max=INT_MIN;
        ans=0;
        isBST=true;
    }
};
Info LargestBSTOptimalHelper(Node* root){
    if(root==nullptr){
        return Info();
    }
    if(root->left==nullptr && root->right==nullptr){
        Info singleNode;
        singleNode.size=1;
        singleNode.min=root->data;
        singleNode.max=root->data;
        singleNode.ans=1;
        singleNode.isBST=true;
        return singleNode;
    }
    Info leftInfo=LargestBSTOptimalHelper(root->left);
    Info rightInfo=LargestBSTOptimalHelper(root->right);
    Info curr;
    curr.size=1+leftInfo.size+rightInfo.size;
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
        curr.min=min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max=max(rightInfo.max,max(leftInfo.max,root->data));
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}
void LargestBSTOptimal(Node* root){
    Info result=LargestBSTOptimalHelper(root);
    cout<<"Size of Largest BST is: "<<result.ans<<endl;
} // TC=O(n) SC=O(h)
int main(){
    Node* root=new Node(1);
    root->left=new Node(3);
    root->right=new Node(2);
    root->left->right=new Node(4);
    root->left->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left=new Node(7);
    int largestBSTSize=LargestBSTBruteForce(root);
    cout<<"Size of Largest BST is: "<<largestBSTSize<<endl;
    LargestBSTOptimal(root);
    RecoverBSTBruteForce(root);
    RecoverBSTOptimal(root);
    return 0;
}