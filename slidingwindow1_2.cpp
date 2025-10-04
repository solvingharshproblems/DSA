#include <iostream>
using namespace std;
//Problem 1: Maximum points you can obtain from cards
//You have given an array of points and an integer k. In one move, you can take one card from the beginning or from the end of the array. 
//You have to return the maximum points you can obtain from cards.
//For Brute Force Approach, we can generate all of the combinations of taking k cards from the beginning or end and calculate the maximum points
void MaxPointsBruteForce(vector<int> arr,int k){
    int n=arr.size();
    int maxPoints=0;
    for(int i=0;i<=k;i++){
        int points=0;
        for(int j=0;j<i;j++){
            points+=arr[j];
        }
        for(int j=n-(k-i);j<n;j++){
            points+=arr[j];
        }
        maxPoints=max(maxPoints,points);
    }
    cout<<maxPoints;
} // TC=O(n^2) SC=O(1)
//For Optimal Approach, we can declare leftsum=0 and rightsum=sum of last k elements
//Then we can iterate from k to 0 and update leftsum and rightsum and calculate maxPoints
void MaxPointsOptimal(vector<int> arr,int k){
    int n=arr.size();
    int leftsum=0;
    int rightsum=0;
    int maxPoints=0;
    for(int i=0;i<k;i++){
        leftsum+=arr[i];
    }
    maxPoints=leftsum;
    int rightIndex=n-1;
    for(int i=k-1;i>=0;i--){
        leftsum-=arr[i];
        rightsum+=arr[rightIndex];
        rightIndex--;
        maxPoints=max(maxPoints,leftsum+rightsum);
    }
    cout<<maxPoints;
} // TC=O(2n) SC=O(1)
int main(){
    int n;
    cout<<"Enter the size of array: ";  
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the number of cards to be taken: ";
    cin>>k;
    MaxPointsBruteForce(arr,k);
    cout<<endl;
    MaxPointsOptimal(arr,k);
    cout<<endl;
    return 0;
}