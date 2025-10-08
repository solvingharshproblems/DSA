#include <iostream>
using namespace std;
//Problem 1: Binary Subarrays with Sum
//For Optimal Approach, we will change the statement to sum smaller than or equal to k to also return the subarrays with sum equal to k
void CountBinarySubarraysOptimal(vector<int>& arr,int k){
    if(k<0){
        cout<<"Count of binary subarrays with sum less than or equal to k is: 0"<<endl;
        return;
    }
    int n=arr.size();
    int left=0;
    int right=0;
    int sum=0;
    long long count=0;
    while(right<n){
        sum+=arr[right];
        while(sum>k && left<=right){
            sum-=arr[left];
            left++;
        }
        count+=right-left+1;
        right++;
    }
    cout<<"Count of binary subarrays with sum less than or equal to k is: "<<count<<endl;
} // TC=O(n) SC=O(1)
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
    CountBinarySubarraysOptimal(arr,k);
    return 0;
}