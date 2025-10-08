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
//Problem 2: Count the number of nice subarrays
//Return the number of subarrays where the count of odd integers is equal to k
 //For Optimal Approach, we will modify the count binary subarray solution with even numbers as 0 and odd nmumbers as 1 and sum=k
int CountNiceSubarraysOptimal(vector<int>& arr,int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            arr[i]=0;
        }
        else{
            arr[i]=1;
        }
    }
    int left=0;
    int right=0;
    int sum=0;
    long long count=0;
    while(right<n){
        sum+=arr[right]%2;
        while(sum>k && left<=right){
            sum-=arr[left]%2;
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
} 
void PrintNiceSubarraysOptimal(vector<int>& arr,int k){
    cout<<"Count of nice subarrays is: "<<CountNiceSubarraysOptimal(arr,k)-CountNiceSubarraysOptimal(arr,k-1)<<endl;
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
    PrintNiceSubarraysOptimal(arr,k);
    return 0;
}