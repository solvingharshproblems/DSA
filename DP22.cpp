#include <iostream>
using namespace std;
//Partition DP
//If there can be formed multiple patterns in a problem, then we can use partition DP to solve it.
//Steps:
//1. Start with entire block/array f(i,j) where i and j are the starting and ending index of the block/array.
//2. Try all possible partitions of the block/array by running a loop from i to j and partitioning the block/array at k where i<=k<j.
//3. Return the best possible 2 partitions of the block/array by using the results of the smaller blocks/arrays which we have already calculated and stored in a dp table.
//Problem 1: Matrix Chain Multiplication
//Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.
//For Brute Force Approach, we can use recursion to find all possible combinations of multiplying the matrices and return the minimum number of multiplications needed.
int DFS1(int i,int j,vector<int>& arr){
    if(i==j){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=DFS1(i,k,arr)+DFS1(k+1,j,arr)+arr[i-1]*arr[k]*arr[j];
        res=min(res,temp);
    }
    return res;
}
int MatrixChainMultiplicationBruteForce(vector<int>& arr){
    int n=arr.size();
    return DFS1(1,n-1,arr);
} //TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=DFS2(i,k,arr,dp)+DFS2(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j];
        res=min(res,temp);
    }
    dp[i][j]=res;
    return dp[i][j];
}
int MatrixChainMultiplicationBetter(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return DFS2(1,n-1,arr,dp);
} //TC=O(N^3) SC=O(N^2)+O(N)
//For Optimal Approach, we will use tabulation to fill a dp table iteratively based on the recursive relation defined in the DFS function.
int MatrixChainMultiplicationOptimal(vector<int>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int res=INT_MAX;
            for(int k=i;k<j;k++){
                int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                res=min(res,temp);
            }
            dp[i][j]=res;
        }
    }
    return dp[1][n-1];
} //TC=O(N^3) SC=O(N^2)
int main(void){
    int n=5;
    vector<int> arr={1,2,3,4,3};
    cout<<MatrixChainMultiplicationBruteForce(arr)<<endl;
    cout<<MatrixChainMultiplicationBetter(arr)<<endl;
    cout<<MatrixChainMultiplicationOptimal(arr)<<endl;
    return 0;
}