#include <iostream>
using namespace std;
//Problem 1: Finding the missing number in an array of size n containing numbers from 1 to n
void FindingMissingNo(int n,int arr[]){
    int sum=(n*(n+1))/2; // Sum of first n natural numbers
    int s=0;
    for(int i=0;i<n-1;i++){
        s+=arr[i]; // Sum of elements in the array
    }
    int missingNo=sum-s; // The missing number is the difference between the expected sum and the actual sum
    cout<<missingNo<<endl; // Output the missing number
}
//Problem 2: Finding maximum consecutive 1's in a binary array
void FindingMaxConsecutiveOnes(int n,int arr[]){
    int maxCount=0,count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maxCount=max(maxCount, count); // Update maxCount if current count is greater
        }
        else{
            count=0; // Reset count for the next sequence
        }
    }
    cout<<maxCount<<endl; // Output the maximum count of consecutive 1's
}
//Problem 3: Finding number that appeaers only once in an array where every other number appears twice
void FindingSingleNumber(int n,int arr[]){
    int count=0;
    for(int i=0;i<n;i++){
        count ^= arr[i]; // Using XOR to find the unique number
    }
    cout<<count<<endl; // Output the count of unique elements
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The resultant is: ";
    //FindingMissingNo(size, arr);
    //FindingMaxConsecutiveOnes(size, arr);
    FindingSingleNumber(size, arr);
    return 0;
}