#include <iostream>
using namespace std;
//Problem 1: Find the longest subarray with sum k
void FindingSubArray(int n,int arr[],int k){
    int sum=0,start=0,maxLength=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>k && start<=i){
            sum-=arr[start];
            start++;
        }
        if(sum==k){
            maxLength=max(maxLength,i-start+1);
        }
    }
    cout<<maxLength;
}
int main(){
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the sum k: ";
    cin >> k;
    cout<<"The result is: ";
    FindingSubArray(size, arr, k);
    return 0;
}