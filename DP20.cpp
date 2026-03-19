#include <iostream>
using namespace std;
//Problem 1: LIS using Binary Search
//For Optimal Approach, we will maintain a vector which will store the longest increasing subsequence at any point of time. 
//We will iterate through the given array and for each element, we will check if it is greater than the last element of the vector. If it is, then we will push it to the vector. 
//Otherwise, we will find the position of the first element in the vector which is greater than or equal to the current element and replace it with the current element. 
int LIS(vector<int>& nums){
    vector<int> v;
    for(int i=0;i<nums.size();i++){
        if(v.empty() || nums[i]>v.back()){
            v.push_back(nums[i]);
        }
        else{
            int pos=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            v[pos]=nums[i];
        }
    }
    return v.size();
} // TC=O(nlogn) SC=O(n)
//Problem 2: Largest Divisible Subset
//We need to find the largest subset of the given array such that for every pair (Si, Sj) of elements in this subset, either Si % Sj == 0 or Sj % Si == 0.
//For Optimal Approach, we will sort the given array and then use a similar approach as the longest increasing subsequence to find the largest divisible subset.
vector<int> largestDivisibleSubset(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<int> dp(nums.size(),1),hash(nums.size());
    int maxLen=1,lastIndex=0;
    for(int i=0;i<nums.size();i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxLen){
            maxLen=dp[i];
            lastIndex=i;
        }
    }
    vector<int> result;
    result.push_back(nums[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        result.push_back(nums[lastIndex]);
    }
    reverse(result.begin(), result.end());
    return result;
} // TC=O(n^2) SC=O(n)
int main(){
    int n=6;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<LIS(nums)<<endl;
    vector<int> result=largestDivisibleSubset(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}