#include <iostream>
using namespace std;
//Problem 1: Jump Game
//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//Return true if you can reach the last index, or false otherwise.
//For Optimal Approach, we will keep track of the maximum reachable index at each step
bool JumpGameOptimal(vector<int> nums){
    int n=nums.size();
    int maxReach=0;
    for(int i=0;i<n;i++){
        if(i>maxReach){
            return false;
        }
        maxReach=max(maxReach,i+nums[i]);
    }
    return true;
} // TC=O(n) SC=O(1)
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    if(JumpGameOptimal(nums)){
        cout<<"You can reach the last index."<<endl;
    }
    else{
        cout<<"You cannot reach the last index."<<endl;
    }
    return 0;
}