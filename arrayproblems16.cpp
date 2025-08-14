#include <iostream>
#include <unordered_map>
using namespace std;
//Problem 1: 2Sum: take an array of integers and a target integer, return indices of the two numbers such that they add up to the target.
//Variety 1: Print the indices of the two numbers that add up to the target sum.
void TwoSumBruteForce(int n,int arr[],int target){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                cout<<"Indices found: "<<i<<" and "<<j<<endl;
                return;
            }
        }
    }
    cout<<"No such indices found"<<endl;
}
//For better solution, we can use a hash map to store the indices of the elements.
void TwoSumBetter(int n,int arr[],int target){
    unordered_map<int,int>ump;
    for(int i=0;i<n;i++){
        int complement=target-arr[i]; // Find the complement of the current element
        if(ump.find(complement)!=ump.end()){
            cout<<"Indices found: "<<ump[complement]<<" and "<<i<<endl;
            return;
        }
        ump[arr[i]] = i;
    }
}
//For optimal solution, we can declare 2 pointers, one at the start and one at the end of the sorted array, and move them towards each other.
//However, this requires the array to be sorted, which is not always the case in the input.
void TwoSumOptimal(int n,int arr[],int target){
    // Sort the array first (not implemented here)
    // Then use two pointers to find the indices
    sort(arr, arr + n); // Sorting the array
    int left=0,right=n-1;
    while (left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            cout<<"Indices found: "<<left<<" and "<<right<<endl;
            return;
        } 
        else if(sum<target){
            left++;
        }
        else {
            right--;
        }
    }
    cout << "No such indices found" << endl;
}
int main(){
    int size,target;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the target sum: ";
    cin>>target;
    TwoSumBruteForce(size, arr, target);
    TwoSumBetter(size, arr, target);
    TwoSumOptimal(size, arr, target);
    return 0;
}