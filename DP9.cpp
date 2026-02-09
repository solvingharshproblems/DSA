#include <iostream>
using namespace std;
//Problem 1: Count Subsets with a Given Sum K
//For Brute Force Approach, we can use recursion to explore all possible subsets.
int DFS(int i,vector<int>& arr,int target){
    if(target==0){
        return 1;
    }
    if(i==0){
        if(arr[0]==target){
            return 1;
        }
        else{
            return 0;
        }
    }
    int notTake=DFS(i-1,arr,target);
    int take=0;
    if(arr[i]<=target){
        take=DFS(i-1,arr,target-arr[i]);   
    }
    return take+notTake;
}
int countSubsets(vector<int>& arr,int target){
    int n=arr.size();
    return DFS(n-1,arr,target);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS2(int i,vector<int>& arr,int target,vector<vector<int>>& dp){
    if(target==0){
        return 1;
    }
    if(i==0){
        if(arr[0]==target){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int notTake=DFS2(i-1,arr,target,dp);
    int take=0;
    if(arr[i]<=target){
        take=DFS2(i-1,arr,target-arr[i],dp);
    }
    dp[i][target]=take+notTake;
    return dp[i][target];
}
int countSubsetsBetter(vector<int>& arr,int target){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return DFS2(n-1,arr,target,dp);
} // TC=O(N*K) SC=O(N*K)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int countSubsetsOptimal(vector<int>& arr,int target){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=target){
        dp[0][arr[0]]+=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int notTake=dp[i-1][j];
            int take=0;
            if(arr[i]<=j){
                take=dp[i-1][j-arr[i]];
            }
            dp[i][j]=take+notTake;
        }
    }
    return dp[n-1][target];
} // TC=O(N*K) SC=O(N*K)
//For Space Optimized Approach, we can optimize the space used in the tabulation method.
int countSubsetsSpaceOptimized(vector<int>& arr,int target){
    int n=arr.size();
    vector<int> prev(target+1,0),curr(target+1,0);
    prev[0]=1;
    if(arr[0]<=target){
        prev[arr[0]]+=1;
    }
    for(int i=1;i<n;i++){
        curr[0]=1;
        for(int j=1;j<=target;j++){
            int notTake=prev[j];
            int take=0;
            if(arr[i]<=j){
                take=prev[j-arr[i]];
            }
            curr[j]=take+notTake;
        }
        prev=curr;
    }
    return prev[target];
} // TC=O(N*K) SC=O(K)
int main(void){
    int n=4;
    vector<int> arr={1,2,3,3};
    int target=6;
    cout<<countSubsets(arr,target)<<endl;
    cout<<countSubsetsBetter(arr,target)<<endl;
    cout<<countSubsetsOptimal(arr,target)<<endl;
    cout<<countSubsetsSpaceOptimized(arr,target)<<endl;
}