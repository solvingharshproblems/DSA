#include <iostream>
using namespace std;
//Problem 1: Target Sum
//Given an array of integers, you can add a '+' or '-' sign before each integer and then concatenate them to form an expression. 
//For example, if the array is [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to form the expression "+2-1". 
//Return the number of different expressions that you can build, which evaluates to the target sum.
//For Brute Force Approach, we can use a recursive function to explore all possible combinations of '+' and '-' signs for each integer in the array.
int DFS(vector<int>& nums,int target,int index,int currentSum){
    if(index==nums.size()){
        if(currentSum==target){
            return 1;
        }
        else{
            return 0;
        }
    }
    int add=DFS(nums,target,index+1,currentSum+nums[index]);
    int subtract=DFS(nums,target,index+1,currentSum-nums[index]);
    return add+subtract;
}
int findTargetSumWaysBruteForce(vector<int>& nums,int target){
    int n=nums.size();
    return DFS(nums,target,0,0);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS2(vector<int>& nums,int target,int index,int currentSum,vector<vector<int>>& dp){
    if(index==nums.size()){
        if(currentSum==target){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[index][currentSum+1000]!=-1){
        return dp[index][currentSum+1000];
    }
    int add=DFS2(nums,target,index+1,currentSum+nums[index],dp);
    int subtract=DFS2(nums,target,index+1,currentSum-nums[index],dp);
    dp[index][currentSum+1000]=add+subtract;
    return dp[index][currentSum+1000];
}
int findTargetSumWaysBetter(vector<int>& nums,int target){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(2001,-1));
    return DFS2(nums,target,0,0,dp);
} // TC=O(N*2001) SC=O(N*2001)+O(N)
//For Optimal Approach, we will use tabulation to iteratively fill a 2D array where the rows represent the index of the current integer and the columns represent the possible sums from -1000 to 1000.
int findTargetSumWaysOptimal(vector<int>& nums,int target){
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(2001,0));
    dp[0][nums[0]+1000]=1;
    dp[0][-nums[0]+1000]+=1;
    for(int i=1;i<n;i++){
        for(int sum=-1000;sum<=1000;sum++){
            if(dp[i-1][sum+1000]>0){
                dp[i][sum+nums[i]+1000]+=dp[i-1][sum+1000];
                dp[i][sum-nums[i]+1000]+=dp[i-1][sum+1000];
            }
        }
    }   
    if(target>1000 || target<-1000){
        return 0;
    }
    return dp[n-1][target+1000];
} // TC=O(N*2001) SC=O(N*2001)
//For Space Optimized Approach, we will optimize the space complexity by using a 1D array instead of a 2D array, since the current state only depends on the previous state.
int findTargetSumWaysSpaceOptimized(vector<int>& nums,int target){
    int n=nums.size();
    vector<int> dp(2001,0);
    dp[nums[0]+1000]=1;
    dp[-nums[0]+1000]+=1;
    for(int i=1;i<n;i++){
        vector<int> next(2001,0);
        for(int sum=-1000;sum<=1000;sum++){
            if(dp[sum+1000]>0){
                next[sum+nums[i]+1000]+=dp[sum+1000];
                next[sum-nums[i]+1000]+=dp[sum+1000];
            }
        }
        dp=next;
    }
    if(target>1000 || target<-1000){
        return 0;
    }
    return dp[target+1000];
} // TC=O(N*2001) SC=O(2001)
//Problem 2: Coin Change 2
//Given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
//For Brute Force Approach, we can use a recursive function to explore all possible combinations of coins that sum up to the target amount.
int DFS3(vector<int>& coins,int amount,int index){
    if(amount==0){  
        return 1;
    }
    if(index==coins.size() || amount<0){
        return 0;
    }
    int include=DFS3(coins,amount-coins[index],index);
    int exclude=DFS3(coins,amount,index+1);
    return include+exclude;
}
int changeBruteForce(vector<int>& coins,int amount){
    return DFS3(coins,amount,0);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of previously computed subproblems and avoid redundant calculations.
int DFS4(vector<int>& coins,int amount,int index,vector<vector<int>>& dp){
    if(amount==0){
        return 1;
    }
    if(index==coins.size() || amount<0){
        return 0;
    }
    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    int include=DFS4(coins,amount-coins[index],index,dp);
    int exclude=DFS4(coins,amount,index+1,dp);
    dp[index][amount]=include+exclude;
    return dp[index][amount];
}
int changeBetter(vector<int>& coins,int amount){
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return DFS4(coins,amount,0,dp);
} // TC=O(N*Amount) SC=O(N*Amount)+O(N)
//For Optimal Approach, we will use tabulation to iteratively fill a 2D array where the rows represent the index of the current coin and the columns represent the possible amounts from 0 to the target amount.
int changeOptimal(vector<int>& coins,int amount){
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,0));
    for(int i=0;i<n;i++){   
        dp[i][0]=1;
    }       
    for(int i=0;i<n;i++){
        for(int j=1;j<=amount;j++){
            if(i>0){
                dp[i][j]=dp[i-1][j];
            }
            if(j>=coins[i]){
                dp[i][j]+=dp[i][j-coins[i]];
            }
        }
    }
    return dp[n-1][amount];
} // TC=O(N*Amount) SC=O(N*Amount)
//For Space Optimized Approach, we will optimize the space complexity by using a 1D array instead of a 2D array, since the current state only depends on the previous state.    
int changeSpaceOptimized(vector<int>& coins,int amount){
    int n=coins.size();
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=coins[i];j<=amount;j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[amount];
} // TC=O(N*Amount) SC=O(Amount)
int main(){
    int n=5;
    vector<int> nums={1,1,1,1,1};
    int target=3;
    cout<<findTargetSumWaysBruteForce(nums,target)<<endl;
    cout<<findTargetSumWaysBetter(nums,target)<<endl;
    cout<<findTargetSumWaysOptimal(nums,target)<<endl;
    cout<<findTargetSumWaysSpaceOptimized(nums,target)<<endl;
    int m=3;
    vector<int> coins={1,2,3};
    int amount=4;
    cout<<changeBruteForce(coins,amount)<<endl;
    cout<<changeBetter(coins,amount)<<endl;
    cout<<changeOptimal(coins,amount)<<endl;
    cout<<changeSpaceOptimized(coins,amount)<<endl;
    return 0;
}