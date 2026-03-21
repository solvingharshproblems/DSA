#include <iostream>
using namespace std;
//Problem 1: Longest Bitonic Subsequence
//A bitonic subsequence is a sequence of numbers which is first increasing and then decreasing.
//For Optimal Approach, we will use two arrays, one to store the length of the longest increasing subsequence ending at each index and another to store the length of the longest decreasing subsequence starting at each index. 
//We will then iterate through the given array and for each index, we will find the length of the bitonic subsequence by adding the lengths of the increasing and decreasing subsequences and subtracting 1 (to avoid counting the peak element twice). 
//We will keep track of the maximum length of the bitonic subsequence and return it at the end.
int longestBitonicSubsequence(vector<int>& nums){
    int n=nums.size();
    vector<int> inc(n,1),dec(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                inc[i]=max(inc[i],inc[j]+1);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(nums[i]>nums[j]){
                dec[i]=max(dec[i],dec[j]+1);
            }
        }
    }
    int maxLen=0;
    for(int i=0;i<n;i++){
        maxLen=max(maxLen,inc[i]+dec[i]-1);
    }
    return maxLen;
} // TC=O(n^2) SC=O(n)
int main() {
    int n=5;
    vector<int> nums={1,11,2,10,4};
    cout<<longestBitonicSubsequence(nums)<<endl;
    return 0;
}