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
//Problem 3: Longest String Chain
//A string chain is a sequence of words [word1, word2, ..., wordk] such that word1 is a predecessor of word2, word2 is a predecessor of word3 and so on. A word A is a predecessor of B if and only if we can add exactly one letter anywhere in A to get B.
//For Optimal Approach, we will sort the given array of strings based on their lengths and then use a similar approach as the longest increasing subsequence to find the longest string chain.
bool isPredecessor(string& a,string& b){
    if(b.length()-a.length()!=1){
        return false;
    }
    int i=0,j=0;
    while(i<a.length() && j<b.length()){
        if(a[i]==b[j]){
            i++;
        }
        j++;
    }
    return i==a.length();
}
bool compare(string& a,string& b){
    return a.length()<b.length();
}
int longestStrChain(vector<string>& words){
    sort(words.begin(),words.end(),compare);
    vector<int> dp(words.size(),1),hash(words.size());
    int maxLen=1,lastIndex=0;
    for(int i=0;i<words.size();i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(isPredecessor(words[j],words[i]) && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxLen){
            maxLen=dp[i];
            lastIndex=i;
        }
    }
    return maxLen;
} // TC=O(n^2*m) SC=O(n)
int main(){
    int n=6;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<LIS(nums)<<endl;
    vector<int> result=largestDivisibleSubset(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    vector<string> words={"a","b","ba","bca","bda","bdca"};
    cout<<longestStrChain(words)<<endl;
    return 0;
}