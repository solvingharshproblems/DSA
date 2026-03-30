#include <iostream>
using namespace std;
//Problem 1: Minimum bit flips to convert a number
//For Optimal Approach, we will use the XOR operator to find the bits that are different between the two numbers. 
//Then, we will count the number of set bits in the result, which will give us the minimum number of bit flips required.
int minBitFlips(int a,int b){
    int xorResult=a^b; 
    int count=0;
    while(xorResult){
        count+=xorResult&1; 
        xorResult>>=1; 
    }
    return count; 
} // TC=O(log(max(a,b))) SC=O(1)
//Problem 2: Power Set
//Given a set, we need to return all possible subsets of the given set.
//For Optimal Approach, we will use bit manipulation to generate all possible subsets. We can represent each subset as a binary number, 
//where the i-th bit indicates whether the i-th element of the set is included in the subset or not. 
//We will iterate through all numbers from 0 to 2^n - 1 (where n is the size of the set) and generate the corresponding subset for each number.
vector<vector<int>> powerSet(vector<int>& nums){
    vector<vector<int>> result;
    int n=nums.size();
    int totalSubsets=1<<n; 
    for(int i=0;i<totalSubsets;i++){
        vector<int> subset;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){ 
                subset.push_back(nums[j]);
            }
        }
        result.push_back(subset);
    }
    return result;
} // TC=O(N*2^N) SC=O(N*2^N)
//Problem 3: Single Number - I
//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//For Optimal Approach, we will use the XOR operator to find the single number.
int singleNumber(vector<int>& nums){
    int result=0;
    for(int num:nums){
        result^=num; 
    }
    return result; 
} // TC=O(N) SC=O(1)
//Problem 4: Single Number - II
//Given a non-empty array of integers, every element appears three times except for one. Find that single one.
//For Optimal Approach, we will use bit manipulation to count the number of times each bit is set across all numbers. 
//We will then take the count of each bit modulo 3 to find the bits of the single number.
int singleNumberII(vector<int>& nums){
    int result=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int num:nums){
            if(num & (1<<i)){
                count++;
            }
        }
        if(count%3){
            result|=(1<<i);
        }
    }
    return result;
} // TC=O(N) SC=O(1)
int main(){
    int a=29;
    int b=15;
    cout<<"Minimum bit flips required to convert "<<a<<" to "<<b<<" is: "<<minBitFlips(a,b)<<endl;
    vector<int> nums={1,2,3};
    vector<vector<int>> subsets=powerSet(nums);
    cout<<"Power Set:"<<endl;
    for(const auto& subset:subsets){
        cout<<"{ ";
        for(int num:subset){
            cout<<num<<" ";
        }
        cout<<"}"<<endl;
    }
    vector<int> arr={2,2,1};
    cout<<"Single Number is: "<<singleNumber(arr)<<endl;
    vector<int> arr2={0,1,0,1,0,1,99};
    cout<<"Single Number is: "<<singleNumberII(arr2)<<endl;
    return 0;
}