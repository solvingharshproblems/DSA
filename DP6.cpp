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
int main(){
    int n=4;
    vector<vector<int>> triangle={{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<minimumTotalBruteForce(triangle)<<endl;
    cout<<minimumTotalBetter(triangle)<<endl;
    cout<<minimumTotalOptimal(triangle)<<endl;
    return 0;
}