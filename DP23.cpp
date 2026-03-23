#include <iostream>
using namespace std;
//Problem 1: Minimum Cost of Cutting a Stick
//Given a stick of length n units. The stick can be cut into smaller sticks at given positions. 
//The cost of cutting the stick at a position is equal to the length of the stick being cut. We need to find the minimum cost of cutting the stick into smaller sticks at the given positions.
//For Brute Force Approach, we can use recursion to find all possible combinations of cutting the stick and return the minimum cost needed.
int DFS1(int n,vector<int>& cuts,int i,int j){
    if(i>j){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i;k<=j;k++){
        int temp=DFS1(n,cuts,i,k-1)+DFS1(n,cuts,k+1,j)+cuts[j+1]-cuts[i-1];
        res=min(res,temp);
    }
    return res;
}
int minCostBruteForce(int n,vector<int>& cuts){
    int m=cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    return DFS1(n,cuts,1,m);
} //TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(int n,vector<int>& cuts,int i,int j,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MAX;
    for(int k=i;k<=j;k++){
        int temp=DFS2(n,cuts,i,k-1,dp)+DFS2(n,cuts,k+1,j,dp)+cuts[j+1]-cuts[i-1];
        res=min(res,temp);
    }
    return dp[i][j]=res;
}
int minCostBetter(int n,vector<int>& cuts){
    int m=cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(m+2,vector<int>(m+2,-1));
    return DFS2(n,cuts,1,m,dp);
} //TC=O(N^3) SC=O(N^2)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int minCostOptimal(int n,vector<int>& cuts){
    int m=cuts.size();
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    vector<vector<int>> dp(m+2,vector<int>(m+2,0));
    for(int i=m;i>=1;i--){
        for(int j=i;j<=m;j++){
            int res=INT_MAX;
            for(int k=i;k<=j;k++){
                int temp=dp[i][k-1]+dp[k+1][j]+cuts[j+1]-cuts[i-1];
                res=min(res,temp);
            }
            dp[i][j]=res;
        }
    }
    return dp[1][m];
} //TC=O(N^3) SC=O(N^2)
//Problem 2: Burst Balloons
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by an array nums. 
//You are asked to burst all the balloons. If you burst the ith balloon, you will get nums[i-1] * nums[i] * nums[i+1] coins. 
//If i-1 or i+1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it. Return the maximum coins you can collect by bursting the balloons wisely.
//For Brute Force Approach, we can use recursion to find all possible combinations of bursting the balloons and return the maximum coins collected.
int DFS3(vector<int>& nums,int i,int j){
    if(i>j){
        return 0;
    }
    int res=INT_MIN;
    for(int k=i;k<=j;k++){
        int temp=DFS3(nums,i,k-1)+DFS3(nums,k+1,j)+nums[i-1]*nums[k]*nums[j+1];
        res=max(res,temp);
    }
    return res;
}
int maxCoinsBruteForce(vector<int>& nums){
    int n=nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    return DFS3(nums,1,n);
} //TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS4(vector<int>& nums,int i,int j,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MIN;
    for(int k=i;k<=j;k++){
        int temp=DFS4(nums,i,k-1,dp)+DFS4(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j+1];
        res=max(res,temp);
    }
    return dp[i][j]=res;
}
int maxCoinsBetter(vector<int>& nums){
    int n=nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
    return DFS4(nums,1,n,dp);
} //TC=O(N^3) SC=O(N^2)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int maxCoinsOptimal(vector<int>& nums){
    int n=nums.size();
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;i--){      
        for(int j=i;j<=n;j++){
            int res=INT_MIN;
            for(int k=i;k<=j;k++){
                int temp=dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1];
                res=max(res,temp);
            }
            dp[i][j]=res;
        }
    }
    return dp[1][n];
} //TC=O(N^3) SC=O(N^2)
int main(){
    int n=7;
    vector<int> cuts={1,3,4,5};
    cout<<minCostBruteForce(n,cuts)<<endl;
    cout<<minCostBetter(n,cuts)<<endl;
    cout<<minCostOptimal(n,cuts)<<endl;
    vector<int> nums={3,1,5,8};
    cout<<maxCoinsBruteForce(nums)<<endl;
    cout<<maxCoinsBetter(nums)<<endl;
    cout<<maxCoinsOptimal(nums)<<endl;
    return 0;
}