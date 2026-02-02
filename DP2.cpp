#include <iostream>
using namespace std;
//Problem 1: Frog Jump
//A frog is at the bottom of a staircase with n steps. The frog can jump either 1 step or 2 steps at a time. 
//Write a function to calculate the number of distinct ways the frog can reach the top of the staircase.
//For Brute Force Approach, we can use recursion to explore all possible ways the frog can jump to the top.
int frogJump(int n,vector<int>& heights){
    if(n==0){
        return 0;
    }
    int left=frogJump(n-1, heights)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1){
        right=frogJump(n-2, heights)+abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the computed number of ways to reach each step.
int frogJumpDP(int n,vector<int>& heights){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int left=dp[i-1]+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(left,right);
    }
    return dp[n];
} // TC=O(N) SC=O(N)
//For Optimal Approach, we will use space optimization to reduce the space complexity.
int frogJumpSpaceOpt(int n,vector<int>& heights){
    int prev1=0; // dp[i-1]
    int prev2=0; // dp[i-2]
    for(int i=1;i<=n;i++){
        int left=prev1+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1){
            right=prev2+abs(heights[i]-heights[i-2]);
        }
        int curr=min(left,right);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
} // TC=O(N) SC=O(1)
//Problem 2: Frog Jump with K jumps
//A frog is at the bottom of a staircase with n steps. The frog can jump anywhere from 1 to k steps at a time. 
//Write a function to calculate the minimum cost for the frog to reach the top of the staircase.
//For Optimal Approach, we will use memoization to store the computed minimum cost to reach each step.
int frogJumpKSteps(int n,vector<int>& heights,int k){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]=min(dp[i],dp[i-j]+abs(heights[i]-heights[i-j]));
            }
        }
    }   
    return dp[n];
} // TC=O(N*K) SC=O(N)
int main(){
    int n;
    cin>>n;
    vector<int> heights(n+1);
    for(int i=1;i<=n;i++){
        cin>>heights[i];
    }
    cout<<"Number of ways the frog can reach the top: "<<frogJump(n,heights)<<endl;
    cout<<"Number of ways the frog can reach the top using DP: "<<frogJumpDP(n,heights)<<endl;
    cout<<"Number of ways the frog can reach the top using Space Optimization: "<<frogJumpSpaceOpt(n,heights)<<endl;
    int k;
    cout<<"Enter the maximum steps the frog can jump: ";
    cin>>k;
    cout<<"Minimum cost for the frog to reach the top with "<<k<<" jumps: "<<frogJumpKSteps(n,heights,k)<<endl;
    return 0;
}