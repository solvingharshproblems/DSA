#include <iostream>
using namespace std;
//Problem 1: Triangle (Fixed Start and Variable End)
//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//For Brute Force Approach, we can use recursion to explore all possible paths from the top to the bottom of the triangle.
int DFS1(int i,int j,vector<vector<int>>& triangle){
    if(i==triangle.size()-1){
        return triangle[i][j];
    }
    int down=triangle[i][j]+DFS1(i+1,j,triangle);
    int diagonal=triangle[i][j]+DFS1(i+1,j+1,triangle);
    return min(down,diagonal);
}
int minimumTotalBruteForce(vector<vector<int>>& triangle) {
    return DFS1(0,0,triangle);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS2(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    if(i==triangle.size()-1){
        return triangle[i][j];
    }
    if(dp[i][j]!=-1){   
        return dp[i][j];
    }
    int down=triangle[i][j]+DFS2(i+1,j,triangle,dp);
    int diagonal=triangle[i][j]+DFS2(i+1,j+1,triangle,dp);
    dp[i][j]=min(down,diagonal);
    return dp[i][j];
}
int minimumTotalBetter(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
    return DFS2(0,0,triangle,dp);
} // TC=O(N^2) SC=O(N^2)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int minimumTotalOptimal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            if(i==n-1){
                dp[j]=triangle[i][j];
            }
            else{
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);    
            }
        }
    }
    return dp[0];
} // TC=O(N^2) SC=O(N)
//Problem 2: Minimum/Maximum Falling Path Sum
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//For Brute Force Approach, we can use recursion to explore all possible paths from the top to the bottom of the matrix.
int DFS3(int i,int j,vector<vector<int>>& matrix){
    if(i==matrix.size()-1){
        return matrix[i][j];
    }
    int down=matrix[i][j]+DFS3(i+1,j,matrix);
    int diagonal=matrix[i][j]+DFS3(i+1,j+1,matrix);
    int diagonal2=matrix[i][j]+DFS3(i+1,j-1,matrix);
    return min(down,min(diagonal,diagonal2));
}
int minFallingPathSumBruteForce(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int minSum=1e9;
    for(int j=0;j<n;j++){
        minSum=min(minSum,DFS3(0,j,matrix));
    }
    return minSum;
} // TC=O(3^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS4(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    if(i==matrix.size()-1){
        return matrix[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=matrix[i][j]+DFS4(i+1,j,matrix,dp);
    int diagonal=matrix[i][j]+DFS4(i+1,j+1,matrix,dp);
    int diagonal2=matrix[i][j]+DFS4(i+1,j-1,matrix,dp);
    dp[i][j]=min(down,min(diagonal,diagonal2));
    return dp[i][j];
}
int minFallingPathSumBetter(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int minSum=1e9;
    for(int j=0;j<n;j++){
        minSum=min(minSum,DFS4(0,j,matrix,dp));
    }
    return minSum;
} // TC=O(N^2) SC=O(N^2)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int minFallingPathSumOptimal(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i==n-1){
                dp[i][j]=matrix[i][j];
            }
            else{
                int down=matrix[i][j]+dp[i+1][j];
                int diagonal=matrix[i][j]+((j+1<n)?dp[i+1][j+1]:1e9);
                int diagonal2=matrix[i][j]+((j-1>=0)?dp[i+1][j-1]:1e9);
                dp[i][j]=min(down,min(diagonal,diagonal2));
            }
        }
    }
    int minSum=1e9;
    for(int j=0;j<n;j++){
        minSum=min(minSum,dp[0][j]);
    }
    return minSum;
} // TC=O(N^2) SC=O(N^2)
int main(){
    int n=4;
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotalBruteForce(triangle)<<endl;
    cout<<minimumTotalBetter(triangle)<<endl;
    cout<<minimumTotalOptimal(triangle)<<endl;
    int x=2,y=2;
    vector<vector<int>> grid(n,vector<int>(x,0));
    grid={{-19,57},{-40,-5}};
    cout<<"Minimum Falling Path Sum: "<<minFallingPathSumBruteForce(grid)<<endl;
    cout<<"Minimum Falling Path Sum: "<<minFallingPathSumBetter(grid)<<endl;
    cout<<"Minimum Falling Path Sum: "<<minFallingPathSumOptimal(grid)<<endl;
    return 0;
}