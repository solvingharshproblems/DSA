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
//Problem 2: Printing LIS
//Here we will use the same approach as the optimal approach of the previous problem but we will also store the indices of the elements in the longest increasing subsequence and print them at the end.
void printLIS(vector<int>& nums){
    vector<int> dp(nums.size(),1),hash(nums.size());
    int maxLen=1,lastIndex=0;
    for(int i=0;i<nums.size();i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxLen){
            maxLen=dp[i];
            lastIndex=i;
        }
    }
    vector<int> lis;
    lis.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        lis.push_back(nums[lastIndex]);
    }
    reverse(lis.begin(),lis.end());
    for(int i=0;i<lis.size();i++){
        cout<<lis[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n=6;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<lengthOfLISBruteForce(nums)<<endl;
    cout<<lengthOfLISBetter(nums)<<endl;
    cout<<lengthOfLISOptimal(nums)<<endl;
    printLIS(nums);
    return 0;
}