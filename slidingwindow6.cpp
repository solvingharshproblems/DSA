#include <iostream>
#include <unordered_map>
using namespace std;
//Problem 1: Subarrays with K Different Integers
//For Brute Force Approach, we can use a nested loop to find all the subarrays and check if they have k different integers
void CountSubarraysBruteForce(vector<int>& arr,int k){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        unordered_map<int,int> mp;
        for(int j=i;j<n;j++){
            mp[arr[j]]++;
            if(mp.size()==k){
                count++;
            }
            else if(mp.size()>k){
                break;
            }
        }
    }
    cout<<"Count of subarrays with k different integers is: "<<count<<endl;
} // TC=O(n^2) SC=O(n)
//For Optimal Approach, we will try to find subarrays less than or equal to k different integers and subtract it from subarrays less than or equal to k-1 different integers
int CountSubarraysOptimal(vector<int>& arr,int k){
    int n=arr.size();
    int left=0;
    int right=0;
    unordered_map<int,int> mp;
    long long count=0;
    while(right<n){
        mp[arr[right]]++;
        while(mp.size()>k && left<=right){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}
void PrintSubarraysOptimal(vector<int>& arr,int k){
    cout<<"Count of subarrays with k different integers is: "<<CountSubarraysOptimal(arr,k)-CountSubarraysOptimal(arr,k-1)<<endl;
} // TC=O(n) SC=O(n)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    CountSubarraysBruteForce(arr,k);
    PrintSubarraysOptimal(arr,k);
    return 0;
}