#include <iostream>
using namespace std;
//There are mostly 4 types of problem patterns in sliding window/2 pointers
//1. Fixed size window (eg: max sum of k consecutive elements)
void FixedSizeWindow(vector<int> arr,int k){
    int l=0,r=k-1;
    int n=arr.size();
    int sum=0;
    if(n<k){
        cout<<"Invalid input";
        return;
    }
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxSum=sum;
    for(int i=k;i<n;i++){
        sum+=arr[i]-arr[i-k];
        maxSum=max(maxSum,sum);
    }
    cout<<maxSum;
} // TC=O(2n) SC=O(1)
//2. Longest subarray(substring with <condition>)
//Longest subarray with sum<=k
//For Brute Force Approach, we can generate all of the subarrays and check if their sum is less than or equal to k
void LongestSubarrayBruteForce(vector<int> arr,int k){
    int n=arr.size();
    int sum=0;
    int maxLength=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum<=k){
                maxLength=max(maxLength,j-i+1);
            }
            else if(sum>k){
                break;
            }
        }
    }
    cout<<maxLength;
} // TC=O(n^2) SC=O(1)
//For Better Approach, we can use sliding window technique
void LongestSubarrayBetter(vector<int> arr,int k){
    int n=arr.size();
    int l=0,r=0;
    int sum=0;
    int maxLength=0;
    while(r<n){
        sum+=arr[r];
        while(sum>k){
            sum-=arr[l];
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
    }
    cout<<maxLength;
} // TC=O(2n) SC=O(1)
//For Optimal Approach, we will compute 2 of these steps into a single step of better approach
void LongestSubarrayOptimal(vector<int> arr,int k){
    int n=arr.size();
    int l=0,r=0;
    int sum=0;
    int maxLength=0;
    while(r<n){
        sum+=arr[r];
        if(sum>k){
            sum-=arr[l];
            l++;
        }
        maxLength=max(maxLength,r-l+1);
        r++;
    }
    cout<<maxLength;
} // TC=O(n) SC=O(1)
//3. Number of subarrays where <condition> using pattern 2.
//No. of subarrays with sum<=k
void NumberofSubarrays(vector<int> arr,int k){
    int n=arr.size();
    int l=0,r=0;
    int sum=0;
    int count=0;
    while(r<n){
        sum+=arr[r];
        while(sum>k){
            sum-=arr[l];
            l++;
        }
        count+=r-l+1;
        r++;
    }
    cout<<count;
} // TC=O(2n) SC=O(1)
int main(void){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the size of window: ";
    cin>>k;
    FixedSizeWindow(arr,k);
    cout<<endl;
    LongestSubarrayBruteForce(arr,k);
    cout<<endl;
    LongestSubarrayBetter(arr,k);
    cout<<endl; 
    LongestSubarrayOptimal(arr,k);
    cout<<endl;
    NumberofSubarrays(arr,k);
}