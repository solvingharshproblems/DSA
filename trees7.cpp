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
//Problem 2: Zig-Zag traversal
//For Optimal Approach, we can use level order traversal where at the iteration of 2 levels, we will reverse the nodes
void ZigZag(Node* root){
    vector<vector<int>> result;
    if(root==nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int> currentLevel;
        for(int i=0;i<size;i++){
            Node* currentNode=q.front();
            q.pop();
            if(currentNode->left!=nullptr){
                q.push(currentNode->left);
            }
            if(currentNode->right!=nullptr){
                q.push(currentNode->right);
            }
            currentLevel.push_back(currentNode->data);
        }
        result.push_back(currentLevel);
    }
    for(int i=0;i<result.size();i++){
        if(i%2!=0){
            reverse(result[i].begin(),result[i].end());
        }
    }
    for(const auto& level:result){
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
} // TC=O(n) SC=O(n) where n is the number of nodes
int main(){
    /*
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
    */
    Node* root=new Node(1);
    root->left=new Node(2); 
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);
    ZigZag(root);
    return 0;
}