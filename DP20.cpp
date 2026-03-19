#include <iostream>
using namespace std;
//Problem 1: LIS using Binary Search
//For Optimal Approach, we will maintain a vector which will store the longest increasing subsequence at any point of time. 
//We will iterate through the given array and for each element, we will check if it is greater than the last element of the vector. If it is, then we will push it to the vector. 
//Otherwise, we will find the position of the first element in the vector which is greater than or equal to the current element and replace it with the current element. 
int LIS(vector<int>& nums) {
    vector<int> v;
    for(int i=0; i<nums.size(); i++){
        if(v.empty() || nums[i] > v.back()){
            v.push_back(nums[i]);
        }
        else{
            int pos = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v[pos] = nums[i];
        }
    }
    return v.size();
} // TC=O(nlogn) SC=O(n)
int main(){
    int n=6;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<LIS(nums)<<endl;
    return 0;
}