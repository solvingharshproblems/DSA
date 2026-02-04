#include <iostream>
using namespace std;
//Problem 1: Unique Paths II
//The only modification to the original Unique Paths problem is that some cells are marked as obstacles (1) and cannot be traversed.
//For Brute Force Approach, we can use recursion to explore all possible paths from the start to the finish.
int DFS(int m,int n,int i,int j,vector<vector<int>>& obstacleGrid){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m || obstacleGrid[i][j]==1){
        return 0;
    }
    return DFS(m,n,i+1,j,obstacleGrid)+DFS(m,n,i,j+1,obstacleGrid);
} 
int uniquePathsBruteForce(int m,int n,vector<vector<int>>& obstacleGrid){
    return DFS(m,n,0,0,obstacleGrid);
} // TC=O(2^(M+N)) SC=O(M+N)
//For Better Approach, we will use memoization to store the results of subproblems.
int DFS2(int m,int n,int i,int j,vector<vector<int>>& dp){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=DFS2(m,n,i+1,j,dp)+DFS2(m,n,i,j+1,dp);
    return dp[i][j];
}
int uniquePathsBetter(int m,int n,vector<vector<int>>& obstacleGrid){
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return DFS2(m,n,0,0,dp);
} // TC=O(M*N) SC=O(M*N)+O(M+N)
//For Optimal Approach, we will use tabulation to iteratively build the solution.
int uniquePathsOptimal(int m,int n,vector<vector<int>>& obstacleGrid){
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
            }
            else if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{   
                int up=0;
                int left=0;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
} // TC=O(M*N) SC=O(M*N)
int main(){
    int m=3,n=7;
    vector<vector<int>> obstacleGrid(n, vector<int>(m, 0)); // Assuming no obstacles for now
    cout<<"Unique Paths: "<<uniquePathsBruteForce(m,n,obstacleGrid)<<endl; 
    cout<<"Unique Paths: "<<uniquePathsOptimal(m,n,obstacleGrid)<<endl; 
    cout<<"Unique Paths: "<<uniquePathsOptimal(m,n,obstacleGrid)<<endl;    
    return 0;
}