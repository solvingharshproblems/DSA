#include <iostream>
#include <stack>
using namespace std;
//Problem 1: Next Greater Element
//For Brute Force Approach we will use two nested loops to find the next greater element for each element in the array.
void nextGreaterElementBruteForce   (int arr[], int n){
    for(int i=0;i<n;i++){
        int next=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                next=arr[j];
                break;
            }
        }
        cout<<next<<" ";
    }
} //TC=O(n^2)
//For Optimal Approach we will use a stack to keep track of the elements for which we haven't found the next greater element yet.
void nextGreaterElementOptimal(int arr[], int n){
    stack<int> st;
    int res[n];
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]=-1;
        }
        else{
            res[i]=st.top();
        }
        st.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
} //TC=O(2n) SC=O(n)
//Problem 2: Next Greater Element in a Circular Array
//For Brute Force Approach we will use two nested loops to find the next greater element for each element in the circular array.
void nextGreaterElementCircularBruteForce(int arr[], int n){
    for(int i=0;i<n;i++){
        int next=-1;
        for(int j=1;j<n;j++){
            int index=(i+j)%n;
            if(arr[index]>arr[i]){
                next=arr[index];
                break;
            }
        }
        cout<<next<<" ";
    }
} //TC=O(n^2) SC=O(n)
//For Optimal Approach we will use a stack to keep track of the elements for which we haven't found the next greater element yet.
void nextGreaterElementCircularOptimal(int arr[], int n){
    stack<int> st;
    int res[n];
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(st.empty()){
            res[i%n]=-1;
        }
        else{
            res[i%n]=st.top();
        }
        st.push(arr[i%n]);
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
} //TC=O(2n) SC=O(2n)
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Next Greater Element is: ";
    nextGreaterElementBruteForce(arr,n);
    cout<<endl;
    cout<<"Next Greater Element is: ";
    nextGreaterElementOptimal(arr,n);
    cout<<endl;
    cout<<"Next Greater Element in Circular Array is: ";
    nextGreaterElementCircularBruteForce(arr,n);
    cout<<endl;
    cout<<"Next Greater Element in Circular Array is: ";
    nextGreaterElementCircularOptimal(arr,n);
    cout<<endl;
    return 0;
}