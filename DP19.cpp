#include <iostream>
using namespace std;
//Problem 1: Longest Increasing Subsequence
//Given an integer array nums, return the length of the longest strictly increasing subsequence.
//For Brute Force Approach, we can use recursion to find all possible combinations of increasing subsequences and return the length of the longest one.
int DFS1(vector<int>& nums,int i,int prev){
    if(i==nums.size()){
        return 0;
    }
    int take=0,notTake=0;
    if(nums[i]>prev){
        take=1+DFS1(nums,i+1,nums[i]);
    }
    notTake=DFS1(nums,i+1,prev);
    return max(take,notTake);
}
int lengthOfLISBruteForce(vector<int>& nums){
    return DFS1(nums,0,INT_MIN);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(vector<int>& nums,int i,int prev,vector<vector<int>>& dp){
    if(i==nums.size()){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    int take=0,notTake=0;
    if(nums[i]>prev){
        take=1+DFS2(nums,i+1,nums[i],dp);
    }
    notTake=DFS2(nums,i+1,prev,dp);
    dp[i][prev+1]=max(take,notTake);
    return dp[i][prev+1];
}
int lengthOfLISBetter(vector<int>& nums){
    vector<vector<int>> dp(nums.size(),vector<int>(2001,-1));
    return DFS2(nums,0,-1,dp);
} // TC=O(N*2001) SC=O(N*2001)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int lengthOfLISOptimal(vector<int>& nums){
    vector<vector<int>> dp(nums.size()+1,vector<int>(2001,0));
    for(int i=nums.size()-1;i>=0;i--){  
        for(int prev=-1000;prev<=1000;prev++){
            int take=0,notTake=0;
            if(nums[i]>prev){
                take=1+dp[i+1][nums[i]+1000];
            }
            notTake=dp[i+1][prev+1000];
            dp[i][prev+1000]=max(take,notTake);
        }
    }
    return dp[0][0];
} // TC=O(N*2001) SC=O(N*2001)
int main(){
    int n=6;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<lengthOfLISBruteForce(nums)<<endl;
    cout<<lengthOfLISBetter(nums)<<endl;
    cout<<lengthOfLISOptimal(nums)<<endl;
    return 0;
}