#include <iostream>
using namespace std;
//Problem 1: Ninja and His Friends
//We are given a 2D array of size N*M, where each cell of matrix has some chocolates on it.We have 2 friends, alice is standing on cell(0,0) and bob is standing on cell(0,M-1).
// Both of them can move only downwards, diagonally left downwards and diagonally right downwards. 
//We need to find the maximum number of chocolates they can collect together if they start moving from their respective cells at the same time and reach the last row of the matrix.
//For Brute Force Approach, we can use recursion to explore all possible paths for both friends separately.
int DFS(int i1,int j1,int i2,int j2,vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    if(j1<0 || j1>=m|| j2<0 || j2>=m){
        return -1e8;
    }
    if(i1==n-1 && i2==n-1){
        if(j1==j2){
            return grid[i1][j1];
        }
        else{
            return grid[i1][j1]+grid[i2][j2];
        }
    }
    int maxChoco=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2){
                value=grid[i1][j1];
            }
            else{
                value=grid[i1][j1]+grid[i2][j2];
            }
            value+=DFS(i1+1,j1+dj1,i2+1,j2+dj2,grid);
            maxChoco=max(maxChoco,value);
        }
    }
    return maxChoco;
}
int maximumChocolatesBruteForce(vector<vector<int>>& grid){
    return DFS(0,0,0,grid[0].size()-1,grid);
} // TC=O(9^(N)) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS2(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>& dp){
    int n=grid.size(),m =grid[0].size();
    if(j1<0 || j1>=m|| j2<0 || j2>=m){
        return -1e8;
    }
    if(i1==n-1 && i2==n-1){
        if(j1==j2){
            return grid[i1][j1];
        }
        else{
            return grid[i1][j1]+grid[i2][j2];
        }
    }
    if(dp[i1][j1][i2][j2]!=-1){
        return dp[i1][j1][i2][j2];
    }
    int maxChoco=-1e8;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int value=0;
            if(j1==j2){
                value=grid[i1][j1];
            }
            else{
                value=grid[i1][j1]+grid[i2][j2];    
            }
            value+=DFS2(i1+1,j1+dj1,i2+1,j2+dj2,grid,dp);
            maxChoco=max(maxChoco,value);
        }
    }
    dp[i1][j1][i2][j2]=maxChoco;
    return dp[i1][j1][i2][j2];
}
int maximumChocolatesBetter(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
    return DFS2(0,0,0,m-1,grid,dp);
} // TC=O(N*M*M*9) SC=O(N*M*M)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int maximumChocolatesOptimal(vector<vector<int>>& grid){
    int n=grid.size(),m=grid[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                dp[n-1][j1][j2]=grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxChoco=-1e8;
                for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){
                        int value=0;
                        if(j1==j2){
                            value=grid[i][j1];
                        }
                        else{
                            value=grid[i][j1]+grid[i][j2];    
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                            value+=dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value+=-1e8;
                        }
                        maxChoco=max(maxChoco,value);
                    }
                }
                dp[i][j1][j2]=maxChoco;
            }
        }
    }
    return dp[0][0][m-1];
} // TC=O(N*M*M*9) SC=O(N*M*M)
int main(){
    int n=3,m=4;
    vector<vector<int>> grid={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<maximumChocolatesBruteForce(grid)<<endl;
    cout<<maximumChocolatesBetter(grid)<<endl;
    cout<<maximumChocolatesOptimal(grid)<<endl;
    return 0;
}