#include <iostream>
using namespace std;
//Problem 1: Partition Equal Subset Sum
//We need to determine if there exists a subset of the given array that sums up to a target value k.
//For Brute Force Approach, we can use recursion to explore all possible subsets.
int DFS(int i,vector<int>& arr,int target){
    if(i==0){
        if(target==0 && arr[0]==0){
            return 2;
        }
        if(target==0 || target==arr[0]){
            return 1;
        }
        return 0;
    }
    int notTake=DFS(i-1,arr,target);
    int take=0;
    if(arr[i]<=target){
        take=DFS(i-1,arr,target-arr[i]);
    }
    return take+notTake;
}
bool canPartitionBruteForce(vector<int>& arr){
    int n=arr.size();
    int sum=0;
    for(int num:arr){
        sum+=num;
    }
    if(sum%2!=0){
        return false;
    }
    int target=sum/2;
    return DFS(n-1,arr,target)>0;
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS2(int i,vector<int>& arr,int target,vector<vector<int>>& dp){
    if(i==0){
        if(target==0 && arr[0]==0){
            return 2;
        }
        if(target==0 || target==arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int notTake=DFS2(i-1,arr,target,dp);
    int take=0;
    if(arr[i]<=target){
        take=DFS2(i-1,arr,target-arr[i],dp);
    }
    dp[i][target]=take+notTake;
    return dp[i][target];
}
bool canPartitionBetter(vector<int>& arr){
    int n=arr.size();
    int sum=0;
    for(int num:arr){
        sum+=num;
    }
    if(sum%2!=0){
        return false;
    }
    int target=sum/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return DFS2(n-1,arr,target,dp)>0;
} // TC=O(N*K) SC=O(N*K)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
bool canPartitionOptimal(vector<int>& arr){
    int n=arr.size();
    int sum=0;
    for(int num:arr){
        sum+=num;
    }
    if(sum%2!=0){
        return false;
    }
    int target=sum/2;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(arr[0]<=target){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int t=1;t<=target;t++){
            int notTake=dp[i-1][t];
            int take=0;
            if(arr[i]<=t){
                take=dp[i-1][t-arr[i]];
            }
            dp[i][t]=take||notTake;
        }
    }
    return dp[n-1][target]>0;
} // TC=O(N*K) SC=O(N*K)
//For Space Optimized Approach, we can optimize the space used in the memoization method.
bool canPartitionSpaceOptimized(vector<int>& arr){
    int n=arr.size();
    int sum=0;
    for(int num:arr){
        sum+=num;
    }
    if(sum%2!=0){
        return false;
    }
    int target=sum/2;
    vector<bool> prev(target+1,false),curr(target+1,false);
    prev[0]=true;
    if(arr[0]<=target){
        prev[arr[0]]=true;
    }
    for(int i=1;i<n;i++){
        curr[0]=true;
        for(int t=1;t<=target;t++){
            bool notTake=prev[t];
            bool take=false;
            if(arr[i]<=t){
                take=prev[t-arr[i]];
            }
            curr[t]=take||notTake;
        }
        prev=curr;
    }
    return prev[target];    
} // TC=O(N*K) SC=O(K)
int main(){
    int n=4;
    vector<int> arr={1,5,11,5};
    cout<<canPartitionBruteForce(arr)<<endl; 
    cout<<canPartitionBetter(arr)<<endl;
    cout<<canPartitionOptimal(arr)<<endl;
    cout<<canPartitionSpaceOptimized(arr)<<endl;
    return 0;
}