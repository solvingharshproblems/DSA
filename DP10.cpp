#include <iostream>
using namespace std;
//Problem 1: 0/1 Knapsack Problem 
//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
//In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
//Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that the sum of the weights of this subset is smaller than or equal to W. 
//You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
//For Brute Force Approach, we can use recursion to consider all the possible subsets of items and calculate their total weights and values.
int DFS(vector<int>& weights,vector<int>& values,int w,int n,int index){
    if(index==n || w==0){
        return 0;
    }
    if(weights[index]>w){
        return DFS(weights,values,w,n,index+1);
    }
    else{
        int include=values[index]+DFS(weights,values,w-weights[index],n,index+1);
        int exclude=DFS(weights,values,w,n,index+1);
        return max(include,exclude);
    }
}
int knapsackBruteForce(int w,vector<int>& weights,vector<int>& values){
    int n=weights.size();
    return DFS(weights,values,w,n,0);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS2(vector<int>& weights,vector<int>& values,int w,int n,int index,vector<vector<int>>& dp){
    if(index==n || w==0){
        return 0;
    }
    if(weights[index]>w){
        return DFS(weights,values,w,n,index+1);
    }
    else{
        int include=values[index]+DFS2(weights,values,w-weights[index],n,index+1,dp);
        int exclude=DFS2(weights,values,w,n,index+1,dp);
        dp[index][w]=max(include,exclude);
        return dp[index][w];
    }
} 
int knapsackBetter(int W,vector<int>& weights,vector<int>& values){
    int n=weights.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return DFS2(weights,values,W,n,0,dp);
} // TC=O(N*W) SC=O(N*W)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int knapsackOptimal(int W,vector<int>& weights,vector<int>& values){
    int n=weights.size();
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int w=weights[0];w<=W;w++){
        dp[0][w]=values[0]; 
    }
    if(weights[0]<=W){
        dp[0][weights[0]]=values[0];
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=W;w++){
            int notTaken=dp[index-1][w];
            int taken=-1e9;
            if(weights[index]<=w){
                taken=values[index]+dp[index-1][w-weights[index]];
            }
            dp[index][w]=max(notTaken,taken);
        }
    }
    return dp[n-1][W];
} // TC=O(N*W) SC=O(N*W)
//For Space Optimized Approach, we can optimize the space used in the tabulation method.
int knapsackSpaceOptimized(int W,vector<int>& weights,vector<int>& values){
    int n=weights.size();
    vector<int> prev(W+1,0),curr(W+1,0);
    for(int w=weights[0];w<=W;w++){
        prev[w]=values[0];   
    }
    for(int index=1;index<n;index++){
        for(int w=0;w<=W;w++){
            int notTaken=prev[w];
            int taken=-1e9;
            if(weights[index]<=w){
                taken=values[index]+prev[w-weights[index]];
            }
            curr[w]=max(notTaken,taken);
        }
        prev=curr;
    }
    return prev[W];
} // TC=O(N*W) SC=O(W)
int main(){
    int w=7;
    vector<int> weights={1,3,4,5};
    vector<int> values={1,4,5,7};
    cout<<"Maximum value in Knapsack = "<<knapsackBruteForce(w,weights,values)<<endl;
    cout<<"Maximum value in Knapsack = "<<knapsackBetter(w,weights,values)<<endl;
    cout<<"Maximum value in Knapsack = "<<knapsackOptimal(w,weights,values)<<endl;
    cout<<"Maximum value in Knapsack = "<<knapsackSpaceOptimized(w,weights,values)<<endl;   
    return 0;
}