#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Celebrity Problem
//We need to find the celebrity in a party of n people. 
//A celebrity is defined as someone who is known by everyone else but does not know anyone else. 
//That means return the index of n*m matrix where matrix[i][j] = 1 means person i knows person j and matrix[i][j] = 0 means person i does not know person j.
//If there is no celebrity, return -1.
//For Brute Force Approach, we can declare 2 arrays KnowMe and IKnow to keep track of how many people know me and how many people I know.
void FindCelebrityBruteForce(int n,int m,int matrix[][100]){
    int KnowMe[n];
    int IKnow[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 1){
                IKnow[i]++;
                KnowMe[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(KnowMe[i]==n-1 && IKnow[i]==0){
            cout<<"Celebrity is: "<<i<<endl;
            return;
        }
    }
    cout<<"No Celebrity Found"<<endl;
} //TC=O(n^2) SC=O(2n)
//For Optimal Approach, we will declare a top and down variable to keep track of the top and down of the stack.
//We will compare the top and down of the stack and if top knows down, then top cannot be a celebrity, so we will pop the top and push down to the stack.
//If top does not know down, then down cannot be a celebrity, so we will pop the down and push top to the stack.
//We will continue this process until there is only one person left in the stack.
//We will then check if this person is a celebrity or not by checking if everyone knows this person and this person does not know anyone else.
void FindCelebrityOptimal(int n,int m,int matrix[][100]){
    int top=0;
    int down=n-1;
    while(top<down){
        if(matrix[top][down]==1){
            top++;
        }
        else{
            down--;
        }
    }
    int celebrity=top;
    if(top>down){
        cout<<"No Celebrity Found"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(i==celebrity){
            continue;
        }
        if(matrix[i][celebrity]==0 || matrix[celebrity][i]==1){
            cout<<"No Celebrity Found"<<endl;
            return;
        }
    }
    cout<<"Celebrity is: "<<celebrity<<endl;
} //TC=O(2n) SC=O(1)
int main(){
    int n,m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
    int matrix[100][100];
    cout<<"Enter the matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    FindCelebrityBruteForce(n,m,matrix);
    FindCelebrityOptimal(n,m,matrix);
    return 0;
}