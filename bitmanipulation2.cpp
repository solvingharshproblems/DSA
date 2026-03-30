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
    return 0;
}