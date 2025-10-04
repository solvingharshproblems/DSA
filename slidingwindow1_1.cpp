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
}