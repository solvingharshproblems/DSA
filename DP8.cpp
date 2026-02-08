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
//Problem 2: Partition a Set into Two Subsets with Minimum Absolute Sum Difference
//We need to find the minimum absolute difference between the sums of two subsets of the given array.
//For Brute Force Approach, we can use recursion to explore all possible subsets and calculate the minimum absolute difference.
int DFS3(int i,vector<int>& arr,int sum,int totalSum){
    if(i==arr.size()){
        int sum2=totalSum-sum;
        return abs(sum-sum2);
    }
    int take=DFS3(i+1,arr,sum+arr[i],totalSum);
    int notTake=DFS3(i+1,arr,sum,totalSum);
    return min(take, notTake);
}
int subsetSumToKBruteForce(vector<int>& nums){
    int n=nums.size();
    int totalSum=0;
    for(int num:nums){
        totalSum+=num;
    }   
    return DFS3(0,nums,0,totalSum);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the results of subproblems.
int DFS4(int i,int target,vector<int>& arr,int totalSum,vector<vector<int>>& dp){
    if(i==arr.size()){
        return abs(target-(totalSum-target));
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int take=DFS4(i+1,target+arr[i],arr,totalSum,dp);
    int notTake=DFS4(i+1,target,arr,totalSum,dp);
    dp[i][target]=min(take, notTake);
    return dp[i][target];
}
int subsetSumToKBetter(vector<int>& nums){
    int n=nums.size();
    int totalSum=0;
    for(int num:nums){
        totalSum+=num;
    }   
    vector<vector<int>> dp(n,vector<int>(totalSum+1,-1));
    return DFS4(0,0,nums,totalSum,dp);
} // TC=O(N*TotalSum) SC=O(N*TotalSum)+O(N)
//For Optimal Approach, we will use tabulation to fill the dp table iteratively.
int subsetSumToKOptimal(vector<int>& nums){
    int totSum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        totSum+=nums[i];
    }        
    vector<vector<bool>> dp(n,vector<bool>(totSum+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(nums[0]<=totSum){          
        dp[0][nums[0]]=true;
    }
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=totSum;target++){
            bool notTaken=dp[ind-1][target];
            bool taken=false;
            if(nums[ind]<=target){
                taken=dp[ind-1][target-nums[ind]];
            }
            dp[ind][target]=notTaken || taken;
        }
    }
    int mini=INT_MAX;
    for(int i=0;i<=totSum;i++){
        if(dp[n-1][i]){
            int diff=abs(i-(totSum-i));
            mini=min(mini,diff);
        }
    }
    return mini;
} // TC=O(N*TotalSum) SC=O(N*TotalSum)  
//For Space Optimized Approach, we can optimize the space used in the tabulation method.
int subsetSumToKSpaceOptimized(vector<int>& nums){
    int totSum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        totSum+=nums[i];
    }        
    vector<bool> prev(totSum+1,false);
    prev[0]=true;
    if(nums[0]<=totSum){          
        prev[nums[0]]=true;
    }
    for(int ind=1;ind<n;ind++){
        vector<bool> cur(totSum+1,false);
        cur[0]=true;
        for(int target=1;target<=totSum;target++){
            bool notTaken=prev[target];
            bool taken=false;
            if(nums[ind]<=target){
                taken=prev[target-nums[ind]];
            }
            cur[target]=notTaken || taken;
        }
        prev=cur;
    }
    int mini=INT_MAX;
    for(int i=0;i<=totSum;i++){
        if(prev[i]){
            int diff=abs(i-(totSum-i));
            mini=min(mini,diff);
        }
    }
    return mini;
} // TC=O(N*TotalSum) SC=O(TotalSum)
int main(){
    int n=4;
    vector<int> arr={1,5,11,5};
    cout<<canPartitionBruteForce(arr)<<endl; 
    cout<<canPartitionBetter(arr)<<endl;
    cout<<canPartitionOptimal(arr)<<endl;
    cout<<canPartitionSpaceOptimized(arr)<<endl;
    int m=4;
    vector<int> arr2={1,2,3,4};
    cout<<subsetSumToKBruteForce(arr2)<<endl;
    cout<<subsetSumToKBetter(arr2)<<endl;
    cout<<subsetSumToKOptimal(arr2)<<endl;  
    cout<<subsetSumToKSpaceOptimized(arr2)<<endl;
    return 0;
}