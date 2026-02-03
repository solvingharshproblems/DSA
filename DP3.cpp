#include <iostream>
using namespace std;
//Problem 1: House Robber
//You are given an array of non-negative integers representing the amount of money of each house.
//Determine the maximum amount of money you can rob tonight without alerting the police (i.e., without robbing two adjacent houses).
//For Brute Force Approach, we can use recursion to
int DFS(vector<int>& nums,int index){
    if(index<0){
        return 0;
    }
    return max(nums[index]+DFS(nums,index-2),DFS(nums,index-1));
}
int rob(vector<int>& nums){
    int n=nums.size();
    return DFS(nums,n-1);
} // TC=O(2^N) SC=O(N)
//For Better Approach, we can use memoization to store the computed maximum amount that can be robbed up to each house.
int robDP(vector<int>& nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    if(n==0){
        return 0;
    }
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=0;i<n;i++){
        dp[i]=max(nums[i]+(i-2>=0?dp[i-2]:0),dp[i-1]);
    }
    return dp[n-1];
} // TC=O(N) SC=O(N)
//For Optimal Approach, we will use space optimization to reduce the space complexity.
int robSpaceOpt(vector<int>& nums){
    int n=nums.size();
    if(n==0){
        return 0;
    }
    int a=nums[0];
    int b=max(nums[0],nums[1]);
    int c;
    for(int i=2;i<n;i++){
        c=max(nums[i]+a,b);
        a=b;
        b=c;
    }
    return c;
} // TC=O(N) SC=O(1)
//Problem 2: House Robber II
//The modification in this problem is that all houses are arranged in a circle.
//This means the first house is the neighbor of the last one.
//For Optimal Approach, we will use memoization to store the computed maximum amount that can be robbed up to each house
int solve(vector<int>& nums,int start,int end){
    int n=end-start+1;
    if(n==0){
        return 0;
    }
    if(n==1){
        return nums[start];
    }
    vector<int> dp(n,-1);
    dp[0]=nums[start];
    dp[1]=max(nums[start],nums[start+1]);
    for(int i=2;i<n;i++){
        dp[i]=max(nums[start+i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}
int robCircle(vector<int>& nums){
    int n=nums.size();
    if(n==1){
        return nums[0];
    }
    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(nums[i]);
        }
        if(i!=n-1){
            temp2.push_back(nums[i]);
        }
    }
    return max(solve(nums,1,n-1),solve(nums,0,n-2));
} // TC=O(N) SC=O(N) 
int main(){
    int n;
    cout<<"Enter number of houses: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter amount of money in each house: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Maximum amount of money that can be robbed: "<<rob(nums)<<endl;
    cout<<"Maximum amount of money that can be robbed: "<<robDP(nums)<<endl;
    cout<<"Maximum amount of money that can be robbed: "<<robSpaceOpt(nums)<<endl;
    cout<<"Maximum amount of money that can be robbed in circle: "<<robCircle(nums)<<endl;
    return 0;
}