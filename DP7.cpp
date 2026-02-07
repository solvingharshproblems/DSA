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
//Problem 2: Subset/Subsequence Sum Equal to Target
//For Brute Force Approach, we can use recursion to explore all possible subsets.
int DFS3(int index,int target,vector<int>& arr){
    if(index==0){
        if(target==0 && arr[0]==0){
            return 2;
        }
        if(target==0 || target==arr[0]){
            return 1;
        }
        return 0;
    }
    int notTake=DFS3(index-1,target,arr);
    int take=0;
    if(arr[index]<=target){
        take=DFS3(index-1,target-arr[index],arr);    
    }
    return take+notTake;
}
bool subsetSumToKBruteForce(int n,int k,vector<int>& arr){
    return DFS3(n-1,k,arr)>0;
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS4(int index,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(index==0){
        if(target==0 && arr[0]==0){
            return 2;
        }
        if(target==0 || target==arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    int notTake=DFS4(index-1,target,arr,dp);
    int take=0;
    if(arr[index]<=target){
        take=DFS4(index-1,target-arr[index],arr,dp);    
    }
    dp[index][target]=take+notTake;
    return dp[index][target];
}
bool subsetSumToKBetter(int n,int k,vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return DFS4(n-1,k,arr,dp)>0;
} // TC=O(N*K) SC=O(N*K)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
bool subsetSumToKOptimal(int n,int k,vector<int>& arr){
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int t=0;t<=k;t++){
        if(t==0 && arr[0]==0){  
            dp[0][t]=2;
        }
        else if(t==0 || t==arr[0]){
            dp[0][t]=1;
        }
        else{
            dp[0][t]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int target=0;target<=k;target++){
            int notTake=dp[index-1][target];
            int take=0;
            if(arr[index]<=target){
                take=dp[index-1][target-arr[index]];    
            }
            dp[index][target]=take+notTake;
        }
    }
    return dp[n-1][k]>0;
} // TC=O(N*K) SC=O(N*K)
//For Space Optimized Approach, we can optimize the space used in the tabulation method.
bool subsetSumToKSpaceOptimized(int n,int k,vector<int>& arr){
    vector<int> prev(k+1,0),curr(k+1,0);
    for(int t=0;t<=k;t++){
        if(t==0 && arr[0]==0){  
            prev[t]=2;
        }
        else if(t==0 || t==arr[0]){
            prev[t]=1;
        }
        else{
            prev[t]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int target=0;target<=k;target++){
            int notTake=prev[target];
            int take=0;
            if(arr[index]<=target){
                take=prev[target-arr[index]];    
            }
            curr[target]=take+notTake;
        }
        prev=curr;
    }
    return prev[k]>0;
} // TC=O(N*K) SC=O(K)
int main(){
    int n=3,m=4;
    vector<vector<int>> grid={{2,3,1,2},{3,4,2,2},{5,6,3,5}};
    cout<<maximumChocolatesBruteForce(grid)<<endl;
    cout<<maximumChocolatesBetter(grid)<<endl;
    cout<<maximumChocolatesOptimal(grid)<<endl;
    int target=5;
    vector<int> arr={2,3,5};
    if(subsetSumToKBruteForce(n,target,arr)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    if(subsetSumToKBetter(n,target,arr)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    if(subsetSumToKOptimal(n,target,arr)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    if(subsetSumToKSpaceOptimized(n,target,arr)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}