#include <iostream>
#include <set>
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
//Problem 1: Inorder Successor in BST
//For Brute Force Approach, we can store the inorder traversal in an array and return the next element of the given element
void Inorder(Node* root,vector<int>& result){
    if(root==nullptr){
        return;
    }
    Inorder(root->left,result);
    result.push_back(root->data);
    Inorder(root->right,result);
}
void InorderSuccessorBruteForce(Node* root,int key){
    vector<int> result;
    Inorder(root,result);
    for(int i=0;i<result.size();i++){
        if(result[i]==key && i+1<result.size()){
            cout<<"Successor of "<<key<<" is: "<<result[i+1];
            return;
        }
    }
} // TC=O(n) SC=O(n) for storing answers
//For Optimal Approach, we will use the property of BST and only traverse further on the right side till we do not encounter with the key
Node* InorderSuccessorOptimal(Node* root,int key){
    Node* successor=nullptr;
    while(root!=nullptr){
        if(root->data>key){
            successor=root;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return successor;
} // TC=O(h) SC=O(1)
//Problem 2: BST Iterator
//Youre given with a BST with root node, you need to construct the next which returns the next element in inorder everytime you call it 
//AND a hasNext function which returns if there exists a next element in the inorder traversal
//Note: Youre not allowed to store the inorder traversal
//For Optimal Approach, we will use a stack to store the leftmost nodes of the tree
class BSTIterator{
    stack<Node*> st;
    bool reverse=true;
public:
    BSTIterator(Node* root){
        while(root!=nullptr){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(Node* root,bool isReverse):reverse(isReverse){
        pushAll(root); 
    }
    bool hasNext(){
        return !st.empty(); 
    }
    int next(){
        Node* tmpNode=st.top(); 
        st.pop();
        if(!reverse){
            pushAll(tmpNode->right); 
        } 
        else{
            pushAll(tmpNode->left); 
        }
        return tmpNode->data; 
    }
    void pushAll(Node* node){
        while (node != nullptr){
            st.push(node); 
            if(reverse){
                node=node->right; 
            } 
            else{
                node=node->left;
            }
        }
    }
    bool findTarget(Node* root,int k){
        if(!root){
            return false; 
        }
        BSTIterator l(root,false); 
        BSTIterator r(root,true);
        int i=l.next(); 
        int j=r.next(); 
        while(i<j){
            if(i+j==k){
                return true; 
            } 
            else if(i+j<k){
                i=l.next(); 
            } 
            else{
                j=r.next();
            }
        }
        return false; 
    }
}; // TC=O(1) amortized for next() and O(1) for hasNext() SC=O(h) where h is the height of the tree
//Problem 3: 2Sum in BST
//For Brute Force Approach, we can store the elements in a vector and use 2 pointer approach to find the pair with given sum
void Inorder2Sum(Node* root,vector<int>& v){
    if(root==nullptr){
        return;
    }
    Inorder2Sum(root->left,v);
    v.push_back(root->data);
    Inorder2Sum(root->right,v);
}
bool TwoSumBruteForce(Node* root,int k){
    if(root==nullptr){
        return false;
    }
    vector<int> v;
    Inorder2Sum(root,v);
    int left=0;
    int right=v.size()-1;;
    while(left<right){
        int sum=v[left]+v[right];
        if(sum==k){
            return true;
        }
        else if(sum<k){
            left++;
        }
        else{
            right--;
        }
    }
    return false;
} // TC=O(n) SC=O(n)
//For Optimal Approach, we will use the next and before functions to simulate the 2 pointer approach without storing the elements
bool TwoSumOptimal(Node* root,int k){
    if(root==nullptr){
        return false;
    }
    BSTIterator l(root,false); 
    BSTIterator r(root,true); 
    int i=l.next();
    int j=r.next();
    while(i<j){
        int sum=i+j;
        if(sum==k){
            return true;
        }
        else if(sum<k){
            i=l.next();
        }
        else{
            j=r.next();
        }
    }
    return false;
} // TC=O(n) SC=O(h) where h is the height of the tree 
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    /*
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    InorderSuccessorBruteForce(root,key);
    Node* successor=InorderSuccessorOptimal(root,key);
    if(successor!=nullptr){
        cout<<"\nSuccessor of "<<key<<" is: "<<successor->data;;
    }
    else{
        cout<<"\nNo Successor found for "<<key;;
    }
    BSTIterator iterator(root);
    while(iterator.hasNext()){
        cout<<iterator.next()<<" ";
    }
    cout<<endl;
    */
    int sum;
    cout<<"Enter the sum to find in BST: ";
    cin>>sum;
    if(TwoSumBruteForce(root,sum)){
        cout<<"Pair with given sum "<<sum<<" exists in BST.";
    }
    else{
        cout<<"No such pair with given sum "<<sum<<" exists in BST.";
    }
    cout<<endl;
    if(TwoSumOptimal(root,sum)){
        cout<<"Pair with given sum "<<sum<<" exists in BST.";
    }
    else{
        cout<<"No such pair with given sum "<<sum<<" exists in BST.";
    }
    cout<<endl;
    return 0;
}