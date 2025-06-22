#include <iostream>
#include <unordered_set>
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
//Problem 2: Find if the array elements add up to target value k
void FindingElements(int n,int arr[],int k){
    unordered_set<int> s;
    int a=0,b=0;
    for(int i=0;i<n;i++){
        if(s.find(k - arr[i]) != s.end()){
            a = k - arr[i];
            b = arr[i];
            break;
        }
        s.insert(arr[i]);
    }
    cout << "The elements that add up to " << k << " are: " << a << " and " << b << endl;
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
    //cout<<"The result is: ";
    //FindingSubArray(size, arr, k);
    FindingElements(size, arr, k);
    return 0;
}