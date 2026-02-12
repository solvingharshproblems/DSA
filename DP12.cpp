#include <iostream>
using namespace std;
//Problem 1: Unbounded Knapsack
//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. You can use unlimited number of instances of any item.
//For Brute Force Approach, we can use recursion to explore all possible combinations of items. 
int DFS(vector<int>& weights,vector<int>& values,int W,int n,int i){
    if(i>=n || W<=0){
        return 0;
    }
    int exclude=DFS(weights,values,W,n,i+1);
    int include=0;
    if(weights[i]<=W){
        include=values[i]+DFS(weights,values,W-weights[i],n,i); 
    }
    return max(include,exclude);
} 
int knapsackBruteForce(vector<int>& weights,vector<int>& values,int W){
    int n=weights.size();
    return DFS(weights,values,W,n,0);
} // TC=O(2^(N+W)) SC=O(W)
//For Better Approach, we can use memoization to store the results of subproblems to avoid redundant calculations.
int DFS2(vector<int>& weights,vector<int>& values,int W,int n,int i,vector<vector<int>>& dp){
    if(i>=n || W<=0){
        return 0;
    }
    if(dp[i][W]!=-1){
        return dp[i][W];
    }
    int exclude=DFS2(weights,values,W,n,i+1,dp);
    int include=0;
    if(weights[i]<=W){
        include=values[i]+DFS2(weights,values,W-weights[i],n,i,dp);
    }
    dp[i][W]=max(include,exclude);
    return dp[i][W];
}
int knapsackBetter(vector<int>& weights,vector<int>& values,int W){
    int n=weights.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return DFS2(weights,values,W,n,0,dp);
} // TC=O(N*W) SC=O(N*W)+O(W)
//For Optimal Approach, we will use tabulation to build a DP table iteratively.
int knapsackOptimal(vector<int>& weights,vector<int>& values,int W){
    int n=weights.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            int include=0;
            int exclude=dp[i-1][j];
            if(weights[i-1]<=j){
                include=values[i-1]+dp[i][j-weights[i-1]];
            }
            dp[i][j]=max(include,exclude);
        }
    }
    return dp[n][W];
} // TC=O(N*W) SC=O(N*W)
//For Space Optimized Approach, we will use a single array to store the maximum values for each weight capacity.
int knapsackSpaceOptimized(vector<int>& weights,vector<int>& values,int W){
    int n=weights.size();
    vector<int> dp(W+1,0);
    for(int i=0;i<n;i++){
        for(int j=weights[i];j<=W;j++){
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[W];
} // TC=O(N*W) SC=O(W)
int main(){
    int n=3,w=10;
    vector<int> weights={2,4,6};
    vector<int> values={5,11,15};
    cout<<knapsackBruteForce(weights,values,w)<<endl;
    cout<<knapsackBetter(weights,values,w)<<endl;
    cout<<knapsackOptimal(weights,values,w)<<endl;
    cout<<knapsackSpaceOptimized(weights,values,w)<<endl;
    return 0;
}